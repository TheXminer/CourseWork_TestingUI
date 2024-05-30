#include "SingleChoiceQuestion.h"

//void SingleChoiceQuestion::markCorrectAnswer(CourseWorkTestinUI::StartForm^ startForm, int number)
//{
//    System::Windows::Forms::GroupBox^ groupBox = startForm->getGroupBox(number);
//    System::Windows::Forms::RadioButton^ radioButton = dynamic_cast<System::Windows::Forms::RadioButton^>(groupBox->Controls->Find(L"answerOption" + correctAnswer, false)[0]);
//    radioButton->Checked = true;
//    for (int i = 0; i < allAnswers.size(); i++) {
//        System::Windows::Forms::RadioButton^ radioButton = dynamic_cast<System::Windows::Forms::RadioButton^>(groupBox->Controls->Find(L"answerOption" + i, false)[0]);
//        radioButton->Enabled = false;
//    }
//}

SingleChoiceQuestion::SingleChoiceQuestion(std::string question, std::vector<Answer> allAnswers, int mark, int correctAnswer) : Question(question, allAnswers, mark)
{
    this->correctAnswer = correctAnswer;
}

int SingleChoiceQuestion::checkAnswer(int answerNumber) const
{
    if (answerNumber == correctAnswer)
        return mark;
    return 0;
}

void SingleChoiceQuestion::displayQuestion(CourseWorkTestingUI::StartForm^ startForm, int number)
{
    System::String^ strQuestion = gcnew System::String(question.c_str());
    array<System::String^>^ answers = gcnew array<System::String^>(allAnswers.size());

    for (int i = 0; i < allAnswers.size(); i++)
    {
        answers[i] = gcnew System::String(allAnswers[i].getAnswer().c_str());
    }
    startForm->createSingleChoiceTestGB(strQuestion, answers, number, mark);
    startForm->markCorrectAnswer(allAnswers.size(), number, correctAnswer);
}

std::string SingleChoiceQuestion::getType() const
{
    return "Single Choice";
}

int SingleChoiceQuestion::checkAnswer(const std::string& answer)
{
    return checkAnswer(std::stoi(answer));
}

std::string SingleChoiceQuestion::getCorrectAnswers()
{
    return std::to_string(correctAnswer);
}

//void SingleChoiceQuestion::displayQuestionWhithButtons(CourseWorkTestinUI::StartForm^ startForm, int number)
//{
//    System::String^ strQuestion = gcnew System::String(question.c_str());
//    array<System::String^>^ answers = gcnew array<System::String^>(allAnswers.size());
//
//    for (int i = 0; i < allAnswers.size(); i++)
//    {
//        answers[i] = gcnew System::String(allAnswers[i].getAnswer().c_str());
//    }
//    startForm->createAdminChoiceTestGB(strQuestion, answers, number, true);
//    markCorrectAnswer(startForm, number);
//}
