#include "Editor.h"
bool Editor::deleteTestSetName(std::string nameOfSet)
{
	for (int i = 0; i < nameOfTests.size(); i++) {
		if (nameOfTests[i] == nameOfSet) {
			nameOfTests.erase(nameOfTests.begin() + i);
			setOfTests.erase(nameOfSet);
			return true;
		}
	}
	return false;
}

bool Editor::replaceTestSetName(std::string nameOfSet, std::string changedTestSetName)
{
	for (int i = 0; i < nameOfTests.size(); i++) {
		if (nameOfTests[i] == nameOfSet) {
			nameOfTests.at(i) = changedTestSetName;
			return true;
		}
	}
	return false;
}

void Editor::addTestSet(std::string nameOfSet)
{
	std::vector<Question*>* newSetOfQuestion = new std::vector<Question*>;
	setOfTests.insert({ nameOfSet, newSetOfQuestion });
	nameOfTests.push_back(nameOfSet);
}

void Editor::changeTestSetName(std::string testSetName, std::string changedTestSetName)
{
	std::vector<Question*>* setOfQuestions = setOfTests.at(testSetName);
	setOfTests.erase(testSetName);
	setOfTests.insert({ changedTestSetName, setOfQuestions });
	replaceTestSetName(testSetName, changedTestSetName);
}

void Editor::addTest(std::string nameOfSet, Question* question) {
	try {
		std::vector<Question*>* setOfQuestions = setOfTests.at(nameOfSet);
		setOfQuestions->push_back(question);
	}
	catch (const std::exception& e) {
		addTestSet(nameOfSet);
		setOfTests.at(nameOfSet)->push_back(question);
		//std::vector<Question*>* newSetOfQuestion = new std::vector<Question*>;
		//newSetOfQuestion->push_back(question);
		//setOfTests.insert({ nameOfSet, newSetOfQuestion });
		//nameOfTests.push_back(nameOfSet);
	}
}

void Editor::addTest(int testSetNumber, Question* question) {
	addTest(nameOfTests[testSetNumber], question);
}

void Editor::deleteTest(std::string nameOfSet, int nOfTest) {
	try {
		std::vector<Question*>* setOfQuestions = setOfTests.at(nameOfSet);
		if (setOfQuestions->begin() + nOfTest > setOfQuestions->end())
			return;
		setOfQuestions->erase(setOfQuestions->begin() + nOfTest);
		if (setOfQuestions->size() != 0)
			return;
	}
	catch (const std::exception& e) {}
}

void Editor::deleteTest(int testSetNumber, int nOfTest)
{
	deleteTest(nameOfTests[testSetNumber], nOfTest);
}

void Editor::editTest(std::string nameOfSet, int nOfTest, Question* question) {
	try {
		std::vector<Question*>* setOfQuestions = setOfTests.at(nameOfSet);
		if (setOfQuestions->begin() + nOfTest > setOfQuestions->end())
			return;
		Question* toDelete = setOfQuestions->at(nOfTest);
		setOfQuestions->at(nOfTest) = question;
		delete toDelete;
	}
	catch (const std::exception& e) {}
}

Question* Editor::getTest(std::string nameOfSet, int nOfTest) {
	try {
		std::vector<Question*>* setOfQuestions = setOfTests.at(nameOfSet);
		if (setOfQuestions->begin() + nOfTest > setOfQuestions->end())
			return nullptr;
		return setOfQuestions->at(nOfTest);
	}
	catch (const std::exception& e) {
		return nullptr;
	}
}

std::vector<Question*>* Editor::getSetOfTests(std::string nameOfSet) {
	try {
		std::vector<Question*>* setOfQuestions = setOfTests.at(nameOfSet);
		return setOfQuestions;
	}
	catch (const std::exception& e) {
		return nullptr;
	}
}

std::vector<Question*>* Editor::getSetOfTests(int testSetNumber)
{
	return getSetOfTests(nameOfTests[testSetNumber]);
}

void Editor::deleteSetOfTests(std::string nameOfSet) {
	try {
		setOfTests.erase(nameOfSet);
		deleteTestSetName(nameOfSet);
	}
	catch (const std::exception& e) {}
}

void Editor::deleteSetOfTests(int setNumber)
{
	deleteSetOfTests(nameOfTests[setNumber]);
}
