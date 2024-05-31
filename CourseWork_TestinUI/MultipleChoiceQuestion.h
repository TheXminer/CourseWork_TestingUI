#pragma once
#include "Question.h"
#include <sstream> 
class MultipleChoiceQuestion :
    public Question
{
    std::vector<int> correctAnswersIndex;
public:
    //void markCorrectAnswer(CourseWorkTestinUI::StartForm^ startForm, int number) override;
    MultipleChoiceQuestion(std::string question, std::vector<Answer> allAnswers, int mark, std::vector<int> correctAnswers);
    int checkAnswer(std::vector<int> answers) const;
    void displayQuestion(CourseWorkTestingUI::StartForm^ startForm, int number) override;
    std::string getType() const override;
    int checkAnswer(const std::string& answer) override;
    std::string getCorrectAnswers() override;
    bool isCheckedButton(System::Windows::Forms::Control^ control) override;
    void checkButton(System::Windows::Forms::Control^ control) override;
    //void displayQuestionWhithButtons(CourseWorkTestinUI::StartForm^ startForm, int number) override;
};

