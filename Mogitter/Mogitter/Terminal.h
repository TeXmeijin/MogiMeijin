#pragma once
#include "MogiTest.h"
#include "Form1.h"

namespace Mogitter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Terminal の概要
	/// </summary>
	public ref class Terminal : public System::Windows::Forms::Form
	{
	public:
		Terminal(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~Terminal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  mogieditor;
	private: System::Windows::Forms::Button^  mogitester;
	protected: 

	protected: 


	private: Microsoft::VisualBasic::PowerPacks::ShapeContainer^  shapeContainer1;
	private: Microsoft::VisualBasic::PowerPacks::RectangleShape^  rectangleShape2;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: Microsoft::VisualBasic::PowerPacks::RectangleShape^  rectangleShape1;

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Terminal::typeid));
			this->mogieditor = (gcnew System::Windows::Forms::Button());
			this->mogitester = (gcnew System::Windows::Forms::Button());
			this->shapeContainer1 = (gcnew Microsoft::VisualBasic::PowerPacks::ShapeContainer());
			this->rectangleShape2 = (gcnew Microsoft::VisualBasic::PowerPacks::RectangleShape());
			this->rectangleShape1 = (gcnew Microsoft::VisualBasic::PowerPacks::RectangleShape());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// mogieditor
			// 
			this->mogieditor->BackColor = System::Drawing::Color::White;
			this->mogieditor->Font = (gcnew System::Drawing::Font(L"メイリオ", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->mogieditor->ForeColor = System::Drawing::Color::MediumBlue;
			this->mogieditor->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mogieditor.Image")));
			this->mogieditor->ImageAlign = System::Drawing::ContentAlignment::BottomLeft;
			this->mogieditor->Location = System::Drawing::Point(12, 60);
			this->mogieditor->Name = L"mogieditor";
			this->mogieditor->Size = System::Drawing::Size(178, 102);
			this->mogieditor->TabIndex = 1;
			this->mogieditor->Text = L"Mogi　　Editor";
			this->mogieditor->TextAlign = System::Drawing::ContentAlignment::BottomRight;
			this->mogieditor->UseCompatibleTextRendering = true;
			this->mogieditor->UseVisualStyleBackColor = false;
			this->mogieditor->Click += gcnew System::EventHandler(this, &Terminal::mogieditor_Click);
			this->mogieditor->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Terminal::Terminal_KeyDown);
			// 
			// mogitester
			// 
			this->mogitester->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->mogitester->Font = (gcnew System::Drawing::Font(L"Gentium Book Basic", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->mogitester->ForeColor = System::Drawing::Color::ForestGreen;
			this->mogitester->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mogitester.Image")));
			this->mogitester->ImageAlign = System::Drawing::ContentAlignment::BottomLeft;
			this->mogitester->Location = System::Drawing::Point(213, 60);
			this->mogitester->Name = L"mogitester";
			this->mogitester->Size = System::Drawing::Size(178, 102);
			this->mogitester->TabIndex = 2;
			this->mogitester->Text = L"Mogi　　   Tester";
			this->mogitester->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			this->mogitester->UseVisualStyleBackColor = false;
			this->mogitester->Click += gcnew System::EventHandler(this, &Terminal::mogitester_Click);
			this->mogitester->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Terminal::Terminal_KeyDown);
			// 
			// shapeContainer1
			// 
			this->shapeContainer1->Location = System::Drawing::Point(0, 0);
			this->shapeContainer1->Margin = System::Windows::Forms::Padding(0);
			this->shapeContainer1->Name = L"shapeContainer1";
			this->shapeContainer1->Shapes->AddRange(gcnew cli::array< Microsoft::VisualBasic::PowerPacks::Shape^  >(2) {this->rectangleShape2, 
				this->rectangleShape1});
			this->shapeContainer1->Size = System::Drawing::Size(404, 174);
			this->shapeContainer1->TabIndex = 3;
			this->shapeContainer1->TabStop = false;
			// 
			// rectangleShape2
			// 
			this->rectangleShape2->BorderColor = System::Drawing::Color::Green;
			this->rectangleShape2->CornerRadius = 7;
			this->rectangleShape2->FillColor = System::Drawing::Color::Tan;
			this->rectangleShape2->FillGradientColor = System::Drawing::Color::Red;
			this->rectangleShape2->FillStyle = Microsoft::VisualBasic::PowerPacks::FillStyle::HorizontalBrick;
			this->rectangleShape2->Location = System::Drawing::Point(207, 9);
			this->rectangleShape2->Name = L"rectangleShape2";
			this->rectangleShape2->Size = System::Drawing::Size(189, 158);
			// 
			// rectangleShape1
			// 
			this->rectangleShape1->BackStyle = Microsoft::VisualBasic::PowerPacks::BackStyle::Opaque;
			this->rectangleShape1->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->rectangleShape1->CornerRadius = 7;
			this->rectangleShape1->FillColor = System::Drawing::Color::Gainsboro;
			this->rectangleShape1->FillStyle = Microsoft::VisualBasic::PowerPacks::FillStyle::WideUpwardDiagonal;
			this->rectangleShape1->Location = System::Drawing::Point(6, 9);
			this->rectangleShape1->Name = L"rectangleShape1";
			this->rectangleShape1->Size = System::Drawing::Size(189, 158);
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label2->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label2->Location = System::Drawing::Point(17, 24);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(168, 26);
			this->label2->TabIndex = 3;
			this->label2->Text = L"模擬テストを作る(E)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label3->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label3->Location = System::Drawing::Point(219, 24);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(164, 26);
			this->label3->TabIndex = 4;
			this->label3->Text = L"模擬テストを解く(T)";
			// 
			// Terminal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Ivory;
			this->ClientSize = System::Drawing::Size(404, 174);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->mogitester);
			this->Controls->Add(this->mogieditor);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->shapeContainer1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Terminal";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MogiMeijin";
			this->Load += gcnew System::EventHandler(this, &Terminal::Terminal_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: void mogieditor_Click(System::Object^  sender, System::EventArgs^  e) {
				 Form1^ form = gcnew Form1();
				 form->Show();
			 }
	private: void mogitester_Click(System::Object^  sender, System::EventArgs^  e) {
				 MogiTest^ mt = gcnew MogiTest();
				 mt->Show();
			 }
	private: void Terminal_Load(System::Object^  sender, System::EventArgs^  e) {
				 FileInfo^ fi=gcnew FileInfo(Application::ExecutablePath);
				 this->Icon = gcnew System::Drawing::Icon(fi->DirectoryName+"\\"+"icon\\Meijin.ico");
			 }

	private: void Terminal_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 if (e->KeyCode==Keys::E)
				 {
					 mogieditor->PerformClick();
				 }else if (e->KeyCode==Keys::T)
				 {
					 mogitester->PerformClick();
				 }
			 }
};
}
