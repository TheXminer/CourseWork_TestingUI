#include "StartForm.h"
#include "ClientAction.h"
#include "AuthorizeForm.h"
#include "TestEditForm.h"
#include "TestSetEditForm.h"
#include <msclr\marshal_cppstd.h>
using namespace System;
using namespace System::Windows::Forms;
ClientAction* testBack;
[STAThreadAttribute]

int main(array<String^>^) {
	testBack = new ClientAction();
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
	std::string testSetName = "Start Test 1";
	Question* question = new SingleChoiceQuestion("What is the capital city of France?", 
		{ Answer("Berlin"),Answer("Madrid"),Answer("Paris"),Answer("Rome") }, 2, 2);
	testBack->editor->addTest(testSetName, question);
	question = new MultipleChoiceQuestion("Which of the following are programming languages?", 
		{ Answer("Python"),Answer("HTML"),Answer("JavaScript"),Answer("CSS") }, 4, { 0, 2 });
	testBack->editor->addTest(testSetName, question);
	//
	question = new SingleChoiceQuestion("Who wrote the play 'Romeo and Juliet'?",
		{ Answer("Charles Dickens"),Answer("William Shakespeare"),
		Answer("Jane Austen"),Answer("Mark Twain") }, 4, 1);
	testBack->editor->addTest(testSetName, question);
	question = new MultipleChoiceQuestion("Which of the following countries are located in South America?",
		{ Answer("Brazil"),Answer("Mexico"),Answer("Argentina"),Answer("Canada") }, 4, { 0, 2 });
	testBack->editor->addTest(testSetName, question);
	//
	question = new SingleChoiceQuestion("What is the largest planet in our solar system?",
		{ Answer("Earth"),Answer("Mars"),
		Answer("Jupiter"),Answer("Saturn") }, 3, 2);
	testBack->editor->addTest(testSetName, question);
	question = new MultipleChoiceQuestion("Which of the following elements are noble gases?",
		{ Answer("Oxygen"),Answer("Helium"),Answer("Hydrogen"),Answer("Neon") }, 8, { 1, 3 });
	testBack->editor->addTest(testSetName, question);

	//
	testSetName = "Start Test 2";
	question = new SingleChoiceQuestion("What is the chemical symbol for gold?",
		{ Answer("Au"),Answer("Ag"),
		Answer("Pb"),Answer("Fe") }, 2, 0);
	testBack->editor->addTest(testSetName, question);
	question = new MultipleChoiceQuestion("Which of the following are components of a computer?",
		{ Answer("CPU"),Answer("RAM"),Answer("HDD"),Answer("HTTP") }, 5, { 0, 1, 2 });
	testBack->editor->addTest(testSetName, question);
	//
	question = new SingleChoiceQuestion("In what year did the Titanic sink?",
		{ Answer("1905"),Answer("1912"),
		Answer("1918"),Answer("1923") }, 3, 1);
	testBack->editor->addTest(testSetName, question);
	question = new MultipleChoiceQuestion("Which of the following are mammals?",
		{ Answer("Whale"),Answer("Shark"),Answer("Dolphin"),Answer("Crocodile") }, 4, { 0, 2 });
	testBack->editor->addTest(testSetName, question);

	//std::string question = "sdsd";
	//Answer answ1("1?");
	//Answer answ2("2?");
	//Answer answ3("3?");
	//Answer answ4("4?");
	//std::vector<Answer > answers = { Answer("1?"),Answer("2?"),Answer("3?"),Answer("4?") };
	//std::vector<int> correctIdexes = { 2, 3 };
	//Question* extraQuestion1 = new MultipleChoiceQuestion(question, answers, 4, correctIdexes);
	//Question* extraQuestion2 = new MultipleChoiceQuestion(question, answers, 4, {1, 2});
	//Question* extraQuestion3 = new MultipleChoiceQuestion(question, answers, 4, correctIdexes);
	//Question* extraQuestion4 = new MultipleChoiceQuestion(question, answers, 4, correctIdexes);
	////extraQuestion->displayQuestion(this, 0);
	////extraQuestion->displayQuestion(this, 1);
	//Question* extraQuestion11 = new SingleChoiceQuestion(question, answers, 4, 3);
	//Question* extraQuestion12 = new SingleChoiceQuestion(question, answers, 4, 2);
	//Question* extraQuestion13 = new SingleChoiceQuestion(question, answers, 4, 0);
	//Question* extraQuestion14 = new SingleChoiceQuestion(question, answers, 4, 1);
	//testBack->editor->addTest("faf", extraQuestion1);
	//testBack->editor->addTest("faf", extraQuestion2);
	//testBack->editor->addTest("faf", extraQuestion11);
	//testBack->editor->addTest("faf", extraQuestion12);
	//testBack->editor->addTest("faf", extraQuestion13);
	//testBack->editor->addTest("faf", extraQuestion3);
	//testBack->editor->addTest("faf", extraQuestion14);
	//testBack->editor->addTest("faf", extraQuestion4);
	testBack->user->showStartScreen(this);
	//clientBack->setAccess(AuthorizedAsStudent);
	//extraQuestion->displayQuestion(this, 2);
	//extraQuestion->displayQuestion(this, 3);
}

void CourseWorkTestingUI::StartForm::showTopTestInfo(String^ question, int& curControlY, int number, int mark) {
	//
	// QuestionLable
	//
	Label^ labelQuestion = gcnew Label();
	allGroupBoxes[number]->Controls->Add(labelQuestion);
	labelQuestion->AutoSize = true;
	labelQuestion->Location = Drawing::Point(6, yStartMargin);
	labelQuestion->MaximumSize = System::Drawing::Size(groupBoxWidth - 12, 0);
	labelQuestion->Name = L"labelQuestion";
	labelQuestion->Size = Drawing::Size(116, 25);
	labelQuestion->Text = question;
	curControlY += labelQuestion->Size.Height + 10;
	//
	// MarkLable
	//
	Label^ labelMark = gcnew Label();
	allGroupBoxes[number]->Controls->Add(labelMark);
	labelMark->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	labelMark->AutoSize = true;
	labelMark->Location = Drawing::Point(6, curControlY);
	labelMark->MaximumSize = System::Drawing::Size(groupBoxWidth - 12, 0);
	labelMark->Name = L"labelMark";
	labelMark->Size = Drawing::Size(116, 25);
	labelMark->Text = "Mark: " + mark;
	curControlY += labelMark->Size.Height + 20;
}

void CourseWorkTestingUI::StartForm::showTestResults()
{
	clearControls();
	buttonReturn->Visible = true;
	auto allTestAnswers = testBack->studentAnswers->getAllTestAnswers(testBack->editor->nameOfTests[choosenTestSet]);
	if (allTestAnswers->size() == 0)
		return;
	DataGridView^ dataGridView;
	DataGridViewTextBoxColumn^ StudentNameColumn;
	DataGridViewTextBoxColumn^ MarkColumn;
	DataGridViewTextBoxColumn^ UsedTimeColumn;
	//
	dataGridView = (gcnew System::Windows::Forms::DataGridView());
	StudentNameColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
	MarkColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
	UsedTimeColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
	// 
	// dataGridView
	// 
	dataGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::ColumnHeader;
	dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
	dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
		StudentNameColumn,
			MarkColumn, UsedTimeColumn
	});
	dataGridView->Location = System::Drawing::Point(12, 48);
	dataGridView->Name = L"dataGridView";
	dataGridView->Size = System::Drawing::Size(1179, 571);
	dataGridView->TabIndex = 0; 
	dataGridView->Visible = true;
	// 
	// StudentNameColumn
	// 
	StudentNameColumn->Frozen = true;
	StudentNameColumn->HeaderText = L"Student Name";
	StudentNameColumn->Name = L"StudentNameColumn";
	StudentNameColumn->ReadOnly = true;
	StudentNameColumn->Resizable = System::Windows::Forms::DataGridViewTriState::False;
	StudentNameColumn->Width = 300;
	// 
	// MarkColumn
	// 
	MarkColumn->Frozen = true;
	MarkColumn->HeaderText = L"Total mark";
	MarkColumn->Name = L"MarkColumn";
	MarkColumn->ReadOnly = true;
	// 
	// UsedTimeColumn
	// 
	UsedTimeColumn->Frozen = true;
	UsedTimeColumn->HeaderText = L"Used Time";
	UsedTimeColumn->Name = L"UsedTimeColumn";
	UsedTimeColumn->ReadOnly = true;
	UsedTimeColumn->Width = 150;
	

	// 
	// No1
	// 	
	int counter = allTestAnswers->at(0)->size() - 3;
	for (int i = 0; i < counter; i++) {
		DataGridViewTextBoxColumn^ MarkColumn;
		MarkColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		dataGridView->Columns->Add(MarkColumn);
		MarkColumn->Frozen = true;
		MarkColumn->ReadOnly = true;
		MarkColumn->HeaderText = L"No" + counter;
		MarkColumn->Name = L"N" + counter;
	}
	for (auto lineText : *allTestAnswers) {
		array<String^, 1>^ lineItems = gcnew array<String^, 1>(counter + 3);
		//lineItems[0] = msclr::interop::marshal_as<System::String^>(lineText->at(0));
		//lineItems[1] = msclr::interop::marshal_as<System::String^>(lineText->at(1));
		//lineItems[2] = msclr::interop::marshal_as<System::String^>(lineText->at(2));
		counter = 0;
		for (auto curLineItem : *lineText) {
			lineItems[counter] = msclr::interop::marshal_as<System::String^>(curLineItem);
			counter++;
		}
		dataGridView->Rows->Add(lineItems);
	}
	
	
	


	controlPanel->Controls->Add(dataGridView);
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(dataGridView))->EndInit();
	//dataGridView->Rows->Add("Item 1, Col 1", "Item 1, Col 2", "Item 1, Col 3");
	//dataGridView->Rows->Add("Item 2, Col 1", "Item 2, Col 2", "Item 2, Col 3");
	//dataGridView->Rows->Add("Item 3, Col 1", "Item 3, Col 2", "Item 3, Col 3");
	//dataGridView->Rows->Add("Item 1, Col 1", "Item 1, Col 2", "Item 1, Col 3");
	//dataGridView->Rows->Add("Item 2, Col 1", "Item 2, Col 2", "Item 2, Col 3");
	//dataGridView->Rows->Add("Item 3, Col 1", "Item 3, Col 2", "Item 3, Col 3");
	//dataGridView->Rows->Add("Item 1, Col 1", "Item 1, Col 2", "Item 1, Col 3");
	//dataGridView->Rows->Add("Item 2, Col 1", "Item 2, Col 2", "Item 2, Col 3");
	//dataGridView->Rows->Add("Item 3, Col 1", "Item 3, Col 2", "Item 3, Col 3");
	//dataGridView->Rows->Add("Item 1, Col 1", "Item 1, Col 2", "Item 1, Col 3");
	//dataGridView->Rows->Add("Item 2, Col 1", "Item 2, Col 2", "Item 2, Col 3");
	//dataGridView->Rows->Add("Item 3, Col 1", "Item 3, Col 2", "Item 3, Col 3");
	//dataGridView->Rows->Add("Item 1, Col 1", "Item 1, Col 2", "Item 1, Col 3");
	//dataGridView->Rows->Add("Item 2, Col 1", "Item 2, Col 2", "Item 2, Col 3");
	//dataGridView->Rows->Add("Item 3, Col 1", "Item 3, Col 2", "Item 3, Col 3");
	//dataGridView->Rows->Add("Item 1, Col 1", "Item 1, Col 2", "Item 1, Col 3");
	//dataGridView->Rows->Add("Item 2, Col 1", "Item 2, Col 2", "Item 2, Col 3");
	//dataGridView->Rows->Add("Item 3, Col 1", "Item 3, Col 2", "Item 3, Col 3");
	//dataGridView->Rows->Add("Item 1, Col 1", "Item 1, Col 2", "Item 1, Col 3");
	//dataGridView->Rows->Add("Item 2, Col 1", "Item 2, Col 2", "Item 2, Col 3");
	//dataGridView->Rows->Add("Item 3, Col 1", "Item 3, Col 2", "Item 3, Col 3");
	//dataGridView->Rows->Add("Item 1, Col 1", "Item 1, Col 2", "Item 1, Col 3");
	//dataGridView->Rows->Add("Item 2, Col 1", "Item 2, Col 2", "Item 2, Col 3");
	//dataGridView->Rows->Add("Item 3, Col 1", "Item 3, Col 2", "Item 3, Col 3");
	//dataGridView->Rows->Add("Item 1, Col 1", "Item 1, Col 2", "Item 1, Col 3");
	//dataGridView->Rows->Add("Item 2, Col 1", "Item 2, Col 2", "Item 2, Col 3");
	//dataGridView->Rows->Add("Item 3, Col 1", "Item 3, Col 2", "Item 3, Col 3");
	//dataGridView->Rows->Add("Item 1, Col 1", "Item 1, Col 2", "Item 1, Col 3");
	//dataGridView->Rows->Add("Item 2, Col 1", "Item 2, Col 2", "Item 2, Col 3");
	//dataGridView->Rows->Add("Item 3, Col 1", "Item 3, Col 2", "Item 3, Col 3");
	//dataGridView->Rows->Add("Item 1, Col 1", "Item 1, Col 2", "Item 1, Col 3");
	//dataGridView->Rows->Add("Item 2, Col 1", "Item 2, Col 2", "Item 2, Col 3");
	//dataGridView->Rows->Add("Item 3, Col 1", "Item 3, Col 2", "Item 3, Col 3");
	//dataGridView->Rows->Add("Item 1, Col 1", "Item 1, Col 2", "Item 1, Col 3");
	//dataGridView->Rows->Add("Item 2, Col 1", "Item 2, Col 2", "Item 2, Col 3");
	//dataGridView->Rows->Add("Item 3, Col 1", "Item 3, Col 2", "Item 3, Col 3");
	dataGridView->ResumeLayout(false);
	dataGridView->PerformLayout();
}

void CourseWorkTestingUI::StartForm::createSingleChoiceTestGB(String^ question, array<String^>^ answers, int number, int mark)
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

	showTopTestInfo(question, curControlY, number, mark);

	for (int i = 0; i < answers->Length; i++) {
		currControls[i] = gcnew RadioButton;
		allGroupBoxes[number]->Controls->Add(currControls[i]);

		currControls[i]->AutoSize = true;
		currControls[i]->Location = System::Drawing::Point(45, curControlY);
		currControls[i]->Name = L"B" + i;
		currControls[i]->MaximumSize = System::Drawing::Size(groupBoxWidth - 51, 0);
		currControls[i]->Size = System::Drawing::Size(112, controlHeight);
		currControls[i]->Text = answers[i];
		curControlY += 6 + currControls[i]->Size.Height;
	}
	allGroupBoxes[number]->Size = Drawing::Size(groupBoxWidth, curControlY + 15);
	controlPanel->Controls->Add(allGroupBoxes[number]);
	allGroupBoxes[number]->ResumeLayout(false);
	allGroupBoxes[number]->PerformLayout();
	/*if (userBack->user->checkAccess() == AuthorizedAsAdmin) {
		createAdminChoiceTestGB(number);
	}*/
	testBack->user->showTestButtons(this, number);

	curY += allGroupBoxes[number]->Size.Height;
}

void CourseWorkTestingUI::StartForm::createMultipleChoiceTestGB(String^ question, array<String^>^ answers, int number, int mark)
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

	showTopTestInfo(question, curControlY, number, mark);

	for (int i = 0; i < answers->Length; i++) {
		currControls[i] = gcnew CheckBox;
		allGroupBoxes[number]->Controls->Add(currControls[i]);

		currControls[i]->AutoSize = true;
		currControls[i]->Location = System::Drawing::Point(45, curControlY);
		currControls[i]->Name = L"B" + i;
		currControls[i]->MaximumSize = System::Drawing::Size(groupBoxWidth - 51, 0);
		currControls[i]->Size = System::Drawing::Size(112, controlHeight);
		currControls[i]->Text = answers[i];
		curControlY += 6 + currControls[i]->Size.Height;
	}
	allGroupBoxes[number]->Size = Drawing::Size(groupBoxWidth, curControlY + 15);
	controlPanel->Controls->Add(allGroupBoxes[number]);
	allGroupBoxes[number]->ResumeLayout(false);
	allGroupBoxes[number]->PerformLayout();
	if (testBack->user->checkAccess() == AuthorizedAsAdmin) {
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

void CourseWorkTestingUI::StartForm::adminShowTestSetName(String^ testName, int number)
{
	allGroupBoxes[number] = gcnew GroupBox();
	Label^ labelTestName;
	Button^ editSetButton;
	Button^ deleteButton;
	Button^ editNameButton;
	Button^ viewResultsButton;

	labelTestName = gcnew Label();
	deleteButton = gcnew Button();
	editSetButton = gcnew Button();
	editNameButton = gcnew Button();
	viewResultsButton = gcnew Button();
	//
	// GroupBoxQ
	//
	allGroupBoxes[number]->Controls->Add(labelTestName);
	allGroupBoxes[number]->Controls->Add(deleteButton);
	allGroupBoxes[number]->Controls->Add(editSetButton);
	allGroupBoxes[number]->Controls->Add(editNameButton);
	allGroupBoxes[number]->Controls->Add(viewResultsButton);
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
	labelTestName->MaximumSize = System::Drawing::Size(groupBoxWidth - 4 * (buttonMargin + buttonSize) - buttonMargin, 0);
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
	// ViewResultsButton
	//
	viewResultsButton->BackgroundImage = iconResults;
	viewResultsButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
	viewResultsButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
	viewResultsButton->ForeColor = System::Drawing::Color::Transparent;
	viewResultsButton->Location = System::Drawing::Point(groupBoxWidth - 2 * (buttonMargin + buttonSize), 33);
	viewResultsButton->Name = L"V" + Convert::ToString(number);
	viewResultsButton->Size = System::Drawing::Size(buttonSize, buttonSize);
	viewResultsButton->Click += gcnew System::EventHandler(this, &StartForm::buttonViewResults_Click);
	//
	// editSetButton
	//
	editSetButton->BackgroundImage = iconView;
	editSetButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
	editSetButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
	editSetButton->ForeColor = System::Drawing::Color::Transparent;
	editSetButton->Location = System::Drawing::Point(groupBoxWidth - 3 * (buttonMargin + buttonSize), 33);
	editSetButton->Name = L"E" + Convert::ToString(number);
	editSetButton->Size = System::Drawing::Size(buttonSize, buttonSize);
	editSetButton->Click += gcnew System::EventHandler(this, &StartForm::buttonEditTestSet_Click);
	//
	// EditNameButton
	//
	editNameButton->BackgroundImage = iconEdit;
	editNameButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
	editNameButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
	editNameButton->ForeColor = System::Drawing::Color::Transparent;
	editNameButton->Location = System::Drawing::Point(groupBoxWidth - 4 * (buttonMargin + buttonSize), 33);
	editNameButton->Name = L"N" + Convert::ToString(number);
	editNameButton->Size = System::Drawing::Size(buttonSize, buttonSize);
	editNameButton->Click += gcnew System::EventHandler(this, &StartForm::buttonEditTestSetName_Click);
	//
	// Show
	//
	allGroupBoxes[number]->Size = Drawing::Size(groupBoxWidth, yStartMargin + 20 + labelTestName->Size.Height + 20);
	controlPanel->Controls->Add(allGroupBoxes[number]);
	allGroupBoxes[number]->ResumeLayout(false);
	allGroupBoxes[number]->PerformLayout();

	curY += allGroupBoxes[number]->Size.Height;
}

void CourseWorkTestingUI::StartForm::markCorrectAnswer(int answersNumber, int number, int correctAnswerIndex)
{
	if (testBack->user->checkAccess() != AuthorizedAsAdmin)
		return;
	GroupBox^ groupBox = allGroupBoxes[number];
	dynamic_cast<RadioButton^>(groupBox->Controls->Find(L"B" + correctAnswerIndex, false)[0])->Checked = true;
	
	for(int i = 0; i < answersNumber; i++) {
		RadioButton^ radioButton = dynamic_cast<RadioButton^>(groupBox->Controls->Find(L"B" + i, false)[0]);
		radioButton->Enabled = false;
	}
}

void CourseWorkTestingUI::StartForm::markCorrectAnswer(int answersNumber, int number, std::vector<int> correctAnswerIndex)
{
	if (testBack->user->checkAccess() != AuthorizedAsAdmin)
		return;
	GroupBox^ groupBox = allGroupBoxes[number];
	for (int answerIndex : correctAnswerIndex) {
		CheckBox^ checkBox = dynamic_cast<CheckBox^>(groupBox->Controls->Find(L"B" + answerIndex, false)[0]);
		checkBox->Checked = true;
	}
	for(int i = 0; i < answersNumber; i++)
	{
		CheckBox^ checkBox = dynamic_cast<CheckBox^>(groupBox->Controls->Find(L"B" + i, false)[0]);
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
	controlPanel->Controls->Add(allGroupBoxes[number]);
	allGroupBoxes[number]->ResumeLayout(false);
	allGroupBoxes[number]->PerformLayout();

	curY += allGroupBoxes[number]->Size.Height;
}

void CourseWorkTestingUI::StartForm::clientShowTestSetName(String^ testName, int number)
{
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
	if (/*isTestPassed*/testBack->studentAnswers->isTestPassed(testBack->user->getUserName(), msclr::interop::marshal_as<std::string>(testName)))
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
	controlPanel->Controls->Add(allGroupBoxes[number]);
	allGroupBoxes[number]->ResumeLayout(false);
	allGroupBoxes[number]->PerformLayout();

	curY += allGroupBoxes[number]->Size.Height;
}

void CourseWorkTestingUI::StartForm::createFinishButton()
{
	Button^ finishButton = gcnew Button();

	finishButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	finishButton->Location = System::Drawing::Point(12, curY);
	finishButton->Name = L"F";
	finishButton->Size = System::Drawing::Size(buttonSize * 4, buttonSize);
	finishButton->TabIndex = 0;
	finishButton->Text = L"Finish";
	finishButton->UseVisualStyleBackColor = true;
	finishButton->Click += gcnew System::EventHandler(this, &StartForm::buttonFinishTestSet_Click);

	controlPanel->Controls->Add(finishButton);
	curY += finishButton->Size.Height;
	finishButton->PerformLayout();
}

void CourseWorkTestingUI::StartForm::createAddButton(System::EventHandler^ addEvent)
{
	Button^ addButton = gcnew Button();
	addButton->BackgroundImage = iconAdd;
	addButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
	addButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
	addButton->ForeColor = System::Drawing::Color::Transparent;
	addButton->Location = System::Drawing::Point(12, curY);
	addButton->Name = L"A";
	addButton->Size = System::Drawing::Size(buttonSize, buttonSize);
	addButton->Click += addEvent;
	//addButton->Click += gcnew System::EventHandler(this, addEvent);
	addButton->UseVisualStyleBackColor = true;
	curY += addButton->Size.Height;

	controlPanel->Controls->Add(addButton);
	addButton->PerformLayout();
}
void CourseWorkTestingUI::StartForm::showToolBar() {
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
	userToolStrip->Dock = DockStyle::Top;
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
	userToolStripButton->Text = gcnew System::String(testBack->user->getUserName().c_str());
	//userToolStripButton->Margin = System::Windows::Forms::Padding(0, 1, 20, 2);
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
	toolBarPanel->Controls->Add(userToolStrip);
	this->Controls->Add(toolBarPanel);
	this->Controls->Add(controlPanel);
	userToolStrip->ResumeLayout(false);
	userToolStrip->PerformLayout();
}

void CourseWorkTestingUI::StartForm::choosedDeleteSet(int testSetNumber)
{
	testBack->editor->deleteSetOfTests(testSetNumber);
	testBack->user->showStartScreen(this);
}

void CourseWorkTestingUI::StartForm::choosedStartSet(int testSetNumber)
{
	clearControls();
	//buttonReturn->Visible = true;
	std::vector<Question*> testSet = *testBack->editor->getSetOfTests(testBack->editor->nameOfTests[testSetNumber]);
	int number = 0;
	allGroupBoxes = gcnew array<GroupBox^, 1>(testSet.size());
	//getResultsFunc = new std::vector<std::function<std::string()>>();
	for (auto curTest : testSet) {
		curTest->displayQuestion(this, number);
		//getResultsFunc->push_back(curTest.)
		number++;
	}
	createFinishButton();
}

void CourseWorkTestingUI::StartForm::choosedEditSet(int testSetNumber)
{
	clearControls();
	buttonReturn->Visible = true;
	std::vector<Question*> testSet = *testBack->editor->getSetOfTests(testBack->editor->nameOfTests[testSetNumber]);
	allGroupBoxes = gcnew array<GroupBox^, 1>(testSet.size());
	int number = 0;
	for (auto curTest : testSet) {
		curTest->displayQuestion(this, number);
		number++;
	}
	createAddButton(gcnew System::EventHandler(this, &StartForm::buttonAddTest_Click));
}

void CourseWorkTestingUI::StartForm::choosedDeleteTest(int testNumber)
{
	std::string testSetName = testBack->editor->nameOfTests[choosenTestSet];
	testBack->editor->deleteTest(choosenTestSet, testNumber);
	testBack->studentAnswers->deleteStudentsAnswer(testSetName, testNumber);
	if(testBack->editor->getSetOfTests(testSetName))
		choosedEditSet(choosenTestSet);
	else
		testBack->user->showStartScreen(this);
}

void CourseWorkTestingUI::StartForm::choosedEditTest(int testNumber)
{
	this->Enabled = false;
	TestEditForm^ testEditorForm = gcnew TestEditForm(testBack->editor->getTest(testBack->editor->nameOfTests[choosenTestSet], testNumber));
	testEditorForm->ShowDialog();
	Question* question = testEditorForm->getQA();
	delete testEditorForm;
	if (question) {
		testBack->editor->editTest(testBack->editor->nameOfTests[choosenTestSet], testNumber, question);
		choosedEditSet(choosenTestSet);
	}
	this->Enabled = true;
	//throw gcnew System::NotImplementedException();
	//open window test creation
}

void CourseWorkTestingUI::StartForm::choosedReturn()
{
	//if (dataGridView->Visible)
	//	dataGridView->Visible = false;
	buttonReturn->Visible = false;
	testBack->user->showStartScreen(this);
}

void CourseWorkTestingUI::StartForm::showTestSets(void (*showSetFunc)(StartForm^, String^, int))
{
	clearControls();
	std::vector<std::string> testSetsNames = testBack->editor->nameOfTests;
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
	testBack->logout();
	AuthorizeForm^ authorizeForm = gcnew AuthorizeForm;
	this->Hide();
	authorizeForm->ShowDialog();
	String^ userName = authorizeForm->getUserName();
	testBack->login(msclr::interop::marshal_as<std::string>(userName));
	delete authorizeForm;
	testBack->user->showStartScreen(this);
	if(testBack->user->checkAccess() != NonAuthorized)
	{
		this->Show();
		userToolStripButton->Text = gcnew System::String(testBack->user->getUserName().c_str());
	}
}

void CourseWorkTestingUI::StartForm::AddNewTest()
{
	this->Enabled = false;
	TestEditForm^ testEditorForm = gcnew TestEditForm();
	testEditorForm->ShowDialog();
	Question* question = testEditorForm->getQA();
	delete testEditorForm;
	if (question) {
		testBack->editor->addTest(choosenTestSet, question); 
		testBack->studentAnswers->addNewTestMark(testBack->editor->nameOfTests[choosenTestSet]);
		choosedEditSet(choosenTestSet);
	}
	this->Enabled = true;
}

void CourseWorkTestingUI::StartForm::choosedAddSet()
{
	this->Enabled = false;
	TestSetEditForm^ testEditorForm = gcnew TestSetEditForm();
	testEditorForm->ShowDialog();
	String^ testSetName = testEditorForm->getTestSetName();
	delete testEditorForm;
	if (testSetName) {
		testBack->editor->addTestSet(msclr::interop::marshal_as<std::string>(testSetName));
		testBack->user->showStartScreen(this);
	}
	this->Enabled = true;
}

void CourseWorkTestingUI::StartForm::choosedEditSetName(int testSetNumber)
{
	this->Enabled = false;
	std::string setName = testBack->editor->nameOfTests[testSetNumber];
	String^ testToEdit = msclr::interop::marshal_as<System::String^>(setName);;
	TestSetEditForm^ testEditorForm = gcnew TestSetEditForm(testToEdit);
	testEditorForm->ShowDialog();
	String^ testSetName = testEditorForm->getTestSetName();
	delete testEditorForm;
	if (testSetName) {
		testBack->editor->changeTestSetName(setName, msclr::interop::marshal_as<std::string>(testSetName));
		testBack->studentAnswers->changeTestSetName(setName, msclr::interop::marshal_as<std::string>(testSetName));
		//userBack->editor->addTestSet(msclr::interop::marshal_as<std::string>(testSetName));
		testBack->user->showStartScreen(this);
	}
	this->Enabled = true;
}

Control^ FindControlByName(Control^ parent, String^ name) {
	for each (Control ^ control in parent->Controls) {
		if (control->Name == name) {
			return control;
		}
	}
	return nullptr;
}

void CourseWorkTestingUI::StartForm::finishTest()
{
	std::vector<std::vector<int>*>* choosenAnswers = new std::vector<std::vector<int>*>;
	std::vector<int>* marks = new std::vector<int>;
	int testNumber = 0;
	for each (auto var in allGroupBoxes) {
		Control^ foundControl;
		std::string curAnswersIndex = "";
		Question* curQuestion = testBack->editor->getTest(choosenTestSet, testNumber);
		choosenAnswers->push_back(new std::vector<int>);
		int iterator = 0;
		while (foundControl = FindControlByName(var, "B" + iterator)) {
			if (curQuestion->isCheckedButton(foundControl)) {
				curAnswersIndex += std::to_string(iterator) + ",";
				choosenAnswers->at(testNumber)->push_back(iterator);
			}
			iterator++;
		}
		if(curAnswersIndex.size() != 0)
			curAnswersIndex.pop_back();
		marks->push_back(curQuestion->checkAnswer(curAnswersIndex));
		testNumber++;
	}
	time_t finishTime;
	std::time(&finishTime);
	StudentAnswerData* answer = new StudentAnswerData(finishTime - startTime, marks, choosenAnswers);
	testBack->studentAnswers->addStudentAnswer(testBack->user->getUserName(), testBack->editor->nameOfTests[choosenTestSet], answer);
	clearControls();
	clientShowResult();
}
void CourseWorkTestingUI::StartForm::clientShowResult()
{
	clearControls();
	buttonReturn->Visible = true;
	std::vector<Question*> testSet = *testBack->editor->getSetOfTests(testBack->editor->nameOfTests[choosenTestSet]);
	StudentAnswerData* userResults = testBack->studentAnswers->getStudentAnswers(testBack->user->getUserName(), testBack->editor->nameOfTests[choosenTestSet]);
	int testNumber = 0;
	allGroupBoxes = gcnew array<GroupBox^, 1>(testSet.size());
	//getResultsFunc = new std::vector<std::function<std::string()>>();
	for (auto curTest : testSet) {
		Question* curQuestion = testBack->editor->getTest(choosenTestSet, testNumber);
		curTest->displayQuestion(this, testNumber);
		allGroupBoxes[testNumber]->Enabled = false;

		Control^ markLabel = FindControlByName(allGroupBoxes[testNumber], "labelMark");
		markLabel->Text = "Received mark: " + userResults->marks->at(testNumber);
		if (!userResults->choosenAnswers->at(testNumber))
			continue;
		Control^ button; 
		for (int i = 0; i < userResults->choosenAnswers->at(testNumber)->size(); i++) {
			if(button = FindControlByName(allGroupBoxes[testNumber], "B" + userResults->choosenAnswers->at(testNumber)->at(i))){
				curQuestion->checkButton(button);
			}
		}
		if(userResults->marks->at(testNumber) != 0)
			allGroupBoxes[testNumber]->BackColor = testPassedColor;
		else
			allGroupBoxes[testNumber]->BackColor = testFailedColor;
		testNumber++;
	}
}
//void CourseWorkTestingUI::StartForm::showSetsToClient()
//{
//	throw gcnew System::NotImplementedException();
//}
//
//void CourseWorkTestingUI::StartForm::showSetsToAdmin()
//{
//	throw gcnew System::NotImplementedException();
//}

void CourseWorkTestingUI::StartForm::clearControls()
{
	curY = 30;
	xTab = 12;
	yStartMargin = 37;
	groupBoxWidth = this->Size.Width - rightGroupBoxMargin;
	controlPanel->Controls->Clear();
	if(allGroupBoxes)
	{
		delete[] allGroupBoxes;
		allGroupBoxes = nullptr;
	}
	//if (getResultsFunc)
	//{
	//	delete[] getResultsFunc;
	//	getResultsFunc = nullptr;
	//}
}

