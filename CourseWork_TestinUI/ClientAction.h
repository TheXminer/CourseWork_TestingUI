#pragma once
#include "StudentAnswers.h"
#include "MultipleChoiceQuestion.h"
#include "SingleChoiceQuestion.h"
#include "Editor.h"
#include <functional>

enum status {
    NonAuthorized,
    AuthorizedAsStudent,
    AuthorizedAsAdmin
};

class CurrentAction;
class StartTestAction;
class AdminAction;
class UserAction;
class StartTestAction;
class ViewAllMarksAction;

class User abstract {
    std::string userName;
    //int authorizeStatus = AuthorizedAsAdmin;
public:
    User(std::string userName) : userName(userName) {}
    //Editor* editor;
    //StudentAnswers* studentAnswers;
    virtual void showStartScreen(CourseWorkTestingUI::StartForm^ startForm) = 0;
};
class AdminUser : public User {
public:
    AdminUser(std::string userName) : User(userName) {};
    void showStartScreen(CourseWorkTestingUI::StartForm^ startForm) override;
};
class ClientUser : public User {
public:
    ClientUser(std::string userName) : User(userName) {};
    void showStartScreen(CourseWorkTestingUI::StartForm^ startForm) override;
};

class ClientAction {
    std::string userName;
    CurrentAction* action = nullptr;
    int authorizeStatus = NonAuthorized;
public:
    User* user;
    Editor* editor;
    StudentAnswers* studentAnswers;
    ClientAction();
    ClientAction(CurrentAction* action, Editor* editor, StudentAnswers* studentAnswers);
    //ClientAction(CurrentAction* action);

    void setUserName(std::string userName) {
        this->userName = userName;
    }
    std::string getUserName() {
        return userName;
    }
    int checkAccess() {
        return authorizeStatus;
    }
    void setAccess(status status) {
        authorizeStatus = status;
    }

    void setAction(CurrentAction* action);
    void returnAction();
    void start();
};

class CurrentAction abstract
{
protected:
    ClientAction* client = nullptr;
    CurrentAction* previousAction = nullptr;
public:
    static std::string choosedTeseSet; 
    ~CurrentAction();
    void setClient(ClientAction* client);
    void setPreviousAction(CurrentAction* previousAction);
    CurrentAction* getPreviousAction();
    virtual void execute(int userChoice) = 0;
};

class AuthorizeAction : public CurrentAction
{
    void login(std::string userName);
public:
    void execute(int userChoice);
};

class AddTestAction : public CurrentAction {
public:
    Question* addTest();
    void execute(int userChoice);
};

class AddSetAction : public CurrentAction {
public:
    void execute(int userChoice);
};

class DeleteTestAction :public CurrentAction {
public:
    void execute(int userChoice);
};

class ViewTestAction :public CurrentAction {
public:
    void execute(int userChoice);
};

class EditSetAction : public CurrentAction {
public:
    void execute(int userChoice);
};

class DeleteSetAction :public CurrentAction {
public:
    void execute(int userChoice);
};

class ViewAllMarksAction : public CurrentAction {
    int sumOfMarks(std::vector<int>* marks);
    void printMarks(std::vector<int>* marks);
    void showMarks(int choice);
public:
    void execute(int userChoice);
};

class StartTestAction : public CurrentAction {
    //int* randomizeNumbers(int size);
    std::vector<int>* transformOrder(std::vector<int>* currentMarks, int* key);
    void startTest(std::string testName);
public:
    void execute(int userChoice);
};

class ViewMyMarksAction : public CurrentAction {
    int sumOfMarks(std::vector<int>* marks);
    void printMarks(std::vector<int>* marks);
public:
    void execute(int userChoice);
};

class AdminAction : public CurrentAction
{
    enum AdminChoice {
        StartTest = 1,
        ViewMarks,
        AddSetTest,
        EditSetTest,
        DeleteSetTest
    };
public:
    void execute(int userChoice);
};

class UserAction : public CurrentAction {
    enum AdminChoice {
        StartTest = 1,
        ViewMarks
    };
public:
    void execute(int userChoice);
};
