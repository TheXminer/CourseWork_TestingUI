#pragma once
#include <string>
#include <vector>
#include <sstream> 
#include "MultipleChoiceQuestion.h"
#include "SingleChoiceQuestion.h"
#include <msclr\marshal_cppstd.h>
//__interface ButtonFabric;
//class RadioButtonFabric;
//class CheckBoxButtonFabric;

namespace CourseWorkTestingUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;


	/// <summary>
	/// Summary for TestEditForm
	/// </summary>
	public delegate void ShowPossibleAnswer(String^ answer, bool isCorrect, int& yStartPos, int number, EventHandler^ leaveEvent);
	public delegate void QuestionCreate();
	public ref class TestEditForm : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBoxMark;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ comboBox1;



		List<String^>^ answers;
		List<int>^ correctAnswerIndexes;
		ShowPossibleAnswer^ showPossibleAnswerFunc;
		QuestionCreate^ questionCreate;
		String^ testName;
		int mark = 0;
		Question* createdQuestion;



	public:
		TestEditForm(void)
		{
			//ButtonFabric* f = new CheckBoxButtonFabric();
			createdQuestion = nullptr;
			answers = gcnew List<String^>;
			correctAnswerIndexes = gcnew List<int>;
			testName = "";
			InitializeComponent();
			this->buttonApply->BackgroundImage = gcnew Bitmap("./ButtonIcons/iconDone.png");
			this->buttonCancle->BackgroundImage = gcnew Bitmap("./ButtonIcons/iconDelete.png");
			this->textBoxQuestion->Text = (testName->Length == 0) ? L"Enter Your Question Here" : testName;
			this->Text = L"Create Test Form";
			//
			//TODO: Add the constructor code here
			//
		}
		TestEditForm(Question* question)
		{
			answers = gcnew List<String^>;
			correctAnswerIndexes = gcnew List<int>;
			InitializeComponent();
			this->buttonApply->BackgroundImage = gcnew Bitmap("./ButtonIcons/iconDone.png");
			this->buttonCancle->BackgroundImage = gcnew Bitmap("./ButtonIcons/iconDelete.png");
			this->Text = L"Edit Test Form";
			this->textBoxMark->Text = question->getMark().ToString();
			this->textBoxQuestion->Text = gcnew System::String(question->getQuestion().c_str());
			std::vector<Answer> answers = question->getAnswers();
			for (Answer answer : answers) {
				this->answers->Add(gcnew System::String(answer.getAnswer().c_str()));
			}
			convertStringToVector(question->getCorrectAnswers());
			comboBox1->Text = gcnew System::String(question->getType().c_str());
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TestEditForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonApply;
	private: System::Windows::Forms::Button^ buttonCancle;
	protected:

	protected:


	private: System::Windows::Forms::TextBox^ textBoxQuestion;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;








	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:

	protected:

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
		//void InitializeComponent(void)
		//{
		//	this->buttonApply = (gcnew System::Windows::Forms::Button());
		//	this->buttonCancle = (gcnew System::Windows::Forms::Button());
		//	this->textBoxQuestion = (gcnew System::Windows::Forms::TextBox());
		//	this->label1 = (gcnew System::Windows::Forms::Label());
		//	this->label2 = (gcnew System::Windows::Forms::Label());
		//	this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
		//	this->label4 = (gcnew System::Windows::Forms::Label());
		//	this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
		//	this->label3 = (gcnew System::Windows::Forms::Label());
		//	this->textBoxMark = (gcnew System::Windows::Forms::TextBox());
		//	this->groupBox1->SuspendLayout();
		//	this->SuspendLayout();
		//	// 
		//	// buttonApply
		//	// 
		//	this->buttonApply->Location = System::Drawing::Point(380, 28);
		//	this->buttonApply->Name = L"buttonApply";
		//	this->buttonApply->Size = System::Drawing::Size(36, 36);
		//	this->buttonApply->TabIndex = 0;
		//	this->buttonApply->Text = L"Appl";
		//	this->buttonApply->UseVisualStyleBackColor = true;
		//	this->buttonApply->Click += gcnew System::EventHandler(this, &TestEditForm::buttonApply_Click);
		//	// 
		//	// buttonCancle
		//	// 
		//	this->buttonCancle->Location = System::Drawing::Point(422, 28);
		//	this->buttonCancle->Name = L"buttonCancle";
		//	this->buttonCancle->Size = System::Drawing::Size(36, 36);
		//	this->buttonCancle->TabIndex = 1;
		//	this->buttonCancle->Text = L"Can";
		//	this->buttonCancle->UseVisualStyleBackColor = true;
		//	this->buttonCancle->Click += gcnew System::EventHandler(this, &TestEditForm::buttonDelete_Click);
		//	// 
		//	// textBoxQuestion
		//	// 
		//	this->textBoxQuestion->Location = System::Drawing::Point(6, 44);
		//	this->textBoxQuestion->Name = L"textBoxQuestion";
		//	this->textBoxQuestion->Size = System::Drawing::Size(321, 20);
		//	this->textBoxQuestion->TabIndex = 2;
		//	this->textBoxQuestion->Text = L"Enter Your Question Here";
		//	this->textBoxQuestion->Enter += gcnew System::EventHandler(this, &TestEditForm::textBox1_Enter);
		//	this->textBoxQuestion->Leave += gcnew System::EventHandler(this, &TestEditForm::textBox1_Leave);
		//	// 
		//	// label1
		//	// 
		//	this->label1->AutoSize = true;
		//	this->label1->Location = System::Drawing::Point(29, 28);
		//	this->label1->Name = L"label1";
		//	this->label1->Size = System::Drawing::Size(52, 13);
		//	this->label1->TabIndex = 3;
		//	this->label1->Text = L"Question:";
		//	// 
		//	// label2
		//	// 
		//	this->label2->AutoSize = true;
		//	this->label2->Location = System::Drawing::Point(32, 73);
		//	this->label2->Name = L"label2";
		//	this->label2->Size = System::Drawing::Size(50, 13);
		//	this->label2->TabIndex = 4;
		//	this->label2->Text = L"Answers:";
		//	// 
		//	// groupBox1
		//	// 
		//	this->groupBox1->Controls->Add(this->label4);
		//	this->groupBox1->Controls->Add(this->comboBox1);
		//	this->groupBox1->Controls->Add(this->label3);
		//	this->groupBox1->Controls->Add(this->textBoxMark);
		//	this->groupBox1->Controls->Add(this->buttonCancle);
		//	this->groupBox1->Controls->Add(this->buttonApply);
		//	this->groupBox1->Controls->Add(this->label1);
		//	this->groupBox1->Controls->Add(this->label2);
		//	this->groupBox1->Controls->Add(this->textBoxQuestion);
		//	this->groupBox1->Location = System::Drawing::Point(12, 12);
		//	this->groupBox1->Name = L"groupBox1";
		//	this->groupBox1->Size = System::Drawing::Size(464, 196);
		//	this->groupBox1->TabIndex = 15;
		//	this->groupBox1->TabStop = false;
		//	// 
		//	// label4
		//	// 
		//	this->label4->AutoSize = true;
		//	this->label4->Location = System::Drawing::Point(281, 73);
		//	this->label4->Name = L"label4";
		//	this->label4->Size = System::Drawing::Size(34, 13);
		//	this->label4->TabIndex = 18;
		//	this->label4->Text = L"Type:";
		//	// 
		//	// comboBox1
		//	// 
		//	this->comboBox1->FormattingEnabled = true;
		//	this->comboBox1->Location = System::Drawing::Point(337, 70);
		//	this->comboBox1->Name = L"comboBox1";
		//	this->comboBox1->Size = System::Drawing::Size(121, 21);
		//	this->comboBox1->TabIndex = 17;
		//	// 
		//	// label3
		//	// 
		//	this->label3->AutoSize = true;
		//	this->label3->Location = System::Drawing::Point(330, 28);
		//	this->label3->Name = L"label3";
		//	this->label3->Size = System::Drawing::Size(34, 13);
		//	this->label3->TabIndex = 16;
		//	this->label3->Text = L"Mark:";
		//	// 
		//	// textBoxMark
		//	// 
		//	this->textBoxMark->Location = System::Drawing::Point(333, 44);
		//	this->textBoxMark->Name = L"textBoxMark";
		//	this->textBoxMark->Size = System::Drawing::Size(41, 20);
		//	this->textBoxMark->TabIndex = 15;
		//	// 
		//	// TestEditForm
		//	// 
		//	this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		//	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		//	this->AutoScroll = true;
		//	this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
		//	this->ClientSize = System::Drawing::Size(488, 217);
		//	this->Controls->Add(this->groupBox1);
		//	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
		//	this->Name = L"TestEditForm";
		//	this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		//	this->Text = L"Edit Form";
		//	this->groupBox1->ResumeLayout(false);
		//	this->groupBox1->PerformLayout();
		//	this->ResumeLayout(false);
		//}
		void InitializeComponent(void)
		{
			this->buttonApply = (gcnew System::Windows::Forms::Button());
			this->buttonCancle = (gcnew System::Windows::Forms::Button());
			this->textBoxQuestion = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxMark = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// buttonApply
			// 
			this->buttonApply->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->buttonApply->Location = System::Drawing::Point(398, 12);
			this->buttonApply->Name = L"buttonApply";
			this->buttonApply->Size = System::Drawing::Size(36, 36);
			this->buttonApply->TabIndex = 0;
			this->buttonApply->UseVisualStyleBackColor = true;
			this->buttonApply->Click += gcnew System::EventHandler(this, &TestEditForm::buttonApply_Click);
			// 
			// buttonCancle
			// 
			this->buttonCancle->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->buttonCancle->Location = System::Drawing::Point(440, 12);
			this->buttonCancle->Name = L"buttonCancle";
			this->buttonCancle->Size = System::Drawing::Size(36, 36);
			this->buttonCancle->TabIndex = 1;
			this->buttonCancle->UseVisualStyleBackColor = true;
			this->buttonCancle->Click += gcnew System::EventHandler(this, &TestEditForm::buttonDelete_Click);
			// 
			// textBoxQuestion
			// 
			this->textBoxQuestion->Location = System::Drawing::Point(12, 28);
			this->textBoxQuestion->Name = L"textBoxQuestion";
			this->textBoxQuestion->Size = System::Drawing::Size(333, 20);
			this->textBoxQuestion->TabIndex = 2;
			this->textBoxQuestion->Enter += gcnew System::EventHandler(this, &TestEditForm::textBox1_Enter);
			this->textBoxQuestion->Leave += gcnew System::EventHandler(this, &TestEditForm::textBox1_Leave);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(35, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Question:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Answers:";
			// 
			// groupBox1
			// 
			this->groupBox1->Location = System::Drawing::Point(12, 81);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(464, 186);
			this->groupBox1->TabIndex = 15;
			this->groupBox1->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(236, 57);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(34, 13);
			this->label4->TabIndex = 18;
			this->label4->Text = L"Type:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Single Choice", L"Multiple Choice" });
			this->comboBox1->Location = System::Drawing::Point(276, 54);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(200, 21);
			this->comboBox1->TabIndex = 17;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &TestEditForm::comboBox1_SelectedIndexChanged);
			this->comboBox1->TextChanged += gcnew System::EventHandler(this, &TestEditForm::comboBox1_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(348, 12);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(34, 13);
			this->label3->TabIndex = 16;
			this->label3->Text = L"Mark:";
			// 
			// textBoxMark
			// 
			this->textBoxMark->Location = System::Drawing::Point(351, 28);
			this->textBoxMark->Name = L"textBoxMark";
			this->textBoxMark->Size = System::Drawing::Size(41, 20);
			this->textBoxMark->TabIndex = 15;
			this->textBoxMark->Text = L"1";
			this->textBoxMark->TextChanged += gcnew System::EventHandler(this, &TestEditForm::textBoxMark_TextChanged);
			// 
			// TestEditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(497, 304);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->textBoxQuestion);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonApply);
			this->Controls->Add(this->buttonCancle);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBoxMark);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label3);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"TestEditForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Edit Form";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	private:
		void convertStringToVector(std::string answers) {
			std::istringstream iss(answers);
			std::string token;
			while (std::getline(iss, token, ',')) {
				this->correctAnswerIndexes->Add(std::stoi(token));
			}
		}
	private:
		void showTextBoxAnswer(String^ answer, int &yStartPos, int number, EventHandler^ leaveEvent) {
			// 
			// textBox[N]
			// 
			TextBox^ textBox;
			textBox = (gcnew System::Windows::Forms::TextBox());
			textBox->Location = System::Drawing::Point(47, yStartPos);
			textBox->Name = L"A" + number;
			textBox->Size = System::Drawing::Size(405, 20);
			textBox->TabIndex = 20;
			textBox->Text = answer;
			textBox->Leave += leaveEvent;
			this->groupBox1->Controls->Add(textBox);
			yStartPos += 26;
		}
	private:
		void showRadioAnswer(String^ answer, bool isCorrectAnswer, int &yPosition, int number, EventHandler^ leaveEvent) {
			int buttonMargin = 3;
			// 
			// radioButton1
			// 
			RadioButton^ radioButton;
			radioButton = (gcnew System::Windows::Forms::RadioButton());
			radioButton->AutoSize = true;
			radioButton->Location = System::Drawing::Point(26, yPosition + buttonMargin);
			radioButton->Name = L"B" + number;
			radioButton->Size = System::Drawing::Size(15, 14);
			radioButton->TabIndex = 27;
			radioButton->TabStop = true;
			radioButton->Checked = isCorrectAnswer;
			radioButton->UseVisualStyleBackColor = true;
			radioButton->CheckedChanged += gcnew System::EventHandler(this, &TestEditForm::radioButton_CheckedChanged);
			this->groupBox1->Controls->Add(radioButton);
			//
			// textBox
			//
			showTextBoxAnswer(answer, yPosition, number, leaveEvent);
			///////////////////////////////////////////////////////////////////////
			//TextBox^ textBox2;
			//RadioButton^ radioButton2;
			//radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			//textBox2 = (gcnew System::Windows::Forms::TextBox());
			//// 
			//// radioButton2
			//// 
			//radioButton2->AutoSize = true;
			//radioButton2->Location = System::Drawing::Point(33, yStartPos + buttonMargin);
			//radioButton2->Name = L"radioButton2";
			//radioButton2->Size = System::Drawing::Size(14, 13);
			//radioButton2->TabIndex = 28;
			//radioButton2->TabStop = true;
			//radioButton2->UseVisualStyleBackColor = true;
			//// 
			//// textBox2
			//// 
			//textBox2->Location = System::Drawing::Point(47, yStartPos);
			//textBox2->Name = L"textBox2";
			//textBox2->Size = System::Drawing::Size(405, 20);
			//textBox2->TabIndex = 22;
			//this->groupBox1->Controls->Add(radioButton2);
			//this->groupBox1->Controls->Add(textBox2);
			///////////////////////////////////////////////////////////////////////

		}
	private:
		void showCheckBoxAnswer(String^ answer, bool isCorrectAnswer, int &yPosition, int number, EventHandler^ leaveEvent) {
			int buttonMargin = 3;
			// 
			// checkBox1
			// 
			CheckBox^ checkBox;
			checkBox = (gcnew System::Windows::Forms::CheckBox());
			checkBox->AutoSize = true;
			checkBox->Location = System::Drawing::Point(26, yPosition + buttonMargin);
			checkBox->Name = L"B" + number;
			checkBox->Size = System::Drawing::Size(15, 14);
			checkBox->TabIndex = 19;
			checkBox->Checked = isCorrectAnswer;
			checkBox->UseVisualStyleBackColor = true;
			checkBox->CheckedChanged += gcnew System::EventHandler(this, &TestEditForm::checkBox_CheckedChanged);
			this->groupBox1->Controls->Add(checkBox);
			//
			// textBox
			//
			showTextBoxAnswer(answer, yPosition, number, leaveEvent);
		}
	private:
		void clearGroupBox() {
			this->groupBox1->Controls->Clear();
		}
	private:
		int findIndexInVector(List<int>^ curVector, int index) {
			for (int i = 0; i < curVector->Count; i++) {
				if (curVector[i] == index)
					return i;
			}
			return -1;
		}
	private:
		bool isIndexInVector(List<int>^ curVector, int index) {
			int i = findIndexInVector(curVector, index);
			bool res = (i != -1) ? true : false;
			return res;
		}
	private:
		void redraw() {
			//InitializeComponent();
			clearGroupBox();
			int curY = 19, extraMargin = 5;
			for (int i = 0; i < answers->Count; i++) {
				showPossibleAnswerFunc(answers[i], isIndexInVector(correctAnswerIndexes, i), curY, i, gcnew System::EventHandler(this, &TestEditForm::textBox_Leave));
			}
			showTextBoxAnswer("", curY, answers->Count, gcnew System::EventHandler(this, &TestEditForm::extraTextBox_Leave));
			//showPossibleAnswerFunc("", false, curY, answers->Count, gcnew System::EventHandler(this, &TestEditForm::extraTextBox_Leave));
			//showPossibleAnswerFunc("", true, curY, 1);
			//resize groupBox
			this->groupBox1->Size = System::Drawing::Size(groupBox1->Size.Width, curY + extraMargin);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
		}
	private:
		void removeIndex(int index) {
			correctAnswerIndexes->RemoveAt(index);			
		}
	private:
		void editCorrectAnswers(bool isChecked, int itemIndex) {
			if (isChecked) {
				correctAnswerIndexes->Add(itemIndex);
				return;
			}
			int findIndex = findIndexInVector(correctAnswerIndexes, itemIndex);
			removeIndex(findIndex);
		}
	private:
		void answersConvert(std::vector<Answer>& answers) {
			for each (auto answer in this->answers) {
				answers.push_back(Answer(msclr::interop::marshal_as<std::string>(answer)));
			}
		}
	private:
		void SingleChoiceQuestionCreate() {
			std::vector<Answer> answers;
			std::string question = msclr::interop::marshal_as<std::string>(textBoxQuestion->Text);
			answersConvert(answers);
			createdQuestion = new SingleChoiceQuestion(question, answers, Convert::ToInt32(textBoxMark->Text), correctAnswerIndexes[0]);
		}
	private:
		void MultipleChoiceQuestionCreate() {
			std::vector<Answer> answers;
			answersConvert(answers);
			std::string question = msclr::interop::marshal_as<std::string>(textBoxQuestion->Text);
			std::vector<int> correctAnswers;
			for each (auto index in correctAnswerIndexes) {
				correctAnswers.push_back(index);
			}
			createdQuestion = new MultipleChoiceQuestion(question, answers, Convert::ToInt32(textBoxMark->Text), correctAnswers);
		}
	public:
		Question* getQA() {
			return createdQuestion;
		}
#pragma endregion
		private: System::Void buttonApply_Click(System::Object^ sender, System::EventArgs^ e) {
			//std::string question = "new quewstion";
			//Answer answ1("1?");
			//Answer answ2("2?");
			//Answer answ3("3?");
			//Answer answ4("4?");
			//std::vector<Answer > answers = { Answer("1?"),Answer("2?"),Answer("3?"),Answer("4?") };
			//createdQA = new SingleChoiceQuestion(question, answers, 4, 3);
			if (answers->Count == 0 || correctAnswerIndexes->Count == 0 || textBoxQuestion->Text == "Enter Your Question Here")
				return;
			questionCreate();
			this->Close();
		}

		private: System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}

		private: System::Void textBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
			if (textBoxQuestion->Text == "Enter Your Question Here")
			{
				textBoxQuestion->Text = "";
			}
		}

		private: System::Void textBox1_Leave(System::Object^ sender, System::EventArgs^ e) {
			if (textBoxQuestion->Text->Length == 0)
			{
				textBoxQuestion->Text = "Enter Your Question Here";
			}
		}

		private: System::Void textBox_Leave(System::Object^ sender, System::EventArgs^ e) {
			static bool isProcessing = false;
			if (isProcessing) {
				return;
			}
			isProcessing = true;
			TextBox^ textBox = dynamic_cast<TextBox^>(sender);
			int index = Convert::ToInt32(textBox->Name->Remove(0, 1));
			answers[index] = textBox->Text;
			if (textBox->Text->Length != 0) {
				isProcessing = false;
				return;
			}
			//delete
			int findIndex = findIndexInVector(correctAnswerIndexes, index);
			answers->RemoveAt(index);
			if ((findIndex != -1) ? true : false) {
				removeIndex(findIndex); 
			}
			for (int i = 0; i < correctAnswerIndexes->Count; i++) {
				if (correctAnswerIndexes[i] > index)
					correctAnswerIndexes[i]--;
			}
			redraw();
			isProcessing = false;
		}

		private: System::Void extraTextBox_Leave(System::Object^ sender, System::EventArgs^ e) {
			TextBox^ textBox = dynamic_cast<TextBox^>(sender);
			if (textBox->Text->Length != 0) {
				answers->Add(textBox->Text);
				textBox->Text = "";
				redraw();
				//checkButton
				return;
			}
		}

		private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			ComboBox^ comboBox = dynamic_cast<ComboBox^>(sender);
			if (comboBox->Text == "Single Choice") {
				if (correctAnswerIndexes->Count > 1) {
					delete correctAnswerIndexes;
					correctAnswerIndexes = gcnew List<int>;
				}
				showPossibleAnswerFunc = gcnew ShowPossibleAnswer(this, &TestEditForm::showRadioAnswer);
				questionCreate = gcnew QuestionCreate(this, &TestEditForm::SingleChoiceQuestionCreate);
			}
			if (comboBox->Text == "Multiple Choice") {				
				showPossibleAnswerFunc = gcnew ShowPossibleAnswer(this, &TestEditForm::showCheckBoxAnswer);
				questionCreate = gcnew QuestionCreate(this, &TestEditForm::MultipleChoiceQuestionCreate);
			}
			redraw();
		}

		private: System::Void radioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			RadioButton^ currentButton = dynamic_cast<RadioButton^>(sender);
			int index = Convert::ToInt32(currentButton->Name->Remove(0, 1));
			editCorrectAnswers(currentButton->Checked, index);
		}

		private: System::Void checkBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			CheckBox^ currentButton = dynamic_cast<CheckBox^>(sender);
			int index = Convert::ToInt32(currentButton->Name->Remove(0, 1));
			editCorrectAnswers(currentButton->Checked, index);
		}
		private: System::Void textBoxMark_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			TextBox^ markTextBox = dynamic_cast<TextBox^>(sender);
			int curMark;
			if (markTextBox->Text->Length == 0)
			{
				curMark = 0;
				markTextBox->Text = curMark.ToString();
				return;
			}
			if (Int32::TryParse(markTextBox->Text, curMark)) {
				return;
			}
			String^ clearedMark = "";
			for each (auto c in markTextBox->Text) {
				if (std::isdigit(c))
					clearedMark += c;
			}
			markTextBox->Text = clearedMark;
		}
};
}
