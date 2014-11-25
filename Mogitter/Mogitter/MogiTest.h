#pragma once
#include "QMarking.h"
#include "ShareData.h"
#include "MyTools.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Diagnostics;
using namespace System::Collections::Generic;
//	using namespace Sgry::Azuki;
//	using namespace Sgry::Azuki::WinForms;

namespace Mogitter {

	/// <summary>
	/// MogiTest の概要
	///
	/// 警告: このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
	///          正しく相互に利用できなくなります。
	/// </summary>
	public ref class MogiTest : public System::Windows::Forms::Form
	{
	public:
		MogiTest(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクタ コードを追加します
			//
			seikaiNumber = gcnew List<int>;
			seikaiNumber->Add(0);
			randomAftTxt = "";
			plainText = "";
			doneReading=true;

			timelimitSecond=0;
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~MogiTest()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  time_limit;
	private: Sgry::Azuki::WinForms::AzukiControl^  QuestSentence;
	protected: 


	protected: 






	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::GroupBox^  anaumeGroup;
	private: System::Windows::Forms::GroupBox^  sentakuGroup;


	private: System::Windows::Forms::RichTextBox^  anaumeAnsBox;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::ComboBox^  sentakushiCombo;
	private: System::Windows::Forms::Button^  marutsukeButton;

	private: System::Windows::Forms::MenuStrip^  menuStrip1;


			 //int qCount;
	public:String ^plainText;
		   String^ randomAftTxt;
		   ///<summary>
		   ///<para>各問題を以下のような形式で保持します。</para>
		   ///<para>穴埋め問題："1,(answer)"</para>
		   ///<para>解答が長い問題(予定)："1,(answer),describe"</para>
		   ///<para>選択問題："4,(ansNum),aaa:bbb:ccc:ddd"</para>
		   ///<para>別解問題："0,(answer),aaa:bbb:ccc:ddd"</para>
		   ///</summary>
		   List<String^> ^questStrings;
		   List<String^>^ answerStrings;
		   List<String^>^ kaitouGunList;
		   List<int>^ seikaiNumber;

		   String^ filename;

		   int timelimitSecond;
		   bool doneReading;

		   static const int describeWidth=255;

	public:int qCountField;
		   int score;
		   int countUp;
		   /// <summary>
		   /// 丸付け時に、正解となる文字列を格納します。
		   /// 別解問題はタブ記号で区切って格納します。
		   /// <para>
		   /// でも、丸付けのときにタブは解除されます。正解のときはそれに、不正解のときは最初の解になります。
		   /// </para>
		   /// </summary>
		   array<String^>^ collects;


	private: System::Windows::Forms::ToolStripMenuItem^  HelpMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  helpMenuItem;




	private: System::Windows::Forms::ToolStripMenuItem^  FileMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openMenuItem;


	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator;
	private: System::Windows::Forms::ToolStripMenuItem^  exportMenuItem;


	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  endMenuItem;

	private: System::Windows::Forms::NumericUpDown^  QNumUpDown;

	private: System::Windows::Forms::Timer^  timer1;
	public: System::Windows::Forms::Timer^  keikajikan;
	private: 

	private: System::Windows::Forms::SplitContainer^  splitContainer1;


	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::GroupBox^  bunsyouBox;

	private: Sgry::Azuki::WinForms::AzukiControl^  bunsyoudai;

	private: System::Windows::Forms::Button^  revenge;
	private: System::Windows::Forms::Label^  label7;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::CheckBox^  onlyMissCB;
	private: System::Windows::Forms::ToolStripMenuItem^  htmlOUTPUT;
	private: System::Diagnostics::Process^  openHTML;
	private: System::Windows::Forms::SplitContainer^  answerImageSplitter;

	private: Sgry::Azuki::WinForms::AzukiControl^  userAnswerArea;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::PictureBox^  ImageQuest;




	private: System::ComponentModel::IContainer^  components;










	private:
		/// <summary>
		/// 必要なデザイナ変数です。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナ サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディタで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MogiTest::typeid));
			Sgry::Azuki::FontInfo^  fontInfo1 = (gcnew Sgry::Azuki::FontInfo());
			Sgry::Azuki::FontInfo^  fontInfo2 = (gcnew Sgry::Azuki::FontInfo());
			Sgry::Azuki::FontInfo^  fontInfo3 = (gcnew Sgry::Azuki::FontInfo());
			this->time_limit = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->anaumeGroup = (gcnew System::Windows::Forms::GroupBox());
			this->anaumeAnsBox = (gcnew System::Windows::Forms::RichTextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->sentakuGroup = (gcnew System::Windows::Forms::GroupBox());
			this->sentakushiCombo = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->marutsukeButton = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->FileMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exportMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->htmlOUTPUT = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->endMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->HelpMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->QNumUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->keikajikan = (gcnew System::Windows::Forms::Timer(this->components));
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->QuestSentence = (gcnew Sgry::Azuki::WinForms::AzukiControl());
			this->answerImageSplitter = (gcnew System::Windows::Forms::SplitContainer());
			this->userAnswerArea = (gcnew Sgry::Azuki::WinForms::AzukiControl());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->ImageQuest = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->onlyMissCB = (gcnew System::Windows::Forms::CheckBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->revenge = (gcnew System::Windows::Forms::Button());
			this->bunsyouBox = (gcnew System::Windows::Forms::GroupBox());
			this->bunsyoudai = (gcnew Sgry::Azuki::WinForms::AzukiControl());
			this->openHTML = (gcnew System::Diagnostics::Process());
			this->anaumeGroup->SuspendLayout();
			this->sentakuGroup->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->QNumUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->answerImageSplitter))->BeginInit();
			this->answerImageSplitter->Panel1->SuspendLayout();
			this->answerImageSplitter->Panel2->SuspendLayout();
			this->answerImageSplitter->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ImageQuest))->BeginInit();
			this->panel1->SuspendLayout();
			this->bunsyouBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// time_limit
			// 
			this->time_limit->AutoSize = true;
			this->time_limit->BackColor = System::Drawing::SystemColors::Control;
			this->time_limit->Font = (gcnew System::Drawing::Font(L"メイリオ", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->time_limit->Location = System::Drawing::Point(3, 3);
			this->time_limit->Name = L"time_limit";
			this->time_limit->Size = System::Drawing::Size(170, 24);
			this->time_limit->TabIndex = 0;
			this->time_limit->Text = L"制限時間はありません";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"メイリオ", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label3->Location = System::Drawing::Point(115, 17);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(74, 24);
			this->label3->TabIndex = 5;
			this->label3->Text = L"問題番号";
			// 
			// anaumeGroup
			// 
			this->anaumeGroup->Controls->Add(this->anaumeAnsBox);
			this->anaumeGroup->Controls->Add(this->label4);
			this->anaumeGroup->Font = (gcnew System::Drawing::Font(L"メイリオ", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->anaumeGroup->Location = System::Drawing::Point(10, 156);
			this->anaumeGroup->Name = L"anaumeGroup";
			this->anaumeGroup->Size = System::Drawing::Size(290, 73);
			this->anaumeGroup->TabIndex = 6;
			this->anaumeGroup->TabStop = false;
			this->anaumeGroup->Text = L"穴埋め問題";
			// 
			// anaumeAnsBox
			// 
			this->anaumeAnsBox->CausesValidation = false;
			this->anaumeAnsBox->DetectUrls = false;
			this->anaumeAnsBox->Font = (gcnew System::Drawing::Font(L"メイリオ", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->anaumeAnsBox->HideSelection = false;
			this->anaumeAnsBox->Location = System::Drawing::Point(66, 32);
			this->anaumeAnsBox->MaxLength = 100;
			this->anaumeAnsBox->Multiline = false;
			this->anaumeAnsBox->Name = L"anaumeAnsBox";
			this->anaumeAnsBox->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Horizontal;
			this->anaumeAnsBox->Size = System::Drawing::Size(218, 30);
			this->anaumeAnsBox->TabIndex = 9;
			this->anaumeAnsBox->Text = L"";
			this->anaumeAnsBox->WordWrap = false;
			this->anaumeAnsBox->TextChanged += gcnew System::EventHandler(this, &MogiTest::anaumeAnsBox_TextChanged);
			this->anaumeAnsBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MogiTest::anaumeAnsBox_KeyDown);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"メイリオ", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label4->Location = System::Drawing::Point(6, 35);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(58, 24);
			this->label4->TabIndex = 8;
			this->label4->Text = L"解答：";
			// 
			// sentakuGroup
			// 
			this->sentakuGroup->BackColor = System::Drawing::Color::Lime;
			this->sentakuGroup->Controls->Add(this->sentakushiCombo);
			this->sentakuGroup->Controls->Add(this->label5);
			this->sentakuGroup->Font = (gcnew System::Drawing::Font(L"メイリオ", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->sentakuGroup->Location = System::Drawing::Point(10, 251);
			this->sentakuGroup->Name = L"sentakuGroup";
			this->sentakuGroup->Size = System::Drawing::Size(290, 73);
			this->sentakuGroup->TabIndex = 7;
			this->sentakuGroup->TabStop = false;
			this->sentakuGroup->Text = L"選択問題";
			// 
			// sentakushiCombo
			// 
			this->sentakushiCombo->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->sentakushiCombo->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->sentakushiCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->sentakushiCombo->Font = (gcnew System::Drawing::Font(L"メイリオ", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->sentakushiCombo->FormattingEnabled = true;
			this->sentakushiCombo->IntegralHeight = false;
			this->sentakushiCombo->Location = System::Drawing::Point(66, 29);
			this->sentakushiCombo->MaxDropDownItems = 20;
			this->sentakushiCombo->Name = L"sentakushiCombo";
			this->sentakushiCombo->Size = System::Drawing::Size(218, 32);
			this->sentakushiCombo->Sorted = true;
			this->sentakushiCombo->TabIndex = 8;
			this->sentakushiCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &MogiTest::sentakushiCombo_SelectedIndexChanged);
			this->sentakushiCombo->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MogiTest::anaumeAnsBox_KeyDown);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"メイリオ", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label5->Location = System::Drawing::Point(6, 32);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(58, 24);
			this->label5->TabIndex = 10;
			this->label5->Text = L"解答：";
			// 
			// marutsukeButton
			// 
			this->marutsukeButton->BackColor = System::Drawing::Color::Ivory;
			this->marutsukeButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->marutsukeButton->Font = (gcnew System::Drawing::Font(L"HGP行書体", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->marutsukeButton->ForeColor = System::Drawing::Color::Red;
			this->marutsukeButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"marutsukeButton.Image")));
			this->marutsukeButton->ImageAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->marutsukeButton->Location = System::Drawing::Point(45, 522);
			this->marutsukeButton->Name = L"marutsukeButton";
			this->marutsukeButton->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->marutsukeButton->Size = System::Drawing::Size(89, 62);
			this->marutsukeButton->TabIndex = 8;
			this->marutsukeButton->Text = L"採点";
			this->marutsukeButton->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->marutsukeButton->UseVisualStyleBackColor = false;
			this->marutsukeButton->Click += gcnew System::EventHandler(this, &MogiTest::marutsukeButton_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->FileMenuItem, this->HelpMenu});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->menuStrip1->Size = System::Drawing::Size(1009, 26);
			this->menuStrip1->TabIndex = 9;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// FileMenuItem
			// 
			this->FileMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->openMenuItem, 
				this->toolStripSeparator, this->exportMenuItem, this->htmlOUTPUT, this->toolStripSeparator1, this->endMenuItem});
			this->FileMenuItem->Name = L"FileMenuItem";
			this->FileMenuItem->Size = System::Drawing::Size(85, 22);
			this->FileMenuItem->Text = L"ファイル(&F)";
			// 
			// openMenuItem
			// 
			this->openMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"openMenuItem.Image")));
			this->openMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->openMenuItem->Name = L"openMenuItem";
			this->openMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->openMenuItem->Size = System::Drawing::Size(251, 22);
			this->openMenuItem->Text = L"模擬テストを始める(&O)";
			this->openMenuItem->Click += gcnew System::EventHandler(this, &MogiTest::openMenuItem_Click);
			// 
			// toolStripSeparator
			// 
			this->toolStripSeparator->Name = L"toolStripSeparator";
			this->toolStripSeparator->Size = System::Drawing::Size(248, 6);
			// 
			// exportMenuItem
			// 
			this->exportMenuItem->Name = L"exportMenuItem";
			this->exportMenuItem->Size = System::Drawing::Size(251, 22);
			this->exportMenuItem->Text = L"試験問題をテキスト出力(&T)";
			this->exportMenuItem->Click += gcnew System::EventHandler(this, &MogiTest::exportMenuItem_Click);
			// 
			// htmlOUTPUT
			// 
			this->htmlOUTPUT->Name = L"htmlOUTPUT";
			this->htmlOUTPUT->Size = System::Drawing::Size(251, 22);
			this->htmlOUTPUT->Text = L"採点結果をHTML出力(&H)";
			this->htmlOUTPUT->Click += gcnew System::EventHandler(this, &MogiTest::htmlOUTPUT_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(248, 6);
			// 
			// endMenuItem
			// 
			this->endMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"endMenuItem.Image")));
			this->endMenuItem->Name = L"endMenuItem";
			this->endMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::X));
			this->endMenuItem->Size = System::Drawing::Size(251, 22);
			this->endMenuItem->Text = L"終了(&X)";
			this->endMenuItem->Click += gcnew System::EventHandler(this, &MogiTest::endMenuItem_Click);
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
			this->helpMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::H));
			this->helpMenuItem->Size = System::Drawing::Size(166, 22);
			this->helpMenuItem->Text = L"内容(&C)";
			// 
			// QNumUpDown
			// 
			this->QNumUpDown->BackColor = System::Drawing::Color::LightGoldenrodYellow;
			this->QNumUpDown->Font = (gcnew System::Drawing::Font(L"メイリオ", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->QNumUpDown->Location = System::Drawing::Point(105, 44);
			this->QNumUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->QNumUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->QNumUpDown->Name = L"QNumUpDown";
			this->QNumUpDown->ReadOnly = true;
			this->QNumUpDown->Size = System::Drawing::Size(96, 43);
			this->QNumUpDown->TabIndex = 10;
			this->QNumUpDown->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->QNumUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->QNumUpDown->ValueChanged += gcnew System::EventHandler(this, &MogiTest::QNumUpDown_ValueChanged);
			// 
			// timer1
			// 
			this->timer1->Interval = 60;
			this->timer1->Tick += gcnew System::EventHandler(this, &MogiTest::timer1_Tick);
			// 
			// keikajikan
			// 
			this->keikajikan->Interval = 1000;
			this->keikajikan->Tick += gcnew System::EventHandler(this, &MogiTest::keikajikan_Tick);
			// 
			// splitContainer1
			// 
			this->splitContainer1->BackColor = System::Drawing::Color::Lime;
			this->splitContainer1->Location = System::Drawing::Point(9, 26);
			this->splitContainer1->Margin = System::Windows::Forms::Padding(0);
			this->splitContainer1->Name = L"splitContainer1";
			this->splitContainer1->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->BackColor = System::Drawing::SystemColors::Control;
			this->splitContainer1->Panel1->Controls->Add(this->time_limit);
			this->splitContainer1->Panel1->Controls->Add(this->QuestSentence);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->answerImageSplitter);
			this->splitContainer1->Size = System::Drawing::Size(687, 633);
			this->splitContainer1->SplitterDistance = 432;
			this->splitContainer1->SplitterWidth = 3;
			this->splitContainer1->TabIndex = 12;
			this->splitContainer1->TabStop = false;
			// 
			// QuestSentence
			// 
			this->QuestSentence->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->QuestSentence->BackColor = System::Drawing::Color::Ivory;
			this->QuestSentence->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->QuestSentence->DrawingOption = Sgry::Azuki::DrawingOption::ShowsLineNumber;
			this->QuestSentence->DrawsEolCode = false;
			this->QuestSentence->DrawsFullWidthSpace = false;
			this->QuestSentence->DrawsTab = false;
			this->QuestSentence->FirstVisibleLine = 0;
			this->QuestSentence->Font = (gcnew System::Drawing::Font(L"メイリオ", 12));
			fontInfo1->Name = L"メイリオ";
			fontInfo1->Size = 12;
			fontInfo1->Style = System::Drawing::FontStyle::Regular;
			this->QuestSentence->FontInfo = fontInfo1;
			this->QuestSentence->ForeColor = System::Drawing::Color::Black;
			this->QuestSentence->HighlightsCurrentLine = false;
			this->QuestSentence->HighlightsMatchedBracket = false;
			this->QuestSentence->IsReadOnly = true;
			this->QuestSentence->Location = System::Drawing::Point(0, 27);
			this->QuestSentence->Name = L"QuestSentence";
			this->QuestSentence->ScrollPos = System::Drawing::Point(0, 0);
			this->QuestSentence->ShowsDirtBar = false;
			this->QuestSentence->ShowsHScrollBar = false;
			this->QuestSentence->Size = System::Drawing::Size(686, 403);
			this->QuestSentence->TabIndex = 1;
			this->QuestSentence->TabStop = false;
			this->QuestSentence->ViewType = Sgry::Azuki::ViewType::WrappedProportional;
			this->QuestSentence->ViewWidth = 561;
			this->QuestSentence->SizeChanged += gcnew System::EventHandler(this, &MogiTest::QuestSentence_SizeChanged);
			// 
			// answerImageSplitter
			// 
			this->answerImageSplitter->Dock = System::Windows::Forms::DockStyle::Fill;
			this->answerImageSplitter->Location = System::Drawing::Point(0, 0);
			this->answerImageSplitter->Name = L"answerImageSplitter";
			// 
			// answerImageSplitter.Panel1
			// 
			this->answerImageSplitter->Panel1->BackColor = System::Drawing::SystemColors::Control;
			this->answerImageSplitter->Panel1->Controls->Add(this->userAnswerArea);
			this->answerImageSplitter->Panel1->Controls->Add(this->label2);
			this->answerImageSplitter->Panel1MinSize = 0;
			// 
			// answerImageSplitter.Panel2
			// 
			this->answerImageSplitter->Panel2->Controls->Add(this->ImageQuest);
			this->answerImageSplitter->Panel2Collapsed = true;
			this->answerImageSplitter->Panel2MinSize = 0;
			this->answerImageSplitter->Size = System::Drawing::Size(687, 198);
			this->answerImageSplitter->SplitterDistance = 662;
			this->answerImageSplitter->SplitterWidth = 2;
			this->answerImageSplitter->TabIndex = 12;
			// 
			// userAnswerArea
			// 
			this->userAnswerArea->AcceptsReturn = false;
			this->userAnswerArea->AcceptsTab = false;
			this->userAnswerArea->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->userAnswerArea->BackColor = System::Drawing::Color::White;
			this->userAnswerArea->CausesValidation = false;
			this->userAnswerArea->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->userAnswerArea->DrawingOption = static_cast<Sgry::Azuki::DrawingOption>(((Sgry::Azuki::DrawingOption::DrawsFullWidthSpace | Sgry::Azuki::DrawingOption::DrawsTab) 
				| Sgry::Azuki::DrawingOption::ShowsLineNumber));
			this->userAnswerArea->DrawsEolCode = false;
			this->userAnswerArea->FirstVisibleLine = 0;
			this->userAnswerArea->Font = (gcnew System::Drawing::Font(L"HG正楷書体-PRO", 14));
			fontInfo2->Name = L"HG正楷書体-PRO";
			fontInfo2->Size = 14;
			fontInfo2->Style = System::Drawing::FontStyle::Regular;
			this->userAnswerArea->FontInfo = fontInfo2;
			this->userAnswerArea->ForeColor = System::Drawing::Color::Black;
			this->userAnswerArea->HighlightsCurrentLine = false;
			this->userAnswerArea->HighlightsMatchedBracket = false;
			this->userAnswerArea->IsReadOnly = true;
			this->userAnswerArea->LinePadding = 4;
			this->userAnswerArea->Location = System::Drawing::Point(0, 31);
			this->userAnswerArea->Name = L"userAnswerArea";
			this->userAnswerArea->ScrollPos = System::Drawing::Point(0, 0);
			this->userAnswerArea->ScrollsBeyondLastLine = false;
			this->userAnswerArea->ShowsDirtBar = false;
			this->userAnswerArea->Size = System::Drawing::Size(684, 167);
			this->userAnswerArea->TabIndex = 13;
			this->userAnswerArea->TabStop = false;
			this->userAnswerArea->TabWidth = 9;
			this->userAnswerArea->TopMargin = 4;
			this->userAnswerArea->ViewWidth = 200;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::Control;
			this->label2->Font = (gcnew System::Drawing::Font(L"メイリオ", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label2->Location = System::Drawing::Point(3, 4);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(90, 24);
			this->label2->TabIndex = 12;
			this->label2->Text = L"解答表示欄";
			// 
			// ImageQuest
			// 
			this->ImageQuest->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ImageQuest->Location = System::Drawing::Point(0, 0);
			this->ImageQuest->Name = L"ImageQuest";
			this->ImageQuest->Size = System::Drawing::Size(96, 100);
			this->ImageQuest->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->ImageQuest->TabIndex = 0;
			this->ImageQuest->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Lime;
			this->panel1->Controls->Add(this->onlyMissCB);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->revenge);
			this->panel1->Controls->Add(this->bunsyouBox);
			this->panel1->Controls->Add(this->marutsukeButton);
			this->panel1->Controls->Add(this->QNumUpDown);
			this->panel1->Controls->Add(this->sentakuGroup);
			this->panel1->Controls->Add(this->anaumeGroup);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Location = System::Drawing::Point(701, 29);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(310, 646);
			this->panel1->TabIndex = 14;
			// 
			// onlyMissCB
			// 
			this->onlyMissCB->AutoSize = true;
			this->onlyMissCB->Font = (gcnew System::Drawing::Font(L"メイリオ", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->onlyMissCB->Location = System::Drawing::Point(177, 582);
			this->onlyMissCB->Name = L"onlyMissCB";
			this->onlyMissCB->Size = System::Drawing::Size(80, 24);
			this->onlyMissCB->TabIndex = 15;
			this->onlyMissCB->Text = L"誤答のみ";
			this->onlyMissCB->UseVisualStyleBackColor = true;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"メイリオ", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label7->ForeColor = System::Drawing::Color::Indigo;
			this->label7->Location = System::Drawing::Point(6, 124);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(165, 23);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Ctrl＋Enter：前の問題";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"メイリオ", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label1->ForeColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(6, 100);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(124, 23);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Enter：次の問題";
			// 
			// revenge
			// 
			this->revenge->BackColor = System::Drawing::Color::Yellow;
			this->revenge->Font = (gcnew System::Drawing::Font(L"HGP行書体", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->revenge->ForeColor = System::Drawing::Color::Red;
			this->revenge->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"revenge.Image")));
			this->revenge->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->revenge->Location = System::Drawing::Point(177, 522);
			this->revenge->Name = L"revenge";
			this->revenge->Size = System::Drawing::Size(88, 58);
			this->revenge->TabIndex = 11;
			this->revenge->Text = L"再挑戦";
			this->revenge->UseVisualStyleBackColor = false;
			this->revenge->EnabledChanged += gcnew System::EventHandler(this, &MogiTest::revenge_EnabledChanged);
			this->revenge->Click += gcnew System::EventHandler(this, &MogiTest::revenge_Click);
			// 
			// bunsyouBox
			// 
			this->bunsyouBox->Controls->Add(this->bunsyoudai);
			this->bunsyouBox->Font = (gcnew System::Drawing::Font(L"メイリオ", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->bunsyouBox->Location = System::Drawing::Point(10, 344);
			this->bunsyouBox->Name = L"bunsyouBox";
			this->bunsyouBox->Size = System::Drawing::Size(290, 149);
			this->bunsyouBox->TabIndex = 10;
			this->bunsyouBox->TabStop = false;
			this->bunsyouBox->Text = L"記述問題";
			// 
			// bunsyoudai
			// 
			this->bunsyoudai->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(250)), 
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->bunsyoudai->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->bunsyoudai->DrawingOption = static_cast<Sgry::Azuki::DrawingOption>(((((Sgry::Azuki::DrawingOption::DrawsFullWidthSpace | Sgry::Azuki::DrawingOption::DrawsTab) 
				| Sgry::Azuki::DrawingOption::DrawsEol) 
				| Sgry::Azuki::DrawingOption::ShowsDirtBar) 
				| Sgry::Azuki::DrawingOption::HighlightsMatchedBracket));
			this->bunsyoudai->FirstVisibleLine = 0;
			this->bunsyoudai->Font = (gcnew System::Drawing::Font(L"メイリオ", 12));
			fontInfo3->Name = L"メイリオ";
			fontInfo3->Size = 12;
			fontInfo3->Style = System::Drawing::FontStyle::Regular;
			this->bunsyoudai->FontInfo = fontInfo3;
			this->bunsyoudai->ForeColor = System::Drawing::Color::Black;
			this->bunsyoudai->HighlightsCurrentLine = false;
			this->bunsyoudai->IsSingleLineMode = true;
			this->bunsyoudai->Location = System::Drawing::Point(10, 27);
			this->bunsyoudai->Name = L"bunsyoudai";
			this->bunsyoudai->ScrollPos = System::Drawing::Point(0, 0);
			this->bunsyoudai->ShowsHScrollBar = false;
			this->bunsyoudai->ShowsLineNumber = false;
			this->bunsyoudai->Size = System::Drawing::Size(274, 112);
			this->bunsyoudai->TabIndex = 0;
			this->bunsyoudai->ViewType = Sgry::Azuki::ViewType::WrappedProportional;
			this->bunsyoudai->ViewWidth = 210;
			this->bunsyoudai->TextChanged += gcnew System::EventHandler(this, &MogiTest::bunsyoudai_TextChanged);
			this->bunsyoudai->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MogiTest::bunsyoudai_KeyDown);
			// 
			// openHTML
			// 
			this->openHTML->StartInfo->Domain = L"";
			this->openHTML->StartInfo->LoadUserProfile = false;
			this->openHTML->StartInfo->Password = nullptr;
			this->openHTML->StartInfo->StandardErrorEncoding = nullptr;
			this->openHTML->StartInfo->StandardOutputEncoding = nullptr;
			this->openHTML->StartInfo->UserName = L"";
			this->openHTML->SynchronizingObject = this;
			// 
			// MogiTest
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1009, 670);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->splitContainer1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"MogiTest";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MogiTester";
			this->Load += gcnew System::EventHandler(this, &MogiTest::MogiTest_Load);
			this->Shown += gcnew System::EventHandler(this, &MogiTest::MogiTest_Shown);
			this->anaumeGroup->ResumeLayout(false);
			this->anaumeGroup->PerformLayout();
			this->sentakuGroup->ResumeLayout(false);
			this->sentakuGroup->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->QNumUpDown))->EndInit();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->answerImageSplitter->Panel1->ResumeLayout(false);
			this->answerImageSplitter->Panel1->PerformLayout();
			this->answerImageSplitter->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->answerImageSplitter))->EndInit();
			this->answerImageSplitter->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ImageQuest))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->bunsyouBox->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: 
		static array<String^>^ toEsc = {",","=",";",":"};
		///<summary>
		///<para>エスケープ文字toEsc = {",","=",";",":"};を</para>
		///<para>ダブルクォーテーションで挟みます</para>
		///</summary>
		static String^ escapeReady(String^ text){
			String^ txt = text;
			for each(String^ esc in toEsc){
				txt = txt->Replace(esc,"\""+esc+"\"");
			}
			return txt;
		}
		///<summary>
		///<para>ダブルクォーテーションで挟んだエスケープ文字を</para>
		///<para>ユーザーには極秘の文字列@n@に変換します。</para>
		///</summary>
		static String^ escapeSet(String^ text){
			String^ txt = text;
			int i=toEsc->Length-1;
			System::Array::Reverse(toEsc);
			for each(String^ esc in toEsc){
				txt = txt->Replace("\""+esc+"\"","@"+i.ToString()+"@");
				i--;
			}
			System::Array::Reverse(toEsc);
			return txt;
		}
		///<summary>
		///<para>エスケープ文字toEsc = {",","=",";",":"};を</para>
		///<para>元の状態に復元します。</para>
		///</summary>
		static String^ escapeReSet(String^ text){
			String^ txt = text;
			int i=0;
			for each(String^ esc in toEsc){
				txt = txt->Replace("@"+i.ToString()+"@",esc);
				i++;
			}
			return txt;
		}

		static String^ replaceFirst(String^ oriStr , String^ pat , String^ after){
			int indF = oriStr->IndexOf(pat);
			if (indF<0)
			{
				return oriStr;
			}
			return oriStr->Substring(0,indF)+after+oriStr->Substring(indF+pat->Length);
		}

		static String^ getLineText(Sgry::Azuki::WinForms::AzukiControl^ azuki,int lineNum){
			return azuki->Text->Substring(azuki->GetLineHeadIndex(lineNum-1),azuki->GetLineLength(lineNum-1));
		}

		static int getString_width(String^ str,Image^ img){
			Graphics^ g = Graphics::FromImage(img);
			System::Drawing::Font^ f=(gcnew System::Drawing::Font(L"メイリオ", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(128)));
			return static_cast<int>((g->MeasureString(str,f)).Width);
		}

		static int getString_width(String^ str){
			Bitmap^ img=gcnew Bitmap(3,3);
			return getString_width(str,img);
		}

		static bool isBunsyou(String^ txt){
			return getString_width(txt)>=describeWidth;
		}

	private: Sgry::Azuki::Highlighter::KeywordHighlighter^ marubatsu;
			 Sgry::Azuki::Highlighter::KeywordHighlighter^ kakkohigh;
			 array<String^>^ maru;
			 array<String^>^ batsu;
	public:   int keikaSec;

	private: void MogiTest_Load(System::Object^  sender, System::EventArgs^  e);

			 void setEnableSaiten(bool bl);

	public: bool compile(String^ text, bool isPass);

	public: bool compile(String^ text);

	private: void anaumeAnsBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 changeAnswer(anaumeAnsBox->Text);
			 }

	private: void marutsukeButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 marking();
			 }

	private: void QNumUpDown_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
				 qnumDoing();
			 }

			 void qnumDoing();

	private: void marking();

			 void setCollects();

	private: void timer1_Tick(System::Object^  sender, System::EventArgs^  e);

			 void moveQ(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e,bool shift);

	private: void anaumeAnsBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);

			 void setNumberScroll(int val);

	private: void keikajikan_Tick(System::Object^  sender, System::EventArgs^  e);

			 void setTime_Limit();

	public: void kaitouranClean();

	private: void QuestSentence_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
				 QuestSentence->ViewWidth = QuestSentence->ClientSize.Width;
			 }

	private: void endMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
			 }

	private: void openMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

	private: void exportMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

	private: void MogiTest_Shown(System::Object^  sender, System::EventArgs^  e);

	private: void revenge_Click(System::Object^  sender, System::EventArgs^  e);

	private: void userAnswerArea_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
				 userAnswerArea->ViewWidth = userAnswerArea->ClientSize.Width-5;
			 }

	private: void bunsyoudai_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 moveQ(sender,e,false);
			 }

	private: void bunsyoudai_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 changeAnswer(bunsyoudai->Text);
			 }

			 void changeAnswer(String^ txt);

			 void commitAnswer2(int seleNum);

			 void commitAnswer();

	private: void revenge_EnabledChanged(System::Object^  sender, System::EventArgs^  e);

	private: void htmlOUTPUT_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void sentakushiCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);



	};
}
