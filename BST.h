#include "stdafx.h"


class BST
{
private:
	struct Node
	{
		int key;
		Node * Left;
		Node * Right;
	};
	Node * root;

	void AddLeafPrivate(int key, Node * ptr);
	void PrintInOrderPrivate(Node * ptr);
	Node * ReturnNodePrivate(int key, Node * ptr);
	int FindSmallestPrivate(Node * ptr);
	void RemoveNodePrivate(int key, Node * parent);
	void RemoveRootMatch();
	//void RemoveMatch(Node * parent, Node * match, bool Left);

public:
	BST();
	Node * CreateLeaf(int key);
	void AddLeaf(int key);
	void PrintInOrder();
	Node * ReturnNode(int key);
	int ReturnRootKey();
	void PrintChildren(int key);
	int FindSmallest();
	void RemoveNode(int key);


};