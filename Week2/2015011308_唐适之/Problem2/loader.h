#ifndef INCLUDED_LOADER_H
#define INCLUDED_LOADER_H

#include <vector>
#include <string>
#include <fstream>

struct Student
{
	int id;
	std::string email;
	
	Student(int _id, const std::string &_email)
		: id(_id), email(_email) {}
};

std::vector<Student> loader(const char *filename);

#endif // INCLUDED_LOADER_H
