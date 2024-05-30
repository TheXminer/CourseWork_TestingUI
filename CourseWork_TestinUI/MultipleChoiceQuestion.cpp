#include "MultipleChoiceQuestion.h"
//void MultipleChoiceQuestion::markCorrectAnswer(CourseWorkTestinUI::StartForm^ startForm, int number)
//{
//    System::Windows::Forms::GroupBox^ groupBox = startForm->getGroupBox(number);
//    for (int answerIndex : correctAnswersIndex) {
//        System::Windows::Forms::CheckBox^ checkBox = dynamic_cast<System::Windows::Forms::CheckBox^>(groupBox->Controls->Find(L"answerOption" + answerIndex, false)[0]);
//        checkBox->Checked = true;
//    }
//    for (int i = 0; i < allAnswers.size(); i++) {
//        System::Windows::Forms::CheckBox^ checkBox = dynamic_cast<System::Windows::Forms::CheckBox^>(groupBox->Controls->Find(L"answerOption" + i, false)[0]);
//        checkBox->Enabled = false;
//    }
//}
MultipleChoiceQuestion::MultipleChoiceQuestion(std::string question, std::vector<Answer> allAnswers, int mark, std::vector<int> correctAnswers) : Question(question, allAnswers, mark)
{
    this->correctAnswersIndex = correctAnswers;
}
int MultipleChoiceQuestion::checkAnswer(std::vector<int> answers) const
{
    if (answers.size() != correctAnswersIndex.size())
        return 0;
    int size = answers.size();
    for (int i = 0; i < size; i++) {
        bool isContain = false;
        for (int j = 0; j < size; j++) {
            if (correctAnswersIndex[j] == answers[i]) {
                isContain = true;
                break;
            }
        }
        if (!isContain)
            return 0;
    }
    return mark;
}

void MultipleChoiceQuestion::displayQuestion(CourseWorkTestingUI::StartForm^ startForm, int number)
{
    System::String^ strQuestion = gcnew System::String(question.c_str());
    array<System::String^>^ answers = gcnew array<System::String^>(allAnswers.size());

    for (int i = 0; i < allAnswers.size(); i++)
    {
        answers[i] = gcnew System::String(allAnswers[i].getAnswer().c_str());
    }
    startForm->createMultipleChoiceTestGB(strQuestion, answers, number, mark);
    startForm->markCorrectAnswer(allAnswers.size(), number, correctAnswersIndex);
}

std::string MultipleChoiceQuestion::getType() const
{
    return "Multiple Choice";
}

int MultipleChoiceQuestion::checkAnswer(const std::string &answer)
{
    std::vector<int> answers;
    std::istringstream iss(answer);
    std::string token;
    while (std::getline(iss, token, ',')) {
        answers.push_back(std::stoi(token) - 1);
    }
    return checkAnswer(answers);
}

std::string MultipleChoiceQuestion::getCorrectAnswers()
{
    std::string correctIndexes = "";
    for (int index : correctAnswersIndex) {
        correctIndexes += std::to_string(index) + ",";
    }
    correctIndexes.pop_back();
    return correctIndexes;
}

//void MultipleChoiceQuestion::displayQuestionWhithButtons(CourseWorkTestinUI::StartForm^ startForm, int number)
//{
//    System::String^ strQuestion = gcnew System::String(question.c_str());
//    array<System::String^>^ answers = gcnew array<System::String^>(allAnswers.size());
//
//    for (int i = 0; i < allAnswers.size(); i++)
//    {
//        answers[i] = gcnew System::String(allAnswers[i].getAnswer().c_str());
//    }
//    startForm->createAdminChoiceTestGB(strQuestion, answers, number, false);
//    markCorrectAnswer(startForm, number);
//}
