#include "StdAfx.h"
#include "QBuild.h"

using namespace Mogitter;

void QBuild::sentakushi_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	array<wchar_t>^ sep = {'\n'};
	array<System::String ^> ^kinds=sentakushi->Text->Split(sep);
	int len = 1;
	for(int i=0;i<kinds->Length;i++){
		kinds[i] = kinds[i]->Replace("\n","");
		kinds[i] = kinds[i]->Replace("\r","");
		if(kinds[i]->Length==0)
			continue;
		len++;
	}
	if (sentakuRB->Checked)
	{
		seikaiNumber->Maximum = len;
		Random^ rand = gcnew Random();
		seikaiNumber->Value = rand->Next(len)+1; 
	}
}

void QBuild::sentakuRB_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (sentakuRB->Checked)
	{
		sentakushiLabel->Text = "正解以外の選択肢(各行に１つ)";
		seikaiNumber->Enabled = true;
		abc->Enabled = true;
		ABC_->Enabled = true;
		kana_abc->Enabled = true;
		katakana_abc->Enabled = true;
	}
}

void QBuild::cc(){
	if (betsukaiRB->Checked)
	{
		sentakushiLabel->Text = "別解のリスト(各行に1つ)";
		seikaiNumber->Enabled = false;
		abc->Enabled = false;
		ABC_->Enabled = false;
		kana_abc->Enabled = false;
		katakana_abc->Enabled = false;
	}
}

void QBuild::setActive(bool b){
	//				 sentakuRB->Checked=b;
	betsukaiRB->Checked=true;
	sentakuRB->Enabled=b;
}

void QBuild::answerBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	int width=MogiTest::getString_width(answerBox->Text);
	bool b=width>MogiTest::describeWidth;
	if (sentakuRB->Enabled)
	{
		if (b)
		{
			setActive(!b);
		}
	}else
	{
		if (!b)
		{
			setActive(!b);
		}
	}
}