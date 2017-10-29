// BSTproto.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BST.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int TreeKeys[16] = { 50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80 };
	BST myTree;

	cout << "Printing the tree in order\nBefore adding numbers\n";

	myTree.PrintInOrder();
	
	for (int i = 0; i < 16; i++)
	{
		myTree.AddLeaf(TreeKeys[i]);
	}

	cout << "Printing the tree in order\nAfter adding numbers\n";
	
	myTree.PrintInOrder();

	system("pause");
    return 0;
}

