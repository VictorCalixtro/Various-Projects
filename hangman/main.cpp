/*Purpose to implement a simple game of hangman*/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
using namespace std;


void showAsterisk(string TW, string &show, int &lives);
void playHangman(string guess, string &show, string theWord, int &lives);

int main()
{	
	cout << "Welcome to a fun game of hangman!" << endl;

	int gamesPlayed = 0;
	int gamesWon = 0;

	string flag;
	int randomNum;
	const int NUMBER_OF_STRINGS = 4;
	string word[NUMBER_OF_STRINGS] = { "dog", "cat", "pizza", "air" };
	string guess;
	

	do
	{
		int lives = 0;
		string showWord = "";
		srand(time(0));
		randomNum = 1 + rand() % NUMBER_OF_STRINGS;
		
		string theWord = word[randomNum -1];

		cout << "Guess the following word: ";
		showAsterisk(theWord, showWord, lives);

		do
		{
			cout << "Enter a Letter: ";
			cin >> guess;
			if (guess.length() > 1)
			{
				cout << "Error: Enter a single letter, Example: d" << endl;
			}
		} while (guess.length() > 1);
		
		

		while (lives != 0)
		{
			playHangman(guess, showWord, theWord, lives);
			if (showWord == theWord)
			{
				cout << endl;
				cout << "The word was " << theWord << endl;
				cout << "You Win!" << endl;
				gamesPlayed += 1;
				gamesWon += 1;
				break;
			}
			if (lives != 0)
			{
				cout << showWord << endl;
			}
			
			if (lives == 0)
			{
				cout << "The word was " << theWord << endl;
				gamesPlayed += 1;
				break;
			}
			do
			{
				cout << "Enter a Letter: ";
				cin >> guess;
				if (guess.length() > 1)
				{
					cout << "Error: Enter a single letter, Example: d" << endl;
				}
			} while (guess.length() > 1);
		}
		

		cout << "Enter any key to play again, press Enter to quit: " << endl;
		cin.get();
		getline(cin, flag);
		if (flag.empty())
		{
			break;
		}

	} while (true);
	cout << "You won " << gamesWon << " games out of " << gamesPlayed << " games total" << endl;
	cout << "Goodbye!" << endl;


	return 0;
}
void showAsterisk(string TW, string &show, int &lives)
{
	for (int i = 0; i < TW.length(); i++)
	{
		cout << "*";
		show += "*";
		lives += 1;
	}
	cout << endl;
}


void playHangman(string guess, string &show, string theWord, int &lives)
{
	int count = 0;
	for (int i = 0; i < theWord.length(); i++)
	{
		if (theWord[i] == guess[0])
		{
			show[i] = guess[0];
			count += 1;
		}
	}
	if (count == 0)
	{
		lives -= 1;
		if (lives == 0)
		{
			cout << endl;
			cout << "Game Over" << endl;
			return;
		}
		cout << lives << " lives remaining." << endl;
	}
}


/*
Program Output

Welcome to a fun game of hangman!
Guess the following word: ***
Enter a Letter: d
2 lives remaining.
***
Enter a Letter: c
1 lives remaining.
***
Enter a Letter: a
a**
Enter a Letter: i
ai*
Enter a Letter: r

The word was air
You Win!
Enter any key to play again, press Enter to quit:
f
Guess the following word: ***
Enter a Letter: d
2 lives remaining.
***
Enter a Letter: c
c**
Enter a Letter: a
ca*
Enter a Letter: t

The word was cat
You Win!
Enter any key to play again, press Enter to quit:
e
Guess the following word: ***
Enter a Letter: d
2 lives remaining.
***
Enter a Letter: c
c**
Enter a Letter: a
ca*
Enter a Letter: t

The word was cat
You Win!
Enter any key to play again, press Enter to quit:
4
Guess the following word: ***
Enter a Letter: c
2 lives remaining.
***
Enter a Letter: d
d**
Enter a Letter: o
do*
Enter a Letter: s
1 lives remaining.
do*
Enter a Letter: g

The word was dog
You Win!
Enter any key to play again, press Enter to quit:

You won 4 games out of 4 games total
Goodbye!
Press any key to continue . . .

*/
