#ifndef KDTREE_H_
#define KDTREE_H_
#include <vector>

//Node for the KD (K-dimensional) Tree
class KDNode
{
public:
	int axis_;
    std::vector<int> x_;
	unsigned int id_;
	bool checked_;

	KDNode(std::vector<int> &x0, int axis0);
    int distance2(std::vector<int> &x);
    bool equal(std::vector<int> &x);

	KDNode* parent_;
	KDNode* left_;
	KDNode* right_;
};

class KDTree
{
public:
	KDNode* root_;
	KDTree();

	bool		add(std::vector<int> &x);
	KDNode*	    insert(std::vector<int> &x, KDNode* node);
	KDNode*	    findLeaf(std::vector<int> &x0, KDNode *node);
    KDNode*     findNearest(std::vector<int> &x, std::vector<KDNode*> &visitedNodes);
	KDNode*		findNearestBrute(std::vector<int> &x);
	void		checkSubtree(KDNode* node, std::vector<int> &x);
	void		updateMinNode(KDNode* node, std::vector<int> &x);
	void		searchParent(KDNode* parent, std::vector<int> &x);
	void		uncheck();

public:
	int			          d_min_;
	KDNode*		          nearest_neighbour_;
	int			          KD_id_;
	std::vector<KDNode*>  list_;
	std::vector<KDNode*>  checkedNodes_;
};

#endif

