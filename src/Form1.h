#pragma once
#include "QBuild.h"
#include "Sprash.h"
#include "MogiTest.h"
#include "QMarking.h"
#include "ShareData.h"
#include "MyTools.h"
//#include <Windows.h>
//
//#using <mscorlib.dll>

namespace Mogitter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Diagnostics;
	//using namespace Microsoft::Win32;

	/// <summary>
	/// Form1 の概要
	///
	/// 警告: このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
	///          正しく相互に利用できなくなります。
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクタ コードを追加します
			//
			fileName="";
			dropOpen=false;
			ctrlPusing=false;
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

		String^ fileName;
		static array<String^>^ kakkos = {"{","{","}"};

		bool ctrlPusing;


	private: System::Windows::Forms::Button^  openFile;
	private: System::Windows::Forms::Button^  mogiMake;



	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  FileMenu;

	private: System::Windows::Forms::ToolStripMenuItem^  newMakeItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openMenuItem;


	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator;
	private: System::Windows::Forms::ToolStripMenuItem^  over_writeMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  named_saveMenuItem;


	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;





	private: System::Windows::Forms::ToolStripMenuItem^  endMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  EditMenu;


	private: System::Windows::Forms::ToolStripMenuItem^  undoMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  redoMenuItem;


	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;






	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator4;
	private: System::Windows::Forms::ToolStripMenuItem^  all_selectMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ToolMenu;




	private: System::Windows::Forms::ToolStripMenuItem^  HelpMenu;




	private: System::Windows::Forms::ToolStripMenuItem^  helpMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  mogi_makeMenuItem;


	private: System::Windows::Forms::CheckBox^  onlyAnaume;
	private: System::Windows::Forms::CheckBox^  makeKaitougun;
	private: System::Windows::Forms::RadioButton^  sakuseiRB;
	private: System::Windows::Forms::RadioButton^  deleteRB;
	private: System::Windows::Forms::GroupBox^  makeOrDeleteBox;
	private: System::Windows::Forms::GroupBox^  kindSetBox;
	private: System::Windows::Forms::ToolStripMenuItem^  copyMenuItem;
	private: System::Windows::Forms::Button^  saveButton;
	private: Sgry::Azuki::WinForms::AzukiControl^  azukiArea;
	private: System::Windows::Forms::GroupBox^  keishikiBox;

	private: System::Windows::Forms::CheckBox^  randomCheckBox;

	private: System::Windows::Forms::NumericUpDown^  randomQNum;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ToolStripMenuItem^  plusMenuItem;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  whatToDoForUser;
	private: System::Windows::Forms::ToolStripDropDownButton^  mojiCode;
	private: System::Windows::Forms::ToolStripMenuItem^  uTF8ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  shiftjisToolStripMenuItem;
	private: System::Windows::Forms::CheckBox^  timelimit;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::NumericUpDown^  second;
	private: System::Windows::Forms::NumericUpDown^  minute;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::CheckBox^  makeDescription;
	private: System::Diagnostics::Process^  doHelp;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			Sgry::Azuki::FontInfo^  fontInfo1 = (gcnew Sgry::Azuki::FontInfo());
			this->openFile = (gcnew System::Windows::Forms::Button());
			this->mogiMake = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->FileMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newMakeItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->over_writeMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->named_saveMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->plusMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->endMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->EditMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->undoMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->redoMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->copyMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->all_selectMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ToolMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mogi_makeMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->HelpMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->onlyAnaume = (gcnew System::Windows::Forms::CheckBox());
			this->makeKaitougun = (gcnew System::Windows::Forms::CheckBox());
			this->sakuseiRB = (gcnew System::Windows::Forms::RadioButton());
			this->deleteRB = (gcnew System::Windows::Forms::RadioButton());
			this->makeOrDeleteBox = (gcnew System::Windows::Forms::GroupBox());
			this->kindSetBox = (gcnew System::Windows::Forms::GroupBox());
			this->makeDescription = (gcnew System::Windows::Forms::CheckBox());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->azukiArea = (gcnew Sgry::Azuki::WinForms::AzukiControl());
			this->keishikiBox = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->second = (gcnew System::Windows::Forms::NumericUpDown());
			this->minute = (gcnew System::Windows::Forms::NumericUpDown());
			this->timelimit = (gcnew System::Windows::Forms::CheckBox());
			this->randomQNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->randomCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->whatToDoForUser = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->mojiCode = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->uTF8ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->shiftjisToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->doHelp = (gcnew System::Diagnostics::Process());
			this->menuStrip1->SuspendLayout();
			this->makeOrDeleteBox->SuspendLayout();
			this->kindSetBox->SuspendLayout();
			this->keishikiBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->second))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->minute))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->randomQNum))->BeginInit();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFile
			// 
			this->openFile->Font = (gcnew System::Drawing::Font(L"メイリオ", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->openFile->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"openFile.Image")));
			this->openFile->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->openFile->Location = System::Drawing::Point(627, 32);
			this->openFile->Name = L"openFile";
			this->openFile->Size = System::Drawing::Size(91, 45);
			this->openFile->TabIndex = 0;
			this->openFile->Text = L"開く";
			this->openFile->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->openFile->UseVisualStyleBackColor = true;
			this->openFile->Click += gcnew System::EventHandler(this, &Form1::openFile_Click);
			// 
			// mogiMake
			// 
			this->mogiMake->Font = (gcnew System::Drawing::Font(L"メイリオ", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->mogiMake->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mogiMake.Image")));
			this->mogiMake->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->mogiMake->Location = System::Drawing::Point(626, 508);
			this->mogiMake->Name = L"mogiMake";
			this->mogiMake->Size = System::Drawing::Size(193, 45);
			this->mogiMake->TabIndex = 7;
			this->mogiMake->Text = L"模擬テスト試行";
			this->mogiMake->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->mogiMake->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->mogiMake->UseVisualStyleBackColor = true;
			this->mogiMake->Click += gcnew System::EventHandler(this, &Form1::mogiMake_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->FileMenu, this->EditMenu, 
				this->ToolMenu, this->HelpMenu});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->menuStrip1->Size = System::Drawing::Size(827, 26);
			this->menuStrip1->TabIndex = 10;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// FileMenu
			// 
			this->FileMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {this->newMakeItem, 
				this->openMenuItem, this->toolStripSeparator, this->over_writeMenuItem, this->named_saveMenuItem, this->plusMenuItem, this->toolStripSeparator1, 
				this->endMenuItem});
			this->FileMenu->Name = L"FileMenu";
			this->FileMenu->Size = System::Drawing::Size(85, 22);
			this->FileMenu->Text = L"ファイル(&F)";
			// 
			// newMakeItem
			// 
			this->newMakeItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"newMakeItem.Image")));
			this->newMakeItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->newMakeItem->Name = L"newMakeItem";
			this->newMakeItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->newMakeItem->Size = System::Drawing::Size(287, 22);
			this->newMakeItem->Text = L"新規作成(&N)";
			this->newMakeItem->Click += gcnew System::EventHandler(this, &Form1::newMakeItem_Click);
			// 
			// openMenuItem
			// 
			this->openMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"openMenuItem.Image")));
			this->openMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->openMenuItem->Name = L"openMenuItem";
			this->openMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->openMenuItem->Size = System::Drawing::Size(287, 22);
			this->openMenuItem->Text = L"開く(&O)";
			this->openMenuItem->Click += gcnew System::EventHandler(this, &Form1::openMenuItem_Click);
			// 
			// toolStripSeparator
			// 
			this->toolStripSeparator->Name = L"toolStripSeparator";
			this->toolStripSeparator->Size = System::Drawing::Size(284, 6);
			// 
			// over_writeMenuItem
			// 
			this->over_writeMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"over_writeMenuItem.Image")));
			this->over_writeMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->over_writeMenuItem->Name = L"over_writeMenuItem";
			this->over_writeMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->over_writeMenuItem->Size = System::Drawing::Size(287, 22);
			this->over_writeMenuItem->Text = L"上書き保存(&S)";
			this->over_writeMenuItem->Click += gcnew System::EventHandler(this, &Form1::over_writeMenuItem_Click);
			// 
			// named_saveMenuItem
			// 
			this->named_saveMenuItem->Name = L"named_saveMenuItem";
			this->named_saveMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::S));
			this->named_saveMenuItem->Size = System::Drawing::Size(287, 22);
			this->named_saveMenuItem->Text = L"名前を付けて保存(&N)";
			this->named_saveMenuItem->Click += gcnew System::EventHandler(this, &Form1::named_saveMenuItem_Click);
			// 
			// plusMenuItem
			// 
			this->plusMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"plusMenuItem.Image")));
			this->plusMenuItem->Name = L"plusMenuItem";
			this->plusMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt) 
				| System::Windows::Forms::Keys::S));
			this->plusMenuItem->Size = System::Drawing::Size(287, 22);
			this->plusMenuItem->Text = L"既存のファイルに追加(&A)";
			this->plusMenuItem->Click += gcnew System::EventHandler(this, &Form1::plusMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(284, 6);
			// 
			// endMenuItem
			// 
			this->endMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"endMenuItem.Image")));
			this->endMenuItem->Name = L"endMenuItem";
			this->endMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::X));
			this->endMenuItem->Size = System::Drawing::Size(287, 22);
			this->endMenuItem->Text = L"終了(&X)";
			this->endMenuItem->Click += gcnew System::EventHandler(this, &Form1::endMenuItem_Click);
			// 
			// EditMenu
			// 
			this->EditMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->undoMenuItem, 
				this->redoMenuItem, this->toolStripSeparator3, this->copyMenuItem, this->toolStripSeparator4, this->all_selectMenuItem});
			this->EditMenu->Name = L"EditMenu";
			this->EditMenu->Size = System::Drawing::Size(61, 22);
			this->EditMenu->Text = L"編集(&E)";
			// 
			// undoMenuItem
			// 
			this->undoMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"undoMenuItem.Image")));
			this->undoMenuItem->Name = L"undoMenuItem";
			this->undoMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Z));
			this->undoMenuItem->Size = System::Drawing::Size(201, 22);
			this->undoMenuItem->Text = L"元に戻す(&U)";
			this->undoMenuItem->Click += gcnew System::EventHandler(this, &Form1::undoMenuItem_Click);
			// 
			// redoMenuItem
			// 
			this->redoMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"redoMenuItem.Image")));
			this->redoMenuItem->Name = L"redoMenuItem";
			this->redoMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Y));
			this->redoMenuItem->Size = System::Drawing::Size(201, 22);
			this->redoMenuItem->Text = L"やり直し(&R)";
			this->redoMenuItem->Click += gcnew System::EventHandler(this, &Form1::redoMenuItem_Click);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(198, 6);
			// 
			// copyMenuItem
			// 
			this->copyMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"copyMenuItem.Image")));
			this->copyMenuItem->Name = L"copyMenuItem";
			this->copyMenuItem->ShortcutKeyDisplayString = L"Ctrl+C";
			this->copyMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			this->copyMenuItem->Size = System::Drawing::Size(201, 22);
			this->copyMenuItem->Text = L"コピー(&C)";
			this->copyMenuItem->Click += gcnew System::EventHandler(this, &Form1::copyMenuItem_Click);
			// 
			// toolStripSeparator4
			// 
			this->toolStripSeparator4->Name = L"toolStripSeparator4";
			this->toolStripSeparator4->Size = System::Drawing::Size(198, 6);
			// 
			// all_selectMenuItem
			// 
			this->all_selectMenuItem->Name = L"all_selectMenuItem";
			this->all_selectMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::A));
			this->all_selectMenuItem->Size = System::Drawing::Size(201, 22);
			this->all_selectMenuItem->Text = L"すべて選択(&A)";
			this->all_selectMenuItem->Click += gcnew System::EventHandler(this, &Form1::all_selectMenuItem_Click);
			// 
			// ToolMenu
			// 
			this->ToolMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->mogi_makeMenuItem});
			this->ToolMenu->Name = L"ToolMenu";
			this->ToolMenu->Size = System::Drawing::Size(74, 22);
			this->ToolMenu->Text = L"ツール(&T)";
			// 
			// mogi_makeMenuItem
			// 
			this->mogi_makeMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mogi_makeMenuItem.Image")));
			this->mogi_makeMenuItem->Name = L"mogi_makeMenuItem";
			this->mogi_makeMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::G));
			this->mogi_makeMenuItem->Size = System::Drawing::Size(227, 22);
			this->mogi_makeMenuItem->Text = L"模擬テスト生成(&G)";
			this->mogi_makeMenuItem->Click += gcnew System::EventHandler(this, &Form1::mogiMake_Click);
			// 
			// HelpMenu
			// 
			this->HelpMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->helpMenuItem});
			this->HelpMenu->Name = L"HelpMenu";
			this->HelpMenu->Size = System::Drawing::Size(75, 22);
			this->HelpMenu->Text = L"ヘルプ(&H)";
			// 
			// helpMenuItem
			// 
			this->helpMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"helpMenuItem.Image")));
			this->helpMenuItem->Name = L"helpMenuItem";
			this->helpMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F1;
			this->helpMenuItem->Size = System::Drawing::Size(140, 22);
			this->helpMenuItem->Text = L"内容(&C)";
			this->helpMenuItem->Click += gcnew System::EventHandler(this, &Form1::helpMenuItem_Click);
			// 
			// onlyAnaume
			// 
			this->onlyAnaume->AutoSize = true;
			this->onlyAnaume->Font = (gcnew System::Drawing::Font(L"メイリオ", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->onlyAnaume->Location = System::Drawing::Point(12, 26);
			this->onlyAnaume->Name = L"onlyAnaume";
			this->onlyAnaume->Size = System::Drawing::Size(164, 27);
			this->onlyAnaume->TabIndex = 12;
			this->onlyAnaume->Text = L"穴埋め問題のみ作成";
			this->onlyAnaume->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->onlyAnaume->UseVisualStyleBackColor = true;
			// 
			// makeKaitougun
			// 
			this->makeKaitougun->AutoSize = true;
			this->makeKaitougun->Font = (gcnew System::Drawing::Font(L"メイリオ", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->makeKaitougun->Location = System::Drawing::Point(12, 94);
			this->makeKaitougun->Name = L"makeKaitougun";
			this->makeKaitougun->Size = System::Drawing::Size(164, 29);
			this->makeKaitougun->TabIndex = 13;
			this->makeKaitougun->Text = L"解答群問題を作成　";
			this->makeKaitougun->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->makeKaitougun->UseCompatibleTextRendering = true;
			this->makeKaitougun->UseVisualStyleBackColor = true;
			this->makeKaitougun->CheckedChanged += gcnew System::EventHandler(this, &Form1::makeKaitougun_CheckedChanged);
			// 
			// sakuseiRB
			// 
			this->sakuseiRB->AutoSize = true;
			this->sakuseiRB->Checked = true;
			this->sakuseiRB->Font = (gcnew System::Drawing::Font(L"メイリオ", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->sakuseiRB->Location = System::Drawing::Point(12, 26);
			this->sakuseiRB->Name = L"sakuseiRB";
			this->sakuseiRB->Size = System::Drawing::Size(140, 28);
			this->sakuseiRB->TabIndex = 14;
			this->sakuseiRB->TabStop = true;
			this->sakuseiRB->Text = L"問題を作成する";
			this->sakuseiRB->UseVisualStyleBackColor = true;
			// 
			// deleteRB
			// 
			this->deleteRB->AutoSize = true;
			this->deleteRB->Font = (gcnew System::Drawing::Font(L"メイリオ", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->deleteRB->Location = System::Drawing::Point(12, 60);
			this->deleteRB->Name = L"deleteRB";
			this->deleteRB->Size = System::Drawing::Size(140, 28);
			this->deleteRB->TabIndex = 15;
			this->deleteRB->Text = L"問題を削除する";
			this->deleteRB->UseVisualStyleBackColor = true;
			// 
			// makeOrDeleteBox
			// 
			this->makeOrDeleteBox->Controls->Add(this->deleteRB);
			this->makeOrDeleteBox->Controls->Add(this->sakuseiRB);
			this->makeOrDeleteBox->Font = (gcnew System::Drawing::Font(L"メイリオ", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->makeOrDeleteBox->Location = System::Drawing::Point(627, 85);
			this->makeOrDeleteBox->Name = L"makeOrDeleteBox";
			this->makeOrDeleteBox->Size = System::Drawing::Size(192, 99);
			this->makeOrDeleteBox->TabIndex = 14;
			this->makeOrDeleteBox->TabStop = false;
			this->makeOrDeleteBox->Text = L"作成/削除";
			// 
			// kindSetBox
			// 
			this->kindSetBox->Controls->Add(this->makeDescription);
			this->kindSetBox->Controls->Add(this->makeKaitougun);
			this->kindSetBox->Controls->Add(this->onlyAnaume);
			this->kindSetBox->Font = (gcnew System::Drawing::Font(L"メイリオ", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->kindSetBox->Location = System::Drawing::Point(627, 191);
			this->kindSetBox->Name = L"kindSetBox";
			this->kindSetBox->Size = System::Drawing::Size(192, 132);
			this->kindSetBox->TabIndex = 15;
			this->kindSetBox->TabStop = false;
			this->kindSetBox->Text = L"問題の種類指定";
			// 
			// makeDescription
			// 
			this->makeDescription->AutoSize = true;
			this->makeDescription->Font = (gcnew System::Drawing::Font(L"メイリオ", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->makeDescription->Location = System::Drawing::Point(12, 59);
			this->makeDescription->Name = L"makeDescription";
			this->makeDescription->Size = System::Drawing::Size(133, 29);
			this->makeDescription->TabIndex = 14;
			this->makeDescription->Text = L"記述問題を作成";
			this->makeDescription->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->makeDescription->UseCompatibleTextRendering = true;
			this->makeDescription->UseVisualStyleBackColor = true;
			// 
			// saveButton
			// 
			this->saveButton->Font = (gcnew System::Drawing::Font(L"メイリオ", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->saveButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"saveButton.Image")));
			this->saveButton->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->saveButton->Location = System::Drawing::Point(728, 32);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(91, 45);
			this->saveButton->TabIndex = 16;
			this->saveButton->Text = L"保存";
			this->saveButton->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->saveButton->UseVisualStyleBackColor = true;
			this->saveButton->Click += gcnew System::EventHandler(this, &Form1::saveButton_Click);
			// 
			// azukiArea
			// 
			this->azukiArea->BackColor = System::Drawing::Color::White;
			this->azukiArea->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->azukiArea->DrawingOption = static_cast<Sgry::Azuki::DrawingOption>(((((Sgry::Azuki::DrawingOption::DrawsSpace | Sgry::Azuki::DrawingOption::DrawsFullWidthSpace) 
				| Sgry::Azuki::DrawingOption::DrawsTab) 
				| Sgry::Azuki::DrawingOption::DrawsEol) 
				| Sgry::Azuki::DrawingOption::ShowsLineNumber));
			this->azukiArea->DrawsSpace = true;
			this->azukiArea->FirstVisibleLine = 0;
			this->azukiArea->Font = (gcnew System::Drawing::Font(L"メイリオ", 12));
			fontInfo1->Name = L"メイリオ";
			fontInfo1->Size = 12;
			fontInfo1->Style = System::Drawing::FontStyle::Regular;
			this->azukiArea->FontInfo = fontInfo1;
			this->azukiArea->ForeColor = System::Drawing::Color::Black;
			this->azukiArea->HighlightsCurrentLine = false;
			this->azukiArea->HighlightsMatchedBracket = false;
			this->azukiArea->Location = System::Drawing::Point(9, 33);
			this->azukiArea->Name = L"azukiArea";
			this->azukiArea->ScrollPos = System::Drawing::Point(0, 0);
			this->azukiArea->ScrollsBeyondLastLine = false;
			this->azukiArea->ShowsDirtBar = false;
			this->azukiArea->ShowsHScrollBar = false;
			this->azukiArea->Size = System::Drawing::Size(611, 600);
			this->azukiArea->TabIndex = 6;
			this->azukiArea->TabStop = false;
			this->azukiArea->ViewType = Sgry::Azuki::ViewType::WrappedProportional;
			this->azukiArea->ViewWidth = 580;
			this->azukiArea->CaretMoved += gcnew System::EventHandler(this, &Form1::azukiArea_CaretMoved);
			this->azukiArea->TextChanged += gcnew System::EventHandler(this, &Form1::azukiArea_TextChanged);
			this->azukiArea->Enter += gcnew System::EventHandler(this, &Form1::azukiArea_Enter);
			this->azukiArea->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::sampleKeyDown);
			this->azukiArea->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::azukiArea_KeyUp);
			this->azukiArea->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::tArea_MouseUp);
			// 
			// keishikiBox
			// 
			this->keishikiBox->Controls->Add(this->label4);
			this->keishikiBox->Controls->Add(this->label3);
			this->keishikiBox->Controls->Add(this->second);
			this->keishikiBox->Controls->Add(this->minute);
			this->keishikiBox->Controls->Add(this->timelimit);
			this->keishikiBox->Controls->Add(this->randomQNum);
			this->keishikiBox->Controls->Add(this->label2);
			this->keishikiBox->Controls->Add(this->label1);
			this->keishikiBox->Controls->Add(this->randomCheckBox);
			this->keishikiBox->Font = (gcnew System::Drawing::Font(L"メイリオ", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->keishikiBox->Location = System::Drawing::Point(626, 329);
			this->keishikiBox->Name = L"keishikiBox";
			this->keishikiBox->Size = System::Drawing::Size(192, 173);
			this->keishikiBox->TabIndex = 17;
			this->keishikiBox->TabStop = false;
			this->keishikiBox->Text = L"出題形式指定";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"メイリオ", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label4->Location = System::Drawing::Point(158, 136);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(26, 24);
			this->label4->TabIndex = 22;
			this->label4->Text = L"秒";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"メイリオ", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label3->Location = System::Drawing::Point(75, 136);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(26, 24);
			this->label3->TabIndex = 21;
			this->label3->Text = L"分";
			// 
			// second
			// 
			this->second->BackColor = System::Drawing::Color::AliceBlue;
			this->second->Enabled = false;
			this->second->Font = (gcnew System::Drawing::Font(L"メイリオ", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->second->ForeColor = System::Drawing::Color::DarkBlue;
			this->second->Location = System::Drawing::Point(102, 131);
			this->second->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {59, 0, 0, 0});
			this->second->Name = L"second";
			this->second->Size = System::Drawing::Size(50, 36);
			this->second->TabIndex = 20;
			this->second->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->second->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->second->ValueChanged += gcnew System::EventHandler(this, &Form1::minute_ValueChanged);
			// 
			// minute
			// 
			this->minute->BackColor = System::Drawing::Color::AliceBlue;
			this->minute->Enabled = false;
			this->minute->Font = (gcnew System::Drawing::Font(L"メイリオ", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->minute->ForeColor = System::Drawing::Color::DarkBlue;
			this->minute->Location = System::Drawing::Point(12, 131);
			this->minute->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {999, 0, 0, 0});
			this->minute->Name = L"minute";
			this->minute->Size = System::Drawing::Size(60, 36);
			this->minute->TabIndex = 19;
			this->minute->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->minute->ValueChanged += gcnew System::EventHandler(this, &Form1::minute_ValueChanged);
			// 
			// timelimit
			// 
			this->timelimit->AutoSize = true;
			this->timelimit->Font = (gcnew System::Drawing::Font(L"メイリオ", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->timelimit->Location = System::Drawing::Point(12, 103);
			this->timelimit->Name = L"timelimit";
			this->timelimit->Size = System::Drawing::Size(164, 27);
			this->timelimit->TabIndex = 18;
			this->timelimit->Text = L"制限時間を設定する";
			this->timelimit->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->timelimit->UseVisualStyleBackColor = true;
			this->timelimit->CheckedChanged += gcnew System::EventHandler(this, &Form1::timelimit_CheckedChanged);
			// 
			// randomQNum
			// 
			this->randomQNum->BackColor = System::Drawing::Color::AliceBlue;
			this->randomQNum->Enabled = false;
			this->randomQNum->Font = (gcnew System::Drawing::Font(L"メイリオ", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->randomQNum->ForeColor = System::Drawing::Color::DarkBlue;
			this->randomQNum->Location = System::Drawing::Point(88, 56);
			this->randomQNum->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->randomQNum->Name = L"randomQNum";
			this->randomQNum->Size = System::Drawing::Size(64, 36);
			this->randomQNum->TabIndex = 17;
			this->randomQNum->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->randomQNum->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->randomQNum->ValueChanged += gcnew System::EventHandler(this, &Form1::randomQNum_ValueChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"メイリオ", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label2->Location = System::Drawing::Point(158, 61);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(26, 24);
			this->label2->TabIndex = 16;
			this->label2->Text = L"問";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"メイリオ", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label1->Location = System::Drawing::Point(8, 61);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 24);
			this->label1->TabIndex = 15;
			this->label1->Text = L"出題数：";
			// 
			// randomCheckBox
			// 
			this->randomCheckBox->AutoSize = true;
			this->randomCheckBox->Font = (gcnew System::Drawing::Font(L"メイリオ", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->randomCheckBox->Location = System::Drawing::Point(12, 26);
			this->randomCheckBox->Name = L"randomCheckBox";
			this->randomCheckBox->Size = System::Drawing::Size(179, 27);
			this->randomCheckBox->TabIndex = 14;
			this->randomCheckBox->Text = L"行を無作為に並び替え";
			this->randomCheckBox->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->randomCheckBox->UseVisualStyleBackColor = true;
			this->randomCheckBox->CheckedChanged += gcnew System::EventHandler(this, &Form1::randomCheckBox_CheckedChanged);
			// 
			// statusStrip1
			// 
			this->statusStrip1->BackColor = System::Drawing::Color::Blue;
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->whatToDoForUser, 
				this->mojiCode});
			this->statusStrip1->Location = System::Drawing::Point(0, 641);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->statusStrip1->Size = System::Drawing::Size(827, 29);
			this->statusStrip1->SizingGrip = false;
			this->statusStrip1->TabIndex = 18;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// whatToDoForUser
			// 
			this->whatToDoForUser->BackColor = System::Drawing::Color::Black;
			this->whatToDoForUser->BorderSides = static_cast<System::Windows::Forms::ToolStripStatusLabelBorderSides>((System::Windows::Forms::ToolStripStatusLabelBorderSides::Left | System::Windows::Forms::ToolStripStatusLabelBorderSides::Right));
			this->whatToDoForUser->BorderStyle = System::Windows::Forms::Border3DStyle::Etched;
			this->whatToDoForUser->Font = (gcnew System::Drawing::Font(L"メイリオ", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->whatToDoForUser->ForeColor = System::Drawing::Color::White;
			this->whatToDoForUser->Name = L"whatToDoForUser";
			this->whatToDoForUser->Size = System::Drawing::Size(351, 24);
			this->whatToDoForUser->Text = L"模擬テストの原文をテキストエリアに読み込んでください";
			// 
			// mojiCode
			// 
			this->mojiCode->BackColor = System::Drawing::Color::Blue;
			this->mojiCode->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->mojiCode->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->uTF8ToolStripMenuItem, 
				this->shiftjisToolStripMenuItem});
			this->mojiCode->Font = (gcnew System::Drawing::Font(L"メイリオ", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->mojiCode->ForeColor = System::Drawing::Color::White;
			this->mojiCode->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mojiCode.Image")));
			this->mojiCode->ImageTransparentColor = System::Drawing::Color::White;
			this->mojiCode->Name = L"mojiCode";
			this->mojiCode->Size = System::Drawing::Size(67, 27);
			this->mojiCode->Text = L"shift-jis";
			this->mojiCode->TextImageRelation = System::Windows::Forms::TextImageRelation::Overlay;
			this->mojiCode->DropDownClosed += gcnew System::EventHandler(this, &Form1::mojiCode_DropDownClosed);
			this->mojiCode->DropDownOpening += gcnew System::EventHandler(this, &Form1::mojiCode_Click);
			this->mojiCode->DropDownOpened += gcnew System::EventHandler(this, &Form1::mojiCode_DropDownOpened);
			this->mojiCode->Click += gcnew System::EventHandler(this, &Form1::mojiCode_Click);
			this->mojiCode->MouseEnter += gcnew System::EventHandler(this, &Form1::mojiCode_Click);
			this->mojiCode->MouseLeave += gcnew System::EventHandler(this, &Form1::mojiCode_MouseLeave);
			// 
			// uTF8ToolStripMenuItem
			// 
			this->uTF8ToolStripMenuItem->Name = L"uTF8ToolStripMenuItem";
			this->uTF8ToolStripMenuItem->Size = System::Drawing::Size(123, 24);
			this->uTF8ToolStripMenuItem->Text = L"UTF-8";
			this->uTF8ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::uTF8ToolStripMenuItem_Click);
			// 
			// shiftjisToolStripMenuItem
			// 
			this->shiftjisToolStripMenuItem->BackColor = System::Drawing::SystemColors::Control;
			this->shiftjisToolStripMenuItem->Name = L"shiftjisToolStripMenuItem";
			this->shiftjisToolStripMenuItem->Size = System::Drawing::Size(123, 24);
			this->shiftjisToolStripMenuItem->Text = L"shift-jis";
			this->shiftjisToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::shiftjisToolStripMenuItem_Click);
			// 
			// doHelp
			// 
			this->doHelp->EnableRaisingEvents = true;
			this->doHelp->StartInfo->Arguments = L".\\uwsc\\GruGru.UWS";
			this->doHelp->StartInfo->Domain = L"";
			this->doHelp->StartInfo->FileName = L".\\uwsc\\UWSC.exe";
			this->doHelp->StartInfo->LoadUserProfile = false;
			this->doHelp->StartInfo->Password = nullptr;
			this->doHelp->StartInfo->StandardErrorEncoding = nullptr;
			this->doHelp->StartInfo->StandardOutputEncoding = nullptr;
			this->doHelp->StartInfo->UserName = L"";
			this->doHelp->StartInfo->UseShellExecute = false;
			this->doHelp->SynchronizingObject = this;
			this->doHelp->Exited += gcnew System::EventHandler(this, &Form1::doHelp_Exited);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(827, 670);
			this->Controls->Add(this->azukiArea);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->keishikiBox);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->kindSetBox);
			this->Controls->Add(this->makeOrDeleteBox);
			this->Controls->Add(this->mogiMake);
			this->Controls->Add(this->openFile);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->HelpButton = true;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MogiEditor";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->makeOrDeleteBox->ResumeLayout(false);
			this->makeOrDeleteBox->PerformLayout();
			this->kindSetBox->ResumeLayout(false);
			this->kindSetBox->PerformLayout();
			this->keishikiBox->ResumeLayout(false);
			this->keishikiBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->second))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->minute))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->randomQNum))->EndInit();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: static void printMessage(String^ msg){
				MessageBox::Show(msg,"メッセージ");
			}

	private: void setButtonsEnabled(bool setBool);

	private: void setExplainText(int index);

	private: void Form1_Load(System::Object^  sender, System::EventArgs^  e);

			 void open(String^ filename);

			 void setchecks(bool set);

	private: void openFile_Click(System::Object^  sender, System::EventArgs^  e);

			 void remake_doing(String^ sele);

			 void torikeshi_doing(String^ sele);

	private: void mogiMake_Click(System::Object^  sender, System::EventArgs^  e);

			 void _MsgBox(String^title,String^ text);
			 void MouseMove(int a,int b,int c);
			 void MouseDown(String^ txt);
			 void MouseUp(String^ txt);
			 void MouseClick(String^ txt,int a,int b,int c,int d);
			 void Send(String^ txt);

			 void autoitInvoke();

			 void _WinWaitActivate(String^ title,String^ text,int timeout);
			 void _WinWaitActivate(String^ title,String^ text);

	private: void helpMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

	private: void azukiArea_TextChanged(System::Object^  sender, System::EventArgs^  e);

	private: void tArea_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);

	private: void QBuild_doing(QBuild^ exec , String^ sele);
			 String^ Form1::makeDesc(String^ sele);

	private: void openMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 openFile_Click(sender,e);
			 }

	private: void undoMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 azukiArea->Undo();
			 }

	private: void redoMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 azukiArea->Redo();
			 }

	private: void copyMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 azukiArea->Copy();
			 }

	private: void all_selectMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 azukiArea->SelectAll();
			 }

	private: void saveButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 over_writeMenuItem_Click(sender,e);
			 }

	private: void over_writeMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

	private: void savingDo(bool append);

	private: void named_saveMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 savingDo(false);
			 }

	private: void randomQNum_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
				 if (randomQNum->Enabled)
				 {
					 doAddFirstRow();  
				 }
				 //{@Random=10;}{@TimeLimit=120;}{@Kaitougun=true;}
			 }

			 int getsecond();

			 String^ getFirstRow();

			 String^ randoming();

	private: void randomCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 randomQNum->Enabled = randomCheckBox->Checked;
				 randomQNum->Maximum = azukiArea->Text->Split('\n')->Length;
				 doAddFirstRow(); 
			 }

	private: void newMakeItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 azukiArea->Text = "";
				 fileName = "";
				 this->Text = "MogiEditor";
				 azukiArea->Document->ClearHistory();
			 }

	private: void endMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
			 }

	private: void plusMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 savingDo(true);
			 }

	private: void shiftjisToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 mojiCode->Text = shiftjisToolStripMenuItem->Text;
			 }

	private: void uTF8ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 mojiCode->Text = uTF8ToolStripMenuItem->Text;
			 }

	private: void mojiCode_Click(System::Object^  sender, System::EventArgs^  e) {
				 mojiCode->ForeColor = Color::Blue;
			 }

	private: void mojiCode_DropDownClosed(System::Object^  sender, System::EventArgs^  e) {
				 mojiCode->ForeColor = Color::White;
				 dropOpen=false;
			 }

			 bool dropOpen;

	private: void mojiCode_DropDownOpened(System::Object^  sender, System::EventArgs^  e) {
				 dropOpen=true;
			 }

	private: void mojiCode_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
				 if (!dropOpen)
				 {
					 mojiCode->ForeColor = Color::White;
				 }
			 }

	private: void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
				 QMarking::writeToReg(fileName);
			 }

	private: void timelimit_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 minute->Enabled = timelimit->Checked;
				 second->Enabled = timelimit->Checked;
				 doAddFirstRow(); 
			 }

			 void doAddFirstRow();

	private: void minute_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
				 if (minute->Enabled)
				 {
					 doAddFirstRow(); 
				 }
			 }
	private: void makeKaitougun_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 doAddFirstRow(); 
			 }

	private: void azukiArea_CaretMoved(System::Object^  sender, System::EventArgs^  e);

			 bool isMogiText();

	private: void sampleKeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 if (!doHelp->HasExited)
				 {
					 doHelp->Close();
					 doHelp->Refresh();
				 }
			 }
	private: System::Void doHelp_Exited(System::Object^  sender, System::EventArgs^  e) {
				 if (fileName->Length>0)
				 {
					 open(fileName);
				 }else
				 {
					 newMakeItem_Click(sender,e);
				 }
			 }
	private: System::Void azukiArea_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 if (e->KeyCode==Keys::F5)
				 {
					 ctrlPusing=false; 
				 }
			 }
	private: System::Void azukiArea_Enter(System::Object^  sender, System::EventArgs^  e) {
				 ctrlPusing=false;
			 }
	};
}