#pragma once
#include "Question.h"
class SingleChoiceQuestion :
    public Question
{
    int correctAnswer;
public:
    //void markCorrectAnswer(CourseWorkTestinUI::StartForm^ startForm, int number) override;
    SingleChoiceQuestion(std::string question, std::vector<Answer> allAnswers, int mark, int correctAnswer);
    int checkAnswer(int answer) const;
    void displayQuestion(CourseWorkTestingUI::StartForm^ startForm, int number) override;
    std::string getType() const override;
    int checkAnswer(const std::string& answer) override;
    std::string getCorrectAnswers() override;
    bool isCheckedButton(System::Windows::Forms::Control^ control) override;
    void checkButton(System::Windows::Forms::Control^ control) override;
    //void displayQuestionWhithButtons(CourseWorkTestinUI::StartForm^ startForm, int number) override;
};

