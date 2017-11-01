#include <iostream>
#include <class>

#include "Movie_ss.h"

using namespace std;



int main () 
{
ifstream infile;
string text; 
int blank =0, test=0;

string filename;
	cout << "What is the name of your data file?" << endl;
	getline(cin, filename);
	cout << CountLines() << endl;
	system("pause");	
	
infile.open("Movie_List.txt");
while (getline(infile, text))
{
	if (text == "")
	{
		++blank;
	}
	else
	{
		++test;
	}
}
cout << "Blank: " << blank << endl
cout << "With Text: " << text << endl;
return 0;

}

int CountLines()
{
	int numLines = NULL;

	ifstream dataFile("Movie_List.txt");
	string line;
		while (getline(dataFile, line))
		{
			numLines++;
		}
	return numLines;
}
