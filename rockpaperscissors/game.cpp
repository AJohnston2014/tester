#include "game.h"
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

game::game(string input)
{
	//aArray = new string[3];
	aArray[0] = "rock";
	aArray[1] = "paper";
	aArray[2] = "scissors";
	computerWins = 0;
	playerWins = 0;
	userInput = input;
}
game::~game()
{
	//delete[] aArray;
}
void game::displayGame()
{
	cout << "Welcome to rock paper Scissors " << endl;
	cout << "Please Enter rock or scissors  or paper " << endl;
}
string game::play()
{
	int randGenator= rand() % 10 + 1;
	string randResult;
	if (randGenator <= 3)
	{
		randResult=aArray[2];// scissors
	}
	else if (randGenator <= 6)
	{
		randResult=aArray[1]; //paper
	}
	else
	{
		randResult=aArray[0]; //rock
	}
	return comparison(randResult);
}
string game::comparison(string result)
{
	string tryagain;
	string playBack;

	if (userInput=="rock")
	{
		if (result == "rock")
		{
			playBack = "tie";
		}
		if (result == "paper")
		{
			computerWins++;
		}
		if (result == "scissors")
		{
			playerWins++;
		}
	}
	else if (userInput == "paper" )
	{
		if (result == "rock")
		{
			playerWins++;
		}
		if (result == "paper")
		{
			playBack = "tie";
		}
		if (result == "scissors")
		{
			computerWins++;
		}
	}
	else // userInput is equal to scissors
	{
		if (result == "rock")
		{
			computerWins++;
		}
		if (result == "paper")
		{
			playerWins++;
		}
		if (result == "scissors")
		{
			playBack = "tie";
		}
	}

	return winnerOfGame(playBack);
}
string game::winnerOfGame(string winner)
{
	string console;
	if (winner == "tie")
	{
		console = "tie";
	}
	else if (playerWins >= computerWins)
	{
		console = "Player";
	}
	else 
	{
		console = "computer";
	}
	return displayWinnerOfGame(console);
	 
}
string game::displayWinnerOfGame(string print)
{
	cout << "The winner of the game is " << print << endl;
	return print;
}


