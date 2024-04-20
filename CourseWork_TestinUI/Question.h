#pragma once
#include "Answer.h"
#include "StartForm.h"
#include "vector"
#include <string>
class Question abstract
{
protected:
    int mark;
    std::string question;
    std::vector<Answer> allAnswers;
public:
    std::string getQuestion() { return question; }
    std::vector<Answer> getAnswers() { return allAnswers; }

    Question(std::string question, std::vector<Answer> allAnswers, int mark);
    virtual void displayQuestion(CourseWorkTestingUI::StartForm^ startForm, int number) = 0;
    //virtual void markCorrectAnswer(CourseWorkTestinUI::StartForm^ startForm, int number) {};
    //virtual void displayQuestionWhithButtons(CourseWorkTestinUI::StartForm^ startForm, int number) {};
};

