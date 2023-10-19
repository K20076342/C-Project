#ifndef TREE_H
#define TREE_H

#include "treenode.h"
#include <iostream>


using std::unique_ptr;


// TODO your code goes here:

template <typename T>
class BinarySearchTree{

private:
	
	unique_ptr<TreeNode<T>> root;

public:

//empty constructor
BinarySearchTree (){}

//copy constructor

BinarySearchTree(BinarySearchTree& item)
{
	root.reset((item.root).get());
}

void write (ostream & c) const {
	root->write(c);
}

void operator = (BinarySearchTree& item)
{
	root.reset((item.root).get());
}

TreeNode<T> *insert(T item)
{
	TreeNode<T>* current = root.get();
	TreeNode<T>* newTreeNode = new TreeNode<T> (item);

//If the data is not already in the tree, it should make a node and add this in the correct place
	if (!current)
	{
		root = unique_ptr<TreeNode<T>>(newTreeNode);
		return newTreeNode;

	}

	while (current)
	{
		if (current->data <item)
		{
			if (!current->rightChild)
			{
				current->setRightChild(newTreeNode);
				return newTreeNode;
			}
			current=current->rightChild.get();
		}
		 else if (item < current->data)
		 {

			if (!current->leftChild)
		
			{
				current->setLeftChild(newTreeNode);
				return newTreeNode;
			}
			current=current->leftChild.get();
		}
		
		else 
		{
			delete newTreeNode;
			return current;
		}
		
	}

	return newTreeNode;

}

	TreeNode<T> *find(T item)
{
	TreeNode<T>* current = root.get();
	TreeNode<T>* newTreeNode = new TreeNode<T> (item);

	if (!current)
	{
		return nullptr;

	}

	while (current)
	{
		if (current->data <item)
		{
			if (!current->rightChild)
			{
				current->setRightChild(newTreeNode);
				return nullptr;
			}
			current=current->rightChild.get();
		}
		 else if (item < current->data)
		 {

			if (!current->leftChild)
		
			{
				return nullptr;
			}
			current=current->leftChild.get();
		}
		
		else 
		{
			delete newTreeNode;
			return current;
		}
		
	}

	return nullptr;

}
	
};


// do not edit below this line

#endif
