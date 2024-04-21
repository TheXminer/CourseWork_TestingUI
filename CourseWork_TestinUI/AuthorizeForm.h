#pragma once
namespace CourseWorkTestingUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AuthorizeForm
	/// </summary>
	public ref class AuthorizeForm : public System::Windows::Forms::Form
	{
	public:
		AuthorizeForm(void)
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
		~AuthorizeForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ userNameTextBox;

	protected:

	private: System::Windows::Forms::Button^ buttonStart;


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->userNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->buttonStart = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter username:";
			// 
			// userNameTextBox
			// 
			this->userNameTextBox->Location = System::Drawing::Point(102, 12);
			this->userNameTextBox->Name = L"userNameTextBox";
			this->userNameTextBox->Size = System::Drawing::Size(185, 20);
			this->userNameTextBox->TabIndex = 1;
			// 
			// buttonStart
			// 
			this->buttonStart->Location = System::Drawing::Point(63, 38);
			this->buttonStart->Name = L"buttonStart";
			this->buttonStart->Size = System::Drawing::Size(167, 34);
			this->buttonStart->TabIndex = 2;
			this->buttonStart->Text = L"Start!";
			this->buttonStart->UseVisualStyleBackColor = true;
			this->buttonStart->Click += gcnew System::EventHandler(this, &AuthorizeForm::buttonStart_Click);
			// 
			// AuthorizeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(301, 87);
			this->Controls->Add(this->buttonStart);
			this->Controls->Add(this->userNameTextBox);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"AuthorizeForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AuthorizeForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: String^ getUserName() {
		return userNameTextBox->Text;
	}
	private: System::Void buttonStart_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
