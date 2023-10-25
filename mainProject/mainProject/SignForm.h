#pragma once
#include "LogForm.h" 

namespace mainProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SignForm
	/// </summary>
	public ref class SignForm : public System::Windows::Forms::Form
	{
	public:
		SignForm(void)
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
		~SignForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lEnterData;

	private: System::Windows::Forms::Label^ lPassw;

	protected:

	protected:


	protected:









	private: System::Windows::Forms::CheckBox^ CbShow;
	private: System::Windows::Forms::MaskedTextBox^ mTbPassw;
	private: System::Windows::Forms::TextBox^ TbPatr;
	private: System::Windows::Forms::TextBox^ TbSurn;
	private: System::Windows::Forms::TextBox^ TbTel;
	private: System::Windows::Forms::TextBox^ TbName;
	private: System::Windows::Forms::Label^ lTel;

	private: System::Windows::Forms::Label^ lFio;

	private: System::Windows::Forms::Button^ BSign;
	private: System::Windows::Forms::DateTimePicker^ dateBith;
	private: System::Windows::Forms::Label^ lBirthDate;

	private: System::Windows::Forms::Label^ lPatr;
	private: System::Windows::Forms::Label^ lSurname;
	private: System::Windows::Forms::Label^ lName;
	private: System::Windows::Forms::Label^ linfo;
	private: System::Windows::Forms::PictureBox^ picBox;










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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SignForm::typeid));
			this->lEnterData = (gcnew System::Windows::Forms::Label());
			this->lPassw = (gcnew System::Windows::Forms::Label());
			this->CbShow = (gcnew System::Windows::Forms::CheckBox());
			this->mTbPassw = (gcnew System::Windows::Forms::MaskedTextBox());
			this->TbPatr = (gcnew System::Windows::Forms::TextBox());
			this->TbSurn = (gcnew System::Windows::Forms::TextBox());
			this->TbTel = (gcnew System::Windows::Forms::TextBox());
			this->TbName = (gcnew System::Windows::Forms::TextBox());
			this->lTel = (gcnew System::Windows::Forms::Label());
			this->lFio = (gcnew System::Windows::Forms::Label());
			this->BSign = (gcnew System::Windows::Forms::Button());
			this->dateBith = (gcnew System::Windows::Forms::DateTimePicker());
			this->lBirthDate = (gcnew System::Windows::Forms::Label());
			this->lPatr = (gcnew System::Windows::Forms::Label());
			this->lSurname = (gcnew System::Windows::Forms::Label());
			this->lName = (gcnew System::Windows::Forms::Label());
			this->linfo = (gcnew System::Windows::Forms::Label());
			this->picBox = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBox))->BeginInit();
			this->SuspendLayout();
			// 
			// lEnterData
			// 
			this->lEnterData->AutoSize = true;
			this->lEnterData->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->lEnterData->Location = System::Drawing::Point(165, 145);
			this->lEnterData->Name = L"lEnterData";
			this->lEnterData->Size = System::Drawing::Size(226, 18);
			this->lEnterData->TabIndex = 0;
			this->lEnterData->Text = L"Введіть свої дані в поля нижче:";
			// 
			// lPassw
			// 
			this->lPassw->AutoSize = true;
			this->lPassw->Location = System::Drawing::Point(34, 323);
			this->lPassw->Name = L"lPassw";
			this->lPassw->Size = System::Drawing::Size(111, 13);
			this->lPassw->TabIndex = 4;
			this->lPassw->Text = L"Придумайте пароль:";
			// 
			// CbShow
			// 
			this->CbShow->AutoSize = true;
			this->CbShow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7));
			this->CbShow->Location = System::Drawing::Point(271, 323);
			this->CbShow->Name = L"CbShow";
			this->CbShow->Size = System::Drawing::Size(109, 17);
			this->CbShow->TabIndex = 15;
			this->CbShow->Text = L"показати пароль";
			this->CbShow->UseVisualStyleBackColor = true;
			this->CbShow->CheckedChanged += gcnew System::EventHandler(this, &SignForm::CbShow_CheckedChanged);
			this->CbShow->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &SignForm::CbShow_MouseMove);
			// 
			// mTbPassw
			// 
			this->mTbPassw->Location = System::Drawing::Point(155, 320);
			this->mTbPassw->Name = L"mTbPassw";
			this->mTbPassw->PasswordChar = '*';
			this->mTbPassw->Size = System::Drawing::Size(108, 20);
			this->mTbPassw->TabIndex = 14;
			this->mTbPassw->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &SignForm::mTbPassw_MouseMove);
			// 
			// TbPatr
			// 
			this->TbPatr->ForeColor = System::Drawing::Color::Black;
			this->TbPatr->Location = System::Drawing::Point(393, 210);
			this->TbPatr->Margin = System::Windows::Forms::Padding(2);
			this->TbPatr->Name = L"TbPatr";
			this->TbPatr->Size = System::Drawing::Size(108, 20);
			this->TbPatr->TabIndex = 21;
			this->TbPatr->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &SignForm::TbPatr_MouseMove);
			// 
			// TbSurn
			// 
			this->TbSurn->Location = System::Drawing::Point(272, 210);
			this->TbSurn->Margin = System::Windows::Forms::Padding(2);
			this->TbSurn->Name = L"TbSurn";
			this->TbSurn->Size = System::Drawing::Size(108, 20);
			this->TbSurn->TabIndex = 20;
			this->TbSurn->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &SignForm::TbSurn_MouseMove);
			// 
			// TbTel
			// 
			this->TbTel->Location = System::Drawing::Point(155, 250);
			this->TbTel->Margin = System::Windows::Forms::Padding(2);
			this->TbTel->Name = L"TbTel";
			this->TbTel->Size = System::Drawing::Size(108, 20);
			this->TbTel->TabIndex = 19;
			this->TbTel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &SignForm::TbTel_MouseMove);
			// 
			// TbName
			// 
			this->TbName->Location = System::Drawing::Point(154, 210);
			this->TbName->Margin = System::Windows::Forms::Padding(2);
			this->TbName->Name = L"TbName";
			this->TbName->Size = System::Drawing::Size(108, 20);
			this->TbName->TabIndex = 18;
			this->TbName->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &SignForm::TbName_MouseMove);
			// 
			// lTel
			// 
			this->lTel->AutoSize = true;
			this->lTel->Location = System::Drawing::Point(78, 253);
			this->lTel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lTel->Name = L"lTel";
			this->lTel->Size = System::Drawing::Size(55, 13);
			this->lTel->TabIndex = 17;
			this->lTel->Text = L"Телефон:";
			// 
			// lFio
			// 
			this->lFio->AutoSize = true;
			this->lFio->Location = System::Drawing::Point(78, 213);
			this->lFio->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lFio->Name = L"lFio";
			this->lFio->Size = System::Drawing::Size(28, 13);
			this->lFio->TabIndex = 16;
			this->lFio->Text = L"ПІБ:";
			// 
			// BSign
			// 
			this->BSign->Location = System::Drawing::Point(196, 387);
			this->BSign->Margin = System::Windows::Forms::Padding(2);
			this->BSign->Name = L"BSign";
			this->BSign->Size = System::Drawing::Size(140, 30);
			this->BSign->TabIndex = 22;
			this->BSign->Text = L"Зареєструватись";
			this->BSign->UseVisualStyleBackColor = true;
			this->BSign->Click += gcnew System::EventHandler(this, &SignForm::BSign_Click);
			this->BSign->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &SignForm::BSign_MouseMove);
			// 
			// dateBith
			// 
			this->dateBith->Location = System::Drawing::Point(155, 285);
			this->dateBith->Name = L"dateBith";
			this->dateBith->Size = System::Drawing::Size(200, 20);
			this->dateBith->TabIndex = 26;
			this->dateBith->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &SignForm::dateBith_MouseMove);
			// 
			// lBirthDate
			// 
			this->lBirthDate->AutoSize = true;
			this->lBirthDate->Location = System::Drawing::Point(34, 285);
			this->lBirthDate->Name = L"lBirthDate";
			this->lBirthDate->Size = System::Drawing::Size(101, 13);
			this->lBirthDate->TabIndex = 25;
			this->lBirthDate->Text = L"Дата народження:";
			// 
			// lPatr
			// 
			this->lPatr->AutoSize = true;
			this->lPatr->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6));
			this->lPatr->Location = System::Drawing::Point(417, 232);
			this->lPatr->Name = L"lPatr";
			this->lPatr->Size = System::Drawing::Size(47, 9);
			this->lPatr->TabIndex = 29;
			this->lPatr->Text = L"по-батькові";
			// 
			// lSurname
			// 
			this->lSurname->AutoSize = true;
			this->lSurname->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6));
			this->lSurname->Location = System::Drawing::Point(298, 232);
			this->lSurname->Name = L"lSurname";
			this->lSurname->Size = System::Drawing::Size(38, 9);
			this->lSurname->TabIndex = 28;
			this->lSurname->Text = L"прізвище";
			// 
			// lName
			// 
			this->lName->AutoSize = true;
			this->lName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lName->Location = System::Drawing::Point(201, 232);
			this->lName->Name = L"lName";
			this->lName->Size = System::Drawing::Size(19, 9);
			this->lName->TabIndex = 27;
			this->lName->Text = L"ім\'я";
			// 
			// linfo
			// 
			this->linfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->linfo->AutoSize = true;
			this->linfo->Location = System::Drawing::Point(12, 489);
			this->linfo->Name = L"linfo";
			this->linfo->Size = System::Drawing::Size(256, 13);
			this->linfo->TabIndex = 30;
			this->linfo->Text = L"Для отриманя інформації по формі - натисніть F1";
			// 
			// picBox
			// 
			this->picBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picBox.Image")));
			this->picBox->Location = System::Drawing::Point(141, -30);
			this->picBox->Name = L"picBox";
			this->picBox->Size = System::Drawing::Size(270, 193);
			this->picBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->picBox->TabIndex = 31;
			this->picBox->TabStop = false;
			// 
			// SignForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(534, 511);
			this->Controls->Add(this->linfo);
			this->Controls->Add(this->lPatr);
			this->Controls->Add(this->lSurname);
			this->Controls->Add(this->lName);
			this->Controls->Add(this->dateBith);
			this->Controls->Add(this->lBirthDate);
			this->Controls->Add(this->BSign);
			this->Controls->Add(this->TbPatr);
			this->Controls->Add(this->TbSurn);
			this->Controls->Add(this->TbTel);
			this->Controls->Add(this->TbName);
			this->Controls->Add(this->lTel);
			this->Controls->Add(this->lFio);
			this->Controls->Add(this->CbShow);
			this->Controls->Add(this->mTbPassw);
			this->Controls->Add(this->lPassw);
			this->Controls->Add(this->lEnterData);
			this->Controls->Add(this->picBox);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"SignForm";
			this->Text = L"SignForm";
			this->HelpRequested += gcnew System::Windows::Forms::HelpEventHandler(this, &SignForm::SignForm_HelpRequested);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void BSign_Click(System::Object^ sender, System::EventArgs^ e) {


	// Створюємо новий екземпляр форми LogForm
	LogForm^ logForm = gcnew LogForm();

	// Ховаємо поточну форму 
	this->Hide();

	// Показуємо нову форму LogForm
	logForm->Show();
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

private: System::Void dateBith_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();
	toolTip1->SetToolTip(dateBith, "Введіть тут свою дату народження ");
}

private: System::Void CbShow_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();
	toolTip1->SetToolTip(CbShow, "Відмітьте галочкою, якщо хочете побачити введений пароль ");
}

private: System::Void mTbPassw_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();
	toolTip1->SetToolTip(mTbPassw, "Придумайте та введіть тут свій пароль ");
}
private: System::Void BSign_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();
	toolTip1->SetToolTip(BSign, "Якщо все введено коректно, то натисніть цю кнопку ");
}
private: System::Void SignForm_HelpRequested(System::Object^ sender, System::Windows::Forms::HelpEventArgs^ hlpevent) {

	// Текст допомоги або пояснення для форми SignForm
	String^ helpText = "Ця форма призначена для реєстрації нового користувача. Ви повинні ввести свої особисті дані та придумати пароль для облікового запису.\n";
	helpText += "Щоб ввести своє ім'я, прізвище, по-батькові, телефон та дату народження, використовуйте відповідні поля вводу.\n";
	helpText += "Придумайте пароль і введіть його в поле 'Пароль'. Можете використовувати символ '*' для захисту пароля.\n";
	helpText += "Якщо бажаєте побачити введений пароль, поставте галочку біля 'показати пароль'.\n";
	helpText += "Натисніть кнопку 'Зареєструватись', якщо всі дані введені коректно.\n";

	// Показати MessageBox із текстом допомоги
	MessageBox::Show(helpText, "Довідка", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
private: System::Void CbShow_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (CbShow->Checked) {
		mTbPassw->PasswordChar = '\0'; // Показати пароль
	}
	else {
		mTbPassw->PasswordChar = '*'; // Приховати пароль
	}
}
};
}
