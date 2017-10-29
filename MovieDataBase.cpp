// MovieDataBase.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
//#include <stdio.h>

using namespace std;

struct Moviedb
{
	string Movie_Title;
	int Release_Year;
	string Actors;
	Moviedb * left;
	Moviedb * right;

	void Print_List()
	{
		cout << Movie_Title << " " << Release_Year << " " << Actors << " " << endl;
	}
	//Node(string title, int year, string[] actors)
	//{
		/*this->Movie_Title = title;
		this->Release_Year = year;
		this->Actors = Actors;*/
	//}
};

//typedef struct Moviedb db;

#define Maxint 20

Moviedb currDB[20];

int ReadMoviedb(char * dnName, int maxMovie);
void ShowMovie(ofstream & outFile, int nMV);

int main()
{
	Moviedb db;
	ofstream outFile("Movie_List_output.txt", ios::out);
	if (!outFile)
	{
		cerr << "Unable to open: \"" << "Movie_List_output.txt" << "\"" << endl;
		exit(-1);
	}
	int nMV = ReadMoviedb("Movie_List.txt", 20);

	outFile << "Movies Read: " << nMV << endl;

	if (nMV > 0)
	{
		outFile << "Initial contents of Movie Data Base : \n" << endl;
		ShowMovie(outFile, nMV);
	}
	outFile.close();
	db.Print_List();

	system("Pause");
	return 0;
}

int ReadMoviedb(char * dbName, int maxMovie)
{
	ifstream inMovieFile(dbName);
	if (!inMovieFile)
	{
		cerr << "Unable to open file: " << dbName << endl;
		return -1;
	}
	int i = 0;
	bool done = false;
	const int MAX_LINE = 80;
	char tmpLine[MAX_LINE];

	while (!done && i < maxMovie)
	{
		char * line = "";
		char Actor[] = "";
		//strcpy(Actor[], Moviedb.Actors);
		

		inMovieFile.getline(line, Maxint);
		currDB[i].Movie_Title = line;
		//inMovieFile.getline(currDB[i].title, MAX_TITLE_LENGTH);
		//inMovieFile.getline(strcpy(Actor, currDB[i].Actors, line);
		/*inMovieFile.getline(line, Maxint);
		currDB[i].Actors = new string(line);*/

		inMovieFile.getline(Actor, Maxint);
		currDB[i].Actors = Actor;

		//currDB[i].Actors = strcpy( currDB[i], Moviedb.Actors);
		
		inMovieFile >> currDB[i].Release_Year;
		inMovieFile.getline(tmpLine, MAX_LINE);
		//if( !inCDFile.good() && i < maxCDs )  done = true;

		if (inMovieFile.eof())
			done = true;

		++i;
	}
	inMovieFile.close();
	return i; //one too many?
}

/* ShowCDs
*
*  Show the contents of the CD data base
*/

void ShowMovie(ofstream & o , const int nMV)
{
	for (int i = 0; i < nMV; i++)
	{
		o << currDB[i].Movie_Title << "\n\t";
		o << currDB[i].Actors;
		o << endl;
	}
	o << "---------------------\n " << endl;
}
