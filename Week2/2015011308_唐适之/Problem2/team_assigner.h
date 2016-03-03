#ifndef INCLUDED_TEAM_ASSIGNER_H
#define INCLUDED_TEAM_ASSIGNER_H

#include "loader.h"

class TeamAssigner
{
	std::vector<Student> list;
	std::vector< std::vector<int> > result;

public:
	void load();
	void assign();
	void output();
};

#endif // INCLUDED_REVIEWER_ASSIGNER_H
