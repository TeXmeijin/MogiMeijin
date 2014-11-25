#pragma once
#include "MogiTest.h"
#include "ShareData.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Diagnostics;


namespace Mogitter {

	/// <summary>
	/// QBuild の概要
	///
	/// 警告: このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
	///          正しく相互に利用できなくなります。
	/// </summary>
	public ref class QBuild : public System::Windows::Forms::Form
	{
	public:
		QBuild(void)
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
		~QBuild()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Button^  cancel;
	public: System::Windows::Forms::Button^  okButton;
	public: System::Windows::Forms::TextBox^  answerBox;

	public: System::Windows::Forms::Label^  label1;





	public: System::Windows::Forms::GroupBox^  sentakuGroup;












	public: System::Windows::Forms::Label^  label2;


	public: System::Windows::Forms::Label^  label4;
	public: System::Windows::Forms::Label^  label3;
	public: System::Windows::Forms::NumericUpDown^  seikaiNumber;


	public: Sgry::Azuki::WinForms::AzukiControl^  sentakushi;
	public: System::Windows::Forms::Label^  sentakushiLabel;

	private: System::Windows::Forms::Panel^  panel1;
	public: System::Windows::Forms::RadioButton^  betsukaiRB;
	private: 
	public: System::Windows::Forms::RadioButton^  sentakuRB;


	private: Microsoft::VisualBasic::PowerPacks::ShapeContainer^  shapeContainer1;
	private: Microsoft::VisualBasic::PowerPacks::LineShape^  lineShape1;
	private: System::Windows::Forms::Panel^  panel2;
	public: System::Windows::Forms::RadioButton^  katakana_abc;
	private: 
	public: System::Windows::Forms::RadioButton^  kana_abc;
	public: System::Windows::Forms::RadioButton^  ABC_;
	public: System::Windows::Forms::RadioButton^  abc;
	public: 









	protected: 


	protected: 

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
			Sgry::Azuki::FontInfo^  fontInfo1 = (gcnew Sgry::Azuki::FontInfo());
			this->cancel = (gcnew System::Windows::Forms::Button());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->answerBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->sentakuGroup = (gcnew System::Windows::Forms::GroupBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->katakana_abc = (gcnew System::Windows::Forms::RadioButton());
			this->kana_abc = (gcnew System::Windows::Forms::RadioButton());
			this->ABC_ = (gcnew System::Windows::Forms::RadioButton());
			this->abc = (gcnew System::Windows::Forms::RadioButton());
			this->betsukaiRB = (gcnew System::Windows::Forms::RadioButton());
			this->sentakuRB = (gcnew System::Windows::Forms::RadioButton());
			this->sentakushi = (gcnew Sgry::Azuki::WinForms::AzukiControl());
			this->seikaiNumber = (gcnew System::Windows::Forms::NumericUpDown());
			this->sentakushiLabel = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->shapeContainer1 = (gcnew Microsoft::VisualBasic::PowerPacks::ShapeContainer());
			this->lineShape1 = (gcnew Microsoft::VisualBasic::PowerPacks::LineShape());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->sentakuGroup->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->seikaiNumber))->BeginInit();
			this->SuspendLayout();
			// 
			// cancel
			// 
			this->cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->cancel->Font = (gcnew System::Drawing::Font(L"メイリオ", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->cancel->Location = System::Drawing::Point(235, 318);
			this->cancel->Name = L"cancel";
			this->cancel->Size = System::Drawing::Size(115, 32);
			this->cancel->TabIndex = 2;
			this->cancel->Text = L"キャンセル";
			this->cancel->UseVisualStyleBackColor = true;
			this->cancel->Click += gcnew System::EventHandler(this, &QBuild::cancel_Click);
			// 
			// okButton
			// 
			this->okButton->BackColor = System::Drawing::SystemColors::Control;
			this->okButton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->okButton->Font = (gcnew System::Drawing::Font(L"メイリオ", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->okButton->Location = System::Drawing::Point(123, 318);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(75, 32);
			this->okButton->TabIndex = 1;
			this->okButton->Text = L"OK";
			this->okButton->UseVisualStyleBackColor = true;
			// 
			// answerBox
			// 
			this->answerBox->Font = (gcnew System::Drawing::Font(L"メイリオ", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->answerBox->Location = System::Drawing::Point(73, 9);
			this->answerBox->Name = L"answerBox";
			this->answerBox->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->answerBox->Size = System::Drawing::Size(389, 30);
			this->answerBox->TabIndex = 3;
			this->answerBox->TextChanged += gcnew System::EventHandler(this, &QBuild::answerBox_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"メイリオ", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label1->Location = System::Drawing::Point(14, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 23);
			this->label1->TabIndex = 4;
			this->label1->Text = L"解答：";
			// 
			// sentakuGroup
			// 
			this->sentakuGroup->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->sentakuGroup->Controls->Add(this->panel2);
			this->sentakuGroup->Controls->Add(this->betsukaiRB);
			this->sentakuGroup->Controls->Add(this->sentakuRB);
			this->sentakuGroup->Controls->Add(this->sentakushi);
			this->sentakuGroup->Controls->Add(this->seikaiNumber);
			this->sentakuGroup->Controls->Add(this->sentakushiLabel);
			this->sentakuGroup->Controls->Add(this->label4);
			this->sentakuGroup->Controls->Add(this->label3);
			this->sentakuGroup->Controls->Add(this->label2);
			this->sentakuGroup->Controls->Add(this->shapeContainer1);
			this->sentakuGroup->Font = (gcnew System::Drawing::Font(L"メイリオ", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->sentakuGroup->Location = System::Drawing::Point(12, 49);
			this->sentakuGroup->Name = L"sentakuGroup";
			this->sentakuGroup->Size = System::Drawing::Size(449, 259);
			this->sentakuGroup->TabIndex = 8;
			this->sentakuGroup->TabStop = false;
			this->sentakuGroup->Text = L"記入欄（選択問題か別解がある穴埋め問題を作成するとき）";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->katakana_abc);
			this->panel2->Controls->Add(this->kana_abc);
			this->panel2->Controls->Add(this->ABC_);
			this->panel2->Controls->Add(this->abc);
			this->panel2->Location = System::Drawing::Point(298, 118);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(145, 135);
			this->panel2->TabIndex = 14;
			// 
			// katakana_abc
			// 
			this->katakana_abc->AutoSize = true;
			this->katakana_abc->Font = (gcnew System::Drawing::Font(L"メイリオ", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->katakana_abc->Location = System::Drawing::Point(16, 103);
			this->katakana_abc->Name = L"katakana_abc";
			this->katakana_abc->Size = System::Drawing::Size(112, 27);
			this->katakana_abc->TabIndex = 8;
			this->katakana_abc->Text = L"ア,イ,ウ,･･･";
			this->katakana_abc->UseVisualStyleBackColor = true;
			// 
			// kana_abc
			// 
			this->kana_abc->AutoSize = true;
			this->kana_abc->Font = (gcnew System::Drawing::Font(L"メイリオ", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->kana_abc->Location = System::Drawing::Point(16, 70);
			this->kana_abc->Name = L"kana_abc";
			this->kana_abc->Size = System::Drawing::Size(112, 27);
			this->kana_abc->TabIndex = 7;
			this->kana_abc->Text = L"あ,い,う,･･･";
			this->kana_abc->UseVisualStyleBackColor = true;
			// 
			// ABC_
			// 
			this->ABC_->AutoSize = true;
			this->ABC_->Font = (gcnew System::Drawing::Font(L"メイリオ", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->ABC_->Location = System::Drawing::Point(16, 37);
			this->ABC_->Name = L"ABC_";
			this->ABC_->Size = System::Drawing::Size(97, 27);
			this->ABC_->TabIndex = 6;
			this->ABC_->Text = L"A,B,C,･･･";
			this->ABC_->UseVisualStyleBackColor = true;
			// 
			// abc
			// 
			this->abc->AutoSize = true;
			this->abc->Checked = true;
			this->abc->Font = (gcnew System::Drawing::Font(L"メイリオ", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->abc->Location = System::Drawing::Point(16, 4);
			this->abc->Name = L"abc";
			this->abc->Size = System::Drawing::Size(93, 27);
			this->abc->TabIndex = 5;
			this->abc->TabStop = true;
			this->abc->Text = L"a,b,c,･･･";
			this->abc->UseVisualStyleBackColor = true;
			// 
			// betsukaiRB
			// 
			this->betsukaiRB->AutoSize = true;
			this->betsukaiRB->Font = (gcnew System::Drawing::Font(L"メイリオ", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->betsukaiRB->Location = System::Drawing::Point(231, 24);
			this->betsukaiRB->Name = L"betsukaiRB";
			this->betsukaiRB->Size = System::Drawing::Size(133, 27);
			this->betsukaiRB->TabIndex = 12;
			this->betsukaiRB->Text = L"別解がある問題";
			this->betsukaiRB->UseVisualStyleBackColor = true;
			this->betsukaiRB->CheckedChanged += gcnew System::EventHandler(this, &QBuild::betsukaiRB_CheckedChanged);
			// 
			// sentakuRB
			// 
			this->sentakuRB->AutoSize = true;
			this->sentakuRB->Checked = true;
			this->sentakuRB->Font = (gcnew System::Drawing::Font(L"メイリオ", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->sentakuRB->Location = System::Drawing::Point(107, 24);
			this->sentakuRB->Name = L"sentakuRB";
			this->sentakuRB->Size = System::Drawing::Size(88, 27);
			this->sentakuRB->TabIndex = 11;
			this->sentakuRB->TabStop = true;
			this->sentakuRB->Text = L"選択問題";
			this->sentakuRB->UseVisualStyleBackColor = true;
			this->sentakuRB->CheckedChanged += gcnew System::EventHandler(this, &QBuild::sentakuRB_CheckedChanged);
			// 
			// sentakushi
			// 
			this->sentakushi->BackColor = System::Drawing::Color::White;
			this->sentakushi->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->sentakushi->DrawingOption = static_cast<Sgry::Azuki::DrawingOption>((((Sgry::Azuki::DrawingOption::DrawsFullWidthSpace | Sgry::Azuki::DrawingOption::DrawsTab) 
				| Sgry::Azuki::DrawingOption::ShowsLineNumber) 
				| Sgry::Azuki::DrawingOption::HighlightsMatchedBracket));
			this->sentakushi->DrawsEolCode = false;
			this->sentakushi->FirstVisibleLine = 0;
			this->sentakushi->Font = (gcnew System::Drawing::Font(L"メイリオ", 11));
			fontInfo1->Name = L"メイリオ";
			fontInfo1->Size = 11;
			fontInfo1->Style = System::Drawing::FontStyle::Regular;
			this->sentakushi->FontInfo = fontInfo1;
			this->sentakushi->ForeColor = System::Drawing::Color::Black;
			this->sentakushi->HighlightsCurrentLine = false;
			this->sentakushi->Location = System::Drawing::Point(6, 85);
			this->sentakushi->Name = L"sentakushi";
			this->sentakushi->ScrollPos = System::Drawing::Point(0, 0);
			this->sentakushi->ScrollsBeyondLastLine = false;
			this->sentakushi->ShowsDirtBar = false;
			this->sentakushi->ShowsHScrollBar = false;
			this->sentakushi->Size = System::Drawing::Size(229, 168);
			this->sentakushi->TabIndex = 8;
			this->sentakushi->ViewType = Sgry::Azuki::ViewType::WrappedProportional;
			this->sentakushi->ViewWidth = 207;
			this->sentakushi->TextChanged += gcnew System::EventHandler(this, &QBuild::sentakushi_TextChanged);
			// 
			// seikaiNumber
			// 
			this->seikaiNumber->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->seikaiNumber->Font = (gcnew System::Drawing::Font(L"メイリオ", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->seikaiNumber->ForeColor = System::Drawing::Color::Red;
			this->seikaiNumber->Location = System::Drawing::Point(298, 78);
			this->seikaiNumber->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->seikaiNumber->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->seikaiNumber->Name = L"seikaiNumber";
			this->seikaiNumber->Size = System::Drawing::Size(51, 36);
			this->seikaiNumber->TabIndex = 10;
			this->seikaiNumber->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->seikaiNumber->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// sentakushiLabel
			// 
			this->sentakushiLabel->AutoSize = true;
			this->sentakushiLabel->Font = (gcnew System::Drawing::Font(L"メイリオ", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->sentakushiLabel->Location = System::Drawing::Point(2, 59);
			this->sentakushiLabel->Name = L"sentakushiLabel";
			this->sentakushiLabel->Size = System::Drawing::Size(219, 23);
			this->sentakushiLabel->TabIndex = 9;
			this->sentakushiLabel->Text = L"正解以外の選択肢(各行に１つ)";
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"メイリオ", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label4->Location = System::Drawing::Point(355, 85);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(88, 29);
			this->label4->TabIndex = 6;
			this->label4->Text = L"番目にする";
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"メイリオ", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label3->Location = System::Drawing::Point(241, 85);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(62, 29);
			this->label3->TabIndex = 5;
			this->label3->Text = L"正解を";
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"メイリオ", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label2->Location = System::Drawing::Point(241, 123);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 29);
			this->label2->TabIndex = 0;
			this->label2->Text = L"記号：";
			// 
			// shapeContainer1
			// 
			this->shapeContainer1->Location = System::Drawing::Point(3, 23);
			this->shapeContainer1->Margin = System::Windows::Forms::Padding(0);
			this->shapeContainer1->Name = L"shapeContainer1";
			this->shapeContainer1->Shapes->AddRange(gcnew cli::array< Microsoft::VisualBasic::PowerPacks::Shape^  >(1) {this->lineShape1});
			this->shapeContainer1->Size = System::Drawing::Size(443, 233);
			this->shapeContainer1->TabIndex = 13;
			this->shapeContainer1->TabStop = false;
			// 
			// lineShape1
			// 
			this->lineShape1->BorderColor = System::Drawing::Color::DarkGray;
			this->lineShape1->Name = L"lineShape1";
			this->lineShape1->X1 = 5;
			this->lineShape1->X2 = 439;
			this->lineShape1->Y1 = 29;
			this->lineShape1->Y2 = 29;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::DarkOrange;
			this->panel1->Location = System::Drawing::Point(-2, 314);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(476, 40);
			this->panel1->TabIndex = 9;
			// 
			// QBuild
			// 
			this->AcceptButton = this->okButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->cancel;
			this->ClientSize = System::Drawing::Size(474, 354);
			this->Controls->Add(this->sentakuGroup);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->answerBox);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->cancel);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"QBuild";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"問題作成";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &QBuild::QBuild_Load);
			this->sentakuGroup->ResumeLayout(false);
			this->sentakuGroup->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->seikaiNumber))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	public: void beginSet(String^ sele){
				answerBox->Text = sele;
			}
#pragma endregion
	private: void QBuild_Load(System::Object^  sender, System::EventArgs^  e) {
				 this->sentakushi->BackColor = System::Drawing::Color::White;
				 sentakushi->SetKeyBind(static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C)),gcnew Sgry::Azuki::ActionProc(&Sgry::Azuki::Actions::Copy));
				 sentakushi->SetKeyBind(static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::V)),gcnew Sgry::Azuki::ActionProc(&Sgry::Azuki::Actions::Paste));
				 sentakushi->SetKeyBind(static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Z)),gcnew Sgry::Azuki::ActionProc(&Sgry::Azuki::Actions::Undo));
				 sentakushi->SetKeyBind(static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Y)),gcnew Sgry::Azuki::ActionProc(&Sgry::Azuki::Actions::Redo));
				 sentakushi->ColorScheme->LineNumberBack = Color::SeaShell;// SeaShell;
				 sentakushi->ColorScheme->LineNumberFore = Color::Sienna;
			 }

	private: void cancel_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
			 }

	private: void sentakushi_TextChanged(System::Object^  sender, System::EventArgs^  e);

	private: void sentakuRB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

	private: void betsukaiRB_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 cc();
			 }

	public: void cc();

	private: void answerBox_TextChanged(System::Object^  sender, System::EventArgs^  e);

			 void setActive(bool b);
	};
}
