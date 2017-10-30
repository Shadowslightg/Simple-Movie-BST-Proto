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
	Node * CreateLeaf(int key);
	Node * ReturnNode(int key);
	int FindSmallestPrivate(Node * ptr);
	void RemoveNodePrivate(int key, Node * parent);
	void RemoveRootMatch();		//remove the root node from the tree
	void RemoveMatch(Node * parent, Node * match, bool Left); 	//remove a matching node from the tree that is not a root
	void RemoveSubtree (Node * ptr);
	
public:
	BST();	//Null terminator assignment
	~BST();
	void AddLeaf(int key);
	void PrintInOrder();
	int ReturnRootKey();
	void PrintChildren(int key);
	int FindSmallest();
	void RemoveNode(int key);


};
