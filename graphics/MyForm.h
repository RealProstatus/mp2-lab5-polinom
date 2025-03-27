#pragma once

#include<msclr/marshal_cppstd.h>
#include"Model.h"

#include<stack>
#include<sstream>
#include<variant>

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
			model = new Model();
			charStack = gcnew Stack();
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
	private: System::Windows::Forms::TextBox^ tbCoeff;

	private: System::Windows::Forms::TextBox^ tbX;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ tbY;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ tbZ;




	private:
		Model* model;
		Stack^ charStack;
		System::ComponentModel::Container^ components;

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
			this->tbCoeff = (gcnew System::Windows::Forms::TextBox());
			this->tbX = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tbY = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tbZ = (gcnew System::Windows::Forms::TextBox());
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
			this->bAddPol->Click += gcnew System::EventHandler(this, &MyForm::bAddPol_Click);
			// 
			// tbCoeff
			// 
			this->tbCoeff->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbCoeff->Location = System::Drawing::Point(260, 403);
			this->tbCoeff->Name = L"tbCoeff";
			this->tbCoeff->Size = System::Drawing::Size(53, 29);
			this->tbCoeff->TabIndex = 4;
			this->tbCoeff->Text = L"1";
			this->tbCoeff->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbX
			// 
			this->tbX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbX->Location = System::Drawing::Point(332, 396);
			this->tbX->Name = L"tbX";
			this->tbX->Size = System::Drawing::Size(15, 21);
			this->tbX->TabIndex = 5;
			this->tbX->Text = L"0";
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
			// tbY
			// 
			this->tbY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbY->Location = System::Drawing::Point(366, 396);
			this->tbY->Name = L"tbY";
			this->tbY->Size = System::Drawing::Size(15, 21);
			this->tbY->TabIndex = 7;
			this->tbY->Text = L"0";
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
			// tbZ
			// 
			this->tbZ->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbZ->Location = System::Drawing::Point(400, 396);
			this->tbZ->Name = L"tbZ";
			this->tbZ->Size = System::Drawing::Size(15, 21);
			this->tbZ->TabIndex = 9;
			this->tbZ->Text = L"0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(545, 444);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tbZ);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->tbY);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tbX);
			this->Controls->Add(this->tbCoeff);
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
		calculateFromPostfix(parseToPostfix(tbExpression->Text));
		updListBox();
	}

	String^ parseToPostfix(System::String^ inp) {
		std::string out = "";

		String^ stmp = "(" + inp->Replace(" ", "") + ")"; // Удаляем пробелы
		std::string str = msclr::interop::marshal_as<std::string>(stmp);

		for (size_t i = 0; i < str.size(); i++) {
			if (str[i] == '(') {
				charStack->Push('(');
			}
			else if (isdigit(str[i]) || str[i] == '.' || str[i] == '[') {
				// Обработка чисел и [id]
				if (str[i] == '[') {
					size_t id_end = str.find(']', i);
					if (id_end == std::string::npos) {
						MessageBox::Show("Ошибка: отсутствует ]");
						return "";
					}
					out += str.substr(i, id_end - i + 1) + " ";
					i = id_end;
				}
				else {
					size_t idx;
					try {
						stod(str.substr(i), &idx);
					}
					catch (...) {
						MessageBox::Show("Неправильное число");
						return "";
					}
					out += str.substr(i, idx) + " ";
					i += idx - 1;
				}
			}
			else if (str[i] == ')') {
				try {
					while (Convert::ToChar(charStack->Peek()) != '(') {
						out += Convert::ToChar(charStack->Pop());
						out += " ";
					}
					charStack->Pop(); // Удаляем '('
				}
				catch (...) {
					MessageBox::Show("Неправильные скобки");
					return "";
				}
			}
			else if (str[i] == '+' || str[i] == '-' || str[i] == '*') {
				while (charStack->Count > 0 &&
					opPriority(str[i]) <= opPriority(Convert::ToChar(charStack->Peek()))) {
					out += Convert::ToChar(charStack->Pop());
					out += " ";
				}
				charStack->Push(str[i]);
			}
			else {
				MessageBox::Show("Недопустимый символ: " + str[i]);
				return "";
			}
		}

		// Удаляем последний пробел
		if (!out.empty() && out.back() == ' ') out.pop_back();

		return msclr::interop::marshal_as<String^>(out);
	}
	

	int opPriority(char c) {
		switch (c) {
		case '(':
			return 0;
			break;
		case '+':
		case '-':
			return 1;
			break;
		case '*':
			return 2;
			break;
		default:
			return -1;
			break;
		}
	}

	Void calculateFromPostfix(String^ inp) {
		std::string postfix = msclr::interop::marshal_as<std::string>(inp);

		using StackElement = std::variant<double, int>;
		std::stack<StackElement> stack;

		std::istringstream iss(postfix);
		std::string token;

		while (iss >> token) {
			if (token[0] == '[') {
				// Полином: извлекаем индекс
				int index = std::stoi(token.substr(1, token.size() - 2));
				stack.push(index);
			}
			else if (token == "+" || token == "-" || token == "*") {
				// Бинарная операция
				if (stack.size() < 2) MessageBox::Show("Недостаточно операндов");

				StackElement b = stack.top(); stack.pop();
				StackElement a = stack.top(); stack.pop();

				if (token == "+") {
					// Сложение полиномов
					auto p1 = std::get_if<int>(&a);
					auto p2 = std::get_if<int>(&b);
					if (p1 && p2) {
						model->addPolinom(*p1, *p2);
						stack.push(Convert::ToInt32(model->getPolinomVectorPtr().size()));
					}
					else {
						MessageBox::Show("Сложение поддерживается только для полиномов");
					}
				}
				else if (token == "-") {
					// Вычитание полиномов
					auto p1 = std::get_if<int>(&a);
					auto p2 = std::get_if<int>(&b);
					if (p1 && p2) {
						model->subPolinom(*p1, *p2);
						stack.push(Convert::ToInt32(model->getPolinomVectorPtr().size()));
					}
					else {
						MessageBox::Show("Вычитание поддерживается только для полиномов");
					}
				}
				else if (token == "*") {
					// Умножение (полином*полином или константа*полином)
					auto p1 = std::get_if<int>(&a);
					auto p2 = std::get_if<int>(&b);
					auto cnst_a = std::get_if<double>(&a);
					auto cnst_b = std::get_if<double>(&b);
					if (p1 && p2) {
						model->mulPolinom(*p1, *p2);
						stack.push(Convert::ToInt32(model->getPolinomVectorPtr().size()));
					}
					else if (cnst_a && p2) {
						model->mulPolinom(*cnst_a, *p2);
						stack.push(Convert::ToInt32(model->getPolinomVectorPtr().size()));
					}
					else if (p1 && cnst_b) {
						model->mulPolinom(*cnst_b, *p1);
						stack.push(Convert::ToInt32(model->getPolinomVectorPtr().size()));
					}
					else {
						MessageBox::Show("Неверные типы для умножения");
					}
				}
			}
			else {
				// Константа
				double cnst = std::stod(token);
				stack.push(cnst);
			}
		}
	}

private: System::Void bAddPol_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		double c = Convert::ToDouble(tbCoeff->Text);
		int x = Convert::ToInt32(tbX->Text);
		int y = Convert::ToInt32(tbY->Text);
		int z = Convert::ToInt32(tbZ->Text);

		if (c == 0) {
			model->loadBufferPolinom();
			updListBox();
			model->clrBufferPolinom();
			return;
		}
		else {
			Monom m = Monom{ c,x,y,z };
			model->addMonomToBufferPolinom(m);
			return;
		}

	}
	catch (FormatException^ e) {
		MessageBox::Show("Некорректный формат ввода!");
	}
	catch (EmptyPolinom e) {
		MessageBox::Show(msclr::interop::marshal_as<String^>(e.getMessage()));
	}
}
	Void updListBox() {
		lbVectorView->Items->Clear();

		auto ptr = model->getPolinomVectorPtr();
		for (int i = 0; i < ptr.size(); i++) {
			String^ str = "[" + (i + 1) + "]: ";
			str += msclr::interop::marshal_as<String^>(ptr[i].getString());
			lbVectorView->Items->Add(str);
		}
	}
};
}
