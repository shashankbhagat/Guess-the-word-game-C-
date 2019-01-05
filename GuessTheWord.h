// File Name: GuessTheWord.h
// Author: Shashank Bhagat
// Date: 09/24/2017
// Compiler Used: VC++
// Notes: This is a header file. Includes all the declaration of the variables and member functions in private and public section.

#pragma once
#ifndef GUESSTHEWORD
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class GuessTheWord
{
public:
	GuessTheWord()
	{
		word = "";
		nextChar = NULL;
		guessWord = "";
		random_number = -1;
	}
	void LoadDictionary(string inputFile = "default.txt");
	void Clear();
	int GetSecretWord();
	friend const ostream& operator<<(ostream&, GuessTheWord&);
	friend istream& operator>>(istream& in, GuessTheWord&);
	bool CheckChar();
	bool IsWin();	

private:
	locale loc;
	int random_number;
	string word;
	vector <string> input;
	char nextChar;
	string guessWord;

	void getWordSorted();
};
#endif