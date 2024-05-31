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
    std::string getQuestion() const { return question; }
    std::vector<Answer> getAnswers() const { return allAnswers; }
    int getMark() const { return mark; }
    Question(std::string question, std::vector<Answer> allAnswers, int mark);
    virtual void displayQuestion(CourseWorkTestingUI::StartForm^ startForm, int number) = 0;
    virtual std::string getType() const = 0;
    virtual int checkAnswer(const std::string& answer) = 0;
    virtual std::string getCorrectAnswers() = 0;
    virtual bool isCheckedButton(System::Windows::Forms::Control^ control) = 0;
    virtual void checkButton(System::Windows::Forms::Control^ control) = 0;
    //virtual void markCorrectAnswer(CourseWorkTestinUI::StartForm^ startForm, int number) {};
    //virtual void displayQuestionWhithButtons(CourseWorkTestinUI::StartForm^ startForm, int number) {};
};

