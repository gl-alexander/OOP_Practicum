#pragma once
#include "Student.h"

const size_t MAX_STUDENT_COUNT = 20;

class School
{
	Student students[MAX_STUDENT_COUNT];
	size_t countStudents = 0;

public:
	School() = default;
	School(const char* fileName);
	void addStudent(const char* fName, const char* lName);

	void saveSchoolToFile(const char* fileName) const;
	void readSchoolFromFile(const char* fileName);

	const Student& getStudent(int i) const;
};