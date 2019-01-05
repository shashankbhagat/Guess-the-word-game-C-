// File Name: GuessTheWord.cpp
// Author: Shashank Bhagat
// Date: 09/24/2017
// Compiler Used: VC++
// Notes: This is an implementation file. All the member & non-member functions are implemented.

#include "GuessTheWord.h"
#include <string>
#include <time.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <locale>

using namespace std;

void GuessTheWord::LoadDictionary(string inputFile)
{
	string fileinput;
	int cnt = 0;
	ifstream infile(inputFile);

	while (!infile.eof())
	{
		getline(infile, fileinput);
		input.push_back(fileinput);
	}
	infile.close();
}

void GuessTheWord::Clear()
{
	word = "";
	nextChar = NULL;
	guessWord = "";
	random_number = -1;
}

int GuessTheWord::GetSecretWord()
{
	bool status = true;
	srand(time(0));
	random_number = rand();
	word = input[random_number % input.size()];
	return word.length();
}

const ostream& operator<<(ostream& os, GuessTheWord& obj)
{
	int pos = -1;

	if (obj.nextChar == NULL)
	{
		obj.guessWord = obj.word;
		obj.guessWord.assign(obj.guessWord.length(), '-');
		srand(time(NULL));
		obj.random_number = rand() % (obj.word.length());
		obj.getWordSorted();
	}
	else
	{
		while (obj.word.find(obj.nextChar, pos + 1) != string::npos)
		{
			pos = obj.word.find(obj.nextChar, pos + 1);
			obj.guessWord.replace(pos, 1, obj.word.substr(pos, 1));
		}
	}

	os << obj.guessWord << endl;
	return os;
}

istream& operator>>(istream& in, GuessTheWord& obj)
{
	do
	{
		in >> obj.nextChar;
		obj.nextChar = toupper(obj.nextChar, obj.loc);
	} while (!isalpha(obj.nextChar) || obj.guessWord.find(obj.nextChar, 0) != string::npos);

	return in;
}

bool GuessTheWord::CheckChar()
{
	if (word.find(nextChar, 0) != string::npos)
		return true;
	else
		return false;
}

bool GuessTheWord::IsWin()
{
	if (guessWord == word)
		return true;
	else
		return false;
}

void GuessTheWord::getWordSorted()
{
	int position = -1;
	char ch = word.at(random_number);
	while (word.find(ch, position + 1) != string::npos)
	{
		position = word.find(ch, position + 1);
		guessWord.replace(position, 1, word.substr(position, 1));
	}
}
