#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include "BST.h"
using namespace std;

BST::BST()
{
	root = NULL;
}

BST::Node * BST::CreateLeaf(int key)
{
	Node * n = new Node;
	n-> key = key;
	n-> Left = NULL;
	n-> Right = NULL;

	return n;
}

void BST::AddLeaf(int key)
{
	AddLeafPrivate (key, root);
}


void BST::AddLeafPrivate (int key, Node * ptr)
{
	if (root==NULL)	//if the tree is empty
	{
		root = CreateLeaf(key);
	}
	else if(key < ptr->key)	//Left leaf creation
	{
		if (ptr -> Left != NULL)
		{
			AddLeafPrivate(key, ptr->Left);		//location where we add new leaf to tree
		}
		else
		{
			ptr->Left = CreateLeaf(key);
		}
	}
	else if(key > ptr->key) //right leaf creation
	{
		if (ptr -> Right != NULL)
		{
			AddLeafPrivate(key, ptr->Right);	//location where we add new leaf to tree
		}
		else
		{
			ptr->Right = CreateLeaf(key);
		}
	}
	else 
	{
		cout << "The Key " << key << "has already been added to the tree\n" << endl;
	}
}

void BST::PrintInOrder()
{
	PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(Node *ptr)
{
	if (root != NULL)
	{
		if (root->Left != NULL)
		{
			PrintInOrderPrivate(ptr->Left);
		}
		cout << ptr->key << " ";
		if (ptr->Right != NULL)
		{
			PrintInOrderPrivate(ptr->Right);
		}
	}
	else
	{
		cout << "The tree is empty " << endl;
	}
}