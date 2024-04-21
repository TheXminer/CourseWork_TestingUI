#pragma once
#include <vcclr.h>
#include <vector>
#include "AuthorizeForm.h"
namespace CourseWorkTestingUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Resources;
	using namespace System::Reflection;

	/// <summary>
	/// Summary for StartForm
	/// </summary>
	public ref class StartForm : public System::Windows::Forms::Form
	{
		int curY;
		int xTab;
		int groupBoxWidth, yStartMargin;
		array<GroupBox^, 1>^ allGroupBoxes;
		int buttonSize = 40, buttonMargin = 20;
		int choosenTestSet;
	private: System::Windows::Forms::ToolStrip^ userToolStrip;
	private: System::Windows::Forms::ToolStripMenuItem^ buttonExit;
	private: System::Windows::Forms::ToolStripButton^ buttonReturn;
	private: System::Windows::Forms::ToolStripSplitButton^ userToolStripButton;
		   Bitmap^ iconDelete;
		   Bitmap^ iconEdit;
		   Bitmap^ iconStart;
		   Bitmap^ iconDone;
		   Bitmap^ iconAdd;
		   Bitmap^ iconReturn;
		   Bitmap^ iconExit;
		   Bitmap^ iconProfile;
	public:
		StartForm(void)
		{
			InitializeComponent();

			//TODO: Add the constructor code here
			//
			curY = 32;
			xTab = 12;
			yStartMargin = 37;
			groupBoxWidth = this->Size.Width - 30;
			allGroupBoxes = gcnew array<GroupBox^, 1>(15);

			iconDelete = gcnew Bitmap("./ButtonIcons/iconDelete.png");
			iconEdit = gcnew Bitmap("./ButtonIcons/iconEdit.png");
			iconStart = gcnew Bitmap("./ButtonIcons/iconStart.png");
			iconAdd = gcnew Bitmap("./ButtonIcons/iconAdd.png");
			iconDone = gcnew Bitmap("./ButtonIcons/iconDone.png");
			iconReturn = gcnew Bitmap("./ButtonIcons/iconBack.png");
			iconExit = gcnew Bitmap("./ButtonIcons/iconExit.png");
			iconProfile = gcnew Bitmap("./ButtonIcons/iconProfile.png");
			addTest();
			//showTestSets(&adminShow);
			//showTestSets();
			//createAddButton();
			//_sleep(1000);
			//clearControls();
			//addSetTestNameGB("dfndghdrthrt", 0);
			//addSetTestNameGB("asddddddddddddddddddd", 1);
			//addSetTestNameGB("asdasdashhfghdfgdfggerergerhdb", 2);
			//addSetTestNameGB("xcvgergwfwefsdgzcvsdfsdfsdfsd", 3);
			//addSetTestNameGB("dfndghdrthrt", 4);
			//addSetTestNameGB("sdhrtkdy,.jk,uk;iofghdfgasfg", 5);
			//addNewGroupBox("Why?asdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsd", 14);
			//addNewGroupBox("Why?", 14);
			//array<String^>^ answers = { "blablablaas","sdsdsdsad","adssgasdasdasd","4das", "sadasdasd" };
			//addNewGroupBox("Which?", answers, 4, true);
			//addNewGroupBox("Which?", answers, 5, false);
			//allGroupBoxes[14]->Scale()
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
			this->SuspendLayout();
			// 
			// StartForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1203, 631);
			this->Name = L"StartForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"StartForm";
			this->ResumeLayout(false);

		}
		
		void addTest();
		//Array<GroupBox^

	public:
		//single/multiple chise questions (for user)
		void createSingleChoiceTestGB(String^ question, array<String^>^ answers, int number);
		void markCorrectAnswer(int answersNumber, int number, int correctAnswerIndex);
		void createMultipleChoiceTestGB(String^ question, array<String^>^ answers, int number);
		void markCorrectAnswer(int answersNumber, int number, std::vector<int> correctAnswerIndex);
		//open answer question (for user)
		void createOpenTestGB(String^ question, int number);
		//single/multiple chise questions (D/E actions)
		void createAdminChoiceTestGB(int number);
		//show test set name for admin (D/E actions)
		void adminShowTestSetName(String^ testName, int number) {
			allGroupBoxes[number] = gcnew GroupBox();
			Label^ labelTestName;
			Button^ editButton;
			Button^ deleteButton; 

			labelTestName = gcnew Label();
			deleteButton = gcnew Button();
			editButton = gcnew Button(); 
			//
			// GroupBoxQ
			//
			allGroupBoxes[number]->Controls->Add(labelTestName);
			allGroupBoxes[number]->Controls->Add(deleteButton);
			allGroupBoxes[number]->Controls->Add(editButton);
			allGroupBoxes[number]->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			allGroupBoxes[number]->Location = Drawing::Point(12, curY);
			allGroupBoxes[number]->Size = Drawing::Size(groupBoxWidth, 131);
			allGroupBoxes[number]->Text = Convert::ToString(number + 1);
			//
			// Label
			//
			labelTestName->AutoSize = true;
			labelTestName->Location = Drawing::Point(6, yStartMargin);
			labelTestName->MaximumSize = System::Drawing::Size(groupBoxWidth - 2 * (buttonMargin + buttonSize) - buttonMargin, 0);
			labelTestName->Name = L"labelQuestion";
			labelTestName->Size = Drawing::Size(116, 25);
			labelTestName->Text = testName;
			//
			// DeleteButton
			//
			deleteButton->BackgroundImage = iconDelete;
			deleteButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			deleteButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			deleteButton->ForeColor = System::Drawing::Color::Transparent;
			deleteButton->Location = System::Drawing::Point(groupBoxWidth - buttonMargin - buttonSize, 33);
			deleteButton->Name = L"D" + Convert::ToString(number);
			deleteButton->Size = System::Drawing::Size(buttonSize, buttonSize);
			deleteButton->Click += gcnew System::EventHandler(this, &StartForm::buttonDeleteTestSet_Click);
			//
			// EditButton
			//
			editButton->BackgroundImage = iconEdit;
			editButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			editButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			editButton->ForeColor = System::Drawing::Color::Transparent;
			editButton->Location = System::Drawing::Point(groupBoxWidth - 2 * (buttonMargin + buttonSize), 33);
			editButton->Name = L"E" + Convert::ToString(number);
			editButton->Size = System::Drawing::Size(buttonSize, buttonSize);
			editButton->Click += gcnew System::EventHandler(this, &StartForm::buttonEditTestSet_Click);
			//
			// Show
			//
			allGroupBoxes[number]->Size = Drawing::Size(groupBoxWidth, yStartMargin + 20 + labelTestName->Size.Height + 20);
			this->Controls->Add(allGroupBoxes[number]);
			allGroupBoxes[number]->ResumeLayout(false);
			allGroupBoxes[number]->PerformLayout();

			curY += allGroupBoxes[number]->Size.Height;
		}
		//show test set name for user (S action)
		void clientShowTestSetName(String^ testName, int number) {
			allGroupBoxes[number] = gcnew GroupBox();
			Label^ labelTestName;
			Button^ startButton;

			labelTestName = gcnew Label();
			startButton = gcnew Button();

			allGroupBoxes[number]->Controls->Add(labelTestName);
			allGroupBoxes[number]->Controls->Add(startButton);
			allGroupBoxes[number]->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			allGroupBoxes[number]->Location = Drawing::Point(12, curY);
			allGroupBoxes[number]->Size = Drawing::Size(groupBoxWidth, 131);
			allGroupBoxes[number]->Text = Convert::ToString(number + 1);
			//
			// Label
			//
			labelTestName->AutoSize = true;
			labelTestName->Location = Drawing::Point(6, yStartMargin);
			labelTestName->MaximumSize = System::Drawing::Size(groupBoxWidth - (buttonMargin + buttonSize) - buttonMargin, 0);
			labelTestName->Name = L"labelQuestion";
			labelTestName->Size = Drawing::Size(116, 25);
			labelTestName->Text = testName;
			//
			// DeleteButton
			//
			if(/*isTestPassed*/false)
			{
				startButton->BackgroundImage = iconDone;
				startButton->Click += gcnew System::EventHandler(this, &StartForm::buttonViewMyMarks_Click);
			}
			else
			{
				startButton->BackgroundImage = iconStart;
				startButton->Click += gcnew System::EventHandler(this, &StartForm::buttonStartTestSet_Click);
			}
			startButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			startButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			startButton->ForeColor = System::Drawing::Color::Transparent;
			startButton->Location = System::Drawing::Point(groupBoxWidth - buttonMargin - buttonSize, 33);
			startButton->Name = L"S" + Convert::ToString(number);
			startButton->Size = System::Drawing::Size(buttonSize, buttonSize);
			//
			// Show
			//
			allGroupBoxes[number]->Size = Drawing::Size(groupBoxWidth, yStartMargin + 20 + labelTestName->Size.Height + 20);
			this->Controls->Add(allGroupBoxes[number]);
			allGroupBoxes[number]->ResumeLayout(false);
			allGroupBoxes[number]->PerformLayout();

			curY += allGroupBoxes[number]->Size.Height;
		}
		//show button to finish test
		void createFinishButton() {
			Button^ finishButton = gcnew Button();

			finishButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			finishButton->Location = System::Drawing::Point(12, curY);
			finishButton->Name = L"F";
			finishButton->Size = System::Drawing::Size(buttonSize * 4, buttonSize);
			finishButton->TabIndex = 0;
			finishButton->Text = L"Finish";
			finishButton->UseVisualStyleBackColor = true;

			this->Controls->Add(finishButton);
			curY += finishButton->Size.Height;
			finishButton->PerformLayout();
		}
		//show button to start test
		void createAddButton() {
			Button^ addButton = gcnew Button();
			addButton->BackgroundImage = iconAdd;
			addButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			addButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			addButton->ForeColor = System::Drawing::Color::Transparent;
			addButton->Location = System::Drawing::Point(12, curY);
			addButton->Name = L"A";
			addButton->Size = System::Drawing::Size(buttonSize, buttonSize);
			addButton->Click += gcnew System::EventHandler(this, &StartForm::buttonAddTest_Click);
			addButton->UseVisualStyleBackColor = true;
			curY += addButton->Size.Height;

			this->Controls->Add(addButton);
			addButton->PerformLayout();
		}
		
		void showToolBar() {
			userToolStrip = gcnew ToolStrip();
			buttonExit = gcnew ToolStripMenuItem();
			buttonReturn = gcnew ToolStripButton();
			userToolStripButton = gcnew ToolStripSplitButton();
			userToolStrip->SuspendLayout();
			// 
			// userToolStrip
			// 
			userToolStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->buttonReturn,
					this->userToolStripButton
			});
			userToolStrip->Location = System::Drawing::Point(0, 0);
			userToolStrip->Name = L"userToolStrip";
			userToolStrip->Size = System::Drawing::Size(1203, 25);
			userToolStrip->TabIndex = 0;
			userToolStrip->Text = L"userToolStrip";
			// 
			// buttonReturn
			// 
			buttonReturn->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			buttonReturn->ImageTransparentColor = System::Drawing::Color::Magenta;
			buttonReturn->Name = L"buttonReturn";
			buttonReturn->Size = System::Drawing::Size(23, 22);
			buttonReturn->Text = L"buttonReturn";
			buttonReturn->Click += gcnew System::EventHandler(this, &StartForm::buttonReturn_Click);
			buttonReturn->Visible = false;
			// 
			// userToolStripButton
			// 
			userToolStripButton->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			userToolStripButton->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { buttonExit });
			userToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			userToolStripButton->Name = L"userToolStripButton";
			userToolStripButton->Size = System::Drawing::Size(78, 22);
			userToolStripButton->Text = L"UserName";
			// 
			// buttonExit
			// 
			buttonExit->ImageTransparentColor = System::Drawing::Color::Transparent;
			buttonExit->Name = L"buttonExit";
			buttonExit->Size = System::Drawing::Size(180, 22);
			buttonExit->Text = L"Exit";
			buttonExit->Click += gcnew System::EventHandler(this, &StartForm::buttonExit_Click);
			//
			//Icons
			//
			buttonReturn->Image = iconReturn;
			buttonExit->Image = iconExit;
			userToolStripButton->Image = iconProfile;
			//show
			this->Controls->Add(userToolStrip);
			userToolStrip->ResumeLayout(false);
			userToolStrip->PerformLayout();
		}

		GroupBox^ getGroupBox(int number) {
			return allGroupBoxes[number];
		}

		//event actions
		void choosedDeleteSet(int testSetNumber);
		void choosedStartSet(int testSetNumber);
		void choosedEditSet(int testSetNumber);
		void choosedDeleteTest(int testSetNumber);
		void choosedEditTest(int testSetNumber);
		void choosedReturn();
		void showTestSets(void (*showSetFunc)(StartForm^, String^, int));
		void authorization();
		//void AddNewTest();
		//void TestCreationWindow();
		void showSetsToClient();
		void showSetsToAdmin();
		void clearControls();

#pragma endregion
	//private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	//	//this->Controls->Clear();
	//	Button^ clickedButton = dynamic_cast<Button^>(sender);
	//	//if (clickedButton != nullptr)
	//	//{
	//	//	String^ buttonName = clickedButton->Name;
	//	//	MessageBox::Show("Button clicked: " + buttonName);
	//	//}
	//	//Reflection::Assembly^ pxAssembly = Reflection::Assembly::GetExecutingAssembly();
	//	//String^ pxResName = pxAssembly->GetName()->Name + ".Resource"; //Note: add your resourcefile name here, i.e. ".MyResourceFile" as it appears in solution explorer, without it's extension
	//	//ResourceManager^ s_pxResourceManager = (gcnew Resources::ResourceManager(pxResName, pxAssembly));
	//	//button2->BackgroundImage = (cli::safe_cast<Drawing::Bitmap^>(s_pxResourceManager->GetObject("iconDelete.png")));
	//	//sender.
	//}
	//private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	//	this->Controls->Clear();
	//	Button^ clickedButton = dynamic_cast<Button^>(sender);
	//	if (clickedButton != nullptr)
	//	{
	//		String^ buttonName = clickedButton->Name;
	//		MessageBox::Show("Button clicked: " + buttonName);
	//	}
	//	curY = 12;
	//	xTab = 12;
	//	yStartMargin = 37;
	//	addNewGroupBox("Why?asdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsd", 14);
	//	addNewGroupBox("Why?", 15);
	//	array<String^>^ answers = { "blablablaas","sdsdsdsad","adssgasdasdasd","4das", "sadasdasd" };
	//	addNewGroupBox("Which?", answers, 4, true);
	//	addNewGroupBox("Which?", answers, 5, false);
	//	addNewGroupBox("Which?", answers, 6, true);
	//	addNewGroupBox("Which?", answers, 7, false);
	//	addNewGroupBox("Which?", answers, 8, true);
	//	addNewGroupBox("Which?", answers, 9, false);
	//	addNewGroupBox("Which?", answers, 10, true);
	//	addNewGroupBox("Which?", answers, 11, false);
	//}
	private:
		System::Void buttonDeleteTestSet_Click(System::Object^ sender, System::EventArgs^ e) {
			Button^ clickedButton = dynamic_cast<Button^>(sender);
			//TextBox^ text = allGroupBoxes[14]->Controls->Find("sdsd");
			String^ name = clickedButton->Name->Remove(0, 1);
			choosedDeleteSet(Convert::ToInt32(name));
		}
	private:
		System::Void buttonEditTestSet_Click(System::Object^ sender, System::EventArgs^ e) {
			Button^ clickedButton = dynamic_cast<Button^>(sender);
			String^ name = clickedButton->Name->Remove(0, 1);
			choosenTestSet = Convert::ToInt32(name);
			choosedEditSet(choosenTestSet);
		}
	private:
		System::Void buttonDeleteTest_Click(System::Object^ sender, System::EventArgs^ e) {
			Button^ clickedButton = dynamic_cast<Button^>(sender);
			//TextBox^ text = allGroupBoxes[14]->Controls->Find("sdsd");
			String^ name = clickedButton->Name->Remove(0, 1);
			choosedDeleteTest(Convert::ToInt32(name));
		}
	private:
		System::Void buttonEditTest_Click(System::Object^ sender, System::EventArgs^ e) {
			Button^ clickedButton = dynamic_cast<Button^>(sender);
			String^ name = clickedButton->Name->Remove(0, 1);
			//choosedEditSet(Convert::ToInt32(name));
		}
	private:
		System::Void buttonStartTestSet_Click(System::Object^ sender, System::EventArgs^ e) {
			Button^ clickedButton = dynamic_cast<Button^>(sender);
			String^ name = clickedButton->Name->Remove(0, 1);
			choosedStartSet(Convert::ToInt32(name));
		}
	private:
		System::Void buttonViewMyMarks_Click(System::Object^ sender, System::EventArgs^ e) {
			//Button^ clickedButton = dynamic_cast<Button^>(sender);
			//String^ name = clickedButton->Name->Remove(0, 1);
			//choosedStartSet(Convert::ToInt32(name));
		}
	private:
		System::Void buttonAddTest_Click(System::Object^ sender, System::EventArgs^ e) {
			//Button^ clickedButton = dynamic_cast<Button^>(sender);
			//String^ name = clickedButton->Name->Remove(0, 1);
			//choosedStartSet(Convert::ToInt32(name));
		}
	private:
		System::Void buttonFinishTestSet_Click(System::Object^ sender, System::EventArgs^ e) {
			//Button^ clickedButton = dynamic_cast<Button^>(sender);
			//String^ name = clickedButton->Name->Remove(0, 1);
			//choosedStartSet(Convert::ToInt32(name));
		}
	private: 
		System::Void buttonReturn_Click(System::Object^ sender, System::EventArgs^ e) {
			choosedReturn();
		}
	private: 
		System::Void buttonExit_Click(System::Object^ sender, System::EventArgs^ e) {
			authorization();
		}
};
}
