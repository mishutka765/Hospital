#pragma once
#include "Include.h"
#include "LogForm.h"
#include "SignForm.h"
#include "AboutAppForm.h"
#include "Data.h"
#include "Algorithms.h"

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
			this->Blog->Location = System::Drawing::Point(212, 322);
			this->Blog->Margin = System::Windows::Forms::Padding(2);
			this->Blog->Name = L"Blog";
			this->Blog->Size = System::Drawing::Size(140, 30);
			this->Blog->TabIndex = 0;
			this->Blog->Text = L"Увійти";
			this->Blog->UseVisualStyleBackColor = true;
			this->Blog->Click += gcnew System::EventHandler(this, &StartForm::Blog_Click);
			this->Blog->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &StartForm::Blog_MouseMove);
			//
			// BSign
			//
			this->BSign->Location = System::Drawing::Point(212, 387);
			this->BSign->Margin = System::Windows::Forms::Padding(2);
			this->BSign->Name = L"BSign";
			this->BSign->Size = System::Drawing::Size(140, 30);
			this->BSign->TabIndex = 1;
			this->BSign->Text = L"Зареєструватись";
			this->BSign->UseVisualStyleBackColor = true;
			this->BSign->Click += gcnew System::EventHandler(this, &StartForm::BSign_Click);
			this->BSign->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &StartForm::BSign_MouseMove);
			//
			// Ltel
			//
			this->Ltel->AutoSize = true;
			this->Ltel->Location = System::Drawing::Point(154, 228);
			this->Ltel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Ltel->Name = L"Ltel";
			this->Ltel->Size = System::Drawing::Size(55, 13);
			this->Ltel->TabIndex = 3;
			this->Ltel->Text = L"Телефон:";
			//
			// Lpassw
			//
			this->Lpassw->AutoSize = true;
			this->Lpassw->Location = System::Drawing::Point(154, 270);
			this->Lpassw->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Lpassw->Name = L"Lpassw";
			this->Lpassw->Size = System::Drawing::Size(48, 13);
			this->Lpassw->TabIndex = 4;
			this->Lpassw->Text = L"Пароль:";
			//
			// lAbo
			//
			this->lAbo->AutoSize = true;
			this->lAbo->Location = System::Drawing::Point(274, 362);
			this->lAbo->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lAbo->Name = L"lAbo";
			this->lAbo->Size = System::Drawing::Size(25, 13);
			this->lAbo->TabIndex = 5;
			this->lAbo->Text = L"або";
			//
			// TbTel
			//
			this->TbTel->Location = System::Drawing::Point(236, 228);
			this->TbTel->Margin = System::Windows::Forms::Padding(2);
			this->TbTel->Name = L"TbTel";
			this->TbTel->Size = System::Drawing::Size(108, 20);
			this->TbTel->TabIndex = 7;
			this->TbTel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &StartForm::TbTel_MouseMove);
			//
			// lWelcome
			//
			this->lWelcome->AutoSize = true;
			this->lWelcome->BackColor = System::Drawing::SystemColors::Control;
			this->lWelcome->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Bold));
			this->lWelcome->Location = System::Drawing::Point(205, 138);
			this->lWelcome->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lWelcome->Name = L"lWelcome";
			this->lWelcome->Size = System::Drawing::Size(160, 39);
			this->lWelcome->TabIndex = 11;
			this->lWelcome->Text = L"Вітаємо!";
			//
			// mTbPassw
			//
			this->mTbPassw->Location = System::Drawing::Point(234, 270);
			this->mTbPassw->Name = L"mTbPassw";
			this->mTbPassw->PasswordChar = '*';
			this->mTbPassw->Size = System::Drawing::Size(108, 20);
			this->mTbPassw->TabIndex = 12;
			this->mTbPassw->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &StartForm::mTbPassw_MouseMove);
			//
			// CbShow
			//
			this->CbShow->AutoSize = true;
			this->CbShow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7));
			this->CbShow->Location = System::Drawing::Point(350, 273);
			this->CbShow->Name = L"CbShow";
			this->CbShow->Size = System::Drawing::Size(109, 17);
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
			this->bQuestion->Location = System::Drawing::Point(494, 474);
			this->bQuestion->Name = L"bQuestion";
			this->bQuestion->Size = System::Drawing::Size(28, 25);
			this->bQuestion->TabIndex = 17;
			this->bQuestion->Text = L"❓";
			this->bQuestion->UseVisualStyleBackColor = true;
			this->bQuestion->Click += gcnew System::EventHandler(this, &StartForm::button1_Click);
			this->bQuestion->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &StartForm::bQuestion_MouseMove);
			//
			// linfo
			//
			this->linfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->linfo->AutoSize = true;
			this->linfo->Location = System::Drawing::Point(12, 489);
			this->linfo->Name = L"linfo";
			this->linfo->Size = System::Drawing::Size(256, 13);
			this->linfo->TabIndex = 18;
			this->linfo->Text = L"Для отриманя інформації по формі - натисніть F1";
			//
			// picBox
			//
			this->picBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picBox.Image")));
			this->picBox->Location = System::Drawing::Point(144, -26);
			this->picBox->Name = L"picBox";
			this->picBox->Size = System::Drawing::Size(270, 193);
			this->picBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->picBox->TabIndex = 19;
			this->picBox->TabStop = false;
			//
			// StartForm
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(534, 511);
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
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
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
			Phone_Number = standardizePhoneNumberUA(Phone_Number);
			if (Phone_Number == "Invalid Number")
			{
				MessageBox::Show("Неправильний формат номера. Введіть правильний номер.", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			std::string Password = ParseToStringorSTDSTRING(NowPassword);
			//Перевірочні змінні
			bool phoneNumberExists = false;
			bool passwordExists = false;
			//Хеш
			std::string hashPassword;
			hashPassword = obj.getHash(Password, 6);
			//Якщо користувач нічого не ввів
			//if (Phone_Number.length() == 0 || Password.length() == 0)
			//{
			//	//Треба зробити викид якогось повідомлення.
			//	Console::WriteLine("Write password or login");
			//	return;
			//}
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
					Console::WriteLine("Неправильний пароль");
					// Номер телефону існує, але пароль не співпадає
				}
			}
			// Якщо користувача немає в базі
			else
			{
				Console::WriteLine("Користувача не знайдено");
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

		   System::Windows::Forms::ToolTip^ toolTip1;

	private: System::Void TbTel_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();
		toolTip1->SetToolTip(TbTel, "Введіть тут свій телефон ");
	}

	private: System::Void mTbPassw_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();
		toolTip1->SetToolTip(mTbPassw, "Введіть тут свій пароль ");
	}

	private: System::Void CbShow_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();
		toolTip1->SetToolTip(CbShow, "Відмітьте галочкою, якщо хочете побачити введений пароль ");
	}

	private: System::Void Blog_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();
		toolTip1->SetToolTip(Blog, "Якщо всі поля заповнено коректними даними - натисніть цю кнопку і увійдіть в свій обліковий запис ");
	}

	private: System::Void BSign_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();
		toolTip1->SetToolTip(BSign, "Якщо в вас немає облікового запису - Натисніть цю кнопку щоб створити ");
	}

	private: System::Void bQuestion_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();
		toolTip1->SetToolTip(bQuestion, "Кнопка виводу інформації о додатку та розробниках ");
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
