#pragma once
#include "Question.h"
class MultipleChoiceQuestion :
    public Question
{
    std::vector<int> correctAnswersIndex;
public:
    //void markCorrectAnswer(CourseWorkTestinUI::StartForm^ startForm, int number) override;
    MultipleChoiceQuestion(std::string question, std::vector<Answer> allAnswers, int mark, std::vector<int> correctAnswers);
    int checkAnswer(std::vector<int> answers) const;
    void displayQuestion(CourseWorkTestingUI::StartForm^ startForm, int number) override;
    //void displayQuestionWhithButtons(CourseWorkTestinUI::StartForm^ startForm, int number) override;
};

