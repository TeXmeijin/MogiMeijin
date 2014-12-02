#include "StdAfx.h"
#include "Form1.h"

using namespace Mogitter;

void Form1::Form1_Load(System::Object^  sender, System::EventArgs^  e) {

	FileInfo^ fi=gcnew FileInfo(Application::ExecutablePath);
	this->Icon = gcnew System::Drawing::Icon(fi->DirectoryName+"\\"+"icon\\Edit.ico");

	azukiArea->SetKeyBind(static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C)),gcnew Sgry::Azuki::ActionProc(&Sgry::Azuki::Actions::Copy));
	azukiArea->SetKeyBind(static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::V)),gcnew Sgry::Azuki::ActionProc(&Sgry::Azuki::Actions::Paste));
	azukiArea->SetKeyBind(static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Z)),gcnew Sgry::Azuki::ActionProc(&Sgry::Azuki::Actions::Undo));
	azukiArea->SetKeyBind(static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Y)),gcnew Sgry::Azuki::ActionProc(&Sgry::Azuki::Actions::Redo));
	Sgry::Azuki::Highlighter::KeywordHighlighter^ high = 
		gcnew Sgry::Azuki::Highlighter::KeywordHighlighter();
	//				 array<String^>^ tenkaku = {"\"{\"","\"}\""};
	//				 high->AddKeywordSet(tenkaku,Sgry::Azuki::CharClass::Normal,false);
	high->AddEnclosure("\"{\"","\"}\"",Sgry::Azuki::CharClass::Normal,false);
	high->AddEnclosure("{","}",Sgry::Azuki::CharClass::Function,false);
	azukiArea->Highlighter = high;
	azukiArea->ColorScheme->SetColor(Sgry::Azuki::CharClass::Function,Color::Blue,Color::White);
	//				 azukiArea->ColorScheme->SetColor(Sgry::Azuki::CharClass::DocComment,Color::Gray,Color::White);
	azukiArea->ColorScheme->LineNumberFore = Color::DarkBlue;
	azukiArea->ColorScheme->LineNumberBack = Color::AliceBlue;
	azukiArea->BackColor = Color::White;

	azukiArea->View->setMaxLineNum(999);
	azukiArea->ShowsHScrollBar=false;

	setButtonsEnabled(false);

	fileName = QMarking::readFileName();
	if (fileName->Length > 0)
	{
		open(fileName);
	}

	this->Activate();
	setExplainText(0);
}
void Form1::setchecks(bool set){
	randomCheckBox->Checked = set;
	randomQNum->Enabled = set;
	timelimit->Checked = set;
	makeDescription->Checked = false;
	onlyAnaume->Checked = false;
	makeKaitougun->Checked = false;
	sakuseiRB->Checked = true;
	if (!set)
	{
		minute->Value=0;
		second->Value=1;
	}
}
void Form1::setButtonsEnabled(bool setBool){
	mogiMake->Enabled = isMogiText();
	makeOrDeleteBox->Enabled = setBool;
	kindSetBox->Enabled = setBool;
	keishikiBox->Enabled = setBool;
}
void Form1::setExplainText(int index){
	array<System::String ^> ^text = {"模擬テストの原文をテキストエリアに読み込んでください",
		"穴埋め / 選択問題にしたい箇所をマウスで選択することで作成できます",
		"問題作成が完了したら、生成ボタンを押して試験を始めて下さい。保存もできます",};
	if(index>=0 && index<=text->Length-1)
		whatToDoForUser->Text = text[index];
}
void Form1::over_writeMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (fileName->Length > 0)// && fileName->ToLower()->EndsWith(".mogi")
	{
		FileInfo^ f = gcnew FileInfo(fileName);
		bool IsWriteAble=false;
		IsWriteAble=fileName->ToLower()->EndsWith(".mogi") && isMogiText();
		if (!IsWriteAble)
		{
			IsWriteAble=fileName->ToLower()->EndsWith(".txt") && !isMogiText();
		}
		if (f->Exists && IsWriteAble)
		{
			MyTools::writeTextFile(azukiArea->Text,fileName,mojiCode->Text);
		}else
		{
			named_saveMenuItem_Click(sender,e);
		}
	}else
	{
		named_saveMenuItem_Click(sender,e);
	}
}
void Form1::savingDo(bool append){
	SaveFileDialog^ sdg = gcnew SaveFileDialog();
	sdg->OverwritePrompt = !append;
	if (append)
	{
		sdg->Title = "既存のファイルに追加保存"; 
	}
	if (isMogiText())
	{
		sdg->Filter = "Mogiファイル(*.mogi)|*.mogi"; 
	}else
	{
		sdg->Filter = "テキストファイル(*.txt)|*.txt|すべてのファイル(*.*)|*.*";
	}
	if(sdg->ShowDialog() != System::Windows::Forms::DialogResult::OK){
		return;
	}
	this->Cursor=Windows::Forms::Cursors::AppStarting;
	String^ str2 = "";
	if (append)
	{
		str2 = MyTools::getTextFile(sdg->FileName,mojiCode->Text);
	}
	else
	{
		fileName = sdg->FileName;
	}
	//StreamWriter^ writer = gcnew StreamWriter(sdg->FileName,append,System::Text::Encoding::GetEncoding(mojiCode->Text));
	String^ str = azukiArea->Text->Trim();
	if (append)
	{
		if (str==(ShareData::randomString))
		{
			str = str->Substring(str->IndexOf("\n")+1);
			if (!str2->EndsWith("\n"))
			{
				str = "\n"+str; 
			}
			//temp = temp->Replace(temp->Substring(0,temp->IndexOf("\n")+1),"");
		}
	}
	this->Cursor=Windows::Forms::Cursors::Default;

	MyTools::writeTextFile(str,sdg->FileName,mojiCode->Text);
}

void Form1::azukiArea_CaretMoved(System::Object^  sender, System::EventArgs^  e) {
	if (azukiArea->GetSelectedTextLength()>0)
	{
		return;
	}
	if (isMogiText())
	{
		int now = azukiArea->CaretIndex;
		int top = azukiArea->Document->GetLineHeadIndexFromCharIndex(now);
		int end = azukiArea->Document->GetLineEndIndexFromCharIndex(now);
		for (int i = now-1; i >= top; i--)
		{
			if (azukiArea->Document->GetCharAt(i) == '}')
			{
				if (i>0 && azukiArea->Document->GetCharAt(i-1) == '\"')
				{

				}else
				{
					break;
				}
			}
			if (azukiArea->Document->GetCharAt(i) == '{')
			{
				if (i>0 && azukiArea->Document->GetCharAt(i-1) == '\"')
				{

				}else
				{
					int beg = 0;
					int col = 0;
					azukiArea->Document->GetCaretIndex(beg,col);
					int endKakkoIndex = end;
					for (int j = i; j < end; j++)
					{
						if (azukiArea->Document->GetCharAt(j) == '}')
						{
							if (j>0 && azukiArea->Document->GetCharAt(j-1) == '\"')
							{

							}else
							{
								endKakkoIndex = j;
								break;
							}
						}
					}
					if ((endKakkoIndex - top - col) < (top + col - i))
					{
						azukiArea->Document->SetCaretIndex(beg,endKakkoIndex - top +1);
					}else
					{
						azukiArea->Document->SetCaretIndex(beg,i-top);
					}
					break;
				}
			}
		}
	}
}

void Form1::sampleKeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode==Keys::F5)
	{
		ctrlPusing=true;
	}
	if (!MyTools::isOKString(azukiArea->GetSelectedText()))//!!!
	{
		e->Handled = true;
		e->SuppressKeyPress = true;
		azukiArea->SetSelection(azukiArea->CaretIndex,azukiArea->CaretIndex);
		return;
	}
	if (!(e->KeyCode == Keys::Back || e->KeyCode == Keys::Delete))
	{
		if (e->KeyCode==Keys::Return)
		{
			randomQNum->Maximum = azukiArea->Text->Split('\n')->Length;
		}
		if (e->Shift && e->KeyValue == 219)
		{
			e->SuppressKeyPress = true;
			azukiArea->Document->Replace("\"{\"");
		}
		if (e->Shift && e->KeyValue == 221)
		{
			azukiArea->Document->Replace("\"}\"");
			e->SuppressKeyPress = true;
		}
		return;
	}
	if (azukiArea->Text->Length>0)
	{
		randomQNum->Maximum = azukiArea->Text->Split('\n')->Length;

		int now = azukiArea->CaretIndex;
		int top = azukiArea->Document->GetLineHeadIndexFromCharIndex(now);
		int end = azukiArea->Document->GetLineEndIndexFromCharIndex(now);
		array<wchar_t>^ kak = {'\"','}','\"'};
		if (e->KeyCode == Keys::Back )
		{
			if (now > 0 && azukiArea->Document->GetCharAt(now-1)=='}')
			{
				if (now > 1 && azukiArea->Document->GetCharAt(now-2)=='\"')
				{
					azukiArea->Document->Replace("",now-2,now+1);
					e->Handled = true;
				}else
				{
					e->Handled = true;
				}
			}
			if (now > 0 && azukiArea->Document->GetCharAt(now-1)=='{')
			{
				if (now > 1 && azukiArea->Document->GetCharAt(now-2)=='\"')
				{
					azukiArea->Document->Replace("",now-2,now+1);
					e->Handled = true;
				}
			}
			if (now > 0 && azukiArea->Document->GetCharAt(now-1)=='\"')
			{
				if (now > 1 && azukiArea->Document->GetCharAt(now-2)=='}')
				{
					azukiArea->Document->Replace("",now-3,now);
					e->Handled = true;
				}
				else	 if (now < end-2 && azukiArea->Document->GetCharAt(now)=='}')
				{
					azukiArea->Document->Replace("",now-1,now+2);
					e->Handled = true;
				}
				else if (now > 1 && azukiArea->Document->GetCharAt(now-2)=='{')
				{
					azukiArea->Document->Replace("",now-3,now);
					e->Handled = true;
				}
				else	 if (now < end-2 && azukiArea->Document->GetCharAt(now)=='{')
				{
					azukiArea->Document->Replace("",now-1,now+2);
					e->Handled = true;
				}
			}							 
		}
		if (e->KeyCode == Keys::Delete)
		{
			if (now < end && azukiArea->Document->GetCharAt(now)=='{')
			{
				if (now < end-2 && azukiArea->Document->GetCharAt(now+1)=='\"')
				{
					azukiArea->Document->Replace("",now-1,now+2);
					e->Handled = true;
				}else
				{
					e->Handled = true;
				}
			}
			if (now < end && azukiArea->Document->GetCharAt(now)=='}')
			{
				if (now < end-2 && azukiArea->Document->GetCharAt(now+1)=='\"')
				{
					azukiArea->Document->Replace("",now-1,now+2);
					e->Handled = true;
				}
			}
			if (now < end && azukiArea->Document->GetCharAt(now)=='\"')
			{
				if (now < end-3 && azukiArea->Document->GetCharAt(now+1)=='}')
				{
					azukiArea->Document->Replace("",now,now+3);
					e->Handled = true;
				}
				else	 if (now > 1 && azukiArea->Document->GetCharAt(now-1)=='}')
				{
					azukiArea->Document->Replace("",now-2,now+1);
					e->Handled = true;
				}
				else if (now < end-3 && azukiArea->Document->GetCharAt(now+1)=='{')
				{
					azukiArea->Document->Replace("",now,now+3);
					e->Handled = true;
				}
				else	 if (now > 1 && azukiArea->Document->GetCharAt(now-1)=='{')
				{
					azukiArea->Document->Replace("",now-2,now+1);
					e->Handled = true;
				}
			}							 
		}
	}
}

void Form1::open(String^ filename){
	azukiArea->IsReadOnly = false;
	azukiArea->ClearHistory();
	this->Cursor=Windows::Forms::Cursors::AppStarting;

	if (filename!="AutoIt\\japan_Constitution.txt")
	{
		fileName = filename;
		this->Text = "MogiEditor - "+fileName;
	}
	String^ str = MyTools::getTextFile(filename,mojiCode->Text);
	if(!filename->EndsWith(".mogi")){
		str = str->Replace("{","\"{\"");
		str = str->Replace("}","\"}\"");
		setExplainText(2);
	}else
	{
		setExplainText(1);
	}
	azukiArea->Text = str;
	if (str->StartsWith(ShareData::randomString))
	{
		//{@Random=10;}{@TimeLimit=120;}{@Kaitougun=True;}
		array<String^> ^bufbef = str->Split('\n');
		String^ aft = bufbef[0]->Split('=')[1];
		int qnum = int::Parse(aft->Substring(0,aft->IndexOf(";")));

		if (qnum>0)
		{
			setchecks(true);
		}else
		{
			setchecks(false);
		}
		String^ tl = "@TimeLimit=";
		int timelimitInd = bufbef[0]->IndexOf(tl);
		int timeLimit=0;
		if (timelimitInd>=0)
		{
			timelimitInd+=tl->Length;
			String^ tlStr = bufbef[0]->Substring(timelimitInd,bufbef[0]->IndexOf(ShareData::semiAndKakko,timelimitInd)-timelimitInd);
			if (int::TryParse(tlStr,timeLimit))
			{
				timeLimit = int::Parse(tlStr);
			}
		}

		if (timeLimit>0)
		{
			timelimit->Checked = true;
			minute->Value = timeLimit/60;
			second->Value = timeLimit%60;
		}else
		{
			timelimit->Checked = false;
			minute->Value = 0;
			second->Value = 1;
		}

		makeKaitougun->Checked = bufbef[0]->IndexOf(ShareData::kaitougunString+"=True;}")>=0;

		//2014/9/7 ここにこれを書かないとよくわからない謎バグで落ちる
		randomQNum->Maximum = azukiArea->Text->Split('\n')->Length;
		randomQNum->Value = qnum;
	}else
	{
		setchecks(false);
		randomQNum->Maximum = azukiArea->Text->Split('\n')->Length;
		randomQNum->Value = randomQNum->Maximum;
	}
	this->Cursor=Windows::Forms::Cursors::Default;
	azukiArea->Highlighter->Highlight(azukiArea->Document);
}

void Form1::remake_doing(String^ sele){
	if(sele ==nullptr || sele->Length <= 0){
		return;
	}
	if(sele->StartsWith("{Answer") && sele->EndsWith(ShareData::semiAndKakko)){
		//array<wchar_t>^ sep = {'\n'};
		sele = MogiTest::escapeSet(sele);
		array<String^> ^commands = sele->Split(';');
		if(commands->Length<3 || sele->IndexOf(ShareData::describeString)>=0){
			torikeshi_doing(sele);
			return;
		}
		if (sele->IndexOf("Other=")>=0)
		{
			String^ ansStr = commands[0]->Split('=')[1];
			String^ itemsStr = commands[1]->Split('=')[1];
			array<String^>^ items = itemsStr->Split(',');
			QBuild^ exec = gcnew QBuild();
			exec->answerBox->Text = MogiTest::escapeReSet(ansStr);
			for each(String^ item in items)
			{
				exec->sentakushi->Text += MogiTest::escapeReSet(item) + "\n";
			}
			exec->Text = "問題作り直し";
			exec->betsukaiRB->Checked = true;
			exec->cc();
			bool only = onlyAnaume->Checked;
			onlyAnaume->Checked = false;
			QBuild_doing(exec,MogiTest::escapeReSet(sele));
			onlyAnaume->Checked = only;
		}else{
			String^ ansStr = commands[0]->Split('=')[1];
			int ansNum = int::Parse(commands[2]->Split('=')[1]);
			String^ headMode = commands[3]->Split('=')[1];
			String^ itemsStr = commands[1]->Split('=')[1];
			array<String^>^ items = itemsStr->Split(',');

			QBuild^ exec = gcnew QBuild();
			exec->answerBox->Text = MogiTest::escapeReSet(ansStr);
			exec->seikaiNumber->Maximum = items->Length + 1;
			exec->seikaiNumber->Value = ansNum;
			for each(String^ item in items){
				exec->sentakushi->Text += MogiTest::escapeReSet(item) + "\n";
			}
			if(headMode == "kana"){
				exec->kana_abc->Checked = true;
			}else if(headMode == "katakana"){
				exec->katakana_abc->Checked = true;
			}else if(headMode == "abc"){
				exec->abc->Checked = true;
			}else{
				exec->ABC_->Checked = true;
			}
			exec->Text = "問題作り直し";
			bool only = onlyAnaume->Checked;
			onlyAnaume->Checked = false;
			QBuild_doing(exec,MogiTest::escapeReSet(sele));
			onlyAnaume->Checked = only;
		}
	}else
		MessageBox::Show("\"{\"から\"}\"まで選択してください。","警告!!",MessageBoxButtons::OK,MessageBoxIcon::Error);
}

void Form1::tArea_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	String^ sele = azukiArea->GetSelectedText();
	if(deleteRB->Checked){
		torikeshi_doing(sele);
		return;
	}
	if(sele->StartsWith("{Answer") && sele->EndsWith(ShareData::semiAndKakko)){
		remake_doing(sele);
		return;
	}
	String ^errMsg = "選択位置が\"{}\"の中です。";
	bool isOK = true;
	bool through=false;
	if(sele ==nullptr || sele->Length <= 0){
		return;
	}
	for each (String^ kak in kakkos){
		sele = sele->Replace("\"{\"","@1@");
		sele = sele->Replace("\"}\"","@2@");
		if(sele->IndexOf(kak)>=0){
			errMsg = "選択したテキストに\""+kak+"\"が含まれています。";
			isOK = false;
			through=MyTools::isOKString(sele);
		}
		sele = sele->Replace("@1@","\"{\"");
		sele = sele->Replace("@2@","\"}\"");
	} 
	if(sele->IndexOf("\"")>=0){
		errMsg = "選択したテキストに「\"」が含まれています。";
		isOK = false;
	}
	int caretposi = 	azukiArea->CaretIndex;
	int ancposi = azukiArea->Document->AnchorIndex;

	if(ancposi > caretposi){
		int temp = caretposi;
		caretposi = ancposi;
		ancposi = temp;
	}

	String^ text = azukiArea->Text;
	text = text->Replace("\"{\"","@@@");
	text = text->Replace("\"}\"","@@@");
	String^ before = text->Substring(0,ancposi);
	String^ after = text->Substring(caretposi,text->Length-caretposi);
	if(before->IndexOf("{") > before->IndexOf("}"))
		isOK = false;
	if(after->IndexOf("{")<0){
		if(after->IndexOf("}") >=0)
			isOK = false;
	}else if(after->IndexOf("{") > after->IndexOf("}"))
		if(after->IndexOf("}") >=0)
			isOK = false;

	if(sele->IndexOf("\n") >=0){

		through=MyTools::isOKString(sele);

		isOK = false;
		errMsg = "複数行を問題にはできません。";
	}

	through=MyTools::isOKString(sele) && ctrlPusing;
	if (through)
	{
		isOK=false;
	}

	if(isOK){
		QBuild^ exec = gcnew QBuild();
		exec->beginSet(sele);
		exec->ImeMode=Windows::Forms::ImeMode::Hiragana;
		QBuild_doing(exec,sele);
	}else if(!through){
		MessageBox::Show(errMsg,"エラー",MessageBoxButtons::OK,MessageBoxIcon::Stop);
		azukiArea->Document->Replace(sele);
	}else
	{
		//azukiArea->Document->Replace(sele);
	}
}
String^ Form1::makeDesc(String^ sele){
	String^ retStr="";
	if (makeDescription->Checked)
	{
		retStr = kakkos[0]+ShareData::answerStringMini + MogiTest::escapeReady(sele)+";"+ShareData::describeString+"True;}";
	}else
	{
		retStr = kakkos[0]+ShareData::answerStringMini + MogiTest::escapeReady(sele)+ShareData::semiAndKakko;
	}
	return retStr;
}

void Form1::QBuild_doing(QBuild^ exec , String^ sele){
	String^ retStr = sele;
	if(onlyAnaume->Checked || makeDescription->Checked){// ||  sele->IndexOf("\n") >=0
		retStr = makeDesc(sele);
	}else{
		System::Windows::Forms::DialogResult result = exec->ShowDialog();
		if(result == System::Windows::Forms::DialogResult::OK){
			retStr = "";
			int num = System::Decimal::ToInt32(exec->seikaiNumber->Value);
			int max = System::Decimal::ToInt32(exec->seikaiNumber->Maximum);
			String^ ansStr = exec->answerBox->Text;
			ansStr = MogiTest::escapeReady(ansStr);
			if(exec->sentakushi->Text->Length<=0){// && exec->sentakuRB->Checked
				retStr += makeDesc(ansStr);
			}else{
				retStr += kakkos[1] + ShareData::answerStringMini + ansStr + ";";
				if (exec->betsukaiRB->Checked)
				{
					retStr += "Other=";
				}
				else
				{
					retStr += "Item=";
				}
				//int len = exec->sentakushi->LineCount;
				array<wchar_t>^ sep = {'\n'};
				array<System::String ^> ^kinds=exec->sentakushi->Text->Split(sep);
				int len = 0;
				for(int i=0;i<kinds->Length;i++){
					kinds[i] = kinds[i]->Replace("\n","");
					kinds[i] = kinds[i]->Replace("\r","");
					if(kinds[i]->Length==0)
						continue;
					if(len>0)
						retStr+=",";
					kinds[i] = MogiTest::escapeReady(kinds[i]);
					retStr +=kinds[i];
					len++;
				}
				if (exec->sentakuRB->Checked)
				{
					if(len<num) num = len+1;
					retStr += ";AnswerNum=" + num.ToString("D")+";";
					retStr += "HeadChar=";
					if(exec->kana_abc->Checked){
						retStr += "kana";
					}else if(exec->katakana_abc->Checked){
						retStr += "katakana";
					}else if(exec->abc->Checked){
						retStr += "abc";
					}else{
						retStr += "ABC";
					}
				}
				retStr += ";";
				retStr += "}";
			}
		}
	}
	azukiArea->Document->Replace(retStr);
	this->Focus();
	azukiArea->Focus();
}
void Form1::openFile_Click(System::Object^  sender, System::EventArgs^  e) {
	//randomCheckBox->Checked = false;
	OpenFileDialog^ ofd = gcnew OpenFileDialog();
	ofd->Filter = "テキストファイル(*.txt)|*.txt|Mogiファイル(*.mogi)|*.mogi|すべてのファイル(*.*)|*.*";
	if (fileName->EndsWith(".mogi"))
	{
		ofd->FilterIndex = 2;
	}
	if(ofd->ShowDialog() != System::Windows::Forms::DialogResult::OK){
		return;
	}
	open(ofd->FileName);
}
int Form1::getsecond(){
	int second = 0;
	if (timelimit->Checked)
	{
		second = (Decimal::ToInt32(minute->Value))*60+Decimal::ToInt32(this->second->Value);
	}else
	{
		second = 0;
	}
	return second;
}
void Form1::doAddFirstRow(){
	if (azukiArea->Text->Length <=0)
	{
		return;
	}
	String^ first = MogiTest::getLineText(azukiArea,1)+"\n";
	int randInd = first->IndexOf(ShareData::randomString);
	String^ ins = getFirstRow();
	//{@Random=10;}{@TimeLimit=120;}{@Kaitougun=true;}
	if (ins->IndexOf(ShareData::randomString+"0;}")>=0 && ins->IndexOf(ShareData::timeLimitString+"0;}")>=0 && ins->IndexOf(ShareData::kaitougunString+"False;}")>=0)
	{
		ins = "";
	}
	if (randInd>=0)
	{
		if (ins->IndexOf(ShareData::randomString)>=0)
		{
			ins+="\n";
		}
		azukiArea->Document->Replace(ins,0,azukiArea->GetLineHeadIndex(1));
		//azukiArea->Text = ins+azukiArea->Text->Substring(azukiArea->GetLineHeadIndex(1));
	}
	else
	{
		if (ins->Length >0)
		{
			ins += "\n";
		}
		azukiArea->Document->Replace(ins,0,0);
		//azukiArea->Text = ins+azukiArea->Text;
	}
}
void Form1::mogiMake_Click(System::Object^  sender, System::EventArgs^  e) {
	if (isMogiText())
	{
		this->Cursor=Windows::Forms::Cursors::AppStarting;
		MogiTest^ test = gcnew MogiTest();
		test->ImeMode=Windows::Forms::ImeMode::Hiragana;
		String^ comTxt = "";
		comTxt = azukiArea->Text;
		test->Show();
		test->compile(comTxt);
		this->Cursor=Windows::Forms::Cursors::Default;
	}
}

void Form1::torikeshi_doing(String^ sele) {
	if(sele ==nullptr || sele->Length <= 0){
		return;
	}
	if(sele->StartsWith(ShareData::answerString) && sele->EndsWith(ShareData::semiAndKakko)){
		array<wchar_t> ^spliters={';'};
		array<String^> ^commands = sele->Split(spliters);
		spliters[0] = '=';
		commands[0] = MogiTest::escapeSet(commands[0]);
		String^ answer = (commands[0]->Split(spliters))[1];
		azukiArea->Document->Replace(MogiTest::escapeReSet(answer));//->Substring(0,answer->Length-1)
	}else
		MessageBox::Show("\"{\"から\"}\"まで選択してください。","警告!!",MessageBoxButtons::OK,MessageBoxIcon::Error);
}

void Form1::MouseMove(int a,int b,int c)
{
	//AutoItX::MouseMove(a,b,c);
}
void Form1::MouseDown(String^ txt)
{
	//AutoItX::MouseDown(txt);
}
void Form1::MouseUp(String^ txt)
{
	//AutoItX::MouseUp(txt);
}
void Form1::MouseClick(String^ txt,int a,int b,int numClick,int d)
{
	//AutoItX::MouseClick(txt,a,b,numClick,d);
}
void Form1::Send(String^ txt)
{
	//AutoItX::Send(txt,0);
}

void Form1::autoitInvoke(){
	FileInfo^ fi=gcnew FileInfo(Application::ExecutablePath);
	doHelp->StartInfo->FileName=fi->DirectoryName+"\\AutoIt\\try.exe";
	//doHelp->StartInfo->Arguments=fi->DirectoryName+"\\uwsc\\help.UWS";
	doHelp->Start();
}

void Form1::helpMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	open("AutoIt\\japan_Constitution.txt");
	this->ImeMode=Windows::Forms::ImeMode::Hiragana;

	System::Threading::ThreadStart^ ts = gcnew System::Threading::ThreadStart(this,&Form1::autoitInvoke);
	System::Threading::Thread^ th = gcnew System::Threading::Thread(ts);
	th->Start();
	//if (th->ThreadState != System::Threading::ThreadState::Unstarted)
	//{
	//	th->Abort();
	//}
}
void Form1::_MsgBox(String^title,String^ text){
	//MessageBox::Show(text,title,MessageBoxButtons::OK, MessageBoxIcon::Information);
}

void Form1::_WinWaitActivate(String^title,String^text){
	//_WinWaitActivate(title,text,0);
}

void Form1::_WinWaitActivate(String^ title,String^ text,int timeout){
	//AutoItX::WinWait(title,text,timeout);
	//if (!AutoItX::WinActive(title,text))
	//{
	//	AutoItX::WinActivate(title,text);
	//}
	//AutoItX::WinWaitActive(title,text,timeout);
}

void Form1::azukiArea_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	setButtonsEnabled(azukiArea->Text->Length>0);
	azukiArea->Highlighter->Highlight(azukiArea->Document);
	randomQNum->Maximum = azukiArea->Document->LineCount;
	if (isMogiText())
	{
		setExplainText(2);
	}else
	{
		setExplainText(1);
	}
}
String^ Form1::randoming(){
	String^ insStr = ShareData::randomString;
	int num = Decimal::ToInt32(randomQNum->Value);
	if (!randomCheckBox->Checked)
	{
		num=0;
	}
	insStr+=num.ToString()+ShareData::semiAndKakko;
	return insStr;
}
String^ Form1::getFirstRow(){
	String^ insStr = "";
	insStr+=randoming();
	insStr+=ShareData::timeLimitString+getsecond().ToString()+ShareData::semiAndKakko;
	insStr+=ShareData::kaitougunString+makeKaitougun->Checked.ToString()+ShareData::semiAndKakko;
	return insStr;
}
bool Form1::isMogiText(){
	if (azukiArea->Text->IndexOf(ShareData::answerString)>=0)
	{
		return true;
	}
	//if (azukiArea->Text->IndexOf("{@")>=0)
	//{
	//	return true;
	//}
	return false;
}
