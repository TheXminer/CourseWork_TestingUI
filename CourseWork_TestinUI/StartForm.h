#pragma once
#include <vcclr.h>
#include <functional>
#include <vector>
#include <ctime>
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
		int groupBoxWidth, yStartMargin, rightGroupBoxMargin;
		array<GroupBox^, 1>^ allGroupBoxes;
		int buttonSize = 40, buttonMargin = 20;
		int choosenTestSet;
	private: Panel^ controlPanel;
	private: Panel^ toolBarPanel;
	private: System::Windows::Forms::ToolStrip^ userToolStrip;
	private: System::Windows::Forms::ToolStripMenuItem^ buttonExit;
	private: System::Windows::Forms::ToolStripButton^ buttonReturn;
	private: System::Windows::Forms::ToolStripSplitButton^ userToolStripButton;
		   Bitmap^ iconDelete;
		   Bitmap^ iconDone;
		   Bitmap^ iconEdit;
		   Bitmap^ iconStart;
		   Bitmap^ iconAdd;
		   Bitmap^ iconReturn;
		   Bitmap^ iconExit;
		   Bitmap^ iconResults;
		   Bitmap^ iconView;
		   std::time_t startTime;
		const Color testPassedColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
		const Color testFailedColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));






















		   Bitmap^ iconProfile;
	public:
		StartForm(void)
		{
			InitializeComponent();
			toolBarPanel = gcnew Panel();
			toolBarPanel->Dock = DockStyle::Top;
			toolBarPanel->Height = 25;

			controlPanel = gcnew Panel();
			controlPanel->Dock = DockStyle::Fill;
			controlPanel->AutoScroll = true;
			//TODO: Add the constructor code here
			//
			curY = 32;
			xTab = 12;
			rightGroupBoxMargin = 50;
			yStartMargin = 37;
			groupBoxWidth = this->Size.Width - rightGroupBoxMargin;
			iconDelete = gcnew Bitmap("./ButtonIcons/iconDelete.png");
			iconDone = gcnew Bitmap("./ButtonIcons/iconDone.png");
			iconEdit = gcnew Bitmap("./ButtonIcons/iconEdit.png");
			iconStart = gcnew Bitmap("./ButtonIcons/iconStart.png");
			iconAdd = gcnew Bitmap("./ButtonIcons/iconAdd.png");
			iconReturn = gcnew Bitmap("./ButtonIcons/iconBack.png");
			iconExit = gcnew Bitmap("./ButtonIcons/iconExit.png");
			iconProfile = gcnew Bitmap("./ButtonIcons/iconProfile.png");
			iconResults = gcnew Bitmap("./ButtonIcons/iconResults.png");
			iconView = gcnew Bitmap("./ButtonIcons/iconView.png");

			showToolBar();

			allGroupBoxes = gcnew array<GroupBox^, 1>(15);
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
			this->AutoScrollMargin = System::Drawing::Size(0, 100);
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1225, 631);
			this->Name = L"StartForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"StartForm";
			this->ResumeLayout(false);

		}
		
		void addTest();
		//Array<GroupBox^

	public:
		//single/multiple chise questions (for user)
		void createSingleChoiceTestGB(String^ question, array<String^>^ answers, int number, int mark);
		void markCorrectAnswer(int answersNumber, int number, int correctAnswerIndex);
		void createMultipleChoiceTestGB(String^ question, array<String^>^ answers, int number, int mark);
		void markCorrectAnswer(int answersNumber, int number, std::vector<int> correctAnswerIndex);
		//open answer question (for user)
		void createOpenTestGB(String^ question, int number);
		//single/multiple chise questions (D/E actions)
		void createAdminChoiceTestGB(int number);
		//show test set name for admin (D/E actions)
		void adminShowTestSetName(String^ testName, int number);
		//show test set name for user (S action)
		void clientShowTestSetName(String^ testName, int number);
		//show button to finish test
		void createFinishButton();
		//show button to start test
		void createAddButton(System::EventHandler^ addEvent);
		
		void showToolBar();

		GroupBox^ getGroupBox(int number) {
			return allGroupBoxes[number];
		}

		//event actions
		void choosedDeleteSet(int testSetNumber);
		void choosedStartSet(int testSetNumber);
		void choosedEditSet(int testSetNumber);
		void choosedDeleteTest(int testNumber);
		void choosedEditTest(int testNumber);
		void choosedReturn();
		void showTestSets(void (*showSetFunc)(StartForm^, String^, int));
		void authorization();
		void AddNewTest();
		void choosedAddSet();
		void choosedEditSetName(int testSetNumber);
		void clearControls();
	private:
		void finishTest();
		void clientShowResult();
		void showTopTestInfo(String^ question, int& curControlY, int number, int mark);
		void showTestResults();
		//void TestCreationWindow();
		//void showSetsToClient();
		//void showSetsToAdmin();

#pragma endregion
	public:
		System::Void buttonAddTestSet_Click(System::Object^ sender, System::EventArgs^ e) {
			choosedAddSet();
		}
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
		System::Void buttonEditTestSetName_Click(System::Object^ sender, System::EventArgs^ e) {
			Button^ clickedButton = dynamic_cast<Button^>(sender);
			String^ name = clickedButton->Name->Remove(0, 1);
			choosenTestSet = Convert::ToInt32(name);
			choosedEditSetName(choosenTestSet);
		}
	private:
		System::Void buttonViewResults_Click(System::Object^ sender, System::EventArgs^ e) {
			Button^ clickedButton = dynamic_cast<Button^>(sender);
			String^ name = clickedButton->Name->Remove(0, 1);
			choosenTestSet = Convert::ToInt32(name);
			showTestResults();
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
			choosedEditTest(Convert::ToInt32(name));
		}
	private:
		System::Void buttonStartTestSet_Click(System::Object^ sender, System::EventArgs^ e) {
			Button^ clickedButton = dynamic_cast<Button^>(sender);
			String^ name = clickedButton->Name->Remove(0, 1);
			choosenTestSet = Convert::ToInt32(name);
			std::time_t curTime;
			std::time(&curTime);
			startTime = curTime;
			choosedStartSet(Convert::ToInt32(name));
		}
	private:
		System::Void buttonViewMyMarks_Click(System::Object^ sender, System::EventArgs^ e) {
			Button^ clickedButton = dynamic_cast<Button^>(sender);
			String^ name = clickedButton->Name->Remove(0, 1);
			choosenTestSet = Convert::ToInt32(name);
			//choosedStartSet(Convert::ToInt32(name));
			clientShowResult();
		}
	private:
		System::Void buttonAddTest_Click(System::Object^ sender, System::EventArgs^ e) {
			//Button^ clickedButton = dynamic_cast<Button^>(sender);
			//String^ name = clickedButton->Name->Remove(0, 1);
			AddNewTest();
		}
	private:
		System::Void buttonFinishTestSet_Click(System::Object^ sender, System::EventArgs^ e) {
			finishTest();
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
