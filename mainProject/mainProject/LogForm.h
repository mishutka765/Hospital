#pragma once
#include "Include.h"
#include "Data.h"
#include "Algorithms.h"
#include "NewRecordForm.h"


namespace mainProject {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LogForm
	/// </summary>
	///
	//Дані користувача який авторизувався
	static User us;
	//Його телефон
	static std::string ph;
	public ref class LogForm : public System::Windows::Forms::Form
	{
	private:
		//Айді
		int UserID;
	private: System::Windows::Forms::Button^ bCancle;

	private: System::Windows::Forms::TextBox^ TbOld;

	public:
		System::String^ pass;

		LogForm(User& user, String^ password, std::string phone)
		{
			InitializeComponent();
			ph = phone;
			UserID = 0;
			us = user;
			pass = password;

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LogForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MonthCalendar^ monthCalendar;
	private: System::Windows::Forms::ComboBox^ CbLast;

	private: System::Windows::Forms::Label^ lFio;

	private: System::Windows::Forms::Label^ lTel;
	private: System::Windows::Forms::Label^ lAge;

	private: System::Windows::Forms::CheckBox^ CbShow;
	private: System::Windows::Forms::MaskedTextBox^ mTbPassw;
	private: System::Windows::Forms::Label^ lPassw;

	private: System::Windows::Forms::Label^ lLast;
	private: System::Windows::Forms::Label^ lFuture;
	private: System::Windows::Forms::ComboBox^ CbFuture;
	private: System::Windows::Forms::Label^ lShowData;


	private: System::Windows::Forms::TextBox^ TbPatr;
	private: System::Windows::Forms::TextBox^ TbSurn;
	private: System::Windows::Forms::TextBox^ TbTel;
	private: System::Windows::Forms::TextBox^ TbName;








	private: System::Windows::Forms::Button^ bSingUp;

	private: System::Windows::Forms::GroupBox^ gBAppoin;

	private: System::Windows::Forms::Label^ lPatr;
	private: System::Windows::Forms::Label^ lSurname;
	private: System::Windows::Forms::Label^ lName;
	private: System::Windows::Forms::Label^ linfo;
	private: System::Windows::Forms::PictureBox^ piсBox;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LogForm::typeid));
			this->monthCalendar = (gcnew System::Windows::Forms::MonthCalendar());
			this->CbLast = (gcnew System::Windows::Forms::ComboBox());
			this->lFio = (gcnew System::Windows::Forms::Label());
			this->lTel = (gcnew System::Windows::Forms::Label());
			this->lAge = (gcnew System::Windows::Forms::Label());
			this->CbShow = (gcnew System::Windows::Forms::CheckBox());
			this->mTbPassw = (gcnew System::Windows::Forms::MaskedTextBox());
			this->lPassw = (gcnew System::Windows::Forms::Label());
			this->lLast = (gcnew System::Windows::Forms::Label());
			this->lFuture = (gcnew System::Windows::Forms::Label());
			this->CbFuture = (gcnew System::Windows::Forms::ComboBox());
			this->lShowData = (gcnew System::Windows::Forms::Label());
			this->TbPatr = (gcnew System::Windows::Forms::TextBox());
			this->TbSurn = (gcnew System::Windows::Forms::TextBox());
			this->TbTel = (gcnew System::Windows::Forms::TextBox());
			this->TbName = (gcnew System::Windows::Forms::TextBox());
			this->bSingUp = (gcnew System::Windows::Forms::Button());
			this->gBAppoin = (gcnew System::Windows::Forms::GroupBox());
			this->lPatr = (gcnew System::Windows::Forms::Label());
			this->lSurname = (gcnew System::Windows::Forms::Label());
			this->lName = (gcnew System::Windows::Forms::Label());
			this->linfo = (gcnew System::Windows::Forms::Label());
			this->piсBox = (gcnew System::Windows::Forms::PictureBox());
			this->bCancle = (gcnew System::Windows::Forms::Button());
			this->TbOld = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->piсBox))->BeginInit();
			this->SuspendLayout();
			// 
			// monthCalendar
			// 
			this->monthCalendar->Location = System::Drawing::Point(533, 46);
			this->monthCalendar->Name = L"monthCalendar";
			this->monthCalendar->TabIndex = 0;
			this->monthCalendar->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &LogForm::monthCalendar_MouseMove);
			// 
			// CbLast
			// 
			this->CbLast->FormattingEnabled = true;
			this->CbLast->Location = System::Drawing::Point(533, 405);
			this->CbLast->Name = L"CbLast";
			this->CbLast->Size = System::Drawing::Size(164, 21);
			this->CbLast->TabIndex = 1;
			this->CbLast->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &LogForm::CbLast_MouseMove);
			// 
			// lFio
			// 
			this->lFio->AutoSize = true;
			this->lFio->Location = System::Drawing::Point(23, 211);
			this->lFio->Name = L"lFio";
			this->lFio->Size = System::Drawing::Size(34, 13);
			this->lFio->TabIndex = 3;
			this->lFio->Text = L"ПІБ : ";
			// 
			// lTel
			// 
			this->lTel->AutoSize = true;
			this->lTel->Location = System::Drawing::Point(23, 248);
			this->lTel->Name = L"lTel";
			this->lTel->Size = System::Drawing::Size(61, 13);
			this->lTel->TabIndex = 4;
			this->lTel->Text = L"Телефон : ";
			// 
			// lAge
			// 
			this->lAge->AutoSize = true;
			this->lAge->Location = System::Drawing::Point(23, 287);
			this->lAge->Name = L"lAge";
			this->lAge->Size = System::Drawing::Size(28, 13);
			this->lAge->TabIndex = 5;
			this->lAge->Text = L"Вік :";
			// 
			// CbShow
			// 
			this->CbShow->AutoSize = true;
			this->CbShow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7));
			this->CbShow->Location = System::Drawing::Point(133, 346);
			this->CbShow->Name = L"CbShow";
			this->CbShow->Size = System::Drawing::Size(109, 17);
			this->CbShow->TabIndex = 18;
			this->CbShow->Text = L"показати пароль";
			this->CbShow->UseVisualStyleBackColor = true;
			this->CbShow->CheckedChanged += gcnew System::EventHandler(this, &LogForm::CbShow_CheckedChanged);
			// 
			// mTbPassw
			// 
			this->mTbPassw->Location = System::Drawing::Point(133, 323);
			this->mTbPassw->Name = L"mTbPassw";
			this->mTbPassw->PasswordChar = '*';
			this->mTbPassw->Size = System::Drawing::Size(108, 20);
			this->mTbPassw->TabIndex = 17;
			this->mTbPassw->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &LogForm::mTbPassw_MouseMove);
			// 
			// lPassw
			// 
			this->lPassw->AutoSize = true;
			this->lPassw->Location = System::Drawing::Point(23, 323);
			this->lPassw->Name = L"lPassw";
			this->lPassw->Size = System::Drawing::Size(70, 13);
			this->lPassw->TabIndex = 16;
			this->lPassw->Text = L"Ваш пароль:";
			// 
			// lLast
			// 
			this->lLast->AutoSize = true;
			this->lLast->Location = System::Drawing::Point(530, 377);
			this->lLast->Name = L"lLast";
			this->lLast->Size = System::Drawing::Size(44, 13);
			this->lLast->TabIndex = 19;
			this->lLast->Text = L"Минулі:";
			// 
			// lFuture
			// 
			this->lFuture->AutoSize = true;
			this->lFuture->Location = System::Drawing::Point(530, 294);
			this->lFuture->Name = L"lFuture";
			this->lFuture->Size = System::Drawing::Size(55, 13);
			this->lFuture->TabIndex = 21;
			this->lFuture->Text = L"Майбутні:";
			// 
			// CbFuture
			// 
			this->CbFuture->FormattingEnabled = true;
			this->CbFuture->Location = System::Drawing::Point(533, 322);
			this->CbFuture->Name = L"CbFuture";
			this->CbFuture->Size = System::Drawing::Size(164, 21);
			this->CbFuture->TabIndex = 20;
			this->CbFuture->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &LogForm::CbFuture_MouseMove);
			// 
			// lShowData
			// 
			this->lShowData->AutoSize = true;
			this->lShowData->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->lShowData->Location = System::Drawing::Point(275, 69);
			this->lShowData->Name = L"lShowData";
			this->lShowData->Size = System::Drawing::Size(84, 18);
			this->lShowData->TabIndex = 22;
			this->lShowData->Text = L"Ваші дані : ";
			this->lShowData->Click += gcnew System::EventHandler(this, &LogForm::lShowData_Click);
			// 
			// TbPatr
			// 
			this->TbPatr->ForeColor = System::Drawing::Color::Black;
			this->TbPatr->Location = System::Drawing::Point(375, 208);
			this->TbPatr->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->TbPatr->Name = L"TbPatr";
			this->TbPatr->Size = System::Drawing::Size(108, 20);
			this->TbPatr->TabIndex = 28;
			// 
			// TbSurn
			// 
			this->TbSurn->Location = System::Drawing::Point(251, 208);
			this->TbSurn->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->TbSurn->Name = L"TbSurn";
			this->TbSurn->Size = System::Drawing::Size(108, 20);
			this->TbSurn->TabIndex = 27;
			// 
			// TbTel
			// 
			this->TbTel->Location = System::Drawing::Point(134, 248);
			this->TbTel->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->TbTel->Name = L"TbTel";
			this->TbTel->Size = System::Drawing::Size(108, 20);
			this->TbTel->TabIndex = 26;
			this->TbTel->TextChanged += gcnew System::EventHandler(this, &LogForm::TbTel_TextChanged);
			// 
			// TbName
			// 
			this->TbName->Location = System::Drawing::Point(133, 208);
			this->TbName->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->TbName->Name = L"TbName";
			this->TbName->Size = System::Drawing::Size(108, 20);
			this->TbName->TabIndex = 25;
			this->TbName->TextChanged += gcnew System::EventHandler(this, &LogForm::TbName_TextChanged);
			// 
			// bSingUp
			// 
			this->bSingUp->Location = System::Drawing::Point(26, 450);
			this->bSingUp->Name = L"bSingUp";
			this->bSingUp->Size = System::Drawing::Size(188, 59);
			this->bSingUp->TabIndex = 34;
			this->bSingUp->Text = L"Записатися до лікаря";
			this->bSingUp->UseVisualStyleBackColor = true;
			this->bSingUp->Click += gcnew System::EventHandler(this, &LogForm::bSingUp_Click);
			this->bSingUp->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &LogForm::bSingUp_MouseMove);
			// 
			// gBAppoin
			// 
			this->gBAppoin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->gBAppoin->Location = System::Drawing::Point(527, 248);
			this->gBAppoin->Name = L"gBAppoin";
			this->gBAppoin->Size = System::Drawing::Size(195, 210);
			this->gBAppoin->TabIndex = 35;
			this->gBAppoin->TabStop = false;
			this->gBAppoin->Text = L"Ваші записи: ";
			// 
			// lPatr
			// 
			this->lPatr->AutoSize = true;
			this->lPatr->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6));
			this->lPatr->Location = System::Drawing::Point(402, 230);
			this->lPatr->Name = L"lPatr";
			this->lPatr->Size = System::Drawing::Size(47, 9);
			this->lPatr->TabIndex = 39;
			this->lPatr->Text = L"по-батькові";
			// 
			// lSurname
			// 
			this->lSurname->AutoSize = true;
			this->lSurname->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6));
			this->lSurname->Location = System::Drawing::Point(283, 230);
			this->lSurname->Name = L"lSurname";
			this->lSurname->Size = System::Drawing::Size(38, 9);
			this->lSurname->TabIndex = 38;
			this->lSurname->Text = L"прізвище";
			// 
			// lName
			// 
			this->lName->AutoSize = true;
			this->lName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lName->Location = System::Drawing::Point(186, 230);
			this->lName->Name = L"lName";
			this->lName->Size = System::Drawing::Size(19, 9);
			this->lName->TabIndex = 37;
			this->lName->Text = L"ім\'я";
			// 
			// linfo
			// 
			this->linfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->linfo->AutoSize = true;
			this->linfo->Location = System::Drawing::Point(9, 768);
			this->linfo->Name = L"linfo";
			this->linfo->Size = System::Drawing::Size(256, 13);
			this->linfo->TabIndex = 40;
			this->linfo->Text = L"Для отриманя інформації по формі - натисніть F1";
			// 
			// piсBox
			// 
			this->piсBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"piсBox.Image")));
			this->piсBox->Location = System::Drawing::Point(-1, 12);
			this->piсBox->Name = L"piсBox";
			this->piсBox->Size = System::Drawing::Size(181, 117);
			this->piсBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->piсBox->TabIndex = 41;
			this->piсBox->TabStop = false;
			// 
			// bCancle
			// 
			this->bCancle->Location = System::Drawing::Point(527, 475);
			this->bCancle->Name = L"bCancle";
			this->bCancle->Size = System::Drawing::Size(151, 34);
			this->bCancle->TabIndex = 42;
			this->bCancle->Text = L"Відмовитися";
			this->bCancle->UseVisualStyleBackColor = true;
			this->bCancle->Click += gcnew System::EventHandler(this, &LogForm::bCancle_Click);
			// 
			// TbOld
			// 
			this->TbOld->Location = System::Drawing::Point(133, 287);
			this->TbOld->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->TbOld->Name = L"TbOld";
			this->TbOld->Size = System::Drawing::Size(23, 20);
			this->TbOld->TabIndex = 44;
			this->TbOld->TextChanged += gcnew System::EventHandler(this, &LogForm::TbOld_TextChanged);
			// 
			// LogForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(734, 535);
			this->Controls->Add(this->TbOld);
			this->Controls->Add(this->bCancle);
			this->Controls->Add(this->piсBox);
			this->Controls->Add(this->linfo);
			this->Controls->Add(this->lPatr);
			this->Controls->Add(this->lSurname);
			this->Controls->Add(this->lName);
			this->Controls->Add(this->bSingUp);
			this->Controls->Add(this->TbPatr);
			this->Controls->Add(this->TbSurn);
			this->Controls->Add(this->TbTel);
			this->Controls->Add(this->TbName);
			this->Controls->Add(this->lShowData);
			this->Controls->Add(this->lFuture);
			this->Controls->Add(this->CbFuture);
			this->Controls->Add(this->lLast);
			this->Controls->Add(this->CbShow);
			this->Controls->Add(this->mTbPassw);
			this->Controls->Add(this->lPassw);
			this->Controls->Add(this->lAge);
			this->Controls->Add(this->lTel);
			this->Controls->Add(this->lFio);
			this->Controls->Add(this->CbLast);
			this->Controls->Add(this->monthCalendar);
			this->Controls->Add(this->gBAppoin);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"LogForm";
			this->Text = L"Головна сторінка";
			this->Load += gcnew System::EventHandler(this, &LogForm::LogForm_Load);
			this->HelpRequested += gcnew System::Windows::Forms::HelpEventHandler(this, &LogForm::LogForm_HelpRequested);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->piсBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void bSingUp_Click(System::Object^ sender, System::EventArgs^ e) {
		NewRecordForm^ newRecordForm = gcnew NewRecordForm(TbTel->Text, CbFuture);

		newRecordForm->Show();
	}
	private: System::Void CbShow_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (CbShow->Checked) {
			mTbPassw->PasswordChar = '\0'; // Показати пароль
		}
		else {
			mTbPassw->PasswordChar = '*'; // Приховати пароль
		}
	}

		   System::Windows::Forms::ToolTip^ toolTip1;

	private: System::Void CbFuture_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();
		toolTip1->SetToolTip(CbFuture, "Натисніть щоб переглянути свої майбутні записи до лікаря");
	}

	private: System::Void CbLast_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();
		toolTip1->SetToolTip(CbLast, "Натисніть щоб переглянути свої минулі записи до лікаря");
	}
	private: System::Void  bSingUp_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();
		toolTip1->SetToolTip(bSingUp, "Натисніть щоб записатися до лікаря");
	}
	private: System::Void monthCalendar_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();
		toolTip1->SetToolTip(monthCalendar, "Календар для відображення поточного дня");
	}

	private: System::Void LogForm_HelpRequested(System::Object^ sender, System::Windows::Forms::HelpEventArgs^ hlpevent) {
		// Текст допомоги або пояснення для форми LogForm
		String^ helpText = "Ця форма дозволяє користувачам переглядати свої дані та дані сімейного лікаря, записуватися до лікаря та переглядати історію записів.\n";
		helpText += "Щоб переглянути свої майбутні записи, виберіть відповідний пункт у списку 'Майбутні'.\n";
		helpText += "Щоб переглянути свої минулі записи, виберіть відповідний пункт у списку 'Минулі'.\n";
		helpText += "Щоб записатися до лікаря, натисніть кнопку 'Записатися до лікаря'.\n";
		helpText += "Ви також можете переглядати інформацію за допомогою календаря та ввести свої особисті дані.\n";

		// Показати MessageBox із текстом допомоги
		MessageBox::Show(helpText, "Довідка", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	private: System::Void mTbPassw_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();
		toolTip1->SetToolTip(mTbPassw, "Введіть тут свій пароль ");
	}

	private: System::Void LogForm_Load(System::Object^ sender, System::EventArgs^ e) {
		std::vector<Doctor> doctors = read_doctortable();
		std::vector<Visit> visits = read_visittable();
		std::vector<User> users = read_usertable();
		//Чистка визитов
		System::DateTime currentDate = System::DateTime::Now;
		//Ініціалізація UserID.
		for (const User& User : users)
		{
			if (ph == User.userPhone)
			{
				UserID = User.userID;
			}
		}

		System::String^ name = ParseToStringorSTDSTRING(us.userName);
		System::String^ surname = ParseToStringorSTDSTRING(us.userSurname);
		System::String^ middlename = ParseToStringorSTDSTRING(us.userMiddleName);
		System::String^ phone = ParseToStringorSTDSTRING(us.userPhone);

		TbName->Text = name;
		TbSurn->Text = surname;
		TbPatr->Text = middlename;
		TbTel->Text = phone;
		TbOld->Text = us.userAge.ToString();

		mTbPassw->Text = pass;

		System::Collections::Generic::List<System::String^>^ visitList = gcnew System::Collections::Generic::List<System::String^>();
		System::Collections::Generic::List<System::String^>^ visitListM = gcnew System::Collections::Generic::List<System::String^>();
		//Ініціалізація ComboBox майбутні записи
		for (Visit& Visit : visits)
		{
			System::DateTime visitDateTime = ConvertTmToDateTime(Visit.visitDate);
				//Якщо теперішній час більше ніж коли ми записувалия, то ми опоздали.
				if (visitDateTime < currentDate)
				{
					Visit.visitStatus = false;
					Visit.update_visitStatus();
				}
				//Якщо 1 то це майбутній запис, + перевірка айді користувача
			if (Visit.visitStatus == 1 && Visit.clientID == UserID)
			{
				System::DateTime visitTime(Visit.visitDate.tm_year, Visit.visitDate.tm_mon, Visit.visitDate.tm_mday, Visit.visitTime.tm_hour, Visit.visitTime.tm_min, Visit.visitTime.tm_sec);
				System::String^ dateTimeString = visitTime.ToString("yyyy-MM-dd HH:mm:ss");
				std::string spec;
				for (Doctor& Doctor : doctors)
				{
					if (Doctor.docID == Visit.doctorID)
					{
						spec = Doctor.docSpeciality;
					}
				}
				System::String^ fullInfoString = gcnew System::String(dateTimeString + " - " + ParseToStringorSTDSTRING(spec));
				visitList->Add(fullInfoString);
				//Сортируємо
				sortVisits(visitList);
			}
			//Минулі завантаження в комбо бокс
			if (Visit.visitStatus == 0 && Visit.clientID == UserID)
			{
				System::DateTime visitTime(Visit.visitDate.tm_year, Visit.visitDate.tm_mon, Visit.visitDate.tm_mday, Visit.visitTime.tm_hour, Visit.visitTime.tm_min, Visit.visitTime.tm_sec);
				System::String^ dateTimeString = visitTime.ToString("yyyy-MM-dd HH:mm:ss");
				std::string spec;
				for (Doctor& Doctor : doctors)
				{
					if (Doctor.docID == Visit.doctorID)
					{
						spec = Doctor.docSpeciality;
					}
				}
				System::String^ fullInfoString = gcnew System::String(dateTimeString + " - " + ParseToStringorSTDSTRING(spec));
				visitListM->Add(fullInfoString);
				//Сортируємо
				sortVisits(visitListM);
			}
		}
		for each (System::String ^ visitString in visitListM)
		{
			CbLast->Items->Add(visitString);
		}
		//Додаємо на комбо бокс візити
		for each (System::String ^ visitString in visitList)
		{
			CbFuture->Items->Add(visitString);
		}
	}
	private: System::Void gBFamDoc_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void TbName_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void lShowData_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void TbTel_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void dateBith_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void bCancle_Click(System::Object^ sender, System::EventArgs^ e) {
		Visit obj;
		std::vector<Visit> visits = read_visittable();
		std::vector<User> users = read_usertable();
		std::vector<Doctor> doctors = read_doctortable();

		System::Object^ selectedItem = CbFuture->SelectedItem;

		System::String^ selectedItemString = dynamic_cast<System::String^>(selectedItem);
		if (selectedItemString != nullptr)
		{
			int year, month, day, hour, minute, second;
			if (sscanf_s(msclr::interop::marshal_as<std::string>(selectedItemString).c_str(),
				"%d-%d-%d %d:%d:%d",
				//Ріжимо дату
				&year, &month, &day, &hour, &minute, &second) == 6)
			{

				for (Visit& visit : visits) 
				{
					if (visit.clientID == UserID&&
						visit.visitDate.tm_year == year&&
						visit.visitDate.tm_mon == month&&
						visit.visitDate.tm_mday == day &&
						visit.visitTime.tm_hour == hour &&
						visit.visitTime.tm_min == minute)
					{
						//Отмєна
						visit.visitStatus = false;
						visit.update_visitStatus();
						break; 
					}
				}
			}
		}
		CbFuture->Items->Clear();
		CbLast->Items->Clear();
		visits = read_visittable();
		System::Collections::Generic::List<System::String^>^ visitList = gcnew System::Collections::Generic::List<System::String^>();
		System::Collections::Generic::List<System::String^>^ visitListM = gcnew System::Collections::Generic::List<System::String^>();

		for (Visit& Visit : visits)
		{
			System::DateTime visitDateTime = ConvertTmToDateTime(Visit.visitDate);

			//Якщо 1 то це майбутній запис, + перевірка айді користувача
			if (Visit.visitStatus == 1 && Visit.clientID == UserID)
			{
				System::DateTime visitTime(Visit.visitDate.tm_year, Visit.visitDate.tm_mon, Visit.visitDate.tm_mday, Visit.visitTime.tm_hour, Visit.visitTime.tm_min, Visit.visitTime.tm_sec);
				System::String^ dateTimeString = visitTime.ToString("yyyy-MM-dd HH:mm:ss");
				std::string spec;
				for (Doctor& Doctor : doctors)
				{
					if (Doctor.docID == Visit.doctorID)
					{
						spec = Doctor.docSpeciality;
					}
				}
				System::String^ fullInfoString = gcnew System::String(dateTimeString + " - " + ParseToStringorSTDSTRING(spec));
				visitList->Add(fullInfoString);
				//Сортируємо
				sortVisits(visitList);
			}
			//Минулі завантаження в комбо бокс
			if (Visit.visitStatus == 0 && Visit.clientID == UserID)
			{
				System::DateTime visitTime(Visit.visitDate.tm_year, Visit.visitDate.tm_mon, Visit.visitDate.tm_mday, Visit.visitTime.tm_hour, Visit.visitTime.tm_min, Visit.visitTime.tm_sec);
				System::String^ dateTimeString = visitTime.ToString("yyyy-MM-dd HH:mm:ss");
				std::string spec;
				for (Doctor& Doctor : doctors)
				{
					if (Doctor.docID == Visit.doctorID)
					{
						spec = Doctor.docSpeciality;
					}
				}
				System::String^ fullInfoString = gcnew System::String(dateTimeString + " - " + ParseToStringorSTDSTRING(spec));
				visitListM->Add(fullInfoString);
				//Сортируємо
				sortVisits(visitListM);
			}
		}
		for each (System::String ^ visitString in visitListM)
		{
			CbLast->Items->Add(visitString);
		}
		//Додаємо на комбо бокс візити
		for each (System::String ^ visitString in visitList)
		{
			CbFuture->Items->Add(visitString);
		}

	}
	private: System::Void TbOld_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
