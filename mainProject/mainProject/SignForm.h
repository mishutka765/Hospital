#pragma once
#include "Include.h"
#include "LogForm.h"
#include "Algorithms.h"
#include "Data.h"
#include "Exceptions.h"

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
			//������������ 
			progressBarPasswordStrength->Value = 1;

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
	private: System::Windows::Forms::ProgressBar^ progressBarPasswordStrength;
	private: System::Windows::Forms::Label^ passwordStrong;

		   // ��������� �������� �������
	private: System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();

	protected:

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
			this->progressBarPasswordStrength = (gcnew System::Windows::Forms::ProgressBar());
			this->passwordStrong = (gcnew System::Windows::Forms::Label());
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
			this->lEnterData->Text = L"������ ��� ���� � ���� �����:";
			// 
			// lPassw
			// 
			this->lPassw->AutoSize = true;
			this->lPassw->Location = System::Drawing::Point(21, 323);
			this->lPassw->Name = L"lPassw";
			this->lPassw->Size = System::Drawing::Size(111, 13);
			this->lPassw->TabIndex = 4;
			this->lPassw->Text = L"���������� ������:";
			// 
			// CbShow
			// 
			this->CbShow->AutoSize = true;
			this->CbShow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7));
			this->CbShow->Location = System::Drawing::Point(271, 323);
			this->CbShow->Name = L"CbShow";
			this->CbShow->Size = System::Drawing::Size(109, 17);
			this->CbShow->TabIndex = 15;
			this->CbShow->Text = L"�������� ������";
			this->CbShow->UseVisualStyleBackColor = true;
			this->CbShow->CheckedChanged += gcnew System::EventHandler(this, &SignForm::CbShow_CheckedChanged);
			this->CbShow->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &SignForm::CbShow_MouseMove);
			// 
			// mTbPassw
			// 
			this->mTbPassw->Location = System::Drawing::Point(141, 321);
			this->mTbPassw->Name = L"mTbPassw";
			this->mTbPassw->PasswordChar = '*';
			this->mTbPassw->Size = System::Drawing::Size(108, 20);
			this->mTbPassw->TabIndex = 14;
			this->mTbPassw->MaskInputRejected += gcnew System::Windows::Forms::MaskInputRejectedEventHandler(this, &SignForm::mTbPassw_MaskInputRejected);
			this->mTbPassw->TextChanged += gcnew System::EventHandler(this, &SignForm::mTbPassw_TextChanged_1);
			// 
			// TbPatr
			// 
			this->TbPatr->ForeColor = System::Drawing::Color::Black;
			this->TbPatr->Location = System::Drawing::Point(380, 210);
			this->TbPatr->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->TbPatr->Name = L"TbPatr";
			this->TbPatr->Size = System::Drawing::Size(108, 20);
			this->TbPatr->TabIndex = 21;
			// 
			// TbSurn
			// 
			this->TbSurn->Location = System::Drawing::Point(260, 210);
			this->TbSurn->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->TbSurn->Name = L"TbSurn";
			this->TbSurn->Size = System::Drawing::Size(108, 20);
			this->TbSurn->TabIndex = 20;
			// 
			// TbTel
			// 
			this->TbTel->Location = System::Drawing::Point(141, 250);
			this->TbTel->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->TbTel->Name = L"TbTel";
			this->TbTel->Size = System::Drawing::Size(108, 20);
			this->TbTel->TabIndex = 19;
			// 
			// TbName
			// 
			this->TbName->Location = System::Drawing::Point(141, 210);
			this->TbName->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->TbName->Name = L"TbName";
			this->TbName->Size = System::Drawing::Size(108, 20);
			this->TbName->TabIndex = 18;
			// 
			// lTel
			// 
			this->lTel->AutoSize = true;
			this->lTel->Location = System::Drawing::Point(75, 253);
			this->lTel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lTel->Name = L"lTel";
			this->lTel->Size = System::Drawing::Size(55, 13);
			this->lTel->TabIndex = 17;
			this->lTel->Text = L"�������:";
			// 
			// lFio
			// 
			this->lFio->AutoSize = true;
			this->lFio->Location = System::Drawing::Point(104, 212);
			this->lFio->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lFio->Name = L"lFio";
			this->lFio->Size = System::Drawing::Size(28, 13);
			this->lFio->TabIndex = 16;
			this->lFio->Text = L"ϲ�:";
			// 
			// BSign
			// 
			this->BSign->Location = System::Drawing::Point(190, 397);
			this->BSign->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->BSign->Name = L"BSign";
			this->BSign->Size = System::Drawing::Size(140, 30);
			this->BSign->TabIndex = 22;
			this->BSign->Text = L"��������������";
			this->BSign->UseVisualStyleBackColor = true;
			this->BSign->Click += gcnew System::EventHandler(this, &SignForm::BSign_Click);
			// 
			// dateBith
			// 
			this->dateBith->Location = System::Drawing::Point(141, 285);
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
			this->lBirthDate->Text = L"���� ����������:";
			// 
			// lPatr
			// 
			this->lPatr->AutoSize = true;
			this->lPatr->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6));
			this->lPatr->Location = System::Drawing::Point(408, 232);
			this->lPatr->Name = L"lPatr";
			this->lPatr->Size = System::Drawing::Size(47, 9);
			this->lPatr->TabIndex = 29;
			this->lPatr->Text = L"��-�������";
			// 
			// lSurname
			// 
			this->lSurname->AutoSize = true;
			this->lSurname->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6));
			this->lSurname->Location = System::Drawing::Point(292, 232);
			this->lSurname->Name = L"lSurname";
			this->lSurname->Size = System::Drawing::Size(38, 9);
			this->lSurname->TabIndex = 28;
			this->lSurname->Text = L"�������";
			// 
			// lName
			// 
			this->lName->AutoSize = true;
			this->lName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lName->Location = System::Drawing::Point(188, 232);
			this->lName->Name = L"lName";
			this->lName->Size = System::Drawing::Size(19, 9);
			this->lName->TabIndex = 27;
			this->lName->Text = L"��\'�";
			// 
			// linfo
			// 
			this->linfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->linfo->AutoSize = true;
			this->linfo->Location = System::Drawing::Point(12, 465);
			this->linfo->Name = L"linfo";
			this->linfo->Size = System::Drawing::Size(256, 13);
			this->linfo->TabIndex = 30;
			this->linfo->Text = L"��� �������� ���������� �� ���� - ��������� F1";
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
			// progressBarPasswordStrength
			// 
			this->progressBarPasswordStrength->Location = System::Drawing::Point(141, 355);
			this->progressBarPasswordStrength->Maximum = 3;
			this->progressBarPasswordStrength->Name = L"progressBarPasswordStrength";
			this->progressBarPasswordStrength->Size = System::Drawing::Size(108, 12);
			this->progressBarPasswordStrength->TabIndex = 32;
			this->progressBarPasswordStrength->Value = 1;
			// 
			// passwordStrong
			// 
			this->passwordStrong->AutoSize = true;
			this->passwordStrong->Location = System::Drawing::Point(66, 354);
			this->passwordStrong->Name = L"passwordStrong";
			this->passwordStrong->Size = System::Drawing::Size(66, 13);
			this->passwordStrong->TabIndex = 33;
			this->passwordStrong->Text = L"����������:";
			// 
			// SignForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(534, 487);
			this->Controls->Add(this->passwordStrong);
			this->Controls->Add(this->progressBarPasswordStrength);
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
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"SignForm";
			this->Text = L"��������������";
			this->Load += gcnew System::EventHandler(this, &SignForm::SignForm_Load);
			this->HelpRequested += gcnew System::Windows::Forms::HelpEventHandler(this, &SignForm::SignForm_HelpRequested);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void BSign_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ errorMsg;

		std::vector<User> UsVec1 = read_usertable();

		User obj;
		Hash pass;
		std::vector<User> users;

		System::String^ TbUser = TbName->Text;
		System::String^ TbSurname = TbSurn->Text;
		System::String^ TbPat = TbPatr->Text;
		System::String^ TbTelephone = TbTel->Text;
		System::DateTime^ TbBirthday = dateBith->Value;
		System::String^ TbPassword = mTbPassw->Text;

		std::string Name = ParseToStringorSTDSTRING(TbUser);
		std::string Surname = ParseToStringorSTDSTRING(TbSurname);
		std::string MiddleName = ParseToStringorSTDSTRING(TbPat);
		std::string Telephone = ParseToStringorSTDSTRING(TbTelephone);
		std::tm Birthday = ParseToTm(TbBirthday);
		std::string Password = ParseToStringorSTDSTRING(TbPassword);
		int strengthLevel = CheckPasswordStrength(Password);

		// ���������� ��'��� ����������� ������ �� ���������� ��.

		if (Name == "" || Surname == "" || MiddleName == "") {
			MessageBox::Show("��������� ����!", "������� ���������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (Password == "") {
			std::cerr << "Sign up error: Empty password." << std::endl;
			MessageBox::Show("������ ������!", "������� ���������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		obj.userName = Name;
		obj.userSurname = Surname;
		obj.userMiddleName = MiddleName;


				// �������� ������ ��������
		try
		{
			if (Telephone != "")
			{ 
				Telephone = standardizePhoneNumberUA(Telephone);

				for (const User& user : UsVec1)
				{
					// ����������, �� ������� ����� ��������
					if (Telephone == standardizePhoneNumberUA(user.userPhone))
					{
						throw Exceptions::PhoneNumberExistsException();
						break;
					}
				}
			}	
			else {
				throw Exceptions::PhoneFormatException();
			}	
		}
		catch (const Exceptions::PhoneFormatException& ex)
		{
			errorMsg = gcnew System::String(ex.what());
			MessageBox::Show(errorMsg, "������� ���������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		catch (const Exceptions::PhoneNumberExistsException& ex)
		{
			errorMsg = gcnew System::String(ex.what());
			MessageBox::Show(errorMsg, "������� ���������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		catch (const std::exception& ex)
		{
			std::cerr << "Sign up phone error: " << ex.what() << std::endl;
			errorMsg = gcnew System::String(ex.what());
			MessageBox::Show(errorMsg, "������� ���������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		obj.userPhone = Telephone;
		obj.userBirthDate = Birthday;
		if (strengthLevel <= 1)
		{
			// �������� ��������� ����������� � ������� �������� ������.
			MessageBox::Show("������� ������, ������ ������!", "��������� ������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		obj.userPassword = pass.getHash(Password, 6); // ���������� ��� ������.

		try
		{
			obj.userAge = AgeCalculator(obj, Birthday); // ���������� �� �����������.
			std::cerr << obj.userAge << std::endl;
		}
		catch (const Exceptions::AgeCalculationException& ex)
		{
			errorMsg = gcnew System::String(ex.what());
			MessageBox::Show(errorMsg, "������� ���������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		catch (const std::exception& ex)
		{
			std::cerr << "Sign up age error: " << ex.what() << std::endl;
			errorMsg = gcnew System::String(ex.what());
			MessageBox::Show(errorMsg, "������� ���������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		
		obj.write_userrow(); // �������� ���� �����������.

		System::String^ Pass = ParseToStringorSTDSTRING(Password);

		LogForm^ logForm = gcnew LogForm(obj, Pass, Telephone);

		this->Hide();

		logForm->Show();
	}

	private: System::Void dateBith_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		toolTip1->SetToolTip(dateBith, "������ ��� ���� ���� ���������� ");
	}

	private: System::Void CbShow_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		toolTip1->SetToolTip(CbShow, "³������ ��������, ���� ������ �������� �������� ������ ");
	}
	private: System::Void SignForm_HelpRequested(System::Object^ sender, System::Windows::Forms::HelpEventArgs^ hlpevent) {
		// ����� �������� ��� ��������� ��� ����� SignForm
		String^ helpText = "�� ����� ���������� ��� ��������� ������ �����������. �� ������� ������ ��� ������� ���� �� ��������� ������ ��� ��������� ������.\n";
		helpText += "��� ������ ��� ��'�, �������, ��-�������, ������� �� ���� ����������, �������������� �������� ���� �����.\n";
		helpText += "���������� ������ � ������ ���� � ���� '������'. ������ ��������������� ������ '*' ��� ������� ������.\n";
		helpText += "���� ������ �������� �������� ������, �������� ������� ��� '�������� ������'.\n";
		helpText += "��������� ������ '��������������', ���� �� ���� ������� ��������.\n";

		// �������� MessageBox �� ������� ��������
		MessageBox::Show(helpText, "������", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	private: System::Void CbShow_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (CbShow->Checked) {
			mTbPassw->PasswordChar = '\0'; // �������� ������
		}
		else {
			mTbPassw->PasswordChar = '*'; // ��������� ������
		}
	}
	private: System::Void SignForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void mTbPassw_MaskInputRejected(System::Object^ sender, System::Windows::Forms::MaskInputRejectedEventArgs^ e) {
	}
		   //��� ���� ������, �� ������ ����������� ��������� ������.
	private: System::Void mTbPassw_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
		int strength = CheckPasswordStrength(ParseToStringorSTDSTRING(mTbPassw->Text));
		progressBarPasswordStrength->Value = strength; 
		switch (strength)
		{
		case 1:
			passwordStrong->Text = "�������";
			passwordStrong->ForeColor = System::Drawing::Color::Red;
			progressBarPasswordStrength->ForeColor = System::Drawing::Color::Red;
			break;
		case 2:
			passwordStrong->Text = "��������";
			passwordStrong->ForeColor = System::Drawing::Color::Orange;
			progressBarPasswordStrength->ForeColor = System::Drawing::Color::Orange;
			break;
		case 3:
			passwordStrong->Text = "�������";
			passwordStrong->ForeColor = System::Drawing::Color::Green;
			progressBarPasswordStrength->ForeColor = System::Drawing::Color::Green;
			break;
		}
	}
	};
}