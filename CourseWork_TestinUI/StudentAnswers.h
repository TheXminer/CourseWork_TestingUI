#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <ctime>

struct StudentAnswerData {
	time_t usedTime;
	std::vector<int>* marks;
	std::vector<std::vector<int>*>* choosenAnswers;
	StudentAnswerData() :usedTime(0), marks(nullptr), choosenAnswers(nullptr) {}
	StudentAnswerData(time_t usedTime, std::vector<int>* marks, std::vector<std::vector<int>*>* choosenAnswers) : usedTime(usedTime), marks(marks), choosenAnswers(choosenAnswers) {}
	~StudentAnswerData() {
		delete marks;
		for (auto answerIndexes : *choosenAnswers)
			delete answerIndexes;
		delete choosenAnswers;
	}
};

class StudentAnswers
{
	std::unordered_map<std::string, std::unordered_map<std::string, StudentAnswerData*>*> studentAnswers;
public:
	std::vector<std::string> studentsNames;
	bool addStudentAnswer(std::string studentName, std::string nameOfTest, StudentAnswerData* marks);
	void addNewTestMark(std::string nameOfTest);
	void deleteStudentsAnswer(std::string nameOfTest, int testNumber);
	void deleteTestAnswers(std::string nameOfTest);
	void changeTestSetName(std::string previousSetName, std::string newSetName);
	StudentAnswerData* getStudentAnswers(std::string studentName, std::string nameOfTest);
	bool isTestPassed(std::string studentName, std::string nameOfTest);
	bool deleteStudentAnswers(std::string studentName, std::string nameOfTest);
	std::vector<std::vector<std::string>*>* getAllTestAnswers(std::string nameOfTest);
};

