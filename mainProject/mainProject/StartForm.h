#pragma once
#include "LogForm.h" 
#include "SignForm.h" 
#include "AboutAppForm.h"

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
	private: System::Windows::Forms::Label^ Lfio;
	private: System::Windows::Forms::Label^ Ltel;
	private: System::Windows::Forms::Label^ Lpassw;
	private: System::Windows::Forms::Label^ lAbo;
	protected:




	protected:

	protected:







	private: System::Windows::Forms::TextBox^ TbName;





	private: System::Windows::Forms::TextBox^ TbTel;

	private: System::Windows::Forms::TextBox^ TbSurn;
	private: System::Windows::Forms::TextBox^ TbPatr;
	private: System::Windows::Forms::Label^ lWelcome;
	private: System::Windows::Forms::MaskedTextBox^ mTbPassw;
	private: System::Windows::Forms::CheckBox^ CbShow;
	private: System::Windows::Forms::Label^ lName;
	private: System::Windows::Forms::Label^ lSurname;
	private: System::Windows::Forms::Label^ lPatr;
	private: System::Windows::Forms::Button^ bQuestion;
	private: System::Windows::Forms::Label^ linfo;
	private: System::Windows::Forms::PictureBox^ picBox;















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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(StartForm::typeid));
			this->Blog = (gcnew System::Windows::Forms::Button());
			this->BSign = (gcnew System::Windows::Forms::Button());
			this->Lfio = (gcnew System::Windows::Forms::Label());
			this->Ltel = (gcnew System::Windows::Forms::Label());
			this->Lpassw = (gcnew System::Windows::Forms::Label());
			this->lAbo = (gcnew System::Windows::Forms::Label());
			this->TbName = (gcnew System::Windows::Forms::TextBox());
			this->TbTel = (gcnew System::Windows::Forms::TextBox());
			this->TbSurn = (gcnew System::Windows::Forms::TextBox());
			this->TbPatr = (gcnew System::Windows::Forms::TextBox());
			this->lWelcome = (gcnew System::Windows::Forms::Label());
			this->mTbPassw = (gcnew System::Windows::Forms::MaskedTextBox());
			this->CbShow = (gcnew System::Windows::Forms::CheckBox());
			this->lName = (gcnew System::Windows::Forms::Label());
			this->lSurname = (gcnew System::Windows::Forms::Label());
			this->lPatr = (gcnew System::Windows::Forms::Label());
			this->bQuestion = (gcnew System::Windows::Forms::Button());
			this->linfo = (gcnew System::Windows::Forms::Label());
			this->picBox = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBox))->BeginInit();
			this->SuspendLayout();
			// 
			// Blog
			// 
			this->Blog->Location = System::Drawing::Point(199, 352);
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
			this->BSign->Location = System::Drawing::Point(199, 417);
			this->BSign->Margin = System::Windows::Forms::Padding(2);
			this->BSign->Name = L"BSign";
			this->BSign->Size = System::Drawing::Size(140, 30);
			this->BSign->TabIndex = 1;
			this->BSign->Text = L"Зареєструватись";
			this->BSign->UseVisualStyleBackColor = true;
			this->BSign->Click += gcnew System::EventHandler(this, &StartForm::BSign_Click);
			this->BSign->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &StartForm::BSign_MouseMove);
			// 
			// Lfio
			// 
			this->Lfio->AutoSize = true;
			this->Lfio->Location = System::Drawing::Point(65, 214);
			this->Lfio->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Lfio->Name = L"Lfio";
			this->Lfio->Size = System::Drawing::Size(28, 13);
			this->Lfio->TabIndex = 2;
			this->Lfio->Text = L"ПІБ:";
			// 
			// Ltel
			// 
			this->Ltel->AutoSize = true;
			this->Ltel->Location = System::Drawing::Point(141, 258);
			this->Ltel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Ltel->Name = L"Ltel";
			this->Ltel->Size = System::Drawing::Size(55, 13);
			this->Ltel->TabIndex = 3;
			this->Ltel->Text = L"Телефон:";
			// 
			// Lpassw
			// 
			this->Lpassw->AutoSize = true;
			this->Lpassw->Location = System::Drawing::Point(141, 300);
			this->Lpassw->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Lpassw->Name = L"Lpassw";
			this->Lpassw->Size = System::Drawing::Size(48, 13);
			this->Lpassw->TabIndex = 4;
			this->Lpassw->Text = L"Пароль:";
			// 
			// lAbo
			// 
			this->lAbo->AutoSize = true;
			this->lAbo->Location = System::Drawing::Point(261, 392);
			this->lAbo->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lAbo->Name = L"lAbo";
			this->lAbo->Size = System::Drawing::Size(25, 13);
			this->lAbo->TabIndex = 5;
			this->lAbo->Text = L"або";
			// 
			// TbName
			// 
			this->TbName->Location = System::Drawing::Point(111, 214);
			this->TbName->Margin = System::Windows::Forms::Padding(2);
			this->TbName->Name = L"TbName";
			this->TbName->Size = System::Drawing::Size(108, 20);
			this->TbName->TabIndex = 6;
			this->TbName->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &StartForm::TbName_MouseMove);
			// 
			// TbTel
			// 
			this->TbTel->Location = System::Drawing::Point(223, 258);
			this->TbTel->Margin = System::Windows::Forms::Padding(2);
			this->TbTel->Name = L"TbTel";
			this->TbTel->Size = System::Drawing::Size(108, 20);
			this->TbTel->TabIndex = 7;
			this->TbTel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &StartForm::TbTel_MouseMove);
			// 
			// TbSurn
			// 
			this->TbSurn->Location = System::Drawing::Point(223, 214);
			this->TbSurn->Margin = System::Windows::Forms::Padding(2);
			this->TbSurn->Name = L"TbSurn";
			this->TbSurn->Size = System::Drawing::Size(108, 20);
			this->TbSurn->TabIndex = 9;
			this->TbSurn->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &StartForm::TbSurn_MouseMove);
			// 
			// TbPatr
			// 
			this->TbPatr->ForeColor = System::Drawing::Color::Black;
			this->TbPatr->Location = System::Drawing::Point(337, 214);
			this->TbPatr->Margin = System::Windows::Forms::Padding(2);
			this->TbPatr->Name = L"TbPatr";
			this->TbPatr->Size = System::Drawing::Size(108, 20);
			this->TbPatr->TabIndex = 10;
			this->TbPatr->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &StartForm::TbPatr_MouseMove);
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
			this->mTbPassw->Location = System::Drawing::Point(221, 300);
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
			this->CbShow->Location = System::Drawing::Point(337, 303);
			this->CbShow->Name = L"CbShow";
			this->CbShow->Size = System::Drawing::Size(109, 17);
			this->CbShow->TabIndex = 13;
			this->CbShow->Text = L"показати пароль";
			this->CbShow->UseVisualStyleBackColor = true;
			this->CbShow->CheckedChanged += gcnew System::EventHandler(this, &StartForm::CbShow_CheckedChanged);
			this->CbShow->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &StartForm::CbShow_MouseMove);
			// 
			// lName
			// 
			this->lName->AutoSize = true;
			this->lName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lName->Location = System::Drawing::Point(151, 236);
			this->lName->Name = L"lName";
			this->lName->Size = System::Drawing::Size(19, 9);
			this->lName->TabIndex = 14;
			this->lName->Text = L"ім\'я";
			// 
			// lSurname
			// 
			this->lSurname->AutoSize = true;
			this->lSurname->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6));
			this->lSurname->Location = System::Drawing::Point(248, 236);
			this->lSurname->Name = L"lSurname";
			this->lSurname->Size = System::Drawing::Size(38, 9);
			this->lSurname->TabIndex = 15;
			this->lSurname->Text = L"прізвище";
			// 
			// lPatr
			// 
			this->lPatr->AutoSize = true;
			this->lPatr->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6));
			this->lPatr->Location = System::Drawing::Point(367, 236);
			this->lPatr->Name = L"lPatr";
			this->lPatr->Size = System::Drawing::Size(47, 9);
			this->lPatr->TabIndex = 16;
			this->lPatr->Text = L"по-батькові";
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
			this->Controls->Add(this->lPatr);
			this->Controls->Add(this->lSurname);
			this->Controls->Add(this->lName);
			this->Controls->Add(this->CbShow);
			this->Controls->Add(this->mTbPassw);
			this->Controls->Add(this->lWelcome);
			this->Controls->Add(this->TbPatr);
			this->Controls->Add(this->TbSurn);
			this->Controls->Add(this->TbTel);
			this->Controls->Add(this->TbName);
			this->Controls->Add(this->lAbo);
			this->Controls->Add(this->Lpassw);
			this->Controls->Add(this->Ltel);
			this->Controls->Add(this->Lfio);
			this->Controls->Add(this->BSign);
			this->Controls->Add(this->Blog);
			this->Controls->Add(this->picBox);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"StartForm";
			this->Text = L"StartForm";
			this->HelpRequested += gcnew System::Windows::Forms::HelpEventHandler(this, &StartForm::StartForm_HelpRequested);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Blog_Click(System::Object^ sender, System::EventArgs^ e) {

		// Створюємо новий екземпляр форми LogForm
			LogForm ^ logForm = gcnew LogForm();

		// Ховаємо поточну форму 
		this->Hide();

		// Показуємо нову форму LogForm
		logForm->Show();
	}
private: System::Void BSign_Click(System::Object^ sender, System::EventArgs^ e) {

	// Створюємо новий екземпляр форми SignForm
	SignForm^ signForm = gcnew SignForm();

	// Ховаємо поточну форму 
	this->Hide();

	// Показуємо нову форму LogForm
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

	// Створюємо новий екземпляр форми SignForm
	AboutAppForm^aboutForm = gcnew AboutAppForm();;

	// Показуємо нову форму LogForm
	aboutForm->Show();
}

	   System::Windows::Forms::ToolTip^ toolTip1;

private: System::Void TbName_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();
	toolTip1->SetToolTip(TbName, "Введіть тут своє ім'я");
}

private: System::Void TbSurn_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();
	toolTip1->SetToolTip(TbSurn, "Введіть тут своє прізвище");
}

private: System::Void TbPatr_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();
	toolTip1->SetToolTip(TbPatr, "Введіть тут своє по-батькові ");
}

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
};
}
