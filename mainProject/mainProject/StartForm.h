#pragma once
#include "Include.h"
#include "LogForm.h"
#include "SignForm.h"
#include "AboutAppForm.h"
#include "Data.h"
#include "Algorithms.h"
#include "Exceptions.h"


namespace mainProject {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for StartForm
	/// </summary>
	///

	public ref class StartForm : public System::Windows::Forms::Form
	{
	public:
		StartForm(void)
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
		~StartForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Blog;
	private: System::Windows::Forms::Button^ BSign;

	private: System::Windows::Forms::Label^ Ltel;
	private: System::Windows::Forms::Label^ Lpassw;
	private: System::Windows::Forms::Label^ lAbo;

		   // Створення загальної підказки
	private: System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();

	protected:

	protected:

	protected:

	private: System::Windows::Forms::TextBox^ TbTel;

	private: System::Windows::Forms::Label^ lWelcome;
	private: System::Windows::Forms::MaskedTextBox^ mTbPassw;
	private: System::Windows::Forms::CheckBox^ CbShow;

	private: System::Windows::Forms::Button^ bQuestion;
	private: System::Windows::Forms::Label^ linfo;
	private: System::Windows::Forms::PictureBox^ picBox;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(StartForm::typeid));
			this->Blog = (gcnew System::Windows::Forms::Button());
			this->BSign = (gcnew System::Windows::Forms::Button());
			this->Ltel = (gcnew System::Windows::Forms::Label());
			this->Lpassw = (gcnew System::Windows::Forms::Label());
			this->lAbo = (gcnew System::Windows::Forms::Label());
			this->TbTel = (gcnew System::Windows::Forms::TextBox());
			this->lWelcome = (gcnew System::Windows::Forms::Label());
			this->mTbPassw = (gcnew System::Windows::Forms::MaskedTextBox());
			this->CbShow = (gcnew System::Windows::Forms::CheckBox());
			this->bQuestion = (gcnew System::Windows::Forms::Button());
			this->linfo = (gcnew System::Windows::Forms::Label());
			this->picBox = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBox))->BeginInit();
			this->SuspendLayout();
			// 
			// Blog
			// 
			this->Blog->Location = System::Drawing::Point(270, 392);
			this->Blog->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Blog->Name = L"Blog";
			this->Blog->Size = System::Drawing::Size(187, 37);
			this->Blog->TabIndex = 0;
			this->Blog->Text = L"Увійти";
			this->Blog->UseVisualStyleBackColor = true;
			this->Blog->Click += gcnew System::EventHandler(this, &StartForm::Blog_Click);
			// 
			// BSign
			// 
			this->BSign->Location = System::Drawing::Point(270, 471);
			this->BSign->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->BSign->Name = L"BSign";
			this->BSign->Size = System::Drawing::Size(187, 37);
			this->BSign->TabIndex = 1;
			this->BSign->Text = L"Зареєструватись";
			this->BSign->UseVisualStyleBackColor = true;
			this->BSign->Click += gcnew System::EventHandler(this, &StartForm::BSign_Click);
			// 
			// Ltel
			// 
			this->Ltel->AutoSize = true;
			this->Ltel->Location = System::Drawing::Point(205, 281);
			this->Ltel->Name = L"Ltel";
			this->Ltel->Size = System::Drawing::Size(70, 16);
			this->Ltel->TabIndex = 3;
			this->Ltel->Text = L"Телефон:";
			// 
			// Lpassw
			// 
			this->Lpassw->AutoSize = true;
			this->Lpassw->Location = System::Drawing::Point(216, 332);
			this->Lpassw->Name = L"Lpassw";
			this->Lpassw->Size = System::Drawing::Size(59, 16);
			this->Lpassw->TabIndex = 4;
			this->Lpassw->Text = L"Пароль:";
			// 
			// lAbo
			// 
			this->lAbo->AutoSize = true;
			this->lAbo->Location = System::Drawing::Point(345, 441);
			this->lAbo->Name = L"lAbo";
			this->lAbo->Size = System::Drawing::Size(31, 16);
			this->lAbo->TabIndex = 5;
			this->lAbo->Text = L"або";
			// 
			// TbTel
			// 
			this->TbTel->Location = System::Drawing::Point(296, 278);
			this->TbTel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->TbTel->Name = L"TbTel";
			this->TbTel->Size = System::Drawing::Size(143, 22);
			this->TbTel->TabIndex = 7;
			this->TbTel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &StartForm::TbTel_MouseMove);
			// 
			// lWelcome
			// 
			this->lWelcome->AutoSize = true;
			this->lWelcome->BackColor = System::Drawing::SystemColors::Control;
			this->lWelcome->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Bold));
			this->lWelcome->Location = System::Drawing::Point(262, 171);
			this->lWelcome->Name = L"lWelcome";
			this->lWelcome->Size = System::Drawing::Size(194, 48);
			this->lWelcome->TabIndex = 11;
			this->lWelcome->Text = L"Вітаємо!";
			// 
			// mTbPassw
			// 
			this->mTbPassw->Location = System::Drawing::Point(296, 329);
			this->mTbPassw->Margin = System::Windows::Forms::Padding(4);
			this->mTbPassw->Name = L"mTbPassw";
			this->mTbPassw->PasswordChar = '*';
			this->mTbPassw->Size = System::Drawing::Size(143, 22);
			this->mTbPassw->TabIndex = 12;
			this->mTbPassw->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &StartForm::mTbPassw_MouseMove);
			// 
			// CbShow
			// 
			this->CbShow->AutoSize = true;
			this->CbShow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7));
			this->CbShow->Location = System::Drawing::Point(463, 331);
			this->CbShow->Margin = System::Windows::Forms::Padding(4);
			this->CbShow->Name = L"CbShow";
			this->CbShow->Size = System::Drawing::Size(128, 19);
			this->CbShow->TabIndex = 13;
			this->CbShow->Text = L"показати пароль";
			this->CbShow->UseVisualStyleBackColor = true;
			this->CbShow->CheckedChanged += gcnew System::EventHandler(this, &StartForm::CbShow_CheckedChanged);
			this->CbShow->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &StartForm::CbShow_MouseMove);
			// 
			// bQuestion
			// 
			this->bQuestion->Font = (gcnew System::Drawing::Font(L"Snap ITC", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bQuestion->Location = System::Drawing::Point(659, 583);
			this->bQuestion->Margin = System::Windows::Forms::Padding(4);
			this->bQuestion->Name = L"bQuestion";
			this->bQuestion->Size = System::Drawing::Size(37, 31);
			this->bQuestion->TabIndex = 17;
			this->bQuestion->Text = L"❓";
			this->bQuestion->UseVisualStyleBackColor = true;
			this->bQuestion->Click += gcnew System::EventHandler(this, &StartForm::button1_Click);
			// 
			// linfo
			// 
			this->linfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->linfo->AutoSize = true;
			this->linfo->Location = System::Drawing::Point(16, 602);
			this->linfo->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->linfo->Name = L"linfo";
			this->linfo->Size = System::Drawing::Size(321, 16);
			this->linfo->TabIndex = 18;
			this->linfo->Text = L"Для отриманя інформації по формі - натисніть F1";
			// 
			// picBox
			// 
			this->picBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picBox.Image")));
			this->picBox->Location = System::Drawing::Point(185, -32);
			this->picBox->Margin = System::Windows::Forms::Padding(4);
			this->picBox->Name = L"picBox";
			this->picBox->Size = System::Drawing::Size(360, 238);
			this->picBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->picBox->TabIndex = 19;
			this->picBox->TabStop = false;
			// 
			// StartForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(712, 629);
			this->Controls->Add(this->linfo);
			this->Controls->Add(this->bQuestion);
			this->Controls->Add(this->CbShow);
			this->Controls->Add(this->mTbPassw);
			this->Controls->Add(this->lWelcome);
			this->Controls->Add(this->TbTel);
			this->Controls->Add(this->lAbo);
			this->Controls->Add(this->Lpassw);
			this->Controls->Add(this->Ltel);
			this->Controls->Add(this->BSign);
			this->Controls->Add(this->Blog);
			this->Controls->Add(this->picBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"StartForm";
			this->Text = L"Вхід";
			this->Load += gcnew System::EventHandler(this, &StartForm::StartForm_Load);
			this->HelpRequested += gcnew System::Windows::Forms::HelpEventHandler(this, &StartForm::StartForm_HelpRequested);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		//Вхід
		System::Void Blog_Click(System::Object^ sender, System::EventArgs^ e) {
			System::String^ errorMsg;
			
			//Використовуємо для хешування
			Hash obj;
			std::vector<User> UsVec1 = read_usertable();
			//Змінна для передачі в інші форми
			std::string phone;
			//То шо написав зараз
			System::String^ NowNumber = TbTel->Text;
			System::String^ NowPassword = mTbPassw->Text;
			
			//Стадартизуємо
			std::string Phone_Number = ParseToStringorSTDSTRING(NowNumber);
			try 
			{
				if (Phone_Number != "")
					Phone_Number = standardizePhoneNumberUA(Phone_Number);
				else 
					throw Exceptions::PhoneFormatException();
			}
			catch (const Exceptions::PhoneFormatException& ex)
			{
				errorMsg = gcnew System::String(ex.what());
				MessageBox::Show(errorMsg, "Помилка входу", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			catch (const std::exception& ex)
			{
				std::cerr << "Sign in error: " << ex.what() << std::endl;
				errorMsg = gcnew System::String(ex.what());
				MessageBox::Show(errorMsg, "Помилка входу", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			if (NowPassword == "") {
				std::cerr << "Sign in error: Empty password." << std::endl;
				MessageBox::Show("Введіть пароль!", "Помилка входу", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			std::string Password = ParseToStringorSTDSTRING(NowPassword);

			//Перевірочні змінні
			bool phoneNumberExists = false;
			bool passwordExists = false;
			//Хеш
			std::string hashPassword;
			hashPassword = obj.getHash(Password, 6);

			//Записуємо номера

			bool isPasswordMatching = false;

			for (const User& user : UsVec1)
			{
				// Перевіряємо, чи співпадає номер телефону
				if (Phone_Number == standardizePhoneNumberUA(user.userPhone))
				{
					phoneNumberExists = true;

					// Якщо номер телефону співпадає, перевіряємо пароль
					if (hashPassword == user.userPassword)
					{
						isPasswordMatching = true;
						int userId = user.userID;
					}

					// Потрібно вийти з циклу після знаходження співпадаючого номера телефону
					break;
				}
			}
			// Якщо користувач є в базі даних
			if (phoneNumberExists)
			{
				if (isPasswordMatching)
				{
					User user1;
					System::String^ Pass = ParseToStringorSTDSTRING(Password);
					for (const User& user : UsVec1)
					{
						if (Phone_Number == user.userPhone && hashPassword == user.userPassword)
						{
							user1 = user;

							phone = user.userPhone;
							break;
						}
					}
					LogForm^ logForm = gcnew LogForm(user1, Pass, phone);

					this->Hide();

					logForm->Show();
				}
				else
				{
					// Номер телефону існує, але пароль не співпадає
					std::cerr << "Sign up error: Wrong password" << std::endl;
					MessageBox::Show("Неправильний пароль!", "Помилка входу", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
			else
			{	// Якщо користувача немає в базі
				std::cerr << "Sign up error: User not found" << std::endl;
				MessageBox::Show("Користувача з таким номером телефону не знайдено!", "Помилка входу", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	private: System::Void BSign_Click(System::Object^ sender, System::EventArgs^ e) {
		SignForm^ signForm = gcnew SignForm();

		this->Hide();

		signForm->Show();
	}

	private: System::Void CbShow_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (CbShow->Checked) {
			mTbPassw->PasswordChar = '\0'; // Показати пароль
		}
		else {
			mTbPassw->PasswordChar = '*'; // Приховати пароль
		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		AboutAppForm^ aboutForm = gcnew AboutAppForm();;

		aboutForm->Show();
	}

	private: System::Void TbTel_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		toolTip1->SetToolTip(TbTel, "Введіть тут свій телефон ");
	}

	private: System::Void mTbPassw_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		toolTip1->SetToolTip(mTbPassw, "Введіть тут свій пароль ");
	}

	private: System::Void CbShow_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		toolTip1->SetToolTip(CbShow, "Відмітьте галочкою, якщо хочете побачити введений пароль ");
	}
	private: System::Void StartForm_HelpRequested(System::Object^ sender, System::Windows::Forms::HelpEventArgs^ hlpevent) {
		String^ helpText = "Ця форма дозволяє користувачам увійти в систему або зареєструвати новий обліковий запис.\n";
		helpText += "Щоб увійти, введіть своє ім'я, телефон та пароль і натисніть кнопку 'Увійти'.\n";
		helpText += "Щоб зареєструвати новий обліковий запис, натисніть 'Зареєструватись' і введіть необхідну інформацію.\n";
		helpText += "Пароль можна приховати або показати, позначивши відповідний чекбокс.\n";
		helpText += "Додаткова інформація доступна за допомогою кнопки з питанням.\n";

		// Показати MessageBox із текстом допомоги
		MessageBox::Show(helpText, "Довідка", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	private: System::Void StartForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
