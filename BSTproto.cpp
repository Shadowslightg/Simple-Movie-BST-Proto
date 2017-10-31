// BSTproto.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

#include "BST.cpp"
using namespace std;



struct Movies_Bio
{
	string Movie Title;
	int Year;
	char Actors[];
};

typedef Movies_Bio info; 

int main()
{
	int TreeKeys[16] = { 50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80 };
	BST myTree;
	int input;
	
	cout << "Printing the tree in order\n" << "Before adding numbers\n";

	myTree.PrintInOrder();
	
	for (int i = 0; i < 16; i++)
	{
		myTree.AddLeaf(TreeKeys[i]);
	}

	cout << "Printing the tree in order\n" << "After adding numbers\n";
	
	myTree.PrintInOrder();

	cout << endl;
	
	myTree.PrintChildren(myTree.ReturnRootKey());

	cout << "The smallest value in the tree is " << myTree.FindSmallest() << endl;
	cout << "Enter a key value to delete. Enter -1 to stop the process\n";
	
	while (input != -1)
	{
		cout << "Delete Node: ";
		cin >>input;
		{
			if (input !=-1)
			{
				cout << endl;
				myTree.RemoveNode(input);
				mtTree.PrintInOrdr();
				cout << endl;
	system("pause");
//**********************************************				
//**********************************************
// This next part is the code for the file functions
				
ifstream infile;
string text; 
int blank =0, 
int text=0;

infile.open("Movie_List.txt");
while (getline(infile, text))
{
	if (text == "")
	{
		++blank;
	}
	else
	{
		++text;
	}
}
cout << "Blank: " << blank << endl
cout << "With Text: " << text << endl;
return 0;				
				
				
				
				
//**********************************************				
//**********************************************			
    return 0;
}

