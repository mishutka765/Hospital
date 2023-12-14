#pragma once

namespace mainProject {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AboutAppForm
	/// </summary>
	public ref class AboutAppForm : public System::Windows::Forms::Form
	{
	public:
		AboutAppForm(void)
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
		~AboutAppForm()
		{
			if (components)
			{
				delete components;
			}
		}
	protected: System::Windows::Forms::RichTextBox^ rTbAbout;
	protected: System::Windows::Forms::Button^ button1;
	protected: System::Windows::Forms::Label^ linfo;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AboutAppForm::typeid));
			this->rTbAbout = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->linfo = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// rTbAbout
			// 
			this->rTbAbout->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->rTbAbout->ForeColor = System::Drawing::SystemColors::WindowText;
			this->rTbAbout->Location = System::Drawing::Point(16, 15);
			this->rTbAbout->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->rTbAbout->Name = L"rTbAbout";
			this->rTbAbout->ReadOnly = true;
			this->rTbAbout->Size = System::Drawing::Size(879, 704);
			this->rTbAbout->TabIndex = 0;
			this->rTbAbout->Text = resources->GetString(L"rTbAbout.Text");
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::OrangeRed;
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Location = System::Drawing::Point(401, 740);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(79, 39);
			this->button1->TabIndex = 1;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &AboutAppForm::button1_Click);
			// 
			// linfo
			// 
			this->linfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->linfo->AutoSize = true;
			this->linfo->Location = System::Drawing::Point(16, 786);
			this->linfo->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->linfo->Name = L"linfo";
			this->linfo->Size = System::Drawing::Size(321, 16);
			this->linfo->TabIndex = 31;
			this->linfo->Text = L"Для отриманя інформації по формі - натисніть F1";
			// 
			// AboutAppForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(912, 814);
			this->Controls->Add(this->linfo);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->rTbAbout);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"AboutAppForm";
			this->Text = L"Про застосунок і розробників";
			this->Load += gcnew System::EventHandler(this, &AboutAppForm::AboutAppForm_Load);
			this->HelpRequested += gcnew System::Windows::Forms::HelpEventHandler(this, &AboutAppForm::AboutAppForm_HelpRequested);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
	}
	private: System::Void AboutAppForm_HelpRequested(System::Object^ sender, System::Windows::Forms::HelpEventArgs^ hlpevent) {
		// Текст допомоги або пояснення для форми AboutAppForm
		String^ helpText = "Ця форма містить інформацію про додаток. Ви можете дізнатися більше про функціональність та мету цього додатку тут.\n";
		helpText += "Для закриття цього вікна, натисніть кнопку 'OK' у нижній частині форми.";

		// Показати MessageBox із текстом допомоги
		MessageBox::Show(helpText, "Довідка", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	private: System::Void AboutAppForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
