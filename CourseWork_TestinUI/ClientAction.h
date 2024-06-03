#pragma once
#include "StudentAnswers.h"
#include "MultipleChoiceQuestion.h"
#include "SingleChoiceQuestion.h"
#include "Editor.h"
#include <functional>

enum status {
    Nothing = -1,
    NonAuthorized,
    AuthorizedAsClient,
    AuthorizedAsAdmin
};

class CurrentAction;
class StartTestAction;
class AdminAction;
class UserAction;
class StartTestAction;
class ViewAllMarksAction;

class Client abstract {
    std::string userName;
protected:
    int authorizeStatus;
public:
    Client(std::string userName) : userName(userName) { 
        authorizeStatus = Nothing; 
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
    virtual void showStartScreen(CourseWorkTestingUI::StartForm^ form) = 0;
    virtual void showTestButtons(CourseWorkTestingUI::StartForm^ form, int number) = 0;
};
class AdminClient : public Client {
public:
    AdminClient(std::string userName) : Client(userName) { authorizeStatus = AuthorizedAsAdmin; };
    void showStartScreen(CourseWorkTestingUI::StartForm^ form) override;
    void showTestButtons(CourseWorkTestingUI::StartForm^ form, int number) override;
};
class UserClient : public Client {
public:
    UserClient(std::string userName) : Client(userName) { authorizeStatus = AuthorizedAsClient; };
    void showStartScreen(CourseWorkTestingUI::StartForm^ form) override;
    void showTestButtons(CourseWorkTestingUI::StartForm^ form, int number) override {};
};
class NonauthorizedClient : public Client {
public:
    NonauthorizedClient() : Client("no name") { authorizeStatus = NonAuthorized; }
    void showStartScreen(CourseWorkTestingUI::StartForm^ form) override;
    void showTestButtons(CourseWorkTestingUI::StartForm^ form, int number) override {};
};

class ClientAction {
public:
    Client* client;
    Editor* editor;
    StudentAnswers* studentAnswers;
    ClientAction();
    ClientAction(Editor* editor, StudentAnswers* studentAnswers);
    void login(std::string userName);
    void logout();
    //ClientAction(CurrentAction* action);
    //void setAction(CurrentAction* action);
    //void returnAction();
    //void start();
};

//class CurrentAction abstract
//{
//protected:
//    ClientAction* client = nullptr;
//    CurrentAction* previousAction = nullptr;
//public:
//    static std::string choosedTeseSet; 
//    ~CurrentAction();
//    void setClient(ClientAction* client);
//    void setPreviousAction(CurrentAction* previousAction);
//    CurrentAction* getPreviousAction();
//    virtual void execute(int userChoice) = 0;
//};
//
//class AuthorizeAction : public CurrentAction
//{
//    void login(std::string userName);
//public:
//    void execute(int userChoice);
//};
//
//class AddTestAction : public CurrentAction {
//public:
//    Question* addTest();
//    void execute(int userChoice);
//};
//
//class AddSetAction : public CurrentAction {
//public:
//    void execute(int userChoice);
//};
//
//class DeleteTestAction :public CurrentAction {
//public:
//    void execute(int userChoice);
//};
//
//class ViewTestAction :public CurrentAction {
//public:
//    void execute(int userChoice);
//};
//
//class EditSetAction : public CurrentAction {
//public:
//    void execute(int userChoice);
//};
//
//class DeleteSetAction :public CurrentAction {
//public:
//    void execute(int userChoice);
//};
//
//class ViewAllMarksAction : public CurrentAction {
//    int sumOfMarks(std::vector<int>* marks);
//    void printMarks(std::vector<int>* marks);
//    void showMarks(int choice);
//public:
//    void execute(int userChoice);
//};
//
//class StartTestAction : public CurrentAction {
//    //int* randomizeNumbers(int size);
//    std::vector<int>* transformOrder(std::vector<int>* currentMarks, int* key);
//    void startTest(std::string testName);
//public:
//    void execute(int userChoice);
//};
//
//class ViewMyMarksAction : public CurrentAction {
//    int sumOfMarks(std::vector<int>* marks);
//    void printMarks(std::vector<int>* marks);
//public:
//    void execute(int userChoice);
//};
//
//class AdminAction : public CurrentAction
//{
//    enum AdminChoice {
//        StartTest = 1,
//        ViewMarks,
//        AddSetTest,
//        EditSetTest,
//        DeleteSetTest
//    };
//public:
//    void execute(int userChoice);
//};
//
//class UserAction : public CurrentAction {
//    enum AdminChoice {
//        StartTest = 1,
//        ViewMarks
//    };
//public:
//    void execute(int userChoice);
//};
