#pragma once
#include"ThuVien.h"
#include <msclr\marshal_cppstd.h>
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;
	using namespace std;



	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  Input_tb;
	protected:

	private: System::Windows::Forms::Label^  INTPUT_lb;
	private: System::Windows::Forms::TextBox^  decoutput_tb;






	private: System::Windows::Forms::Button^  RESULT_bt;
	private: System::Windows::Forms::Button^  div_bt;




	private: System::Windows::Forms::Button^  multi_bt;

	private: System::Windows::Forms::Button^  minus_bt;


	private: System::Windows::Forms::Button^  plus_bt;
	private: System::Windows::Forms::Button^  NOT_bt;


	private: System::Windows::Forms::Button^  XOR_bt;

	private: System::Windows::Forms::Button^  OR_bt;

	private: System::Windows::Forms::Button^  AND_bt;
	private: System::Windows::Forms::Button^  TranslateRight_bt;
	private: System::Windows::Forms::Button^  TranslateLeft_bt;







	private: System::Windows::Forms::Button^  button_hex;

	private: System::Windows::Forms::Button^  button_dec;
	private: System::Windows::Forms::Button^  button_bin;



	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  HEX_bt;
	private: System::Windows::Forms::Button^  BIN_bt;
	private: System::Windows::Forms::Button^  DEC_bt;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  binoutput_tb;
	private: System::Windows::Forms::TextBox^  hexoutput_tb;










	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Input_tb = (gcnew System::Windows::Forms::TextBox());
			this->INTPUT_lb = (gcnew System::Windows::Forms::Label());
			this->decoutput_tb = (gcnew System::Windows::Forms::TextBox());
			this->RESULT_bt = (gcnew System::Windows::Forms::Button());
			this->div_bt = (gcnew System::Windows::Forms::Button());
			this->multi_bt = (gcnew System::Windows::Forms::Button());
			this->minus_bt = (gcnew System::Windows::Forms::Button());
			this->plus_bt = (gcnew System::Windows::Forms::Button());
			this->NOT_bt = (gcnew System::Windows::Forms::Button());
			this->XOR_bt = (gcnew System::Windows::Forms::Button());
			this->OR_bt = (gcnew System::Windows::Forms::Button());
			this->AND_bt = (gcnew System::Windows::Forms::Button());
			this->TranslateRight_bt = (gcnew System::Windows::Forms::Button());
			this->TranslateLeft_bt = (gcnew System::Windows::Forms::Button());
			this->button_hex = (gcnew System::Windows::Forms::Button());
			this->button_dec = (gcnew System::Windows::Forms::Button());
			this->button_bin = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->HEX_bt = (gcnew System::Windows::Forms::Button());
			this->BIN_bt = (gcnew System::Windows::Forms::Button());
			this->DEC_bt = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->binoutput_tb = (gcnew System::Windows::Forms::TextBox());
			this->hexoutput_tb = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// Input_tb
			// 
			this->Input_tb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Input_tb->Location = System::Drawing::Point(184, 75);
			this->Input_tb->Multiline = true;
			this->Input_tb->Name = L"Input_tb";
			this->Input_tb->Size = System::Drawing::Size(679, 30);
			this->Input_tb->TabIndex = 0;
			this->Input_tb->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->Input_tb->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// INTPUT_lb
			// 
			this->INTPUT_lb->CausesValidation = false;
			this->INTPUT_lb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->INTPUT_lb->Location = System::Drawing::Point(87, 75);
			this->INTPUT_lb->Name = L"INTPUT_lb";
			this->INTPUT_lb->Size = System::Drawing::Size(87, 30);
			this->INTPUT_lb->TabIndex = 1;
			this->INTPUT_lb->Text = L"INPUT";
			this->INTPUT_lb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->INTPUT_lb->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// decoutput_tb
			// 
			this->decoutput_tb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->decoutput_tb->Location = System::Drawing::Point(184, 135);
			this->decoutput_tb->Multiline = true;
			this->decoutput_tb->Name = L"decoutput_tb";
			this->decoutput_tb->Size = System::Drawing::Size(679, 30);
			this->decoutput_tb->TabIndex = 2;
			this->decoutput_tb->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->decoutput_tb->TextChanged += gcnew System::EventHandler(this, &MyForm::decoutput_tb_TextChanged);
			// 
			// RESULT_bt
			// 
			this->RESULT_bt->BackColor = System::Drawing::SystemColors::ControlDark;
			this->RESULT_bt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RESULT_bt->Location = System::Drawing::Point(770, 396);
			this->RESULT_bt->Name = L"RESULT_bt";
			this->RESULT_bt->Size = System::Drawing::Size(94, 48);
			this->RESULT_bt->TabIndex = 7;
			this->RESULT_bt->Text = L"=";
			this->RESULT_bt->UseVisualStyleBackColor = false;
			// 
			// div_bt
			// 
			this->div_bt->BackColor = System::Drawing::SystemColors::ControlDark;
			this->div_bt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->div_bt->Location = System::Drawing::Point(770, 468);
			this->div_bt->Name = L"div_bt";
			this->div_bt->Size = System::Drawing::Size(94, 48);
			this->div_bt->TabIndex = 11;
			this->div_bt->Text = L"/";
			this->div_bt->UseVisualStyleBackColor = false;
			// 
			// multi_bt
			// 
			this->multi_bt->BackColor = System::Drawing::SystemColors::ControlDark;
			this->multi_bt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->multi_bt->Location = System::Drawing::Point(657, 468);
			this->multi_bt->Name = L"multi_bt";
			this->multi_bt->Size = System::Drawing::Size(94, 48);
			this->multi_bt->TabIndex = 10;
			this->multi_bt->Text = L"*";
			this->multi_bt->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->multi_bt->UseVisualStyleBackColor = false;
			// 
			// minus_bt
			// 
			this->minus_bt->BackColor = System::Drawing::SystemColors::ControlDark;
			this->minus_bt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->minus_bt->Location = System::Drawing::Point(541, 468);
			this->minus_bt->Name = L"minus_bt";
			this->minus_bt->Size = System::Drawing::Size(94, 48);
			this->minus_bt->TabIndex = 9;
			this->minus_bt->Text = L"-";
			this->minus_bt->UseVisualStyleBackColor = false;
			// 
			// plus_bt
			// 
			this->plus_bt->BackColor = System::Drawing::SystemColors::ControlDark;
			this->plus_bt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->plus_bt->Location = System::Drawing::Point(425, 468);
			this->plus_bt->Name = L"plus_bt";
			this->plus_bt->Size = System::Drawing::Size(94, 48);
			this->plus_bt->TabIndex = 8;
			this->plus_bt->Text = L"+";
			this->plus_bt->UseVisualStyleBackColor = false;
			// 
			// NOT_bt
			// 
			this->NOT_bt->BackColor = System::Drawing::SystemColors::ControlDark;
			this->NOT_bt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NOT_bt->Location = System::Drawing::Point(770, 536);
			this->NOT_bt->Name = L"NOT_bt";
			this->NOT_bt->Size = System::Drawing::Size(94, 48);
			this->NOT_bt->TabIndex = 15;
			this->NOT_bt->Text = L"NOT";
			this->NOT_bt->UseVisualStyleBackColor = false;
			// 
			// XOR_bt
			// 
			this->XOR_bt->BackColor = System::Drawing::SystemColors::ControlDark;
			this->XOR_bt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->XOR_bt->Location = System::Drawing::Point(657, 536);
			this->XOR_bt->Name = L"XOR_bt";
			this->XOR_bt->Size = System::Drawing::Size(94, 48);
			this->XOR_bt->TabIndex = 14;
			this->XOR_bt->Text = L"XOR";
			this->XOR_bt->UseVisualStyleBackColor = false;
			// 
			// OR_bt
			// 
			this->OR_bt->BackColor = System::Drawing::SystemColors::ControlDark;
			this->OR_bt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->OR_bt->Location = System::Drawing::Point(541, 536);
			this->OR_bt->Name = L"OR_bt";
			this->OR_bt->Size = System::Drawing::Size(94, 48);
			this->OR_bt->TabIndex = 13;
			this->OR_bt->Text = L"OR";
			this->OR_bt->UseVisualStyleBackColor = false;
			// 
			// AND_bt
			// 
			this->AND_bt->BackColor = System::Drawing::SystemColors::ControlDark;
			this->AND_bt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AND_bt->Location = System::Drawing::Point(425, 536);
			this->AND_bt->Name = L"AND_bt";
			this->AND_bt->Size = System::Drawing::Size(94, 48);
			this->AND_bt->TabIndex = 12;
			this->AND_bt->Text = L"AND";
			this->AND_bt->UseVisualStyleBackColor = false;
			this->AND_bt->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// TranslateRight_bt
			// 
			this->TranslateRight_bt->BackColor = System::Drawing::SystemColors::ControlDark;
			this->TranslateRight_bt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TranslateRight_bt->Location = System::Drawing::Point(770, 606);
			this->TranslateRight_bt->Name = L"TranslateRight_bt";
			this->TranslateRight_bt->Size = System::Drawing::Size(94, 48);
			this->TranslateRight_bt->TabIndex = 17;
			this->TranslateRight_bt->Text = L">>";
			this->TranslateRight_bt->UseVisualStyleBackColor = false;
			this->TranslateRight_bt->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// TranslateLeft_bt
			// 
			this->TranslateLeft_bt->BackColor = System::Drawing::SystemColors::ControlDark;
			this->TranslateLeft_bt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TranslateLeft_bt->Location = System::Drawing::Point(657, 606);
			this->TranslateLeft_bt->Name = L"TranslateLeft_bt";
			this->TranslateLeft_bt->Size = System::Drawing::Size(94, 48);
			this->TranslateLeft_bt->TabIndex = 16;
			this->TranslateLeft_bt->Text = L"<<";
			this->TranslateLeft_bt->UseVisualStyleBackColor = false;
			this->TranslateLeft_bt->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// button_hex
			// 
			this->button_hex->BackColor = System::Drawing::SystemColors::ControlDark;
			this->button_hex->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_hex->Location = System::Drawing::Point(84, 275);
			this->button_hex->Name = L"button_hex";
			this->button_hex->Size = System::Drawing::Size(94, 34);
			this->button_hex->TabIndex = 20;
			this->button_hex->Text = L"HEX";
			this->button_hex->UseVisualStyleBackColor = false;
			this->button_hex->Click += gcnew System::EventHandler(this, &MyForm::button_hex_Click);
			// 
			// button_dec
			// 
			this->button_dec->BackColor = System::Drawing::SystemColors::ControlDark;
			this->button_dec->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_dec->Location = System::Drawing::Point(84, 135);
			this->button_dec->Name = L"button_dec";
			this->button_dec->Size = System::Drawing::Size(94, 34);
			this->button_dec->TabIndex = 18;
			this->button_dec->Text = L"DEC";
			this->button_dec->UseVisualStyleBackColor = false;
			this->button_dec->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
			// 
			// button_bin
			// 
			this->button_bin->BackColor = System::Drawing::SystemColors::ControlDark;
			this->button_bin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_bin->Location = System::Drawing::Point(84, 207);
			this->button_bin->Name = L"button_bin";
			this->button_bin->Size = System::Drawing::Size(94, 34);
			this->button_bin->TabIndex = 21;
			this->button_bin->Text = L"BIN";
			this->button_bin->UseVisualStyleBackColor = false;
			this->button_bin->Click += gcnew System::EventHandler(this, &MyForm::button_bin_Click);
			// 
			// label2
			// 
			this->label2->CausesValidation = false;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(285, 477);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(125, 30);
			this->label2->TabIndex = 23;
			this->label2->Text = L"OPERATION";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(790, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(74, 23);
			this->button1->TabIndex = 24;
			this->button1->Text = L"Reset";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_2);
			// 
			// HEX_bt
			// 
			this->HEX_bt->BackColor = System::Drawing::SystemColors::ControlDark;
			this->HEX_bt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->HEX_bt->Location = System::Drawing::Point(657, 396);
			this->HEX_bt->Name = L"HEX_bt";
			this->HEX_bt->Size = System::Drawing::Size(94, 48);
			this->HEX_bt->TabIndex = 6;
			this->HEX_bt->Text = L"HEX";
			this->HEX_bt->UseVisualStyleBackColor = false;
			this->HEX_bt->Click += gcnew System::EventHandler(this, &MyForm::HEX_bt_Click);
			// 
			// BIN_bt
			// 
			this->BIN_bt->BackColor = System::Drawing::SystemColors::ControlDark;
			this->BIN_bt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BIN_bt->Location = System::Drawing::Point(541, 396);
			this->BIN_bt->Name = L"BIN_bt";
			this->BIN_bt->Size = System::Drawing::Size(94, 48);
			this->BIN_bt->TabIndex = 5;
			this->BIN_bt->Text = L"BIN";
			this->BIN_bt->UseVisualStyleBackColor = false;
			this->BIN_bt->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// DEC_bt
			// 
			this->DEC_bt->BackColor = System::Drawing::SystemColors::ControlDark;
			this->DEC_bt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DEC_bt->Location = System::Drawing::Point(425, 396);
			this->DEC_bt->Name = L"DEC_bt";
			this->DEC_bt->Size = System::Drawing::Size(94, 48);
			this->DEC_bt->TabIndex = 4;
			this->DEC_bt->Text = L"DEC";
			this->DEC_bt->UseVisualStyleBackColor = false;
			this->DEC_bt->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->CausesValidation = false;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(11, 202);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(68, 30);
			this->label1->TabIndex = 22;
			this->label1->Text = L"MODE";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// binoutput_tb
			// 
			this->binoutput_tb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->binoutput_tb->Location = System::Drawing::Point(185, 207);
			this->binoutput_tb->Multiline = true;
			this->binoutput_tb->Name = L"binoutput_tb";
			this->binoutput_tb->Size = System::Drawing::Size(679, 30);
			this->binoutput_tb->TabIndex = 25;
			this->binoutput_tb->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// hexoutput_tb
			// 
			this->hexoutput_tb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->hexoutput_tb->Location = System::Drawing::Point(185, 275);
			this->hexoutput_tb->Multiline = true;
			this->hexoutput_tb->Name = L"hexoutput_tb";
			this->hexoutput_tb->Size = System::Drawing::Size(679, 30);
			this->hexoutput_tb->TabIndex = 26;
			this->hexoutput_tb->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->ClientSize = System::Drawing::Size(876, 666);
			this->Controls->Add(this->hexoutput_tb);
			this->Controls->Add(this->binoutput_tb);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button_bin);
			this->Controls->Add(this->button_hex);
			this->Controls->Add(this->button_dec);
			this->Controls->Add(this->TranslateRight_bt);
			this->Controls->Add(this->TranslateLeft_bt);
			this->Controls->Add(this->NOT_bt);
			this->Controls->Add(this->XOR_bt);
			this->Controls->Add(this->OR_bt);
			this->Controls->Add(this->AND_bt);
			this->Controls->Add(this->div_bt);
			this->Controls->Add(this->multi_bt);
			this->Controls->Add(this->minus_bt);
			this->Controls->Add(this->plus_bt);
			this->Controls->Add(this->RESULT_bt);
			this->Controls->Add(this->HEX_bt);
			this->Controls->Add(this->BIN_bt);
			this->Controls->Add(this->DEC_bt);
			this->Controls->Add(this->decoutput_tb);
			this->Controls->Add(this->INTPUT_lb);
			this->Controls->Add(this->Input_tb);
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		String^ mode = L"";


	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (mode == L"")
		{
			Input_tb->Text = "";
			MessageBox::Show("Please choose your mode first!!");	
		}
		else if (mode == "DEC")
		{
			//Dec->Dec
			decoutput_tb->Text = Input_tb->Text;
			//Dec->Bin
			//System::String^ clrString = Input_tb->Text;
			//std::string value = marshal_as<std::string>(clrString);
			//BigInt a = ScanfBigInt(value);
			//char *cstr = new char[value.length() + 1];
			//strcpy(cstr, value.c_str());
			//binoutput_tb->Text = gcnew String(PrintBigInt(BinToDec(CharToBool(cstr))).c_str());
			////Dec->Hex
			//hexoutput_tb->Text = gcnew String(PrintBigInt(HexToDec(cstr)).c_str());
		}
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (mode == "DEC")
	{
		decoutput_tb->Text = Input_tb->Text;
}
	else if (mode == "BIN")
	{
		//Source convert String^ to String:https://stackoverflow.com/questions/946813/c-cli-converting-from-systemstring-to-stdstring
		System::String^ clrString = Input_tb->Text;	
		std::string value = marshal_as<std::string>(clrString);
		BigInt a = ScanfBigInt(value);
		char *cstr = new char[value.length() + 1];
		strcpy(cstr, value.c_str());
		decoutput_tb->Text = gcnew String(PrintBigInt(BinToDec(CharToBool(cstr))).c_str());
	}
	else
	{
		System::String^ clrString = Input_tb->Text;
		std::string value = marshal_as<std::string>(clrString);
		BigInt a = ScanfBigInt(value);
		char *cstr = new char[value.length() + 1];
		strcpy(cstr, value.c_str());
		decoutput_tb->Text = gcnew String(PrintBigInt(HexToDec(cstr)).c_str());
	}

}
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) 
{
	if (mode == "DEC")
	{
		System::String^ clrString = Input_tb->Text;
		std::string value = marshal_as<std::string>(clrString);
		BigInt a = ScanfBigInt(value);
		char *cstr = new char[value.length() + 1];
		strcpy(cstr, value.c_str());
		decoutput_tb->Text = gcnew String(BoolToChar(DecToBin(a)).c_str());
	}
	else if (mode == "BIN")


	{
		decoutput_tb->Text = Input_tb->Text;
		//Source convert String^ to String:https://stackoverflow.com/questions/946813/c-cli-converting-from-systemstring-to-stdstring
		
	}
	else
	{
		System::String^ clrString = Input_tb->Text;
		std::string value = marshal_as<std::string>(clrString);
		BigInt a = ScanfBigInt(value);
		char *cstr = new char[value.length() + 1];
		strcpy(cstr, value.c_str());
		decoutput_tb->Text = gcnew String(BoolToChar(DecToBin(HexToDec(cstr))).c_str());
	}
}
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) 
{

}
private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button16_Click(System::Object^  sender, System::EventArgs^  e)
{
	button_dec->BackColor = Color::Red;
	button_bin->BackColor = Color::DarkGray;
	button_hex->BackColor = Color::DarkGray;
	mode = "DEC";
	MessageBox::Show("Input");
}
private: System::Void button_bin_Click(System::Object^  sender, System::EventArgs^  e) {
	button_bin->BackColor = Color::Red;
	button_dec->BackColor = Color::DarkGray;
	button_hex->BackColor = Color::DarkGray;
	mode = "BIN";

	MessageBox::Show("Input");

}
private: System::Void button_hex_Click(System::Object^  sender, System::EventArgs^  e) {
	button_hex->BackColor = Color::Red;
	button_bin->BackColor = Color::DarkGray;
	button_dec->BackColor = Color::DarkGray;
	mode = "HEX";
	MessageBox::Show("Input");

}
private: System::Void button1_Click_2(System::Object^  sender, System::EventArgs^  e) 
{
	Input_tb->Text = "";
	decoutput_tb->Text = "";
	button_dec->BackColor = Color::DarkGray;
	button_bin->BackColor = Color::DarkGray;
	button_hex->BackColor = Color::DarkGray;

}
private: System::Void HEX_bt_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (mode == "DEC")
	{
		System::String^ clrString = Input_tb->Text;
		std::string value = marshal_as<std::string>(clrString);
		BigInt a = ScanfBigInt(value);
		char *cstr = new char[value.length() + 1];
		strcpy(cstr, value.c_str());
		decoutput_tb->Text = gcnew String(PrintBigInt(HexToDec(cstr)).c_str());
	}
	else if (mode == "BIN")
	{
		System::String^ clrString = Input_tb->Text;
		std::string value = marshal_as<std::string>(clrString);
		BigInt a = ScanfBigInt(value);
		char *cstr = new char[value.length() + 1];
		strcpy(cstr, value.c_str());
		decoutput_tb->Text = gcnew String(BoolToChar(DecToBin(HexToDec(cstr))).c_str());
		//Source convert String^ to String:https://stackoverflow.com/questions/946813/c-cli-converting-from-systemstring-to-stdstring

	}
	else
	{
		decoutput_tb->Text = Input_tb->Text;
	
	}
}
private: System::Void decoutput_tb_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}

