#pragma once
#include <fstream>

class Student
{
	char* firstName = nullptr;
	char* lastName = nullptr;

	void copyFrom(const Student& other);
	void free();
	void copyFirstName(const char* other);
	void copyLastName(const char* other);

public:
	Student() = default;
	Student(const char* firstName, const char* lastName);
	Student(const Student& other);
	Student& operator=(const Student& other);
	~Student();

	void setFirstName(const char* firstName);
	void setLastName(const char* lastName);

	const char* getFirstName() const;
	const char* getLastName() const;

	void saveToFile(std::ofstream& ofs) const;
	void readFromFile(std::ifstream& ifs);
};