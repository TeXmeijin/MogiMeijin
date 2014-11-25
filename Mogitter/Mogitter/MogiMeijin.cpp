// Mogitter.cpp : メイン プロジェクト ファイルです。

#include "stdafx.h"
#include "MogiTest.h"
#include "Terminal.h"

using namespace Mogitter;
using namespace System::IO;

void printSprash(Form^ mt,Sprash^ spr){
		spr->Show();
		spr->Refresh();
		for(int i=0;i<40;i++){
			Application::DoEvents();
			System::Threading::Thread::Sleep(30);
		}
		System::Threading::ThreadStart^ ts = gcnew System::Threading::ThreadStart(spr,&Sprash::printSprash);
		System::Threading::Thread^ th = gcnew System::Threading::Thread(ts);
		th->Start();
		Application::Run(mt);
		if (th->ThreadState != System::Threading::ThreadState::Unstarted)
		{
			th->Abort();
		}
}
[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// コントロールが作成される前に、Windows XP ビジュアル効果を有効にします
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// メイン ウィンドウを作成して、実行します
	if(args->Length > 0 && args[0]->EndsWith(".mogi")){
		MogiTest^ mt = gcnew MogiTest();
		mt->doneReading=false;
		mt->filename=args[0];
		Sprash^ spr=gcnew Sprash();
		printSprash(mt,spr);
	}else{
		Sprash^ spr=gcnew Sprash();
		Terminal^ form = gcnew Terminal();
		printSprash(form,spr);
	}
	return 0;
}
