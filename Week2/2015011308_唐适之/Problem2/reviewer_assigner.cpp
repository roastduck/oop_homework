#include <cstdlib>
#include <set>
#include <fstream>
#include "const.h"
#include "loader.h"
#include "reviewer_assigner.h"

void ReviewerAssigner::load()
{
	list = loader(inputFile);
}

void ReviewerAssigner::choose()
{
	std::set<int> chosen;
	for (int i=0; i<3; i++)
	{
		do
			result[i] = rand() % list.size();
		while (chosen.count(result[i]));
		chosen.insert(result[i]);
	}
}

void ReviewerAssigner::output()
{
	std::ofstream os(reviewerFile);
	for (int i=0; i<3; i++)
		os << list[result[i]].email << std::endl;
}

