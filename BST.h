#include "stdafx.h"
#ifndef BST_H
#define BST_H

class BST
{
private:
	struct Node	//creates the Node for the tree; The ROOT
	{
		int key;
		Node * Left;
		Node * Right;
	};
	Node * root;	//used to reference the top of the tree root Node
			//this is the end of the ROOT Node
	
	void AddLeafPrivate(int key, Node * ptr);	//function creates a new leaf for the Node
	void PrintInOrderPrivate(Node * ptr);
	Node * ReturnNodePrivate(int key, Node * ptr);
	Node * CreateLeaf(int key);	//create a leaf with a given value
	Node * ReturnNode(int key);
	int FindSmallestPrivate(Node * ptr);
	void RemoveNodePrivate(int key, Node * parent);
	void RemoveRootMatch();		//remove the root node from the tree
	void RemoveMatch(Node * parent, Node * match, bool Left); 	//remove a matching node from the tree that is not a root
	void RemoveSubtree (Node * ptr);
	
public:
	BST();	//constructor; Called anytime we create a new instance of BST
	~BST();
	void AddLeaf(int key);	//Adding a new Node=leaf to tree; specifying value
	void PrintInOrder();
	int ReturnRootKey();
	void PrintChildren(int key);
	int FindSmallest();
	void RemoveNode(int key);


};

#endif BST_H

