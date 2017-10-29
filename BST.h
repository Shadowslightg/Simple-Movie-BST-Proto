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

public:
	BST();
	Node * CreateLeaf(int key);
	void AddLeaf(int key);
	void PrintInOrder();
};