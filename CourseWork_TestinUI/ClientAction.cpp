#include "ClientAction.h"

ClientAction::ClientAction()
{
    editor = new Editor();
    studentAnswers = new StudentAnswers();
    client = new NonauthorizedClient();
}

ClientAction::ClientAction(Editor* editor, StudentAnswers* studentAnswers) {
    this->editor = editor;
    this->studentAnswers = studentAnswers;
}

void ClientAction::login(std::string userName)
{
    if (userName == "admin") {
        delete client;
        client = new AdminClient(userName);
    }
    if (userName.find("user") != std::string::npos) {
        delete client;
        client = new UserClient(userName);
    }
}

void ClientAction::logout()
{
    delete client;
    client = new NonauthorizedClient();
}

//void ClientAction::setAction(CurrentAction* action) {
//    if (this->action) action->setPreviousAction(this->action);
//    this->action = action;
//    action->setClient(this);
//}
//
//void ClientAction::start() {
//    if (!action)
//        return;
//    CurrentAction* curAction = action;
//    //action->execute();
//}
//
//void ClientAction::returnAction()
//{
//    if (!this->action)
//        return;
//    CurrentAction* previous = this->action->getPreviousAction();
//    this->action->setPreviousAction(nullptr);
//    delete this->action;
//    this->action = previous;
//}
//
//CurrentAction::~CurrentAction() {
//    if (!previousAction) {
//        return;
//    }
//    previousAction->setClient(nullptr);
//    delete previousAction;
//    previousAction = nullptr;
//}
//
//void CurrentAction::setClient(ClientAction* client) {
//    if (client)
//        this->client = client;
//}
//
//void CurrentAction::setPreviousAction(CurrentAction* previousAction) {
//    this->previousAction = previousAction;
//}
//
//CurrentAction* CurrentAction::getPreviousAction() {
//    return previousAction;
//}
//
//std::vector<int>* StartTestAction::transformOrder(std::vector<int>* currentMarks, int* key)
//{
//    return currentMarks;
//}
//
//void StartTestAction::startTest(std::string testName)
//{
//    std::vector<Question*>* tests = client->editor->getSetOfTests(testName);
//    int size = tests->size();
//    //int* numbersOrder = randomizeNumbers(size);
//    std::vector<int>* currentMarks = new std::vector<int>;
//    time_t start, end;
//    time(&start);
//    //if (client->studentAnswers->isTestPassed(client->getUserName(), testName)) {/*
//    //    std::cout << "Test already passed :)" << std::endl;*/
//    //    return;
//    //}
//    for (int i = 0; i < size; i++) {
//        //tests->at(numbersOrder[i])->display();
//        int mark;// = tests->at(numbersOrder[i])->checkEnterQuestion();
//        currentMarks->push_back(mark);
//    }
//    time(&end);
//    studentAnswerData* answers = new studentAnswerData(end - start, currentMarks);
//    //client->studentAnswers->addStudentAnswer(client->getUserName(), testName, answers);
//    //delete numbersOrder;
//}

//void AuthorizeAction::login(std::string userName)
//{
//    if (userName == "admin") {
//        client->setUserName(userName);
//        client->setAccess(AuthorizedAsAdmin);
//        client->setAction(new AdminAction);
//    }
//    if (userName.find("user") != std::string::npos) {
//        client->setUserName(userName);
//        client->setAccess(AuthorizedAsClient);
//        client->setAction(new UserAction);
//    }
//}

//void AuthorizeAction::execute(int userChoice) {
//    std::string username;
//    //ENTER USERNAME -_-
//    login(username);
//}
//
//void ViewAllMarksAction::execute(int userChoice) {
//    showMarks(userChoice);
//}
//
//Question* AddTestAction::addTest() {
    //showTestTypes();
    //int choice;
    //std::cin >> choice;
    //Question* newQuestion = nullptr;
    //if (!client)
    //    return nullptr;
    //switch (choice) {
    //case Exit:
    //    client->setAction(new AuthorizeAction);
    //    return nullptr;
    //case Return:
    //    client->savedChoice = Return;
    //    client->returnAction();
    //    return nullptr;
    //case SingleChoiceTest:
    //    newQuestion = new Question;
    //    if (!newQuestion->enterQuestion()) {
    //        delete newQuestion;
    //        newQuestion = nullptr;
    //    }
    //    return newQuestion;
    //case MultipleChoiceTest:
    //    newQuestion = new MultipleChoiceQuestion;
    //    if (!newQuestion->enterQuestion()) {
    //        delete newQuestion;
    //        newQuestion = nullptr;
    //    }
    //    return newQuestion;
    //}
//    return nullptr;
//}

//void AddTestAction::execute(int userChoice) {
//    Question* question = addTest();
//    if (!question)
//        return;
//    client->editor->addTest(client->editor->nameOfTests[userChoice], question);
//    client->returnAction();
//}
//
//void AddSetAction::execute(int userChoice) {
//    AddTestAction addTestAction;
//    addTestAction.setClient(client);
//    std::string testSetName;
//}
//
//void DeleteTestAction::execute(int userChoice) {
//    client->editor->deleteTest(client->editor->nameOfTests[userChoice], 0);// todo -_-
//    client->returnAction();
//}
//
//void ViewTestAction::execute(int userChoice) {
//    std::vector<Question*>* testSet = client->editor->getSetOfTests(client->editor->nameOfTests[userChoice]);
//    //for (int i = 0; i < testSet->size(); i++) {
//    //    std::cout << i + 1 << ". ";
//    //    testSet->at(i)->viewTest();
//    //}
//}
//
//void EditSetAction::execute(int userChoice) {
//    //if (client->savedChoice == Nothing) {
//    //    client->setAction(new ChooseTestAction);
//    //    return;
//    //}
//    //if (client->savedChoice == Return) {
//    //    client->savedChoice = Nothing;
//    //    client->returnAction();
//    //    return;
//    //}
//    //int choice = Nothing;
//    //while (choice <Exit || choice>client->editor->nameOfTests.size())
//    //std::cin >> choice;
//}

//void DeleteSetAction::execute(int userChoice) {
//    client->editor->deleteSetOfTests(client->editor->nameOfTests[userChoice]);
//}
//
//int ViewAllMarksAction::sumOfMarks(std::vector<int>* marks) {
//    int sum = 0;
//    for (int i = 0; i < marks->size(); i++) {
//        sum += marks->at(i);
//    }
//    return sum;
//}
//
//void ViewAllMarksAction::printMarks(std::vector<int>* marks) {
//    int size = marks->size();
//}
//
//void ViewAllMarksAction::showMarks(int choice) {
//    bool isTyped = false;
//    for (int i = 0; i < client->studentAnswers->studentsNames.size(); i++) {
//        studentAnswerData* marks = client->studentAnswers->getStudentAnswers(client->studentAnswers->studentsNames[i], client->editor->nameOfTests[choice]);
//        if (marks && marks->marks) {
//            //std::cout << client->studentAnswers->studentsNames[i] << " (" << marks->usedTime / 60 << "m " << marks->usedTime % 60 << "s, " << sumOfMarks(marks->marks) << "): ";
//            //printMarks(marks->marks);
//            //std::cout << std::endl;
//            isTyped = true;
//        }
//    }
//    if (!isTyped) {
//
//    }
//        //std::cout << "Students haven`t completed tests yet :(" << std::endl;
//}
//
//void StartTestAction::execute(int userChoice) {
//    startTest(client->editor->nameOfTests[userChoice]);
//    client->returnAction();
//}
//
//int ViewMyMarksAction::sumOfMarks(std::vector<int>* marks) {
//    int sum = 0;
//    for (int i = 0; i < marks->size(); i++) {
//        sum += marks->at(i);
//    }
//    return sum;
//}
//
//void ViewMyMarksAction::printMarks(std::vector<int>* marks) {
//    int size = marks->size();
//}

//void ViewMyMarksAction::execute(int userChoice) {
//    int size = client->editor->nameOfTests.size();
//    for (int i = 0; i < size; i++) {
//        studentAnswerData* answer = client->studentAnswers->getStudentAnswers(client->getUserName(), client->editor->nameOfTests[i]);
//        if (!answer)
//            continue;
//        std::vector<int>* marks = answer->marks;
//        time_t usedTime = answer->usedTime;
//        if (marks) {
//            //std::cout << client->editor->nameOfTests[i] << " (" << usedTime / 60 % 60 << "m " << usedTime % 60 << "s, " << sumOfMarks(marks) << "): ";
//            printMarks(marks);
//        }
//    }
//    int choice = 0;
//    //showAction();
//}

//void AdminAction::execute(int userChoice) {
//    int choice = userChoice;
//    //switch (choice) {
//    //case Exit:
//    //    client->setAction(new AuthorizeAction);
//    //    return;
//    //case StartTest:
//    //    client->setAction(new StartTestAction);
//    //    return;
//    //case ViewMarks:
//    //    client->setAction(new ViewAllMarksAction);
//    //    return;
//    //case AddSetTest:
//    //    client->setAction(new AddSetAction);
//    //    return;
//    //case EditSetTest:
//    //    client->setAction(new EditSetAction);
//    //    return;
//    //case DeleteSetTest:
//    //    client->setAction(new DeleteSetAction);
//    //    return;
//    //}
//}
//
//void UserAction::execute(int userChoice) {
//    int choice;
//    //switch (choice) {
//    //case Exit:
//    //    client->setAction(new AuthorizeAction);
//    //    return;
//    //case StartTest:
//    //    client->setAction(new StartTestAction);
//    //    return;
//    //case ViewMarks:
//    //    client->setAction(new ViewMyMarksAction);
//    //    return;
//    //}
//}
void adminShow(CourseWorkTestingUI::StartForm^ form, System::String^ testSetName, int number) 
{
    form->adminShowTestSetName(testSetName, number);
}

void clientShow(CourseWorkTestingUI::StartForm^ form, System::String^ testSetName, int number)
{
    form->clientShowTestSetName(testSetName, number);
}
//void AdminUser::showStartScreen(CourseWorkTestingUI::StartForm^ startForm)
//{
//}
//
//void ClientUser::showStartScreen(CourseWorkTestingUI::StartForm^ startForm)
//{
//    startForm->showTestSets(&adminShow);
//}

//void AdminUser::callShowFunction(CourseWorkTestingUI::StartForm^ form, System::String^ testSetName, int number)
//{
//    form->adminShowTestSetName(testSetName, number);
//}
//
//void User::showStartScreen(CourseWorkTestingUI::StartForm^ startForm)
//{
//    startForm->showTestSets(&);
//}
//
//void ClientUser::callShowFunction(CourseWorkTestingUI::StartForm^ form, System::String^ testSetName, int number)
//{
//    form->clientShowTestSetName(testSetName, number);
//}

void AdminClient::showStartScreen(CourseWorkTestingUI::StartForm^ form)
{
        form->showTestSets(&adminShow);
        form->createAddButton(gcnew System::EventHandler(form, &CourseWorkTestingUI::StartForm::buttonAddTestSet_Click));
}

void AdminClient::showTestButtons(CourseWorkTestingUI::StartForm^ form, int number)
{
    form->createAdminChoiceTestGB(number);
}

void UserClient::showStartScreen(CourseWorkTestingUI::StartForm^ form)
{
        form->showTestSets(&clientShow);
}

void NonauthorizedClient::showStartScreen(CourseWorkTestingUI::StartForm^ form)
{
    form->authorization();
}
