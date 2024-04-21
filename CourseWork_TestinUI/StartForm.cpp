#include "StartForm.h"
#include "ClientAction.h"
#include <msclr\marshal_cppstd.h>
using namespace System;
using namespace System::Windows::Forms;
ClientAction* userBack;
[STAThreadAttribute]

int main(array<String^>^) {
	StudentAnswers studentAnswers;
	Editor editor;
	userBack = new ClientAction();
	//userBack->user = new ClientUser("sdsds");
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles;
	CourseWorkTestingUI::StartForm form;
	//CourseWorkTestingUI:: form1;
	Application::Run(% form);
	return 0;
}

void CourseWorkTestingUI::StartForm::addTest()
{
	std::string question = "sdsd";
	Answer answ1("1?");
	Answer answ2("2?");
	Answer answ3("3?");
	Answer answ4("4?");
	std::vector<Answer > answers = { Answer("1?"),Answer("2?"),Answer("3?"),Answer("4?") };
	std::vector<int> correctIdexes = { 2, 3 };
	Question* extraQuestion1 = new MultipleChoiceQuestion(question, answers, 4, correctIdexes);
	Question* extraQuestion2 = new MultipleChoiceQuestion(question, answers, 4, {1, 2});
	Question* extraQuestion3 = new MultipleChoiceQuestion(question, answers, 4, correctIdexes);
	Question* extraQuestion4 = new MultipleChoiceQuestion(question, answers, 4, correctIdexes);
	//extraQuestion->displayQuestion(this, 0);
	//extraQuestion->displayQuestion(this, 1);
	Question* extraQuestion11 = new SingleChoiceQuestion(question, answers, 4, 3);
	Question* extraQuestion12 = new SingleChoiceQuestion(question, answers, 4, 2);
	Question* extraQuestion13 = new SingleChoiceQuestion(question, answers, 4, 0);
	Question* extraQuestion14 = new SingleChoiceQuestion(question, answers, 4, 1);
	userBack->editor->addTest("faf", extraQuestion1);
	userBack->editor->addTest("faf", extraQuestion2);
	userBack->editor->addTest("faf", extraQuestion11);
	userBack->editor->addTest("faf", extraQuestion12);
	userBack->editor->addTest("faf", extraQuestion13);
	userBack->editor->addTest("faf", extraQuestion3);
	userBack->editor->addTest("faf", extraQuestion14);
	userBack->editor->addTest("faf", extraQuestion4);
	userBack->user->showStartScreen(this);
	//clientBack->setAccess(AuthorizedAsStudent);
	//extraQuestion->displayQuestion(this, 2);
	//extraQuestion->displayQuestion(this, 3);
}

void CourseWorkTestingUI::StartForm::createSingleChoiceTestGB(String^ question, array<String^>^ answers, int number)
{
	allGroupBoxes[number] = gcnew GroupBox();
	int curControlY = yStartMargin, controlHeight = 29;
	array<Control^, 1>^ currControls;
	currControls = gcnew array<RadioButton^, 1>(answers->Length);

	allGroupBoxes[number]->SuspendLayout();
	allGroupBoxes[number]->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	allGroupBoxes[number]->Location = Drawing::Point(12, curY);
	allGroupBoxes[number]->Size = Drawing::Size(groupBoxWidth, 227);
	allGroupBoxes[number]->Text = Convert::ToString(number + 1);

	Label^ labelQuestion = gcnew Label();
	allGroupBoxes[number]->Controls->Add(labelQuestion);
	labelQuestion->AutoSize = true;
	labelQuestion->Location = Drawing::Point(6, yStartMargin);
	labelQuestion->MaximumSize = System::Drawing::Size(groupBoxWidth - 12, 0);
	labelQuestion->Name = L"labelQuestion";
	labelQuestion->Size = Drawing::Size(116, 25);
	labelQuestion->Text = question;
	curControlY += labelQuestion->Size.Height + 20;

	for (int i = 0; i < answers->Length; i++) {
		currControls[i] = gcnew RadioButton;
		allGroupBoxes[number]->Controls->Add(currControls[i]);

		currControls[i]->AutoSize = true;
		currControls[i]->Location = System::Drawing::Point(45, curControlY);
		currControls[i]->Name = L"answerOption" + i;
		currControls[i]->MaximumSize = System::Drawing::Size(groupBoxWidth - 51, 0);
		currControls[i]->Size = System::Drawing::Size(112, controlHeight);
		currControls[i]->Text = answers[i];
		curControlY += 6 + currControls[i]->Size.Height;
	}
	allGroupBoxes[number]->Size = Drawing::Size(groupBoxWidth, curControlY + 15);
	this->Controls->Add(allGroupBoxes[number]);
	allGroupBoxes[number]->ResumeLayout(false);
	allGroupBoxes[number]->PerformLayout();
	if (userBack->user->checkAccess() == AuthorizedAsAdmin) {
		createAdminChoiceTestGB(number);
	}

	curY += allGroupBoxes[number]->Size.Height;
}

void CourseWorkTestingUI::StartForm::createMultipleChoiceTestGB(String^ question, array<String^>^ answers, int number)
{
	allGroupBoxes[number] = gcnew GroupBox();
	int curControlY = yStartMargin, controlHeight = 29;
	array<Control^, 1>^ currControls;
	currControls = gcnew array<CheckBox^, 1>(answers->Length);

	allGroupBoxes[number]->SuspendLayout();
	allGroupBoxes[number]->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	allGroupBoxes[number]->Location = Drawing::Point(12, curY);
	allGroupBoxes[number]->Size = Drawing::Size(groupBoxWidth, 227);
	allGroupBoxes[number]->Text = Convert::ToString(number + 1);

	Label^ labelQuestion = gcnew Label();
	allGroupBoxes[number]->Controls->Add(labelQuestion);
	labelQuestion->AutoSize = true;
	labelQuestion->Location = Drawing::Point(6, yStartMargin);
	labelQuestion->MaximumSize = System::Drawing::Size(groupBoxWidth - 12, 0);
	labelQuestion->Name = L"labelQuestion";
	labelQuestion->Size = Drawing::Size(116, 25);
	labelQuestion->Text = question;
	curControlY += labelQuestion->Size.Height + 20;

	for (int i = 0; i < answers->Length; i++) {
		currControls[i] = gcnew CheckBox;
		allGroupBoxes[number]->Controls->Add(currControls[i]);

		currControls[i]->AutoSize = true;
		currControls[i]->Location = System::Drawing::Point(45, curControlY);
		currControls[i]->Name = L"answerOption" + i;
		currControls[i]->MaximumSize = System::Drawing::Size(groupBoxWidth - 51, 0);
		currControls[i]->Size = System::Drawing::Size(112, controlHeight);
		currControls[i]->Text = answers[i];
		curControlY += 6 + currControls[i]->Size.Height;
	}
	allGroupBoxes[number]->Size = Drawing::Size(groupBoxWidth, curControlY + 15);
	this->Controls->Add(allGroupBoxes[number]);
	allGroupBoxes[number]->ResumeLayout(false);
	allGroupBoxes[number]->PerformLayout();
	if (userBack->user->checkAccess() == AuthorizedAsAdmin) {
		createAdminChoiceTestGB(number);
	}

	curY += allGroupBoxes[number]->Size.Height;
}

void CourseWorkTestingUI::StartForm::createAdminChoiceTestGB(int number)
{
	Label^ labelQuestion = dynamic_cast<Label^>(allGroupBoxes[number]->Controls->Find(L"labelQuestion", false)[0]);
	labelQuestion->MaximumSize = System::Drawing::Size(groupBoxWidth - 12 - 2 * (buttonSize + 5), 0);

	Button^ editButton;
	Button^ deleteButton;
	deleteButton = gcnew Button();
	editButton = gcnew Button();
	allGroupBoxes[number]->Controls->Add(deleteButton);
	allGroupBoxes[number]->Controls->Add(editButton);

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
	deleteButton->Click += gcnew System::EventHandler(this, &StartForm::buttonDeleteTest_Click);
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
	editButton->Click += gcnew System::EventHandler(this, &StartForm::buttonEditTest_Click);
}

void CourseWorkTestingUI::StartForm::markCorrectAnswer(int answersNumber, int number, int correctAnswerIndex)
{
	if (userBack->user->checkAccess() != AuthorizedAsAdmin)
		return;
	GroupBox^ groupBox = allGroupBoxes[number];
	dynamic_cast<RadioButton^>(groupBox->Controls->Find(L"answerOption" + correctAnswerIndex, false)[0])->Checked = true;
	
	for(int i = 0; i < answersNumber; i++) {
		RadioButton^ radioButton = dynamic_cast<RadioButton^>(groupBox->Controls->Find(L"answerOption" + i, false)[0]);
		radioButton->Enabled = false;
	}
}

void CourseWorkTestingUI::StartForm::markCorrectAnswer(int answersNumber, int number, std::vector<int> correctAnswerIndex)
{
	if (userBack->user->checkAccess() != AuthorizedAsAdmin)
		return;
	GroupBox^ groupBox = allGroupBoxes[number];
	for (int answerIndex : correctAnswerIndex) {
		CheckBox^ checkBox = dynamic_cast<CheckBox^>(groupBox->Controls->Find(L"answerOption" + answerIndex, false)[0]);
		checkBox->Checked = true;
	}
	for(int i = 0; i < answersNumber; i++)
	{
		CheckBox^ checkBox = dynamic_cast<CheckBox^>(groupBox->Controls->Find(L"answerOption" + i, false)[0]);
		checkBox->Enabled = false;
	}
}

void CourseWorkTestingUI::StartForm::createOpenTestGB(String^ question, int number)
{
	allGroupBoxes[number] = gcnew GroupBox();
	Label^ labelQuestion;
	TextBox^ textBoxAnswer;

	labelQuestion = gcnew Label();
	textBoxAnswer = gcnew TextBox();
	allGroupBoxes[number]->SuspendLayout();
	//
	// GroupBoxQA
	//
	allGroupBoxes[number]->Controls->Add(labelQuestion);
	allGroupBoxes[number]->Controls->Add(textBoxAnswer);
	allGroupBoxes[number]->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	allGroupBoxes[number]->Location = Drawing::Point(12, curY);
	allGroupBoxes[number]->Size = Drawing::Size(groupBoxWidth, 131);
	allGroupBoxes[number]->Text = Convert::ToString(number + 1);
	// 
	// labelQuestion
	// 
	labelQuestion->AutoSize = true;
	labelQuestion->Location = Drawing::Point(6, yStartMargin);
	labelQuestion->MaximumSize = System::Drawing::Size(groupBoxWidth - 12, 0);
	labelQuestion->Name = L"labelQuestion";
	labelQuestion->Size = Drawing::Size(116, 25);
	labelQuestion->Text = question;
	// 
	// textBox1
	// 
	textBoxAnswer->Location = Drawing::Point(6, yStartMargin + 20 + labelQuestion->Size.Height);
	textBoxAnswer->Name = L"textBoxAnswer";
	textBoxAnswer->Size = Drawing::Size(groupBoxWidth - 12, 31);
	//
	// Show
	//
	allGroupBoxes[number]->Size = Drawing::Size(groupBoxWidth, yStartMargin + 20 + labelQuestion->Size.Height + 31 + 15);
	this->Controls->Add(allGroupBoxes[number]);
	allGroupBoxes[number]->ResumeLayout(false);
	allGroupBoxes[number]->PerformLayout();

	curY += allGroupBoxes[number]->Size.Height;
}

void CourseWorkTestingUI::StartForm::choosedDeleteSet(int testSetNumber)
{
	userBack->editor->deleteSetOfTests(testSetNumber);
	userBack->user->showStartScreen(this);
}

void CourseWorkTestingUI::StartForm::choosedStartSet(int testSetNumber)
{
	clearControls();
	buttonReturn->Visible = true;
	std::vector<Question*> testSet = *userBack->editor->getSetOfTests(userBack->editor->nameOfTests[testSetNumber]);
	int number = 0;
	allGroupBoxes = gcnew array<GroupBox^, 1>(testSet.size());
	for (auto curTest : testSet) {
		curTest->displayQuestion(this, number);
		number++;
	}
	createFinishButton();
}

void CourseWorkTestingUI::StartForm::choosedEditSet(int testSetNumber)
{
	clearControls();
	buttonReturn->Visible = true;
	std::vector<Question*> testSet = *userBack->editor->getSetOfTests(userBack->editor->nameOfTests[testSetNumber]);
	allGroupBoxes = gcnew array<GroupBox^, 1>(testSet.size());
	int number = 0;
	allGroupBoxes = gcnew array<GroupBox^, 1>(testSet.size());
	for (auto curTest : testSet) {
		curTest->displayQuestion(this, number);
		number++;
	}
	createAddButton();
}

void CourseWorkTestingUI::StartForm::choosedDeleteTest(int testNumber)
{
	std::string testSetName = userBack->editor->nameOfTests[choosenTestSet];
	userBack->editor->deleteTest(choosenTestSet, testNumber);
	if(userBack->editor->getSetOfTests(testSetName))
		choosedEditSet(choosenTestSet);
	else
		userBack->user->showStartScreen(this);
}

void CourseWorkTestingUI::StartForm::choosedEditTest(int testSetNumber)
{
	throw gcnew System::NotImplementedException();
	//open window test creation
}

void CourseWorkTestingUI::StartForm::choosedReturn()
{
	userBack->user->showStartScreen(this);
}

void CourseWorkTestingUI::StartForm::showTestSets(void (*showSetFunc)(StartForm^, String^, int))
{
	clearControls();
	std::vector<std::string> testSetsNames = userBack->editor->nameOfTests;
	allGroupBoxes = gcnew array<GroupBox^, 1>(testSetsNames.size());
	int counter = 0;
	for (std::string curTestName : testSetsNames) {
		String^ testName = gcnew System::String(curTestName.c_str());
		showSetFunc(this, testName, counter);
		counter++;
	}
}

void CourseWorkTestingUI::StartForm::authorization()
{
	userBack->logout();
	AuthorizeForm^ authorizeForm = gcnew AuthorizeForm;
	this->Hide();
	authorizeForm->ShowDialog();
	String^ userName = authorizeForm->getUserName();
	this->Show();
	userBack->login(msclr::interop::marshal_as<std::string>(userName));
	delete authorizeForm;
	userBack->user->showStartScreen(this);
	userToolStripButton->Text = gcnew System::String(userBack->user->getUserName().c_str());
}

void CourseWorkTestingUI::StartForm::showSetsToClient()
{
	throw gcnew System::NotImplementedException();
}

void CourseWorkTestingUI::StartForm::showSetsToAdmin()
{
	throw gcnew System::NotImplementedException();
}

void CourseWorkTestingUI::StartForm::clearControls()
{
	curY = 30;
	xTab = 12;
	yStartMargin = 37;
	groupBoxWidth = this->Size.Width - 30;
	this->Controls->Clear();
	if(allGroupBoxes)
		delete[] allGroupBoxes;
	showToolBar();
}
