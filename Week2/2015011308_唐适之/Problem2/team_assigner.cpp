#include <fstream>
#include <algorithm>
#include "const.h"
#include "loader.h"
#include "team_assigner.h"

void TeamAssigner::load()
{
	list = loader(inputFile);
}

void TeamAssigner::assign()
{
	std::vector<int> order(list.size());
	for (size_t i=0; i!=order.size(); i++)
		order[i] = i;
	random_shuffle(order.begin(), order.end());
	for (size_t i=0; i!=order.size(); i++)
	{
		if (result.empty() || result.back().size()==3 && i!=order.size()-1)
			result.push_back(std::vector<int>());
		result.back().push_back(order[i]);
	}
}

void TeamAssigner::output()
{
	std::ofstream os(teamFile);
	for (size_t i=0; i!=result.size(); i++)
	{
		os << "Team " << i+1 << ":" << std::endl;
		for (size_t j=0; j!=result[i].size(); j++)
			os << "id: " << list[result[i][j]].id << ", email: " << list[result[i][j]].email << std::endl;
		os << std::endl;
	}
}

