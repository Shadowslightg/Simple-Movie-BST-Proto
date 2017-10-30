#include "stdafx.h"


class BST
{
private:
	struct Node	//creates the Node for the tree; The ROOT
	{
		int key;
		Node * Left;
		Node * Right;
	};
	Node * root;
			//this is the end of the ROOT Node. 
	void AddLeafPrivate(int key, Node * ptr);	//function creates a new leaf for the Node
	void PrintInOrderPrivate(Node * ptr);
	Node * ReturnNodePrivate(int key, Node * ptr);
	int FindSmallestPrivate(Node * ptr);
	void RemoveNodePrivate(int key, Node * parent);
	void RemoveRootMatch();
	//void RemoveMatch(Node * parent, Node * match, bool Left);

public:
	BST();	//Null terminator assignment
	Node * CreateLeaf(int key);
	void AddLeaf(int key);
	void PrintInOrder();
	Node * ReturnNode(int key);
	int ReturnRootKey();
	void PrintChildren(int key);
	int FindSmallest();
	void RemoveNode(int key);


};
