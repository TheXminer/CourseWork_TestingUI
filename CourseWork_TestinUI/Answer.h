#pragma once
#include <string>
class Answer
{
    std::string answerText;
public:
    Answer() : answerText("") {}
    Answer(std::string answerText) : answerText(answerText) {};
    std::string getAnswer() const;
};

