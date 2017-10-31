#include "stdafx.h"
#include <iostream>
#include <cstdlib>

#include "BST.h"

using namespace std;

//this function sets the pointer of the Node called root 
//to the NUll termination value
BST::BST()	
{
	root = NULL;	//to ensure root is not pointing to anything when created
}
//this function is used to create a new instance of the struct Node
//and creats a Left and Right Pointer for the BST
BST::Node * BST::CreateLeaf(int key)
{
	Node * n = new Node;	//pointer we will be returning
	n-> key = key;		//access key variable set equal to key we are passing in
	n-> Left = NULL;	//set the Left Pointer to a terminating value
	n-> Right = NULL;	//set the Right Pointer to a terminating value

	return n;		//returns pointer of newly created Node
}
//this function is designed to add a new node without having to account for the root 
//of the tree; it will just take in a value and add it to the tree
void BST::AddLeaf(int key)
{
	AddLeafPrivate (key, root);	
}
//this function is desinged to add a new leaf based off of the root pointer
//
void BST::AddLeafPrivate (int key, Node * ptr)
{
	if (root==NULL)	//if the tree is empty
	{
		root = CreateLeaf(key);	//will point to a new leaf with the current key value
	}
	else if(key < ptr->key)	//Left leaf creation
	{
		if (ptr -> Left != NULL)	//if Left ptr has a value; tranverse left and check again
		{
			AddLeafPrivate(key, ptr->Left);		//location where we add new leaf to tree
		}
		else				//if its not create a new leaf and pass in the value key
		{
			ptr->Left = CreateLeaf(key);
		}
	}
	else if(key > ptr->key) //Right leaf creation
	{
		if (ptr -> Right != NULL)	//if Right ptr has a value; tranverse right and check again
		{
			AddLeafPrivate(key, ptr->Right);	//location where we add new leaf to tree
		}
		else				//if its not create a new leaf and pass in the value key
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
		else
		{
		
			if (key < parent->key && parent->Left != NULL)
			{
				parent->Left->key == key ?
				RemoveMatch(parent, parent->Left, true) :
				RemoveNodePrivate(key, parent->Left);
			}
			else if(key > parent->key && parent->Right != NULL)
			{
				parent->Right->key == key ?
				RemoveMatch(parent, parent->Right, false) :
				RemoveNodePrivate(key, parent->Right);
			}
			else
			{		
				cout << "The key: " << key << "was not found in the tree\n";
			}
		}
	}
	else
	{
		cout << "The tree is empty\n";
	}
}

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
//Node we want to remove is going to be paired with the match pointer
//the parent of that Node is going to be paired with the Parent pointer
//indicate teh relationship between parent and matching node
//if the bool is false then the match is the right side of the parent Node
void BST::RemoveMatch(Node * parent, Node * match, bool Left)
{
	if (root != NULL)
	{
		Node * delptr;
		int matchKey = match->key;
		int smallestInRightSubtree;
	
	//case 0-0 children
	if (match->Left == NULL && match->Right == NULL)
	{
		delptr = match;
		Left = true ? parent->Left = NULL : parent->Right = NULL;
		delete delptr;
		cout << "The node contianing key: " << matchKey << "was removed\n";
	}
	//case 1- 1 child
	else if (match->Left == NULL && match->Right != NULL)
	{
		Left == true ? parent->Left = match->Right : parent->Right = match->Right;
		match->Right = NULL;	//disconnect matching node from tree
		delptr = match;		//point to the Node we want to delete
		delete delptr;		//delete node it was pointing too
		cout << "The node contianing key: " << matchKey << "was removed\n";
	}
	else if (match->Left != NULL && match->Right == NULL)
	{
		Left == true ? parent->Left = match->Left : parent->Right = match->Left;
		match->Left = NULL;	//disconnect matching node from tree
		delptr = match;		//point Node to what we want to delete
		delete delptr;		//delete that Node 
		cout << "The node contianing key: " << matchKey << "was removed\n";
	}
	//case 2-2 children
	else
	{
		//
		smallestInRightSubtree = FindSmallestPrivate(match->Right);
		//remove the smallest key
		RemoveNodePrivate(smallestInRightSubtree, match);
		match->key = smallestInRightSubtree;
	}
	else
	{
		cout << "Can not remove match. The tree is empty\n";		
	}
}
	
BST::~BST();
{
	RemoveSubtree(root);
}

void BST::RemoveSubtree(Node * ptr)
{
	if (ptr != NULL)
	{
		if (ptr->Left != NULL)
		{
			RemoveSubtree(ptr->Left);
		}
		if (ptr->Right != NULL)
		{
			RemoveSubtree(ptr->Right);
		}
		cout << "Deleting the Node containing key: " <<ptr->key << endl; 
		delete ptr;
	}
}
	
	
	
	
	
	
	
	
