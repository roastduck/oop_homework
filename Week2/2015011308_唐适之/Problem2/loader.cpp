#include "loader.h"

std::vector<Student> loader(const char *filename)
{
	std::ifstream is(filename);
	std::string foo;
	is >> foo >> foo;

	std::vector<Student> ret;
	int id;
	std::string email;
	while (is >> id >> email)
		ret.push_back(Student(id, email));
	return ret;
}

