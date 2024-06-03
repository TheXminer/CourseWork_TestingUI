#include "StudentAnswers.h"
bool StudentAnswers::addStudentAnswer(std::string studentName, std::string nameOfTest, StudentAnswerData* marks)
{
	try {
		if (studentAnswers.at(studentName)->count(nameOfTest) != 0)
			return false;
		studentAnswers.at(studentName)->insert({ nameOfTest, marks });
		return true;
	}
	catch (const std::exception& e) {
		std::unordered_map<std::string, StudentAnswerData*>* map = new std::unordered_map<std::string, StudentAnswerData*>;
		map->insert({ nameOfTest, marks });
		studentAnswers.insert({ studentName, map });
		studentsNames.push_back(studentName);
		return true;
	}
}

void StudentAnswers::addNewTestMark(std::string nameOfTest)
{
	for (auto answer : studentAnswers) {
		auto savedMarks = getStudentAnswers(answer.first, nameOfTest);
		if (!savedMarks)
			continue;
		savedMarks->marks->push_back(0);
		savedMarks->choosenAnswers->push_back(nullptr);
	}
}

void StudentAnswers::deleteStudentsAnswer(std::string nameOfTest, int testNumber)
{
	for (auto answer : studentAnswers) {
		auto savedMarks = getStudentAnswers(answer.first, nameOfTest);
		if (!savedMarks)
			continue;
		savedMarks->marks->erase(savedMarks->marks->begin() + testNumber);
		savedMarks->choosenAnswers->erase(savedMarks->choosenAnswers->begin() + testNumber);
	}
}

void StudentAnswers::deleteTestAnswers(std::string nameOfTest)
{
	for (auto answer : studentAnswers) {
		//auto savedMarks = getStudentAnswers(answer.first, nameOfTest);
		if (!isTestPassed(answer.first, nameOfTest))
			continue;
		studentAnswers.at(answer.first)->erase(nameOfTest);
	}
}

void StudentAnswers::changeTestSetName(std::string previousSetName, std::string newSetName)
{
	for (auto answer : studentAnswers) {
		auto savedMarks = getStudentAnswers(answer.first, previousSetName);
		if (!savedMarks)
			continue;
		answer.second->erase(previousSetName);
		addStudentAnswer(answer.first, newSetName, savedMarks);
	}
}

StudentAnswerData* StudentAnswers::getStudentAnswers(std::string studentName, std::string nameOfTest)
{
	if (studentAnswers.find(studentName) == studentAnswers.end() || studentAnswers.at(studentName)->find(nameOfTest) == studentAnswers.at(studentName)->end()) {
		return nullptr;
	}
	return studentAnswers.at(studentName)->at(nameOfTest);
}

bool StudentAnswers::isTestPassed(std::string studentName, std::string nameOfTest)
{
	try {
		StudentAnswerData* marks = studentAnswers.at(studentName)->at(nameOfTest);
		return true;
	}
	catch (const std::exception& e) {
		return false;
	}
}

bool StudentAnswers::deleteStudentAnswers(std::string studentName, std::string nameOfTest)
{
	try {
		studentAnswers.at(studentName)->erase(nameOfTest);
		return true;
	}
	catch (const std::exception& e) {
		return false;
	}
}

std::string convertTime(time_t time) {
	int seconds = time % 60;
	std::string secondsStr = std::to_string(seconds) + "s";
	int minutes = time / 60;
	if (minutes == 0)
		return secondsStr;
	int hours = minutes / 60;
	minutes %= 60;
	std::string minutesStr = std::to_string(minutes) + "m";
	if (hours == 0)
		return minutesStr + " " + secondsStr;
	std::string hoursStr = std::to_string(minutes) + "h";
	return hoursStr + " " + minutesStr + " " + secondsStr;
}

std::vector<std::vector<std::string>*>* StudentAnswers::getAllTestAnswers(std::string nameOfTest)
{
	std::vector<std::vector<std::string>*>* allAnswers = new std::vector<std::vector<std::string>*>;
	for (auto answer : studentAnswers) {
		if (!isTestPassed(answer.first, nameOfTest))
			continue;
		std::vector<std::string>* curStudentResult = new std::vector<std::string>;
		curStudentResult->push_back(answer.first);
		auto savedMarks = getStudentAnswers(answer.first, nameOfTest);
		int resultMark = 0;
		curStudentResult->push_back(std::to_string(resultMark));
		curStudentResult->push_back(/*std::to_string(savedMarks->usedTime)*/convertTime(savedMarks->usedTime));
		for (auto mark : *savedMarks->marks) {
			resultMark += mark;
			curStudentResult->push_back(std::to_string(mark));
		}
		curStudentResult->at(1) = std::to_string(resultMark);
		allAnswers->push_back(curStudentResult);
	}
	return allAnswers;
}
