#pragma once
#include "Question.h"
#include <string>
#include <vector>
#include <unordered_map>

class Editor
{
	std::unordered_map<std::string, std::vector<Question*>*> setOfTests;
	bool deleteTestSetName(std::string nameOfSet);
	bool replaceTestSetName(std::string nameOfSet, std::string changedTestSetName);
public:
	std::vector<std::string> nameOfTests;

	void addTestSet(std::string nameOfSet);
	void changeTestSetName(std::string testSetName, std::string changedTestSetName);
	void addTest(std::string nameOfSet, Question* question);
	void addTest(int testSetNumber, Question* question);
	void deleteTest(std::string nameOfSet, int nOfTest);
	void deleteTest(int testSetNumber, int nOfTest);
	void editTest(std::string nameOfSet, int nOfTest, Question* question);
	Question* getTest(std::string nameOfSet, int nOfTest);
	Question* getTest(int testSetNumber, int nOfTest);

	void deleteSetOfTests(std::string nameOfSet);
	void deleteSetOfTests(int setNumber);
	std::vector<Question*>* getSetOfTests(std::string nameOfSet);
	std::vector<Question*>* getSetOfTests(int setNumber);
};

