#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <ctime>

struct StudentAnswerData {
	time_t usedTime;
	std::vector<int>* marks;
	StudentAnswerData() :usedTime(0), marks(nullptr) {}
	StudentAnswerData(time_t usedTime, std::vector<int>* marks) : usedTime(usedTime), marks(marks) {}
	~StudentAnswerData() {
		delete marks;
	}
};

class StudentAnswers
{
	std::unordered_map<std::string, std::unordered_map<std::string, StudentAnswerData*>*> studentAnswers;
public:
	std::vector<std::string> studentsNames;
	bool addStudentAnswer(std::string studentName, std::string nameOfTest, StudentAnswerData* marks);
	StudentAnswerData* getStudentAnswers(std::string studentName, std::string nameOfTest);
	bool isTestPassed(std::string studentName, std::string nameOfTest);
	bool deleteStudentAnswers(std::string studentName, std::string nameOfTest);
};

