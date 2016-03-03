#include <cstdlib>
#include <ctime>
#include "reviewer_assigner.h"
#include "team_assigner.h"

int main()
{
	srand(time(0));
	ReviewerAssigner mReviewerAssigner;
	TeamAssigner mTeamAssigner;
	mReviewerAssigner.load();
	mReviewerAssigner.choose();
	mReviewerAssigner.output();
	mTeamAssigner.load();
	mTeamAssigner.assign();
	mTeamAssigner.output();
	return 0;
}

