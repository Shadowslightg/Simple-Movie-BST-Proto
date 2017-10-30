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
		//if (root->Left != NULL)
		if (ptr ->Left != NULL)
		{
			PrintInOrderPrivate(ptr -> Left);
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

BST::Node * BST::ReturnNode(int key)
{
	return ReturnNodePrivate(key, root);
}


BST::Node * BST::ReturnNodePrivate(int key, Node * ptr)
{
	if (ptr != NULL)
	{
		if (ptr->key == key)
		{
			return ptr;
		}
		else
		{
			if (key < ptr->key)
			{
				return ReturnNodePrivate(key, ptr->Left);
			}
			else
			{
				return ReturnNodePrivate(key, ptr->Right);
			}
		}
	}
	else
	{
		return NULL;
	}
}

int BST::ReturnRootKey()
{
	if (root != NULL)
	{
		return root->key;
	}
	else
	{
		return -1000;
	}
}

void BST::PrintChildren(int key)
{
	Node *ptr = ReturnNode(key);

	if (ptr != NULL)
	{
		cout << "Parent Node = " << ptr->key << endl;

		ptr->Left == NULL ?
			cout << "Left Child = NULL\n" :
			cout << "Left Child = " << ptr->Left->key << endl;
		
		ptr->Right == NULL ?
			cout << "Right Child = NULL\n" :
			cout << "Right Child = " << ptr->Right->key << endl;
	}
	else
	{
		cout << "Key" << key << "is not int the tree\n";
	}
}

int BST::FindSmallest()
{
	return FindSmallestPrivate(root);
}

int BST::FindSmallestPrivate(Node * ptr)
{
	if (root == NULL)
	{
		cout << "The tree is empty\n";
		return -1000;
	}
	else
	{
		if (ptr->Left != NULL)
		{
			return FindSmallestPrivate(ptr->Left);
		}
		else
		{
			return ptr->key;
		}
			
	}
}

void BST::RemoveNode(int key)
{
	return RemoveNodePrivate(key, root);
}

void BST::RemoveNodePrivate(int key, Node * parent)
{
	if (root != NULL)
	{
		if (root->key == key)
		{
			RemoveRootMatch();
			return;
		}
		
		
		if (key < parent->key && parent->Left != NULL)
		{
			parent->Left->key == key ?
				RemoveMatch(parent, parent->Left, true) :
				RemoveNodePrivate(key, parent->Left);
			return;
		}
		
		if(key > parent->key && parent->Right != NULL)
		{
			parent->Right->key == key ?
				RemoveMatch(parent, parent->Right, false) :\
				RemoveNodePrivate(key, parent->Right);
			return;
		}
		
		
		cout << "The key: " << key << "was not found in the tree\n";
		return;

		
	}
	else
	{
		cout << "The tree is empty\n";
	}
}

//void BST::RemoveRootMatch()
//{
//	return 
//}

void BST::RemoveRootMatch()
{
	if (root != NULL)
	{
		Node * delptr = root;
		int rootket = root->key;
		int smallestinRightSubtree;

		//case 0: has 0 children
		if (root->Left == NULL && root->Right == NULL)
		{
			root = NULL;
			delete delptr;
		}
			//case 1: root node has 1 child
		else if (root->Left == NULL && root->Right != NULL)
		{
			root = root->Right;
			delptr->Right == NULL;
			delete delptr;
			cout << "The root node with key: " << rootkey << "was deleted." << "The new root contains key: " << root->key << endl;
		}
		else if (root->Left != NULL && root->Right == NULL)
		{
			root = root->Left;
			delptr->Left == NULL;
			delete delptr;
			cout << "The root node with key: " << rootkey << "was deleted." << "The new root contains key: " << root->key << endl;
		}
		//case 2: 2 children
		else
		{
			smallestinRightSubtree = FindSmallestPrivate(root->Right);
			RemoveNodePrivate(smallestinRightSubtree, root);
			root->key = smallestinRightSubtree;
			cout << "The rook key containing key" << rootkey << "was overwritten with key" << root->key << endl;
		}
	}
	else
	{
		cout << "Can not remove root. The Tree is empty\n";
		
	}
}

//void BST::RemoveMatch(Node * parent, Node * match, bool Left)
//	{
//		/*if (root != NULL)
//		{
//			Node * delptr;
//			int matchKey = match->key;
//			int smallestInRightSubtree;
//			return;
//		}*/
//
//		if (root == NULL)
//		{
//			cout << "Can not remove match. The Tree is empty.";
//			return;
//		}
//		//we know root is not null
//
//		if (root->Left == root->Right == NULL)
//		{
//			if(root->key == key)
//		}
//		
//
//
//		
//
//			//case 0-0 children
//		if (match->Left == NULL && match->Right == NULL)
//			{
//				delptr = match;
//				Left = true ? parent->Left = NULL : parent->Right = NULL;
//				delete delptr;
//				cout << "The node contianing key: " << matchKey << "was removed\n";
//			}
//			//case 1- 1 child
//		else if (match->Left == NULL && match->Right != NULL)
//			{
//				Left == true ? parent->Left = match->Right : parent->Right = match->Right;
//				match->Right = NULL;
//				delptr = match;
//				delete delptr;
//				cout << "The node contianing key: " << matchKey << "was removed\n";
//			}
//		else if (match->Left != NULL && match->Right == NULL)
//			{
//				Left == true ? parent->Left = match->Left : parent->Right = match->Left;
//				match->Left = NULL;
//				delptr = match;
//				delete delptr;
//				cout << "The node contianing key: " << matchKey << "was removed\n";
//			}
//			//case 2-2 children
//		else
//			{
//				smallestInRightSubtree = FindSmallestPrivate(match->Right);
//				RemoveNodePrivate(smallestInRightSubtree, match);
//				match -> = smallestInRightSubtree;
//			}
//
//		else
//			{
//				
//			}
//		}
	