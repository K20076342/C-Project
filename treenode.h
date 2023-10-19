#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

#include <memory>
using std::unique_ptr;

#include <utility>
using std::pair;

// TODO your code for the TreeNode class goes here:

template <typename T>
class TreeNode{

public:
	T data;
	unique_ptr <TreeNode <T>> leftChild;
	unique_ptr <TreeNode <T>> rightChild;
	TreeNode <T>* parent;
//constructor
TreeNode(const T& d):data (d), parent(nullptr){}

void setLeftChild(TreeNode* child)
{
	leftChild.reset(child);
	child -> parent = this;
}

void setRightChild(TreeNode* child)
{
	rightChild.reset(child);
	child -> parent = this;
}

ostream & write (ostream& c) const
{
	if (leftChild!= nullptr)
	{
		leftChild->write(c);
		
	}

	c<< " " <<this->data<<" ";

	if (rightChild!=nullptr)
	{
		rightChild->write(c);
		
	}

	return c;

	}

int maxDepth(TreeNode* temp)
{
	if (!temp)
	{
		return 0;
	}

	int toLeft = maxDepth(temp-> leftChild.get());
	int toRight = maxDepth(temp-> rightChild.get());

	return 1+ std::max(toLeft, toRight);
}

};
template <typename T>
class TreeNodeIterator
{
private:
	TreeNode<T>* temp;

public:
	TreeNodeIterator(TreeNode<T>*temp1)
	:temp(temp1){}

T& operator*()
{
	return temp->data;
}

TreeNodeIterator<T> operator++()
{
	temp = temp->parent;
	return*this;
}

bool operator==(const TreeNodeIterator& temp1)
{
	return temp == temp1.temp;
}

bool operator!=(const TreeNodeIterator& temp1)
{
	return temp != temp1.temp;
}

};


// do not edit below this line

#endif
