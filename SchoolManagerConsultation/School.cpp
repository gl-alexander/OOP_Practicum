#include <iostream>
#include <fstream>
#include "School.h"


School::School(const char* fileName)
{
	readSchoolFromFile(fileName);
}
void School::addStudent(const char* fName, const char* lName)
{
	if (countStudents >= MAX_STUDENT_COUNT) return;

	students[countStudents++] = Student(fName, lName);
}

void School::saveSchoolToFile(const char* fileName) const
{
	std::cout << "Saving School to file\n";
	std::ofstream ofs(fileName, std::ios::out | std::ios::binary);
	ofs.write((const char*)&countStudents, sizeof(countStudents));
	for (int i = 0; i < countStudents; i++)
	{
		std::cout << "Saving Student " << i << " to file\n";
		students[i].saveToFile(ofs);
	}
}
void School::readSchoolFromFile(const char* fileName)
{
	std::cout << "Reading School to file\n";
	std::ifstream ifs(fileName, std::ios::in | std::ios::binary);
	
	ifs.read((char*)&countStudents, sizeof(countStudents));
	if (countStudents > MAX_STUDENT_COUNT) return;
	for (int i = 0; i < countStudents; i++)
	{
		students[i].readFromFile(ifs);
	}
}

const Student& School::getStudent(int i) const
{
	return students[i];
}