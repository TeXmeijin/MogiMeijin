#include "StdAfx.h"
#include "MogiTest.h"

using namespace Mogitter;
using namespace System::Windows::Forms;

bool MogiTest::compile(String^ text, bool isPass){
	if (isPass)
	{
		try{
			String^ str = MyTools::getTextFile(text,ShareData::defaultEncode);
			filename=text;
			this->Text="MogiTester - "+filename;
			return compile(str);
		}catch(Exception^){
			return false;
		}
	}else{
		return compile(text);
	}
	return true;
}
bool MogiTest::compile(String^ text){

	this->Cursor=Windows::Forms::Cursors::AppStarting;
	this->Focus();
	keikajikan->Stop();

	splitContainer1->SplitterDistance=451;
	this->userAnswerArea->ViewType = Sgry::Azuki::ViewType::Proportional;//!!!
	setEnableSaiten(true);

	String^ temp = "";
	bool kaitougun = false;
	userAnswerArea->Font = (gcnew System::Drawing::Font(userAnswerArea->Font->FontFamily, userAnswerArea->Font->Size, FontStyle::Regular, System::Drawing::GraphicsUnit::Point,static_cast<System::Byte>(128)));
	if (text->StartsWith(ShareData::randomString))
	{
		Random^ rand = gcnew Random();
		array<String^> ^bufbef = text->Split('\n');
		array<String^> ^buf = gcnew array<String^>(bufbef->Length-1);
		int ansOKlineCount=0;//!!!
		for (int i = 0; i < buf->Length; i++)
		{
			if(bufbef[i+1]->IndexOf(ShareData::answerString) >=0)
			{
				buf[ansOKlineCount] = bufbef[i+1];
				ansOKlineCount++;
			}
		}
		String^ aft = bufbef[0]->Split('=')[1];
		int qnum = int::Parse(aft->Substring(0,aft->IndexOf(";")));
		if (qnum>ansOKlineCount)
		{
			qnum=ansOKlineCount;
		}
		if (qnum>0)
		{
			String^ comTxt = "";
			array<String^> ^ret = gcnew array<String^>(qnum);
			array<bool> ^alreadyGot = gcnew array<bool>(ansOKlineCount);
			int len = ansOKlineCount;
			for(int i=0;i<len;i++){
				alreadyGot[i] = false;
			}

			int prevInf = 0;

			for (int i = 0; i < qnum; i++)
			{
				int index = rand->Next(len);
				while (alreadyGot[index] && prevInf<1000000)
				{
					index = rand->Next(len);
					prevInf++;
				}
				alreadyGot[index] = true;
				ret[i] = buf[index];
			}
			for (int i = 0; i < qnum; i++)
			{
				comTxt += ret[i]+"\n";
			}

			comTxt = comTxt->Substring(0,comTxt->Length-1);
			if (seikaiNumber->Count <=0 || seikaiNumber[0]==0)//最初の挑戦のとき
			{
				plainText = text;//ここで誤答再挑戦時の文字列が代入 
			}
			temp = comTxt; 

			randomAftTxt = "{@Random=0;}"+bufbef[0]->Substring(bufbef[0]->IndexOf(ShareData::timeLimitString))+"\n"+temp;

		}else{
			temp = text;
			temp = temp->Replace(temp->Substring(0,temp->IndexOf("\n")+1),"");
			if (seikaiNumber->Count <=0 || seikaiNumber[0]==0)//最初の挑戦のとき
			{
				plainText = text;//ここで誤答再挑戦時の文字列が代入 
			}
			randomAftTxt = text;
		}

		//bufbef[0]から制限時間と回答群を取り出す作業
		//{@Random=10;}{@TimeLimit=120;}{@Kaitougun=True;}
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
		kaitougun = bufbef[0]->IndexOf("{@Kaitougun=True;}")>=0;

		if (timeLimit > 0)
		{
			timelimitSecond=timeLimit;
		}else
		{
			timelimitSecond=0;
		}
	}else{
		if (seikaiNumber->Count <=0 || seikaiNumber[0]==0)//最初の挑戦のとき
		{
			plainText = text;//ここで誤答再挑戦時の文字列が代入 
		}
		temp = text;
		randomAftTxt = text;
	}
	int qCount = 0;
	int index = 0;
	questStrings = gcnew List<String^>;
	answerStrings = gcnew List<String^>;
	imageFileNames = gcnew List<String^>;
	imageIndex = gcnew List<int>;

	int husNumInd = 0;
	int whileCount = 0;

	kaitouGunList = gcnew List<String^>;

	while(qCount < 1000){
		int tempI = temp->IndexOf(ShareData::answerString,index);
		if(tempI >=0){
			index = tempI+1;
			qCount++;
			whileCount++;
		}else
			break;
		//書式："1,(answer)"
		//書式："4,(ansNum),aaa:bbb:ccc:ddd"
		//書式："0,(answer),aaa:bbb:ccc:ddd"
		int lastI = temp->IndexOf(ShareData::semiAndKakko,tempI)+2;
		String^ inKakko = temp->Substring(tempI,lastI-tempI);
		String^ saveInKakko = inKakko;
		inKakko = escapeSet(inKakko);

		String^ listAddStr = "";

		if (husNumInd<seikaiNumber->Count && seikaiNumber[husNumInd] == whileCount)
		{
			husNumInd++;
			qCount--;
			String^ answerPortion = inKakko->Split(';')[0];//{Answer=....;Item=...
			String^ answer = answerPortion->Split('=')[1];
			answer = answer->Substring(0,answer->Length);
			answer = escapeReSet(answer);
			temp = replaceFirst(temp,saveInKakko,answer);

			//2回以上誤答の再挑戦を押すと最初のころの問題が出てくるのを解決?
			//plaintextをいじると再挑戦が利かなくなる
			randomAftTxt = replaceFirst(randomAftTxt,saveInKakko,answer);
			//							 plainText = plainText->Replace(saveInKakko,answer);

			continue;
		}

		if(inKakko->IndexOf("Item=")>=0){
			//選択問題の括弧の中を生成する作業
			array<String^>^ options = inKakko->Split(';');
			array<String^>^ items;
			String^ headMode="";
			array<wchar_t>^ headers;
			String^ answer = "";
			int ansNum=0;
			for(int i=0;i<options->Length;i++){
				array<String^>^ ope = options[i]->Split('=');
				if(ope[0]=="{Answer")
					answer = ope[1];
				if(ope[0]=="Item")
					items = ope[1]->Split(',');
				if(ope[0]=="AnswerNum")
					ansNum = System::Int32::Parse(ope[1]);
				if(ope[0]=="HeadChar"){
					headMode = ope[1];
				}
			}

			headers = gcnew array<wchar_t>(items->Length+1);
			int step=1;
			if(headMode == "kana"){
				headers[0] = System::Char::Parse("あ");
				step = 2;
			}else if(headMode == "katakana"){
				headers[0] = System::Char::Parse("ア");
				step = 2;
			}else if(headMode == "abc"){
				headers[0] = System::Char::Parse("a");
			}else{
				headers[0] = System::Char::Parse("A");
			}
			for(int j=1;j<headers->Length;j++){
				headers[j] = headers[j-1]+step;
			}
			String^ retStr = " ( "+qCount+"  ";
			int otherCount=0;

			listAddStr += headers->Length.ToString()+",";
			listAddStr += ansNum.ToString()+",";

			for(int j=0;j<headers->Length;j++){
				if(j>=1)
					retStr += " , ";
				retStr += headers[j].ToString()+": ";
				if((j+1)==ansNum || otherCount >= items->Length){
					retStr += answer;
					listAddStr += answer+":";
				}else{
					retStr += items[otherCount];
					listAddStr +=  items[otherCount]+":";
					otherCount++;
				}
			}
			retStr += " ) ";
			retStr = escapeReSet(retStr);

			temp = replaceFirst(temp,saveInKakko,retStr);
			questStrings->Add(listAddStr);

		}else if(inKakko->IndexOf("Other=")>=0){
			array<String^>^ options = inKakko->Split(';');
			array<String^>^ others;
			String^ answer = "";
			String^ retStr = "";
			for(int i=0;i<options->Length;i++){
				array<String^>^ ope = options[i]->Split('=');
				if(ope[0]=="{Answer")
					answer = ope[1];
				if(ope[0]=="Other")
					others = ope[1]->Split(',');
			}
			answer = escapeReSet(answer);

			kaitouGunList->Add(answer);

			answer = escapeReady(answer);
			retStr += "0,"+answer+",";
			for (int i = 0; i < others->Length; i++)
			{
				others[i] = escapeReady(escapeReSet(others[i]));
				retStr += others[i];
				if (i<others->Length-1)
				{
					retStr += ":";
				}
			}
			questStrings->Add(retStr);
			temp = replaceFirst(temp,saveInKakko," ( "+qCount+" ) ");
			//}else if(inKakko->IndexOf(ShareData::hintImage=")>=0){
			//	//{Answer=sample;Image=sample.jpg;}
			//	array<String^>^ options = inKakko->Split(';');
			//	String^ imageName;
			//	String^ answer = "";
			//	String^ retStr = "";
			//	for(int i=0;i<options->Length;i++){
			//		array<String^>^ ope = options[i]->Split('=');
			//		if(ope[0]=="{Answer")
			//			answer = ope[1];
			//		if(ope[0]==ShareData::hintImage")
			//			imageName = ope[1];
			//	}
			//	answer = escapeReSet(answer);

			//	kaitouGunList->Add(answer);

			//	answer = escapeReady(answer);
			//	retStr += "-1,"+answer+","+imageName;

			//	questStrings->Add(retStr);
			//	temp = replaceFirst(temp,saveInKakko," ( "+qCount+" ) ");
		}else if(inKakko->IndexOf(ShareData::describeString)>=0){
			array<String^>^ options = inKakko->Split(';');
			String^ answer = options[0]->Split('=')[1];
			answer = answer->Substring(0,answer->Length);
			answer = escapeReSet(answer);

			//kaitouGunList->Add(answer);
			listAddStr = "1,"+escapeReady(answer)+","+"describe";
			questStrings->Add(listAddStr);

			temp = replaceFirst(temp,saveInKakko," ( "+qCount+" ) ");
		}else{
			String^ answer = inKakko->Split('=')[1];
			//****!!!!
			//特殊文字の問題。"," ";" "="はエスケープすべき。
			//ここの-2は;}を取り除くための手抜きアルゴリズム
			answer = answer->Split(';')[0];
			answer = escapeReSet(answer);

			kaitouGunList->Add(answer);
			listAddStr = "1,"+escapeReady(answer);
			questStrings->Add(listAddStr);

			temp = replaceFirst(temp,saveInKakko," ( "+qCount+" ) ");
		}
		if(inKakko->IndexOf(ShareData::hintImage+"=")>=0 || inKakko->IndexOf(ShareData::image+"=")>=0){
			//{Answer=sample;Image=sample.jpg;}
			array<String^>^ options = inKakko->Split(';');
			String^ imageName = "";
			String^ retStr = "";
			for(int i=0;i<options->Length;i++){
				array<String^>^ ope = options[i]->Split('=');
				if(ope[0]==ShareData::hintImage)
					imageName += ope[1];
				if(ope[0]==ShareData::image)
					imageName += ";"+ope[1];
			}
			imageIndex->Add(qCount);
			imageFileNames->Add(imageName);
		}
	}
	if (qCount==0)
	{
		this->Cursor=Windows::Forms::Cursors::Default;
		return false;
	}

	qCountField = qCount;

	QNumUpDown->Enabled = true;
	QNumUpDown->Minimum = 1;
	QNumUpDown->Maximum = qCount;
	QNumUpDown->Value = 1;

	temp = temp->Replace("\"{\"","{");
	temp = temp->Replace("\"}\"","}");

	if (!kaitougun)// && kaitouGunList->Count > 1
	{
		kaitouGunList->Clear();
	}else
	{
		array<String^>^ ListArray=kaitouGunList->ToArray();
		kaitouGunList->Clear();
		for (int i = 0; i < ListArray->Length; i++)
		{
			for (int j = i-1; j >= 0; j--)
			{
				if (ListArray[i]==ListArray[j])
				{
					ListArray[i]="";
					break;
				}
			}
			if (ListArray[i]->Length>0)
			{
				kaitouGunList->Add(ListArray[i]);
			}
		}
	}

	anaumeAnsBox->Text = "";
	sentakushiCombo->Items->Clear();
	sentakushiCombo->Items->Add(ShareData::noneString);
	bunsyoudai->Text = "";

	QuestSentence->Text = "";
	if (Windows::Forms::DialogResult::OK!=MessageBox::Show("模擬テストを始めます。","試験開始!!",MessageBoxButtons::OK,MessageBoxIcon::Information))
	{
		this->Cursor=Windows::Forms::Cursors::Default;
		return false;
	}

	userAnswerArea->Text = "";
	panel1->Enabled=true;
	QuestSentence->Text = temp;
	qnumDoing();
	keikaSec = 0;
	setNumberScroll(1);
	keikajikan->Start();
	setTime_Limit();

	for(int i = 0;i<qCount;i++){
		answerStrings->Add(" ");
		userAnswerArea->Text +=answerStrings[i];
		userAnswerArea->Text += "";
		if (i<qCount-1)
		{
			userAnswerArea->Text += "\n";
		}
	}

	seikaiNumber->Clear();
	seikaiNumber->Add(0);

	setCollects();

	this->Cursor=Windows::Forms::Cursors::Default;
	return true;
}

void MogiTest::keikajikan_Tick(System::Object^  sender, System::EventArgs^  e) {
	keikaSec++;
	if (timelimitSecond > 0)
	{
		if (keikaSec >= timelimitSecond)
		{
			setTime_Limit();
			keikajikan->Stop();
			MessageBox::Show("制限時間になりました!!\n採点を始めます。","終了ー!!",MessageBoxButtons::OK,MessageBoxIcon::Information);
			timelimitSecond = 0;
			marking(); 
		}else
		{
			setTime_Limit();
		}
	}else
	{
		time_limit->Text = "制限時間はありません";
	}
}

void MogiTest::setEnableSaiten(bool bl){
	marutsukeButton->Enabled=bl;
	revenge->Enabled=!bl;
}

void MogiTest::MogiTest_Load(System::Object^  sender, System::EventArgs^  e) {

	this->Icon = gcnew System::Drawing::Icon(MyTools::getApplicationDirectory()+"\\"+"icon\\Copy.ico");

	this->QuestSentence->BackColor = System::Drawing::Color::Ivory;
	this->anaumeAnsBox->BackColor=System::Drawing::Color::Ivory;
	this->bunsyoudai->BackColor=System::Drawing::Color::Ivory;
	userAnswerArea->BackColor = Color::White;

	QuestSentence->ViewWidth = QuestSentence->ClientSize.Width;
	//bunsyoudai->ViewWidth = bunsyoudai->ClientSize.Width;
	userAnswerArea->ViewWidth=userAnswerArea->ClientSize.Width-5;

	marubatsu = 
		gcnew Sgry::Azuki::Highlighter::KeywordHighlighter();
	maru = gcnew array<String^>(1);
	maru[0] = "○";
	batsu = gcnew array<String^>(1);
	batsu[0] = "×";
	marubatsu->AddKeywordSet(maru,Sgry::Azuki::CharClass::Function);
	marubatsu->AddKeywordSet(batsu,Sgry::Azuki::CharClass::Property);
	userAnswerArea->Highlighter = marubatsu;
	userAnswerArea->ColorScheme->SetColor(Sgry::Azuki::CharClass::Function,Color::Red,Color::White);
	userAnswerArea->ColorScheme->SetColor(Sgry::Azuki::CharClass::Property,Color::MediumBlue,Color::White);
	userAnswerArea->ColorScheme->SetColor(Sgry::Azuki::CharClass::DocComment,Color::LimeGreen,Color::White);
	userAnswerArea->ColorScheme->LineNumberFore = Color::LimeGreen;
	userAnswerArea->ColorScheme->LineNumberBack = Color::MintCream;
	userAnswerArea->ColorScheme->SelectionBack = Color::Lime;
	userAnswerArea->ColorScheme->SelectionFore = Color::Maroon;

	userAnswerArea->View->setMaxLineNum(999);
	//userAnswerArea->View->

	QuestSentence->ShowsHScrollBar=false;
	kakkohigh =  gcnew Sgry::Azuki::Highlighter::KeywordHighlighter();
	//kakkohigh->AddEnclosure("{","}",Sgry::Azuki::CharClass::Function,false);
	QuestSentence->Highlighter = kakkohigh;
	QuestSentence->ColorScheme->SetColor(Sgry::Azuki::CharClass::Function,userAnswerArea->ColorScheme->SelectionFore,userAnswerArea->ColorScheme->SelectionBack);

	userAnswerArea->ViewWidth = userAnswerArea->ClientSize.Width-5;

	//bunsyoudai->ShowsHScrollBar=false;

	answerImageSplitter->SplitterDistance=692;

	keikaSec = 0;
	panel1->Enabled=false;
}

void MogiTest::exportMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	SaveFileDialog^ sfd=gcnew SaveFileDialog();
	sfd->Filter="テキストファイル(*.txt)|*.txt";
	if (sfd->ShowDialog()==System::Windows::Forms::DialogResult::OK)
	{
		String^ text=QuestSentence->Text;
		String^ fn=sfd->FileName;
		String^ answers=fn+"の解答です\n\n";
		String^ name=(gcnew FileInfo(fn))->Name->Split('.')[0];
		MyTools::writeTextFile(text,fn,ShareData::defaultEncode);
		fn=fn->Replace(".txt","(解答).txt");//MyTools::getParent(fn)+name+"(解答編).txt";
		for (int i = 0; i < collects->Length; i++)
		{
			answers+="( "+(i+1)+" ) : "+collects[i]+"\n";
		}
		MyTools::writeTextFile(answers,fn,ShareData::defaultEncode);
	}
}

void MogiTest::anaumeAnsBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	moveQ(sender,e,false);
}

void MogiTest::moveQ(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e,bool shift){
	if(e->KeyCode == Keys::Enter && e->Modifiers == Keys::Control)
	{
		e->Handled = true;
		sentakushiCombo->DroppedDown=false;
		if(QNumUpDown->Value > 1){
			QNumUpDown->Value = Decimal::ToInt32(QNumUpDown->Value)-1;
			//QNumUpDown_ValueChanged(sender,gcnew EventArgs());
		}
	}else if(e->KeyCode == Keys::Enter)//(!shift ||  e->Modifiers == Keys::Shift) && 
	{
		e->Handled = true;
		sentakushiCombo->DroppedDown=false;
		if(QNumUpDown->Value < QNumUpDown->Maximum){
			QNumUpDown->Value = Decimal::ToInt32(QNumUpDown->Value)+1;
			//QNumUpDown_ValueChanged(sender,gcnew EventArgs());
		}
	}else if (e->KeyCode == Keys::F1)
	{
		marking();
	}
	if ((!shift ||  e->Modifiers == Keys::Shift) && e->KeyCode == Keys::Enter)
	{
		e->Handled = true;
		int val = Decimal::ToInt32(QNumUpDown->Value);
		setNumberScroll(val);
		try{
			int head = userAnswerArea->GetLineHeadIndex(val-1);
			int end = head + userAnswerArea->GetLineLength(val-1);
			userAnswerArea->SetSelection(head,end);
			//userAnswerArea->Document->SetCaretIndex(val-1,userAnswerArea->GetLineLength(val-1));
		}catch(Exception^){
			return;
		}
		userAnswerArea->ScrollToCaret();
	}
}

void MogiTest::setNumberScroll(int val){
	int ind = QuestSentence->Text->IndexOf(" ( "+val);
	if (ind<0)
	{
		return;
	}
	int av = ind-QuestSentence->Document->GetLineHeadIndexFromCharIndex(ind);
	int ln = QuestSentence->Document->GetLineIndexFromCharIndex(ind);
	QuestSentence->Document->SetCaretIndex(ln,av);
	QuestSentence->ScrollToCaret();
}

void MogiTest::setTime_Limit(){
	int nokori = timelimitSecond-keikaSec;
	if (timelimitSecond==0)
	{
		time_limit->Text = "制限時間はありません";
	}
	else if (nokori>=60)
	{
		time_limit->Text = "残り"+(nokori/60)+"分"+(nokori%60)+"秒"; 
	}else
	{
		time_limit->Text = "残り"+(nokori)+"秒"; 
	}
}

void MogiTest::kaitouranClean(){

	splitContainer1->SplitterDistance=451;
	userAnswerArea->Font = (gcnew System::Drawing::Font(userAnswerArea->Font->FontFamily, userAnswerArea->Font->Size, FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
		static_cast<System::Byte>(128)));
	userAnswerArea->Text = userAnswerArea->Text->Replace("○ ","");
	for(int j=0;j<qCountField;j++){
		//仕様変更に伴いアカンことになっている
		userAnswerArea->Text = userAnswerArea->Text->Replace("× " + collects[j]+"  ","");
	}
	marubatsu->ClearKeywords();
	//keikaSec = 0;
	//keikajikan->Start();//?
}

void MogiTest::openMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenFileDialog^ ofd = gcnew OpenFileDialog();
	ofd->Filter = "Mogiファイル(*.mogi)|*.mogi";
	if(ofd->ShowDialog() != System::Windows::Forms::DialogResult::OK){
		return;
	}
	this->compile(ofd->FileName,true);
}

void MogiTest::MogiTest_Shown(System::Object^  sender, System::EventArgs^  e) {
	if (plainText->Length>0 && !sentakushiCombo->Focused && !anaumeAnsBox->Focused && !bunsyouBox->Focused)
	{
		String^ seleCombo = escapeSet(questStrings[0]);
		array<String^>^ splStrs = seleCombo->Split(',');
		//書式："1,(answer)"
		//書式："4,(ansNum),aaa:bbb:ccc:ddd"
		if(int::Parse(splStrs[0])>1){
			anaumeGroup->Enabled = false;
			sentakuGroup->Enabled = true;
			bunsyouBox->Enabled = false;
			sentakushiCombo->Focus();
		}else{
			sentakushiCombo->Items->Clear();

			if (isBunsyou(splStrs[1]))
			{
				sentakuGroup->Enabled = false;
				anaumeGroup->Enabled = false;
				bunsyouBox->Enabled = true;
				bunsyoudai->Focus();
			}
			else
			{
				sentakuGroup->Enabled = false;
				anaumeGroup->Enabled = true;
				bunsyouBox->Enabled = false;
				anaumeAnsBox->Focus();
			}
		} 
	}
	if (filename!=nullptr && !doneReading)
	{
		/* FileInfo^ fi = gcnew FileInfo(filename);
		MessageBox::Show(fi->Name+"を開きます。","",MessageBoxButtons::OK,MessageBoxIcon::Information);*/
		Focus();
		compile(filename,true);
	}
}

void MogiTest::revenge_Click(System::Object^  sender, System::EventArgs^  e) {
	marubatsu->ClearKeywords();
	if (onlyMissCB->Checked)
	{
		compile(randomAftTxt); 
	}
	else
	{
		seikaiNumber->Clear();
		seikaiNumber->Add(0);
		compile(plainText);
	}
}

void MogiTest::changeAnswer(String^ txt){
	int seleNum = Decimal::ToInt32(QNumUpDown->Value);
	if(seleNum == 0){
		anaumeGroup->Enabled = false;
		sentakuGroup->Enabled = false;
		bunsyouBox->Enabled=false;
	}else{
		if(sentakuGroup->Enabled)
			return;
		//if (bunsyoudai->Tag=="#")
		//{
		//	//MessageBox::Show("###"+seleNum);
		//	return;
		//}
		//userAnswerArea->Text = "";
		if (answerStrings->Count >= seleNum)// && txt->Length>0
		{
			//MessageBox::Show(seleNum+":"+txt);
			answerStrings[seleNum-1] = txt;
		}
		//commitAnswer();
		commitAnswer2(seleNum);
		//userAnswerArea->ScrollToCaret();
	}
}

void MogiTest::commitAnswer2(int seleNum){
	if(seleNum<=0)
		return;

	if(seleNum-1 >= answerStrings->Count)
		return;

	if (userAnswerArea->Text->Length<=0)
		return;

	try{
		int begin = userAnswerArea->GetLineHeadIndex(seleNum-1);
		int end = begin + userAnswerArea->GetLineLength(seleNum-1);


		if (answerStrings[seleNum-1]->Length <= 0)
		{
			//answerStrings[seleNum-1] = " ";
		}
		//Debug::WriteLine("\""+answerStrings[seleNum-1]+"\">>>"+seleNum);
		userAnswerArea->Document->Replace(answerStrings[seleNum-1],begin,end);
		int val = Decimal::ToInt32(QNumUpDown->Value);
		int head = userAnswerArea->GetLineHeadIndex(val-1);
		end = head + userAnswerArea->GetLineLength(val-1);
		userAnswerArea->SetSelection(head,end);
		userAnswerArea->ScrollToCaret();
	}catch(ArgumentOutOfRangeException^){
		return;
	}
}

void MogiTest::commitAnswer(){

	//" 【 "+qCount+"  ";

	String^ buff = "";
	for(int i = 0;i<answerStrings->Count;i++){
		buff += answerStrings[i];
		if (i<answerStrings->Count-1)
		{
			buff += "\n";
		}
	}
	userAnswerArea->Text = buff;
}

void MogiTest::revenge_EnabledChanged(System::Object^  sender, System::EventArgs^  e) {
	onlyMissCB->Enabled=revenge->Enabled;
	htmlOUTPUT->Enabled=revenge->Enabled;
	anaumeGroup->Enabled = !revenge->Enabled;
	sentakuGroup->Enabled = !revenge->Enabled;
	bunsyouBox->Enabled = !revenge->Enabled;
	QNumUpDown->Enabled = !revenge->Enabled;
}

System::Void MogiTest::sentakushiCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	//if (keikajikan->Enabled)
	//{
	//	sentakushiCombo->MaxDropDownItems=30;
	//}else{
	//	sentakushiCombo->MaxDropDownItems=10;
	//}
	if (!sentakushiCombo->DroppedDown)// && keikajikan->Enabled
	{
		sentakushiCombo->MaxDropDownItems=7;
		sentakushiCombo->DroppedDown=true;
	}
	else if (sentakushiCombo->MaxDropDownItems==7 && sentakushiCombo->Items->Count>7)
	{
		int index=sentakushiCombo->SelectedIndex;
		sentakushiCombo->DroppedDown=false;
		sentakushiCombo->MaxDropDownItems=30;
		sentakushiCombo->DroppedDown=true;
		sentakushiCombo->SelectedIndex=index;
	}
	int seleNum = Decimal::ToInt32(QNumUpDown->Value);
	if(seleNum == 0){
		anaumeGroup->Enabled = false;
		sentakuGroup->Enabled = false;
		bunsyouBox->Enabled=false;
	}else{
		String^ ansMe = (String^)(sentakushiCombo->SelectedItem);
		if(ansMe == ShareData::noneString)
		{

		}else
			//userAnswerArea->Text = "";
			try{
				answerStrings[seleNum-1] = ansMe;
				commitAnswer2(seleNum);
		}catch(ArgumentOutOfRangeException^){
		}
	}
}

void MogiTest::qnumDoing(){
	int seleNum = Decimal::ToInt32(QNumUpDown->Value);
	if(seleNum == 0){
		anaumeGroup->Enabled = false;
		sentakuGroup->Enabled = false;
		bunsyouBox->Enabled = false;
	}else{
		answerImageSplitter->Panel2Collapsed=true;
		splitContainer1->SplitterDistance = 432;
		questImageSplitter->Panel2Collapsed=true;
		questImageSplitter->Panel1Collapsed=false;

		QuestSentence->ColorScheme->SetColor(Sgry::Azuki::CharClass::Function,
			userAnswerArea->ColorScheme->SelectionFore,userAnswerArea->ColorScheme->SelectionBack);

		String^ seleCombo = escapeSet(questStrings[seleNum-1]);
		array<String^>^ splStrs = seleCombo->Split(',');

		//!!!
		sentakushiCombo->Items->Clear();
		sentakushiCombo->Items->Add(ShareData::noneString);

		//書式："1,(answer)"
		//書式："4,(ansNum),aaa:bbb:ccc:ddd"
		int kind=int::Parse(splStrs[0]);
		if(kind>1){
			//QuestSentence->ColorScheme->SetColor(Sgry::Azuki::CharClass::Function,
			//	userAnswerArea->ColorScheme->SelectionFore,Color::Yellow);

			anaumeGroup->Enabled = false;
			sentakuGroup->Enabled = true;
			bunsyouBox->Enabled = false;

			//anaumeAnsBox->Text = "";//?????
			//bunsyoudai->Text="";

			array<String^>^ items = splStrs[2]->Split(':');
			sentakushiCombo->Sorted=false;//!!!
			for each(String^ item in items){
				item = escapeReSet(item);
				if(item->Length>0)
					sentakushiCombo->Items->Add(item);
			}
			String^ alreadyAns = getLineText(userAnswerArea,seleNum)->Trim();
			if(alreadyAns->Length == 0)
				sentakushiCombo->SelectedIndex = 0;
			else
				sentakushiCombo->SelectedItem = alreadyAns;
			sentakushiCombo->Focus();
		}else{
			sentakushiCombo->Sorted=true;

			if (splStrs->Length>=3 && splStrs[2]=="describe")
			{
				sentakuGroup->Enabled = false;
				anaumeGroup->Enabled = false;
				bunsyouBox->Enabled = true;
				if (seleNum<=answerStrings->Count)
				{
					bunsyoudai->Tag="#";
					bunsyoudai->Text = answerStrings[seleNum-1]->Trim(); 
					bunsyoudai->Tag="";
				}
				//anaumeAnsBox->Text = "";
				bunsyoudai->SelectAll();
				bunsyoudai->Focus();
			}
			else
			{
				if (kaitouGunList->Count > 1)
				{
					sentakuGroup->Enabled = true;
					anaumeGroup->Enabled = false;
					bunsyouBox->Enabled = false;
					for each (String^ gun in kaitouGunList)
					{
						String^ item = escapeReSet(gun);
						if(item->Length>0)
							sentakushiCombo->Items->Add(item);
					}
					String^ alreadyAns = "";
					if (seleNum<=answerStrings->Count)
						alreadyAns = answerStrings[seleNum-1]->Trim();
					if(alreadyAns->Length == 0)
						sentakushiCombo->SelectedIndex = 0;
					else
						sentakushiCombo->SelectedItem = alreadyAns;
					sentakushiCombo->Focus();
				}else
				{
					//bunsyoudai->Text="";

					sentakuGroup->Enabled = false;
					anaumeGroup->Enabled = true;
					bunsyouBox->Enabled = false;
					if (seleNum<=answerStrings->Count){
						//MessageBox::Show("\""+answerStrings[seleNum-1]+"\"");
						anaumeAnsBox->Tag="#";
						anaumeAnsBox->Text = answerStrings[seleNum-1]->Trim();
						anaumeAnsBox->Tag="";
					}
					anaumeAnsBox->SelectAll();
					anaumeAnsBox->Focus(); 
				}
			}
		}
		for (int i = 0; i < imageIndex->Count; i++)
		{
			if (imageIndex[i]==seleNum)
			{
				try{
					bool hint=true;
					String^ fn=imageFileNames[i];
					array<String^>^ files=fn->Split(';');
					if (files[0]->Length>0)
					{
						answerImageSplitter->Panel2Collapsed=false;
						ImageQuest->Image=Image::FromFile(MyTools::getParent(filename)+"\\"+files[0]);
						int width=ImageQuest->Image->Width;
						int height=ImageQuest->Image->Height;
						double aspect=height/(width*1.0);
						if (aspect>1)
						{
							height=380;
							width=(int)(height/aspect);
						}else
						{
							width=380;
							height=(int)(width*aspect);
						}
						if (files->Length>1 && files[1]->Length>0)
						{
							questImageSplitter->Panel2Collapsed=false;
							questImageSplitter->SplitterDistance=30;
							//questImageSplitter->Panel1Collapsed=true;
						}
						splitContainer1->SplitterDistance=(splitContainer1->Height)-height;
						answerImageSplitter->SplitterDistance=answerImageSplitter->Width-width;
					}
					if (files->Length>1 && files[1]->Length>0)
					{
						//imageViewer->Image=Image::FromFile(MyTools::getParent(filename)+"\\"+files[1]);
						questImageSplitter->Panel2Collapsed=false;
						questImageSplitter->SplitterDistance=30;
						//questImageSplitter->Panel1Collapsed=true;
						imageViewer->Image=Image::FromFile(MyTools::getParent(filename)+"\\"+files[1]);
					}else
					{
						QuestSentence->ColorScheme->SetColor(Sgry::Azuki::CharClass::Function,
							userAnswerArea->ColorScheme->SelectionFore,Color::LightSkyBlue);
					}
				}catch(Exception^){
					MessageBox::Show("指定の画像ファイルは見つかりませんでした。","警告",MessageBoxButtons::OK,MessageBoxIcon::Information);
				}
			}
		}
		kakkohigh->ClearEnclosures();
		array<String^>^ currentQuestion = {"( "+seleNum};
		kakkohigh->AddEnclosure("( "+seleNum+" ",")",Sgry::Azuki::CharClass::Function,false);
		int index = QuestSentence->Text->IndexOf(currentQuestion[0]);
		int len = currentQuestion[0]->Length;
		QuestSentence->Document->Replace(currentQuestion[0],index,index+len);
		QuestSentence->Highlighter->Highlight(QuestSentence->Document);
	}
}

void MogiTest::setCollects(){
	int qCount = questStrings->Count;
	collects = gcnew array<String^>(qCount);
	for(int i=0;i<qCount;i++){
		String ^ans="";
		array<String^>^ kugirin = escapeSet(questStrings[i])->Split(',');
		if(int::Parse(kugirin[0])>1){//選択問題
			array<String^>^ items = escapeReSet(kugirin[2])->Split(':');
			ans = items[int::Parse(escapeReSet(kugirin[1]))-1];
		}else if(int::Parse(kugirin[0])>0){
			if (kugirin->Length>2 && kugirin[2]->Equals("describe"))
			{
				ans = escapeReSet(kugirin[1])+"\fdescribe";
			}else
			{
				ans = escapeReSet(kugirin[1]);
			}
		}else{//別解問題
			ans = escapeReSet(kugirin[1]);
			array<String^>^ others = escapeReSet(kugirin[2])->Split(':');
			for (int i = 0; i < others->Length; i++)
			{
				ans += "\t" + others[i];
			}
		}
		collects[i] = ans;
	}
}

void MogiTest::marking(){
	setEnableSaiten(false);
	this->userAnswerArea->ViewType = Sgry::Azuki::ViewType::Proportional;

	keikajikan->Stop();
	time_limit->Text = "採点中です";
	score = 0;
	int qCount = questStrings->Count;

	//setCollects()

	qCountField = qCount;

	countUp = 0;
	userAnswerArea->Font = (gcnew System::Drawing::Font(userAnswerArea->Font->FontFamily, userAnswerArea->Font->Size, FontStyle::Bold, System::Drawing::GraphicsUnit::Point,static_cast<System::Byte>(128)));
	marubatsu->AddKeywordSet(maru,Sgry::Azuki::CharClass::Function);
	marubatsu->AddKeywordSet(batsu,Sgry::Azuki::CharClass::Property);
	for(int i=0;i<collects->Length;i++){
		if (collects[i]->EndsWith("\fdescribe"))
		{
			array<String^>^ colKwd2 = gcnew array<String^>(1);
			colKwd2[0] = collects[i]->Split('\f')[0]+"";
			marubatsu->AddKeywordSet(colKwd2,Sgry::Azuki::CharClass::DocComment);
			array<String^>^ colKwd = gcnew array<String^>(1);
			colKwd[0] = collects[i]->Split('\f')[0]+" ";
			marubatsu->AddKeywordSet(colKwd,Sgry::Azuki::CharClass::Function);
		}else
			if (collects[i]->IndexOf("\t") < 0)
			{
				array<String^>^ colKwd = gcnew array<String^>(1);
				//ここで空白末尾に加えている意味って何？
				colKwd[0] = collects[i]+" ";
				marubatsu->AddKeywordSet(colKwd,Sgry::Azuki::CharClass::Function); 
			}
	}
	timer1->Start();
	panel1->Enabled=false;

	splitContainer1->SplitterDistance=250;

	seikaiNumber->Clear();
	return;
}

void MogiTest::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	if(countUp >= qCountField){
		timer1->Stop();
		panel1->Enabled=true;
		time_limit->Text = "採点が終了しました。";

		QMarking^ qm = gcnew QMarking();
		qm->Owner = this;
		qm->Show();
		qm->markingX();
		return;
	}
	int i = countUp;

	userAnswerArea->Document->SetCaretIndex( i , 0 );
	userAnswerArea->ScrollToCaret();

	String^ all = userAnswerArea->Text;
	int head = userAnswerArea->GetLineHeadIndex(i);
	int len = userAnswerArea->GetLineLength(i);
	String^ line = userAnswerArea->Text->Substring(head,len);
	bool IsSeikai = (collects[i] == answerStrings[i]);//もし別解問題なら、間違いなくFalseになる
	if (collects[i]->IndexOf("\t") >= 0)
	{
		array<String^>^ answers = collects[i]->Split('\t');
		for (int j = 0; j < answers->Length; j++)
		{
			if (answers[j] == answerStrings[i])
			{
				IsSeikai = true;
				collects[i] = answers[j];
				break;
			}
		}
		if (!IsSeikai)
		{
			collects[i] = answers[0];
		}
		array<String^>^ colKwd = gcnew array<String^>(1);
		colKwd[0] = collects[i]+" ";
		marubatsu->AddKeywordSet(colKwd,Sgry::Azuki::CharClass::Function);
	}
	String^ mohan = collects[i];
	if (collects[i]->EndsWith("\fdescribe"))
	{
		mohan=collects[i]->Split('\f')[0];
	}
	if(line->Trim()->Length <= 0)
	{
		userAnswerArea->Document->Replace("× " + mohan+" ",head,head+len);
	}
	else 	if (collects[i]->EndsWith("\fdescribe"))
	{
		//mohan=collects[i]->Split('\f')[0];
		if (line->Equals(mohan))
		{
			IsSeikai=true;
		}else
		{
			String^ msg = "あなたの答えは\n「"+line+"」\nです。模範解答は\n「"+mohan+"」\nです。正解にしますか？";
			timer1->Stop();
			IsSeikai = MessageBox::Show(msg,"記述問題の採点",MessageBoxButtons::YesNo,MessageBoxIcon::Question)==Windows::Forms::DialogResult::Yes;
			timer1->Start();
		}
		if (IsSeikai)
		{
			userAnswerArea->Document->Replace("○ "+line,head,head+len);
			score++;
			seikaiNumber->Add(i+1);
		}else
		{
			userAnswerArea->Document->Replace("× " + mohan + "  "+line,head,head+len);
		}
	}
	else if(IsSeikai)
	{
		if (collects[i]->EndsWith("\fdescribe"))
		{
			line+=" ( 模範解答： "+mohan+") ";
		}
		userAnswerArea->Document->Replace("○ "+line,head,head+len);
		score++;
		seikaiNumber->Add(i+1);
	}
	else
	{
		userAnswerArea->Document->Replace("× " + mohan + "  "+line,head,head+len);
	}
	userAnswerArea->Highlighter->Highlight(userAnswerArea->Document);
	countUp++;
}

void MogiTest::htmlOUTPUT_Click(System::Object^  sender, System::EventArgs^  e) {
	SaveFileDialog^ sfd=gcnew SaveFileDialog();
	//sdg->Filter = "Mogiファイル(*.mogi)|*.mogi"; 
	sfd->Filter="htmlファイル(*.html)|*.html";
	if(sfd->ShowDialog() != System::Windows::Forms::DialogResult::OK){
		return;
	}
	array<String^>^ answers = userAnswerArea->Text->Split('\n');
	array<String^>^ writeStrs=gcnew array<String^>(answers->Length);
	for (int i = 0; i < answers->Length; i++)
	{
		if (answers[i]->StartsWith("○"))
		{
			//<font color=red >○ 均一</font>  ->  +=" ( 模範解答： "+mohan+" ) "
			String^ mohan=collects[i]->Split('\n')[0];
			if (collects[i]->EndsWith("\fdescribe") && answerStrings[i]!=mohan)
			{
				writeStrs[i]=" <em class=\"maru\">○</em> <em class=\"describe\">"+answerStrings[i]+" </em>( 模範解答： <em class=\"match\">"+mohan+"</em>) ";
			}else{
				collects[i]=collects[i]->Split('\f')[0];
				writeStrs[i]=" <em class=\"maru\">○</em> <em class=\"match\">"+collects[i]+"</em></B>";
			}
		}
		if (answers[i]->StartsWith("×"))
		{
			//× 実利 福利  ->  青 青 赤
			//× 基づく  -> 青 赤
			//<font color=blue>× ファーストフィット</font>  <font color=red>ワーストフィット</font>
			//<font color=blue>×</font>  <font color=red>論理</font>
			if (answerStrings[i]->Length > 0 && answerStrings[i] != " ")
			{
				if (collects[i]->EndsWith("\fdescribe"))
				{
					String^ mohan=collects[i]->Split('\f')[0];
					writeStrs[i]=" <em class=\"batsu\">×</em><em class=\"mistake\">"+answerStrings[i]+"</em> "+" ( 模範解答： <em class=\"match\">"+mohan+"</em>)";
				}else
					writeStrs[i]=" <em class=\"batsu\">×</em><em class=\"mistake\">"+answerStrings[i]+"</em> "+"  <em class=\"match\">"+collects[i]+"</em>";
			}
			else if (answerStrings[i]->Length == 0 || answerStrings[i]==" ")
			{
				if (collects[i]->EndsWith("\fdescribe"))
				{
					String^ mohan=collects[i]->Split('\f')[0];
					//<em class=\"batsu\">×</em>
					writeStrs[i]=" <em class=\"batsu\">×</em> "+"模範解答： <em class=\"describe\">"+mohan+"</em>";
				}else
					writeStrs[i]=" <em class=\"batsu\">×</em> "+" <em class=\"match\">"+collects[i]+"</em>";
			}
		}
	}
	//String^ cssPath=ShareData::getApplicationDirectory()+"\\css\\sample.css";
	//\n<link rel=\"stylesheet\" href=\""+cssPath+"\" type=\"text/css\" >\n
	String^ head="<HTML><HEAD><TITLE>模擬テスト挑戦結果</TITLE>\n";
	String^ css=MyTools::getTextFile(MyTools::getApplicationDirectory()+"\\css\\style.txt")+"\n";
	String^ title="</HEAD>\n<BODY>\n";
	if (filename!=nullptr)
	{
		FileInfo^ fi=gcnew FileInfo(filename);
		//title+="<center><big><big><b><font color=forestgreen >"+fi->Name+"の採点結果</font></b></big>       "+today+"</big></center><br>";
		title+="<p>"+fi->Name+"の採点結果</p>\n";
	}
	//<center><big><big><b>OS 前期末模擬テスト</b></big></big></center><br>
	String^ end="</BODY></HTML>\n";
	String^ honbun=QuestSentence->Text;

	//replace \n to <br>\n
	honbun=honbun->Replace("\n","<br>\n");

	for (int i = 0; i < answers->Length; i++)
	{
		honbun=replaceFirst(honbun," ) ","   "+writeStrs[i]+") ");
	}
	StreamWriter^ writer = gcnew StreamWriter(sfd->FileName,false,System::Text::Encoding::GetEncoding(ShareData::defaultEncode));
	writer->Write(head+css+title+honbun+"\n");

	DateTime^ dt = DateTime::Now;
	String^ today = "<br>受験日：<em class=\"sty1\">"+dt->Year+"年"+dt->Month+"月"+dt->Day+"日</em>";
	int sc = score;
	int qn = qCountField;
	double per = (double)sc/(double)(qn)*100;
	if(qn == 0)
		per = 0;
	String^ perStr = int(per).ToString("d");
	String^ qnStr = qn.ToString()->PadLeft(3);
	String^ scStr = sc.ToString()->PadLeft(3);
	perStr = perStr->PadLeft(3);
	String^ timeStr = "<br><em class=\"norm\">消費時間：</em><em class=\"sty2\">"+keikaSec/60+
		"</em><em class=\"norm\">分</em><em class=\"sty2\">"+keikaSec%60+"<em><em class=\"norm\">秒</em>";

	String^ scoreStr="<br><br><br><em class=\"sty1\">"
		+qnStr+"</em><em class=\"norm\">問中</em><em class=\"sty2\">"+scStr+"</em><em class=\"norm\">問正解<br>"
		+"正解率：</em><em class=\"sty2\">"+perStr+"%</em><br>";

	writer->Write(scoreStr+"\n"+timeStr+"\n"+today+"\n");

	writer->Write(end);
	writer->Close();

	if(MessageBox::Show("HTML出力が完了しました。\nファイル内容を確認しますか？","出力完了",MessageBoxButtons::YesNo,MessageBoxIcon::Information)==System::Windows::Forms::DialogResult::Yes){
		openHTML->StartInfo->FileName=sfd->FileName;
		openHTML->Start();
	}				 
}