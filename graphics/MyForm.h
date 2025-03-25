#pragma once

namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::TextBox^ tbExpression;
	protected:

	protected:

	private: System::Windows::Forms::Button^ bEqual;
	private: System::Windows::Forms::ListBox^ lbVectorView;
	protected:


	private: System::Windows::Forms::Button^ bAddPol;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox4;



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
			this->tbExpression = (gcnew System::Windows::Forms::TextBox());
			this->bEqual = (gcnew System::Windows::Forms::Button());
			this->lbVectorView = (gcnew System::Windows::Forms::ListBox());
			this->bAddPol = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// tbExpression
			// 
			this->tbExpression->Location = System::Drawing::Point(13, 13);
			this->tbExpression->Name = L"tbExpression";
			this->tbExpression->Size = System::Drawing::Size(406, 20);
			this->tbExpression->TabIndex = 0;
			// 
			// bEqual
			// 
			this->bEqual->Location = System::Drawing::Point(433, 12);
			this->bEqual->Name = L"bEqual";
			this->bEqual->Size = System::Drawing::Size(100, 20);
			this->bEqual->TabIndex = 1;
			this->bEqual->Text = L"=";
			this->bEqual->UseVisualStyleBackColor = true;
			this->bEqual->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// lbVectorView
			// 
			this->lbVectorView->FormattingEnabled = true;
			this->lbVectorView->Location = System::Drawing::Point(13, 57);
			this->lbVectorView->Name = L"lbVectorView";
			this->lbVectorView->Size = System::Drawing::Size(520, 303);
			this->lbVectorView->TabIndex = 2;
			// 
			// bAddPol
			// 
			this->bAddPol->Location = System::Drawing::Point(433, 382);
			this->bAddPol->Name = L"bAddPol";
			this->bAddPol->Size = System::Drawing::Size(100, 50);
			this->bAddPol->TabIndex = 3;
			this->bAddPol->Text = L"Добавить моном";
			this->bAddPol->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(260, 403);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(53, 29);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L"1";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(332, 396);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(15, 21);
			this->textBox2->TabIndex = 5;
			this->textBox2->Text = L"0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(319, 412);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(16, 20);
			this->label1->TabIndex = 6;
			this->label1->Text = L"x";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(353, 412);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(16, 20);
			this->label2->TabIndex = 8;
			this->label2->Text = L"y";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(366, 396);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(15, 21);
			this->textBox3->TabIndex = 7;
			this->textBox3->Text = L"0";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(387, 412);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(17, 20);
			this->label3->TabIndex = 10;
			this->label3->Text = L"z";
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(400, 396);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(15, 21);
			this->textBox4->TabIndex = 9;
			this->textBox4->Text = L"0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(545, 444);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->bAddPol);
			this->Controls->Add(this->lbVectorView);
			this->Controls->Add(this->bEqual);
			this->Controls->Add(this->tbExpression);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		throw - 2531;
	}

	System::Void parse(System::String^ inp) {
		throw - 2531;
	}
};
}
