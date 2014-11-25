#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Diagnostics;
using namespace System::Collections::Generic;
using namespace System::IO;


namespace Mogitter {

	/// <summary>
	/// QMarking の概要
	///
	/// 警告: このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
	///          正しく相互に利用できなくなります。
	/// </summary>
	public ref class QMarking : public System::Windows::Forms::Form
	{
	public:
		QMarking(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクタ コードを追加します
			//
			byButtonClose = false;
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~QMarking()
		{
			if (components)
			{
				delete components;
			}
		}
	public: static String^ regPath = "Software\\MeijinProject\\MogiMeijin\\saves";
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::Label^  questNum;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  collectNum;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  persentNum;
	private: System::Windows::Forms::Label^  label7;


	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  timeLabel;
	private: System::Windows::Forms::Button^  button2;
	private: Microsoft::VisualBasic::PowerPacks::ShapeContainer^  shapeContainer2;
	private: Microsoft::VisualBasic::PowerPacks::LineShape^  lineShape1;
	private: System::Windows::Forms::Button^  revenge;



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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->questNum = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->collectNum = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->persentNum = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->shapeContainer2 = (gcnew Microsoft::VisualBasic::PowerPacks::ShapeContainer());
			this->lineShape1 = (gcnew Microsoft::VisualBasic::PowerPacks::LineShape());
			this->timeLabel = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->revenge = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->AutoEllipsis = true;
			this->button1->Font = (gcnew System::Drawing::Font(L"メイリオ", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->button1->Location = System::Drawing::Point(35, 209);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(84, 30);
			this->button1->TabIndex = 2;
			this->button1->Text = L"閉じる";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &QMarking::button1_Click);
			// 
			// questNum
			// 
			this->questNum->AutoSize = true;
			this->questNum->BackColor = System::Drawing::Color::Gold;
			this->questNum->Font = (gcnew System::Drawing::Font(L"HGSｺﾞｼｯｸE", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->questNum->ForeColor = System::Drawing::Color::Black;
			this->questNum->Location = System::Drawing::Point(101, 24);
			this->questNum->Name = L"questNum";
			this->questNum->Size = System::Drawing::Size(49, 24);
			this->questNum->TabIndex = 1;
			this->questNum->Text = L"100";
			this->questNum->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Gold;
			this->label2->Font = (gcnew System::Drawing::Font(L"メイリオ", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(148, 29);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 23);
			this->label2->TabIndex = 2;
			this->label2->Text = L"問中";
			// 
			// collectNum
			// 
			this->collectNum->AutoSize = true;
			this->collectNum->BackColor = System::Drawing::Color::Gold;
			this->collectNum->Font = (gcnew System::Drawing::Font(L"HGSｺﾞｼｯｸE", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->collectNum->ForeColor = System::Drawing::Color::Red;
			this->collectNum->Location = System::Drawing::Point(185, 15);
			this->collectNum->Name = L"collectNum";
			this->collectNum->Size = System::Drawing::Size(75, 35);
			this->collectNum->TabIndex = 3;
			this->collectNum->Text = L"100";
			this->collectNum->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Gold;
			this->label4->Font = (gcnew System::Drawing::Font(L"メイリオ", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(261, 29);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(55, 23);
			this->label4->TabIndex = 4;
			this->label4->Text = L"問正解";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::White;
			this->label5->Font = (gcnew System::Drawing::Font(L"メイリオ", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label5->ForeColor = System::Drawing::Color::Black;
			this->label5->Location = System::Drawing::Point(45, 110);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(111, 36);
			this->label5->TabIndex = 5;
			this->label5->Text = L"正解率は";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// persentNum
			// 
			this->persentNum->AutoSize = true;
			this->persentNum->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->persentNum->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->persentNum->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->persentNum->Font = (gcnew System::Drawing::Font(L"HGSｺﾞｼｯｸE", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->persentNum->ForeColor = System::Drawing::Color::Red;
			this->persentNum->Location = System::Drawing::Point(155, 94);
			this->persentNum->Name = L"persentNum";
			this->persentNum->Size = System::Drawing::Size(103, 50);
			this->persentNum->TabIndex = 6;
			this->persentNum->Text = L"100";
			this->persentNum->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::White;
			this->label7->Font = (gcnew System::Drawing::Font(L"メイリオ", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label7->ForeColor = System::Drawing::Color::Black;
			this->label7->Location = System::Drawing::Point(258, 110);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(87, 36);
			this->label7->TabIndex = 7;
			this->label7->Text = L"％です";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Gold;
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->collectNum);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->questNum);
			this->panel1->Controls->Add(this->shapeContainer2);
			this->panel1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(50)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(396, 67);
			this->panel1->TabIndex = 9;
			// 
			// shapeContainer2
			// 
			this->shapeContainer2->Location = System::Drawing::Point(0, 0);
			this->shapeContainer2->Margin = System::Windows::Forms::Padding(0);
			this->shapeContainer2->Name = L"shapeContainer2";
			this->shapeContainer2->Shapes->AddRange(gcnew cli::array< Microsoft::VisualBasic::PowerPacks::Shape^  >(1) {this->lineShape1});
			this->shapeContainer2->Size = System::Drawing::Size(396, 67);
			this->shapeContainer2->TabIndex = 5;
			this->shapeContainer2->TabStop = false;
			// 
			// lineShape1
			// 
			this->lineShape1->BorderStyle = System::Drawing::Drawing2D::DashStyle::Dot;
			this->lineShape1->BorderWidth = 3;
			this->lineShape1->Name = L"lineShape1";
			this->lineShape1->X1 = 0;
			this->lineShape1->X2 = 394;
			this->lineShape1->Y1 = 66;
			this->lineShape1->Y2 = 66;
			// 
			// timeLabel
			// 
			this->timeLabel->AutoSize = true;
			this->timeLabel->BackColor = System::Drawing::Color::White;
			this->timeLabel->Font = (gcnew System::Drawing::Font(L"メイリオ", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->timeLabel->ForeColor = System::Drawing::Color::Black;
			this->timeLabel->Location = System::Drawing::Point(224, 174);
			this->timeLabel->Name = L"timeLabel";
			this->timeLabel->Size = System::Drawing::Size(160, 23);
			this->timeLabel->TabIndex = 5;
			this->timeLabel->Text = L"消費時間：100分40秒";
			// 
			// button2
			// 
			this->button2->AutoEllipsis = true;
			this->button2->Font = (gcnew System::Drawing::Font(L"メイリオ", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->button2->Location = System::Drawing::Point(136, 209);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(91, 30);
			this->button2->TabIndex = 0;
			this->button2->Text = L"再挑戦";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &QMarking::button2_Click);
			// 
			// revenge
			// 
			this->revenge->AutoEllipsis = true;
			this->revenge->Font = (gcnew System::Drawing::Font(L"メイリオ", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->revenge->Location = System::Drawing::Point(243, 209);
			this->revenge->Name = L"revenge";
			this->revenge->Size = System::Drawing::Size(118, 30);
			this->revenge->TabIndex = 1;
			this->revenge->Text = L"誤答を再挑戦";
			this->revenge->UseVisualStyleBackColor = true;
			this->revenge->Click += gcnew System::EventHandler(this, &QMarking::revenge_Click);
			// 
			// QMarking
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(396, 251);
			this->Controls->Add(this->revenge);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->timeLabel);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->persentNum);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"QMarking";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"採点結果";
			this->TopMost = true;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &QMarking::QMarking_FormClosed);
			this->Load += gcnew System::EventHandler(this, &QMarking::QMarking_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	public: int marking(List<String^> ^questStrings,List<String^> ^answerStrings,ListBox ^answerList,String^ (*escapeSet)(String^)){
				int score = 0;
				int qCount = questStrings->Count;
				array<String^>^ collects = gcnew array<String^>(qCount);
				for(int i=0;i<qCount;i++){
					String ^ans="";
					array<wchar_t> ^spliters = {','};
					array<String^>^ kugirin = escapeSet(questStrings[i])->Split(spliters);
					if(kugirin->Length > 2){//選択問題
						array<wchar_t> ^spliters2 = {':'};
						array<String^>^ items = kugirin[2]->Split(spliters2);
						ans = items[int::Parse(kugirin[1])-1];
					}else{
						ans = kugirin[1];
					}
					collects[i] = ans;
				}
				for(int i=0;i<qCount;i++){
					if(collects[i] == answerStrings[i])
					{
						answerList->Items[i] = "○"+answerList->Items[i];
						score++;
					}
					else
					{
						answerList->Items[i] = "×"+answerList->Items[i];
					}				 
					answerList->Update();
					Threading::Thread::Sleep(200);
				}
				return score;
			}
#pragma endregion
			bool byButtonClose;
	private: void QMarking_Load(System::Object^  sender, System::EventArgs^  e) {

				 FileInfo^ fi=gcnew FileInfo(Application::ExecutablePath);
				 this->Icon = gcnew System::Drawing::Icon(fi->DirectoryName+"\\"+"icon\\Preview.ico");
				 /*				 
				 int w = panel1->Size.Width;
				 int h = panel1->Size.Height;
				 panel1->BackgroundImage = gcnew Bitmap(w,h);
				 Graphics^ g = Graphics::FromImage(panel1->BackgroundImage);
				 Pen^ pn = gcnew Pen(Color::Black,2);
				 pn->DashStyle = System::Drawing::Drawing2D::DashStyle::Dot;
				 g->DrawLine(pn,0,h-2,w,h-2);
				 */
			 }
	public: int QMarking::markingX();
	public: void button1_Click(System::Object^  sender, System::EventArgs^  e);
			void button2_Click(System::Object^  sender, System::EventArgs^  e);
			void revenge_Click(System::Object^  sender, System::EventArgs^  e);
			static void writeToReg(String^ filename);
			static String^ readFileName();


	private: void QMarking_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
				 if (!byButtonClose)
				 {
					 button1_Click(sender,e);
				 }
			 }

	};
}
