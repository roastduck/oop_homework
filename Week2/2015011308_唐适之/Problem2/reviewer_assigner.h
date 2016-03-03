#ifndef INCLUDED_REVIEWER_ASSIGNER_H
#define INCLUDED_REVIEWER_ASSIGNER_H

#include "loader.h"

class ReviewerAssigner
{
	std::vector<Student> list;
	int result[3];

public:
	void load();
	void choose();
	void output();
};

#endif // INCLUDED_REVIEWER_ASSIGNER_H
