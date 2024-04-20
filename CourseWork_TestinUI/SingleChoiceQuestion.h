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
    //void displayQuestionWhithButtons(CourseWorkTestinUI::StartForm^ startForm, int number) override;
};

