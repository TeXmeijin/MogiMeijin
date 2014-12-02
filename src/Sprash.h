#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Mogitter {

	/// <summary>
	/// Sprash の概要
	///
	/// 警告: このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
	///          正しく相互に利用できなくなります。
	/// </summary>
	public ref class Sprash : public System::Windows::Forms::Form
	{
	public:
		Sprash(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクタ コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~Sprash()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// 必要なデザイナ変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナ サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディタで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Sprash::typeid));
			this->SuspendLayout();
			// 
			// Sprash
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(530, 398);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Sprash";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Sprash";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &Sprash::Sprash_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	public:void printSprash(){
			//Sprash^ spr=gcnew Sprash();
			//spr->Show();
			//spr->Refresh();

			for(int i=0;i<40;i++){
			Application::DoEvents();
			System::Threading::Thread::Sleep(20);
			}
			if (this->InvokeRequired)
			{
				EventHandler^ eh = gcnew System::EventHandler(this, &Sprash::closingNow);
				Invoke(eh);
			}else
				this->Close();
	}
	private: void Sprash_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
			 void closingNow(System::Object^  sender, System::EventArgs^  e){
				 this->Close();
			 }
	};
}
