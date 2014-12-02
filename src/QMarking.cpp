#include "StdAfx.h"
#include "QMarking.h"

#include "MogiTest.h"

using namespace Mogitter;
using namespace Microsoft::Win32;

void QMarking::button1_Click(System::Object^  sender, System::EventArgs^  e) {
	byButtonClose = true;
	if (this->Owner != nullptr){
		//MogiTest^ test = static_cast<MogiTest^>(this->Owner);
	}
		this->Close();
}

void QMarking::button2_Click(System::Object^  sender, System::EventArgs^  e) {
	byButtonClose = true;
	Visible=false;
	if (this->Owner != nullptr){
		MogiTest^ test = static_cast<MogiTest^>(this->Owner);
		test->seikaiNumber->Clear();
		test->seikaiNumber->Add(0);
		test->compile(test->plainText);
	}
		this->Close();
}

void QMarking::revenge_Click(System::Object^  sender, System::EventArgs^  e){
	byButtonClose = true;
	Visible=false;
	if (this->Owner != nullptr){
		MogiTest^ test = static_cast<MogiTest^>(this->Owner);
		test->compile(test->randomAftTxt); 
	}
		this->Close();
}

int QMarking::markingX(){	
	if (this->Owner != nullptr){
		//親のフォームクラス
		MogiTest^ test = static_cast<MogiTest^>(this->Owner);
		int sc = test->score;
		int qn = test->qCountField;
		double per = (double)sc/(double)(qn)*100;
		if(qn == 0)
			per = 0;
		String^ perStr = int(per).ToString("d");
		questNum->Text = qn.ToString()->PadLeft(3);
		collectNum->Text = sc.ToString()->PadLeft(3);
		persentNum->Text = perStr->PadLeft(3);
		timeLabel->Text = "消費時間："+test->keikaSec/60+"分"+test->keikaSec%60+"秒";
		if (per==100)
		{
			revenge->Enabled = false;
		}else
		{
			revenge->Enabled = true;
		}
	}
	
	return 0;
}

String^ QMarking::readFileName(){
	RegistryKey^ rk = Registry::CurrentUser->OpenSubKey(regPath,true);
	if (rk==nullptr)
	{
		return "";
	}
	String^ ret = static_cast<String^>(rk->GetValue("filename",""));
	if (ret->Length > 0)
	{
		FileInfo^ fi = gcnew FileInfo(ret);
		if (fi->Exists)
		{
			return ret;
		}
	}
	return "";
}

void QMarking::writeToReg(String^ filename){
	RegistryKey^ rk = Registry::CurrentUser->OpenSubKey(regPath,true);
	if (rk==nullptr)
	{
		rk = Registry::CurrentUser->CreateSubKey(regPath);
	}

	rk->SetValue("filename",filename);

	rk->Close();
}