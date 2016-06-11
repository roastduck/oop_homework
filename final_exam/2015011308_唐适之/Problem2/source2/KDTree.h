#ifndef KDTREE_H_
#define KDTREE_H_
#include <cstdlib>
#include <vector>

//Node for the KD (K-dimensional) Tree
template <class T>
class KDNode
{
public:
	int axis_;
    std::vector<T> x_;
	unsigned int id_;
	bool checked_;

	KDNode(std::vector<T> &x0, int axis0);
    T distance2(std::vector<T> &x);
    bool equal(std::vector<T> &x);

	KDNode* parent_;
	KDNode* left_;
	KDNode* right_;
};

template <class T>
class KDTree
{
public:
	KDNode<T>* root_;
	KDTree();

	bool		add(std::vector<T> &x);
	KDNode<T>*	    insert(std::vector<T> &x, KDNode<T>* node);
	KDNode<T>*	    findLeaf(std::vector<T> &x0, KDNode<T> *node);
    KDNode<T>*     findNearest(std::vector<T> &x, std::vector<KDNode<T>*> &visitedNodes);
	KDNode<T>*		findNearestBrute(std::vector<T> &x);
	void		checkSubtree(KDNode<T>* node, std::vector<T> &x);
	void		updateMinNode(KDNode<T>* node, std::vector<T> &x);
	void		searchParent(KDNode<T>* parent, std::vector<T> &x);
	void		uncheck();

public:
	T			          d_min_;
	KDNode<T>*		          nearest_neighbour_;
	int			          KD_id_;
	std::vector<KDNode<T>*>  list_;
	std::vector<KDNode<T>*>  checkedNodes_;
};

template <class T>
inline T KDNode<T>::distance2(std::vector<T> &x)
{
	T S = 0;
	for (int k = 0; k < (int)x.size(); ++k)
		S += (x_[k]-x[k])*(x_[k]-x[k]);
	return S;
}

template <class T>
inline bool KDNode<T>::equal(std::vector<T> &x)
{
	for (int k = 0; k < (int)x.size(); k++)
	{
		if (x_[k] != x[k])
			return false;
	}
	return true ;
}

template <class T>
inline KDNode<T>::KDNode(std::vector<T> &x0, int axis0)
{
	axis_ = axis0;
	x_ = x0;
	left_ = right_ = parent_ = NULL;
	checked_ = false;
	id_ = 0;
}

template <class T>
inline KDNode<T>* KDTree<T>::findLeaf(std::vector<T> &x0, KDNode<T> *node)
{
	KDNode<T>* parent = NULL;
	while (node)
	{
		int split = node->axis_;
		parent = node;
		if (x0[split] > node->x_[split])
			node = node->right_;
		else
			node = node->left_;
	}
	return parent;
}

template <class T>
inline KDNode<T>* KDTree<T>::insert(std::vector<T> &p, KDNode<T> *node)
{
	KDNode<T>* parent = findLeaf(p, node);
	if (parent->equal(p))
		return NULL;
	KDNode<T>* newNode = new KDNode<T>(p, parent->axis_+1 < (int)p.size() ? parent->axis_+1 : 0);
	newNode->parent_ = parent;

	if (p[parent->axis_] > parent->x_[parent->axis_])
	{
		parent->right_ = newNode;
	}
	else
	{
		parent->left_ = newNode;
	}

	return newNode;
}

template <class T>
inline KDTree<T>::KDTree():root_(NULL), KD_id_(0) { }

template <class T>
inline bool KDTree<T>::add(std::vector<T> &x)
{
	if (!root_)
	{
		root_ = new KDNode<T>(x, 0);
		root_->id_ = KD_id_++;
		list_.push_back(root_);
	}
	else
	{
		KDNode<T>* pNode = NULL;
		if ((pNode = insert(x, root_)))
		{
			pNode->id_ = KD_id_++ ;
			list_.push_back(pNode);
		}
	}
	return true ;
}

template <class T>
inline KDNode<T>* KDTree<T>::findNearest(std::vector<T> &x, std::vector<KDNode<T>*> &visitedNodes)
{
	if (!root_)
		return NULL ;

	KDNode<T>* leaf = findLeaf(x, root_);
	nearest_neighbour_ = leaf;
	d_min_ = leaf->distance2(x);
	if (leaf->equal(x))
		return nearest_neighbour_;
	searchParent(leaf, x);
    visitedNodes = checkedNodes_;
	uncheck();

	return nearest_neighbour_;
}

template <class T>
inline void KDTree<T>::checkSubtree(KDNode<T>* node, std::vector<T> &x)
{
	if (!node || node->checked_)
		return;

	checkedNodes_.push_back(node);
	node->checked_ = true;
	updateMinNode(node, x);
	
	int dim = node->axis_;
	T d = node->x_[dim] - x[dim];

	if (d*d > d_min_)
    {
		if (node->x_[dim] > x[dim])
		  checkSubtree(node->left_, x);
		else
		  checkSubtree(node->right_, x);
	}
	// If the distance from the key to the current value is 
	// less than the nearest distance, we still need to look
	// in both directions.
	else
	{
		checkSubtree(node->left_, x);
		checkSubtree(node->right_, x);
	}
}

template <class T>
inline KDNode<T>* KDTree<T>::findNearestBrute(std::vector<T> &x) 
{
	if (!root_)
		return NULL;

	KDNode<T>* nearest = root_;
	T d;
	d_min_ = root_->distance2(x);
	for (int n = 1; n < (int)list_.size(); n++)
	{
		d = list_[n]->distance2(x);
		if (d < d_min_)
		{
			nearest = list_[n];
			d_min_ = d;
		}
	}
	return nearest;
}

template <class T>
inline void KDTree<T>::updateMinNode(KDNode<T>* node, std::vector<T> &x)
{
	if (!node)
		return;
	T d = 0;
	for (int k = 0; k < (int)x.size(); ++k)
	{
        T dx = node->x_[k]-x[k];
        dx *= dx;
        d += dx;
        if (d > d_min_)
            return;
    }
    if (d < d_min_)
    {
        d_min_ = d;
        nearest_neighbour_ = node;
    }
}

template <class T>
inline void KDTree<T>::searchParent(KDNode<T>* parent, std::vector<T> &x)
{
    while (parent)
    {
        checkSubtree(parent, x);
        parent = parent->parent_;
    }
}

template <class T>
inline void KDTree<T>::uncheck()
{
    for (int k = 0; k < (int)checkedNodes_.size(); ++k)
        checkedNodes_[k]->checked_ = false;
    checkedNodes_.clear();
}

#endif

