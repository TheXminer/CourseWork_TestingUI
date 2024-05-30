#pragma once
#include <string>

namespace CourseWorkTestingUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TestSetEditForm
	/// </summary>
	public ref class TestSetEditForm : public System::Windows::Forms::Form
	{
		String^ testSetName;
	public:
		TestSetEditForm(void)
		{
			InitializeComponent();
			this->buttonApply->BackgroundImage = gcnew Bitmap("./ButtonIcons/iconDone.png");
			this->buttonDelete->BackgroundImage = gcnew Bitmap("./ButtonIcons/iconDelete.png");
			testSetName = nullptr;
			//
			//TODO: Add the constructor code here
			//
		}
		TestSetEditForm(String^ testSetName) : testSetName(testSetName)
		{
			InitializeComponent();
			this->buttonApply->BackgroundImage = gcnew Bitmap("./ButtonIcons/iconDone.png");
			this->buttonDelete->BackgroundImage = gcnew Bitmap("./ButtonIcons/iconDelete.png");
			textBox1->Text = testSetName;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TestSetEditForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ buttonApply;

	protected:

	private: System::Windows::Forms::Button^ buttonDelete;
	private: System::Windows::Forms::Label^ label1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

	public:
		String^ getTestSetName() {
			return testSetName;
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(TestSetEditForm::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->buttonApply = (gcnew System::Windows::Forms::Button());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 27);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(437, 20);
			this->textBox1->TabIndex = 0;
			// 
			// buttonApply
			// 
			this->buttonApply->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->buttonApply->Location = System::Drawing::Point(455, 12);
			this->buttonApply->Name = L"buttonApply";
			this->buttonApply->Size = System::Drawing::Size(36, 35);
			this->buttonApply->TabIndex = 1;
			this->buttonApply->UseVisualStyleBackColor = true;
			this->buttonApply->Click += gcnew System::EventHandler(this, &TestSetEditForm::buttonApply_Click);
			// 
			// buttonDelete
			// 
			this->buttonDelete->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->buttonDelete->Location = System::Drawing::Point(497, 12);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(36, 35);
			this->buttonDelete->TabIndex = 2;
			this->buttonDelete->UseVisualStyleBackColor = true;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &TestSetEditForm::buttonDelete_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(101, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Enter test set name:";
			// 
			// TestSetEditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(546, 59);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonDelete);
			this->Controls->Add(this->buttonApply);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"TestSetEditForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"TestSetEditForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonApply_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text != "")
			testSetName = gcnew String(textBox1->Text);
		this->Close();
	}
	private: System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
