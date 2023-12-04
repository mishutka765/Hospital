#pragma once
#include "Include.h"
#include "Data.h"
#include "Algorithms.h"

namespace mainProject {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for NewRecordForm
	/// </summary>
	public ref class NewRecordForm : public System::Windows::Forms::Form
	{
	private:
		//Телефон
		String^ receivedText;

		int DoctorId;
		int UserID;

	public:
		List<System::String^>^ selectedRegions;
		List<System::String^>^ selectedSpec;
		List<bool>^ selectedHospitalTypes;
		ComboBox^ comboBoxReference;

		NewRecordForm(String^ text, ComboBox^ comboBox)
		{
			InitializeComponent();
			comboBoxReference = comboBox;
			this->receivedText = text;
			DoctorId = 0;
			UserID = 0;
			selectedRegions = gcnew List<System::String^>();
			selectedSpec = gcnew List<System::String^>();
			selectedHospitalTypes = gcnew List<bool>();

			this->cLBplace->ItemCheck += gcnew System::Windows::Forms::ItemCheckEventHandler(this, &NewRecordForm::UpdateSelectedRegions);
			this->cLbDocType->ItemCheck += gcnew System::Windows::Forms::ItemCheckEventHandler(this, &NewRecordForm::UpdateSelectedSpec);
			this->CbState->CheckedChanged += gcnew System::EventHandler(this, &NewRecordForm::chbHospitalType_CheckedChanged);
			this->CbPrivate->CheckedChanged += gcnew System::EventHandler(this, &NewRecordForm::chbHospitalType_CheckedChanged);
			this->cLbDoc->ItemCheck += gcnew ItemCheckEventHandler(this, &NewRecordForm::cLbDoc_ItemCheck);

			//
			//TODO: Add the constructor code here
			//
		}
		//Оброблюємо момент, коли користувач обрав лікаря.
		void NewRecordForm::cLbDoc_ItemCheck(System::Object^ sender, System::Windows::Forms::ItemCheckEventArgs^ e)
		{
			std::vector<Visit> visits = read_visittable();
			std::vector<Doctor> doctors = read_doctortable();
			Doctor doctor;

			if (e->NewValue == CheckState::Checked)
			{
				e->NewValue;
				cBTimeSelect->Items->Clear();
				// Отримуєм дані про лікаря
				System::String^ selectedDocName = cLbDoc->Items[e->Index]->ToString();
				for (const Doctor& doctor : doctors)
				{
					System::String^ docFullName = gcnew System::String((doctor.docName + " " + doctor.docSurname + " " + doctor.docMiddleName + " " + doctor.docSpeciality).c_str());

					if (docFullName == selectedDocName)
					{
						DoctorId = doctor.docID;
						std::vector<std::string> doctorVisits;
						for (const Visit& visit : visits)
						{
							if (visit.doctorID == DoctorId)
							{
								char dateStr[11];
								std::sprintf(dateStr, "%04d-%02d-%02d",
									visit.visitDate.tm_year,
									visit.visitDate.tm_mon,
									visit.visitDate.tm_mday);

								char visitTimeStr[9];
								std::sprintf(visitTimeStr, "%02d:%02d:%02d", visit.visitTime.tm_hour, visit.visitTime.tm_min, visit.visitTime.tm_sec);
								std::string dateTime = std::string(dateStr) + " " + std::string(visitTimeStr);

								doctorVisits.push_back(dateTime);
							}
						}

						// Початок і кінець робочого дня
						int startHour = doctor.docWorkingHoursStart.tm_hour;
						int startMinute = doctor.docWorkingHoursStart.tm_min;
						int endHour = doctor.docWorkingHoursEnd.tm_hour;
						int endMinute = doctor.docWorkingHoursEnd.tm_min;
						//Дату яку обрав користувач
						System::DateTime selectedDate = dTPSelect->Value;
						char selectedDateStr[11];
						std::sprintf(selectedDateStr, "%04d-%02d-%02d",
							selectedDate.Year, selectedDate.Month, selectedDate.Day);
						//Генерація інтервалів часу(тут ми приблизно беремо на опрацювання лікаря користувача 30 хвилин)
						for (int hour = startHour; hour <= endHour; hour++) {
							int minuteStart = (hour == startHour) ? startMinute : 0;

							for (int minute = minuteStart; minute < 60; minute += 30) {
								if (hour == endHour && minute > endMinute) {
									break;
								}

								char timeSlotStr[20];
								std::sprintf(timeSlotStr, "%s %02d:%02d:00", selectedDateStr, hour, minute);

								// Чи доступний час
								bool isSlotAvailable = true;
								for (const Visit& visit : visits) {
									if (visit.doctorID == DoctorId &&
										std::string(timeSlotStr) == ParseTmToString(visit.visitTime) && 
										visit.visitStatus == true) { // Перевірка чи актуальний цей візит
										isSlotAvailable = false;
										break;
									}
								}

								if (isSlotAvailable) {
									System::String^ timeSlot = gcnew System::String(timeSlotStr + 11);
									cBTimeSelect->Items->Add(timeSlot);
								}
							}
						}

					}
				}
			}
			else if (e->NewValue == CheckState::Unchecked)
			{
				cBTimeSelect->Items->Clear();
			}
		}
		// Обрали район
		void UpdateSelectedRegions(System::Object^ sender, System::Windows::Forms::ItemCheckEventArgs^ e)
		{
			//Перевірка стану
			this->BeginInvoke(gcnew Action<System::Object^, System::Windows::Forms::ItemCheckEventArgs^>(this, &NewRecordForm::ActuallyUpdateSelectedRegions), sender, e);
		}
		// Обрали спеціальність
		void UpdateSelectedSpec(System::Object^ sender, System::Windows::Forms::ItemCheckEventArgs^ e)
		{
			this->BeginInvoke(gcnew Action<System::Object^, System::Windows::Forms::ItemCheckEventArgs^>(this, &NewRecordForm::ActuallyUpdateSelectedSpec), sender, e);
		}
		// Тип лікарні
		void chbHospitalType_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		{
			CheckBox^ checkBox = safe_cast<CheckBox^>(sender);

			// Якщо це чекбокс для державних лікарень і він відзначений, то додаємо false до списку
			// Якщо це чекбокс для приватних лікарень і він відмічений, додаємо true
			selectedHospitalTypes->Clear();
			if (CbState->Checked)
				selectedHospitalTypes->Add(false);
			if (CbPrivate->Checked)
				selectedHospitalTypes->Add(true);

			UpdateClinicsList();
		}
		// Оброблюємо район
		void ActuallyUpdateSelectedRegions(System::Object^ sender, System::Windows::Forms::ItemCheckEventArgs^ e)
		{
			CheckedListBox^ list = safe_cast<CheckedListBox^>(sender);
			System::String^ selectedItem = safe_cast<System::String^>(list->Items[e->Index]);

			if (e->NewValue == CheckState::Checked)
			{
				// Якщо елемент вибраний, додаємо його до списку
				selectedRegions->Add(selectedItem);
			}
			else if (e->NewValue == CheckState::Unchecked)
			{
				selectedRegions->Remove(selectedItem);
			}

			// Обновляем
			UpdateClinicsList();
		}
		// Оброблюємо спеціальність
		void ActuallyUpdateSelectedSpec(System::Object^ sender, System::Windows::Forms::ItemCheckEventArgs^ e)
		{
			CheckedListBox^ list = safe_cast<CheckedListBox^>(sender);
			System::String^ selectedItem = safe_cast<System::String^>(list->Items[e->Index]);

			if (e->NewValue == CheckState::Checked)
			{
				selectedSpec->Add(selectedItem);
			}
			else if (e->NewValue == CheckState::Unchecked)
			{
				selectedSpec->Remove(selectedItem);
			}

			// Обновляем
			UpdateClinicsList();
		}
		// Оновлення списку лікарень
		void UpdateClinicsList()
		{
			std::vector<Hospital> hospitals = read_hospitaltable();
			std::vector<Doctor> doctors = read_doctortable();

			// Створюємо масив для зберігання назв лікарень
			array<System::String^>^ hospitalNames = gcnew array<System::String^>(hospitals.size());
			for (size_t i = 0; i < hospitals.size(); i++) {
				hospitalNames[i] = gcnew System::String(hospitals[i].hospitalName.c_str());
			}

			// Сортуємо лікарні за рейтингом
			SortHospitalsByRating(hospitals, hospitalNames);

			this->cLbHospital->Items->Clear();

			for (size_t i = 0; i < hospitals.size(); i++) {
				Hospital hospital = hospitals[i];

				bool regionSelected = selectedRegions->Count > 0 ? IsHospitalSelected(hospital.hospitalDistrict) : true;
				bool specSelected = selectedSpec->Count > 0 ? HospitalHasRequiredSpecialties(hospital, doctors) : true;
				bool typeSelected = selectedHospitalTypes->Count > 0 ? selectedHospitalTypes->Contains(hospital.hospitalIsPrivate) : true;

				if (regionSelected && specSelected && typeSelected) {
					this->cLbHospital->Items->Add(hospitalNames[i]);
				}
			}
		}
		// Допоміжні
		bool IsHospitalSelected(std::string regions)
		{
			System::String^ region = ParseToStringorSTDSTRING(regions);

			return selectedRegions->Contains(region);
		}
		bool HospitalHasRequiredSpecialties(const Hospital& hospital, const std::vector<Doctor>& doctors)
		{
			for (size_t i = 0; i < doctors.size(); i++)
			{
				Doctor doctor = doctors[i];
				// Перевіряємо, чи працює лікар у цій лікарні та чи відповідає його спеціалізація обраним
				if (doctor.docWorkPlace == hospital.hospitalID && selectedSpec->Contains(ParseToStringorSTDSTRING(doctor.docSpeciality)))
				{
					return true;
				}
			}
			return false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~NewRecordForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckedListBox^ cLBplace;
	private: System::Windows::Forms::CheckBox^ CbPrivate;
	protected:

	protected:

	private: System::Windows::Forms::CheckBox^ CbState;
	private: System::Windows::Forms::CheckedListBox^ cLbDocType;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ lPlace;
	private: System::Windows::Forms::Label^ lDocType;
	private: System::Windows::Forms::Label^ lDateVizit;
	private: System::Windows::Forms::ComboBox^ cBTimeSelect;
	private: System::Windows::Forms::TextBox^ tBComments;
	private: System::Windows::Forms::Label^ lComments;
	private: System::Windows::Forms::Label^ lChoose;
	private: System::Windows::Forms::Button^ bSend;
	private: System::Windows::Forms::Label^ linfo;
	private: System::Windows::Forms::DateTimePicker^ dTPSelect;

	private: System::Windows::Forms::CheckedListBox^ cLbDoc;
	private: System::Windows::Forms::CheckedListBox^ cLbHospital;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ lСlinic;

	private: System::Windows::Forms::Label^ label2;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(NewRecordForm::typeid));
			this->cLBplace = (gcnew System::Windows::Forms::CheckedListBox());
			this->CbPrivate = (gcnew System::Windows::Forms::CheckBox());
			this->CbState = (gcnew System::Windows::Forms::CheckBox());
			this->cLbDocType = (gcnew System::Windows::Forms::CheckedListBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->lPlace = (gcnew System::Windows::Forms::Label());
			this->lDocType = (gcnew System::Windows::Forms::Label());
			this->lDateVizit = (gcnew System::Windows::Forms::Label());
			this->cBTimeSelect = (gcnew System::Windows::Forms::ComboBox());
			this->tBComments = (gcnew System::Windows::Forms::TextBox());
			this->lComments = (gcnew System::Windows::Forms::Label());
			this->lChoose = (gcnew System::Windows::Forms::Label());
			this->bSend = (gcnew System::Windows::Forms::Button());
			this->linfo = (gcnew System::Windows::Forms::Label());
			this->dTPSelect = (gcnew System::Windows::Forms::DateTimePicker());
			this->cLbDoc = (gcnew System::Windows::Forms::CheckedListBox());
			this->cLbHospital = (gcnew System::Windows::Forms::CheckedListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->lСlinic = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->piсBox = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->piсBox))->BeginInit();
			this->SuspendLayout();
			// 
			// cLBplace
			// 
			this->cLBplace->FormattingEnabled = true;
			this->cLBplace->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Voznesenivskyi", L"Dniprovskyi ", L"Kommunarsky",
					L"Oleksandrivskyi ", L"Shevchenkivskyi", L"Khortytskyi", L"Zavodskoy"
			});
			this->cLBplace->Location = System::Drawing::Point(16, 152);
			this->cLBplace->Name = L"cLBplace";
			this->cLBplace->Size = System::Drawing::Size(267, 124);
			this->cLBplace->TabIndex = 0;
			this->cLBplace->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &NewRecordForm::cLBplace_MouseMove);
			// 
			// CbPrivate
			// 
			this->CbPrivate->AutoSize = true;
			this->CbPrivate->Location = System::Drawing::Point(13, 47);
			this->CbPrivate->Name = L"CbPrivate";
			this->CbPrivate->Size = System::Drawing::Size(75, 17);
			this->CbPrivate->TabIndex = 1;
			this->CbPrivate->Text = L"Приватна";
			this->CbPrivate->UseVisualStyleBackColor = true;
			this->CbPrivate->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &NewRecordForm::CbPrivate_MouseMove);
			// 
			// CbState
			// 
			this->CbState->AutoSize = true;
			this->CbState->Location = System::Drawing::Point(13, 90);
			this->CbState->Name = L"CbState";
			this->CbState->Size = System::Drawing::Size(79, 17);
			this->CbState->TabIndex = 2;
			this->CbState->Text = L"Державна";
			this->CbState->UseVisualStyleBackColor = true;
			this->CbState->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &NewRecordForm::CbState_MouseMove);
			// 
			// cLbDocType
			// 
			this->cLbDocType->FormattingEnabled = true;
			this->cLbDocType->Items->AddRange(gcnew cli::array< System::Object^  >(18) {
				L"Obstetrician-gynecologist", L"Dermatologist",
					L"Gastroenterologist", L"Hematologist", L"Gynaecologist", L"Cardiologist", L"Neurologist", L"Oculist", L"Onkoloh", L"Ortoped",
					L"Otolarynholoh (LOR-likar)", L"Psykhiatr", L"Pulmonoloh", L"Revmatoloh", L"Dentist", L"Terapevt", L"Uroloh", L"Endokrynoloh"
			});
			this->cLbDocType->Location = System::Drawing::Point(301, 153);
			this->cLbDocType->Name = L"cLbDocType";
			this->cLbDocType->Size = System::Drawing::Size(161, 124);
			this->cLbDocType->TabIndex = 3;
			this->cLbDocType->Tag = L"";
			this->cLbDocType->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &NewRecordForm::cLbDocType_MouseMove);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->CbState);
			this->groupBox1->Controls->Add(this->CbPrivate);
			this->groupBox1->Location = System::Drawing::Point(477, 147);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(118, 130);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Тип клініки:";
			// 
			// lPlace
			// 
			this->lPlace->AutoSize = true;
			this->lPlace->Location = System::Drawing::Point(10, 136);
			this->lPlace->Name = L"lPlace";
			this->lPlace->Size = System::Drawing::Size(87, 13);
			this->lPlace->TabIndex = 7;
			this->lPlace->Text = L"Виберіть район:";
			// 
			// lDocType
			// 
			this->lDocType->AutoSize = true;
			this->lDocType->Location = System::Drawing::Point(298, 136);
			this->lDocType->Name = L"lDocType";
			this->lDocType->Size = System::Drawing::Size(112, 13);
			this->lDocType->TabIndex = 8;
			this->lDocType->Text = L"Спеціалізація лікаря:";
			// 
			// lDateVizit
			// 
			this->lDateVizit->AutoSize = true;
			this->lDateVizit->Location = System::Drawing::Point(16, 312);
			this->lDateVizit->Name = L"lDateVizit";
			this->lDateVizit->Size = System::Drawing::Size(195, 13);
			this->lDateVizit->TabIndex = 9;
			this->lDateVizit->Text = L"Оберіть дату та вільний час прийому:";
			// 
			// cBTimeSelect
			// 
			this->cBTimeSelect->FormattingEnabled = true;
			this->cBTimeSelect->Location = System::Drawing::Point(16, 383);
			this->cBTimeSelect->Name = L"cBTimeSelect";
			this->cBTimeSelect->Size = System::Drawing::Size(195, 21);
			this->cBTimeSelect->TabIndex = 10;
			this->cBTimeSelect->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &NewRecordForm::cBTimeSelect_MouseMove);
			// 
			// tBComments
			// 
			this->tBComments->Location = System::Drawing::Point(384, 584);
			this->tBComments->Multiline = true;
			this->tBComments->Name = L"tBComments";
			this->tBComments->Size = System::Drawing::Size(438, 118);
			this->tBComments->TabIndex = 12;
			this->tBComments->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &NewRecordForm::tBComments_MouseUp);
			// 
			// lComments
			// 
			this->lComments->AutoSize = true;
			this->lComments->Location = System::Drawing::Point(385, 557);
			this->lComments->Name = L"lComments";
			this->lComments->Size = System::Drawing::Size(271, 13);
			this->lComments->TabIndex = 13;
			this->lComments->Text = L"Можете залишити скарги щодо самопочуття нижче:";
			// 
			// lChoose
			// 
			this->lChoose->AutoSize = true;
			this->lChoose->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lChoose->Location = System::Drawing::Point(309, 39);
			this->lChoose->Name = L"lChoose";
			this->lChoose->Size = System::Drawing::Size(227, 18);
			this->lChoose->TabIndex = 14;
			this->lChoose->Text = L"Заповніть блоки нижче даними";
			// 
			// bSend
			// 
			this->bSend->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			this->bSend->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->bSend->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bSend->Location = System::Drawing::Point(9, 641);
			this->bSend->Name = L"bSend";
			this->bSend->Size = System::Drawing::Size(202, 61);
			this->bSend->TabIndex = 15;
			this->bSend->Text = L"Записатися";
			this->bSend->UseVisualStyleBackColor = true;
			this->bSend->Click += gcnew System::EventHandler(this, &NewRecordForm::bSend_Click);
			this->bSend->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &NewRecordForm::bSend_MouseMove);
			// 
			// linfo
			// 
			this->linfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->linfo->AutoSize = true;
			this->linfo->Location = System::Drawing::Point(3, 850);
			this->linfo->Name = L"linfo";
			this->linfo->Size = System::Drawing::Size(256, 13);
			this->linfo->TabIndex = 31;
			this->linfo->Text = L"Для отриманя інформації по формі - натисніть F1";
			// 
			// dTPSelect
			// 
			this->dTPSelect->Format = System::Windows::Forms::DateTimePickerFormat::Time;
			this->dTPSelect->Location = System::Drawing::Point(16, 345);
			this->dTPSelect->Name = L"dTPSelect";
			this->dTPSelect->Size = System::Drawing::Size(89, 20);
			this->dTPSelect->TabIndex = 32;
			this->dTPSelect->ValueChanged += gcnew System::EventHandler(this, &NewRecordForm::dTPSelect_ValueChanged);
			this->dTPSelect->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &NewRecordForm::dTPSelect_MouseMove);
			// 
			// cLbDoc
			// 
			this->cLbDoc->FormattingEnabled = true;
			this->cLbDoc->Location = System::Drawing::Point(384, 342);
			this->cLbDoc->Name = L"cLbDoc";
			this->cLbDoc->Size = System::Drawing::Size(438, 199);
			this->cLbDoc->TabIndex = 34;
			this->cLbDoc->SelectedIndexChanged += gcnew System::EventHandler(this, &NewRecordForm::cLbDoc_SelectedIndexChanged);
			// 
			// cLbHospital
			// 
			this->cLbHospital->FormattingEnabled = true;
			this->cLbHospital->Location = System::Drawing::Point(614, 153);
			this->cLbHospital->Name = L"cLbHospital";
			this->cLbHospital->Size = System::Drawing::Size(212, 124);
			this->cLbHospital->TabIndex = 35;
			this->cLbHospital->SelectedIndexChanged += gcnew System::EventHandler(this, &NewRecordForm::cLbHospital_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(9, 576);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(202, 35);
			this->button1->TabIndex = 36;
			this->button1->Text = L"Знайти доступних лікарів";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &NewRecordForm::button1_Click);
			// 
			// lСlinic
			// 
			this->lСlinic->AutoSize = true;
			this->lСlinic->Location = System::Drawing::Point(611, 136);
			this->lСlinic->Name = L"lСlinic";
			this->lСlinic->Size = System::Drawing::Size(49, 13);
			this->lСlinic->TabIndex = 37;
			this->lСlinic->Text = L"Кліники:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(385, 312);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 13);
			this->label2->TabIndex = 38;
			this->label2->Text = L"Лікарі:";
			// 
			// piсBox
			// 
			this->piсBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"piсBox.Image")));
			this->piсBox->Location = System::Drawing::Point(-24, 3);
			this->piсBox->Name = L"piсBox";
			this->piсBox->Size = System::Drawing::Size(181, 117);
			this->piсBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->piсBox->TabIndex = 42;
			this->piсBox->TabStop = false;
			// 
			// NewRecordForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(838, 713);
			this->Controls->Add(this->piсBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lСlinic);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->cLbHospital);
			this->Controls->Add(this->cLbDoc);
			this->Controls->Add(this->dTPSelect);
			this->Controls->Add(this->linfo);
			this->Controls->Add(this->bSend);
			this->Controls->Add(this->lChoose);
			this->Controls->Add(this->lComments);
			this->Controls->Add(this->tBComments);
			this->Controls->Add(this->cBTimeSelect);
			this->Controls->Add(this->lDateVizit);
			this->Controls->Add(this->lDocType);
			this->Controls->Add(this->lPlace);
			this->Controls->Add(this->cLbDocType);
			this->Controls->Add(this->cLBplace);
			this->Controls->Add(this->groupBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"NewRecordForm";
			this->Text = L"Створити новий запис";
			this->Load += gcnew System::EventHandler(this, &NewRecordForm::NewRecordForm_Load);
			this->HelpRequested += gcnew System::Windows::Forms::HelpEventHandler(this, &NewRecordForm::NewRecordForm_HelpRequested);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->piсBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//Записатися
	private: System::Void bSend_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		Visit obj;
		std::vector<User> users = read_usertable();
		std::vector<Doctor> doctors = read_doctortable();
		std::vector<Visit> visits = read_visittable();
		//Отримуємо дату яку обрав користувач
		DateTime^ dateTime = dTPSelect->Value;
		std::tm Date = ParseToTm(dateTime);
		//Отримуємо час який обрав користувач
		System::String^ selectedTime = cBTimeSelect->SelectedItem->ToString();
		std::string timeStr = ParseToStringorSTDSTRING(selectedTime);
		std::tm tmStruct = {};
		for (auto& user : users)
		{
			//Шукаємо користувача, і записуємо в visit дані
			if (user.userPhone == ParseToStringorSTDSTRING(receivedText))
			{
				UserID = user.userID;
				obj.clientID = user.userID;
				obj.doctorID = DoctorId;
				obj.visitDate = Date;
				if (sscanf_s(timeStr.c_str(), "%d:%d:%d", &tmStruct.tm_hour, &tmStruct.tm_min, &tmStruct.tm_sec) == 3)
				{
					obj.visitTime.tm_hour = tmStruct.tm_hour;
					obj.visitTime.tm_min = tmStruct.tm_min;
					obj.visitTime.tm_sec = tmStruct.tm_sec;
				}
				if (tBComments->Text->Length >= 1)
				{
					obj.diagnosis = ParseToStringorSTDSTRING(tBComments->Text);
				}
				obj.visitStatus = 1;
				obj.write_visitrow();
				//Оновлюємо визитиси, після додавання нового.
				visits = read_visittable();
				// Відразу додаємо в ComboBox(майбутні записи)
				comboBoxReference->Items->Clear();
				System::Collections::Generic::List<System::String^>^ visitList = gcnew System::Collections::Generic::List<System::String^>();

				for (Visit& Visit : visits)
				{
					System::DateTime visitDateTime = ConvertTmToDateTime(Visit.visitDate);

					/*	if (visitDateTime < currentDate)
						{
							Visit.visitStatus = 2;
							Visit.write_visitrow();
						}*/
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
				}
				//Додаємо на комбо бокс візити
				for each (System::String ^ visitString in visitList)
				{
					comboBoxReference->Items->Add(visitString);
				}
			}
		}
	}
	private: System::Void cLBplace_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();
		toolTip1->SetToolTip(cLBplace, "Відмітьте галочкою райони в яких ви хочете побачити клініки ");
	}
	private: System::Void CbPrivate_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();
		toolTip1->SetToolTip(CbPrivate, "Відмітьте галочкою тип клініки ");
	}
	private: System::Void CbState_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();
		toolTip1->SetToolTip(CbState, "Відмітьте галочкою тип клініки ");
	}
	private: System::Void cLbDocType_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();
		toolTip1->SetToolTip(cLbDocType, "Відмітьте галочкою Обрану спеціалізацію лікаря");
	}

	private: System::Void cBTimeSelect_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();
		toolTip1->SetToolTip(cBTimeSelect, "Оберіть доступні час та дату прийому ");
	}
	private: System::Void tBComments_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();
		toolTip1->SetToolTip(tBComments, "Тут ви можете написати коментарі щодо вашого самопочуття ");
	}
	private: System::Void bSend_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();
		toolTip1->SetToolTip(bSend, "Кнопка для підтвердження реєстрації");
	}

	private: System::Void dTPSelect_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();
		toolTip1->SetToolTip(dTPSelect, "Оберіть час та дату прийому");
	}
	private: System::Void NewRecordForm_HelpRequested(System::Object^ sender, System::Windows::Forms::HelpEventArgs^ hlpevent) {
		// Текст допомоги або пояснення для форми NewRecordForm
		String^ helpText = "Ця форма дозволяє користувачам записуватися до лікаря, обирати спеціалізацію, дату та час прийому, а також залишати коментарі щодо свого самопочуття.\n";
		helpText += "Оберіть тип клініки (приватна або державна), район, спеціалізацію лікаря та дату прийому.\n";
		helpText += "Оберіть вільний час прийому і залиште коментарі за потреби.\n";
		helpText += "Завершіть реєстрацію натиснувши кнопку 'Записатися'.";

		// Показати MessageBox із текстом допомоги
		MessageBox::Show(helpText, "Довідка", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
		   // При завантаженні форми
	private: System::Void NewRecordForm_Load(System::Object^ sender, System::EventArgs^ e) {
		std::vector<Hospital> hospitals = read_hospitaltable();

		array<String^>^ dataList = gcnew array<String^>(hospitals.size());

		// Заповнюємо всіма лікарнями
		for (int i = 0; i < hospitals.size(); i++)
		{
			dataList[i] = gcnew System::String(hospitals[i].hospitalName.c_str());
		}

		// Сортируємо за рейтингом
		SortHospitalsByRating(hospitals, dataList);

		// Додаємо на вивід
		cLbHospital->Items->Clear();
		for (int i = 0; i < dataList->Length; i++)
		{
			cLbHospital->Items->Add(dataList[i]);
		}
	}

	private: System::Void cLbHospital_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void dTPSelect_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	}
		   //Знайти доступних лікарів(кнопка)
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Collections::Generic::List<System::String^>^ checkedDocTypes = gcnew System::Collections::Generic::List<System::String^>();
		System::DateTime currentDate = System::DateTime::Now;
		System::DateTime datetime = dTPSelect->Value;

		if (datetime < currentDate)
		{
			MessageBox::Show("Выбрана прошедшая дата.");
		}
		else
		{
			std::vector<Hospital> hospitals = read_hospitaltable();
			std::vector<Doctor> doctors = read_doctortable();

			DateTime^ dateTime = dTPSelect->Value;
			int hour = dateTime->Hour;
			int minute = dateTime->Minute;
			int second = dateTime->Second;
			DayOfWeek dayOfWeek = dateTime->DayOfWeek;
			int idHospital;

			//ЛІКАРНЯ ПЕРЕБОР
			if (cLbHospital->CheckedIndices->Count > 0)
			{
				int checkedIndex = cLbHospital->CheckedIndices[0];
				System::String^ selectedHospital = cLbHospital->Items[checkedIndex]->ToString();

				for (size_t j = 0; j < hospitals.size(); j++)
				{
					// Якщо ім'я лікарні збігається з вибраним елементом
					if (ParseToStringorSTDSTRING(hospitals[j].hospitalName) == selectedHospital)
					{
						//id лікарні
						idHospital = hospitals[j].hospitalID;
						break;
					}
				}
			}

			//ЧИТАЄМО ЧЕК БОКС СПЕЦІАЛЬНОСТЕЙ 
			for (int i = 0; i < cLbDocType->CheckedItems->Count; i++)
			{
				
				checkedDocTypes->Add(cLbDocType->CheckedItems[i]->ToString());
			}

			//ЗАПИС ДО ЧЕК БОКСУ
			cLbDoc->Items->Clear();

		// Перебираємо лікарів
			for (size_t i = 0; i < doctors.size(); i++)
			{
				// Якщо лікарь працює в цій лікарні
				if (doctors[i].docWorkPlace == idHospital)
				{
					String^ dayOfWeekStr = Enum::GetName(DayOfWeek::typeid, dayOfWeek);

					System::String^ workingDays = gcnew System::String(doctors[i].docWorkingDays.c_str());

					// Чи працює врач в цей день
					if (workingDays->Contains(dayOfWeekStr))
					{
						// Перевіряємо, що обраний час входить в робочі часи лікаря
						bool isWorkingHour = hour > doctors[i].docWorkingHoursStart.tm_hour &&
							hour < doctors[i].docWorkingHoursEnd.tm_hour;
						bool isWorkingStartMinute = hour == doctors[i].docWorkingHoursStart.tm_hour &&
							minute >= doctors[i].docWorkingHoursStart.tm_min;
						bool isWorkingEndMinute = hour == doctors[i].docWorkingHoursEnd.tm_hour &&
							minute <= doctors[i].docWorkingHoursEnd.tm_min;

						if (isWorkingHour || isWorkingStartMinute || isWorkingEndMinute)
						{
							for each (System::String ^ type in checkedDocTypes)
							{
								if (ParseToStringorSTDSTRING(doctors[i].docSpeciality) == type)
								{
									// Додаємо лікаря в  CheckedListBox
									std::string fullName = doctors[i].docName + " " + doctors[i].docSurname + " " +
										doctors[i].docMiddleName + " " + doctors[i].docSpeciality;

									cLbDoc->Items->Add(gcnew System::String(fullName.c_str()));
								}
							}
						}
					}
				}
			}
		}
	}
	private: System::Void cLbDoc_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
