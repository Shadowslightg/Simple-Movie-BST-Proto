#include <iostream>
#include <class>

#include "Movie_ss.h"

using namespace std;



int main () 
{
ifstream infile;
string text; 
int blank =0, text=0;

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

}