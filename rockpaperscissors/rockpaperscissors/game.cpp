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
	cout << "Welcome to Rock paper Scissors " << endl;
	cout << "Please Enter (rock or Rock or R) or (scissors or Scissors or S) or (paper or Paper or P)" << endl;
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
	
	string playBack;
	if (userInput == "Rock"|| userInput=="R"|| userInput=="rock")
	{
		if (result == "Rock")
		{
			playBack = "tie";
		}
		if (result == "paper")
		{
			playerWins++;
		}
		if (result == "scissors")
		{
			computerWins++;
		}
	}
	else if (userInput == "paper" || userInput == "p"|| userInput=="Paper")
	{
		if (result == "Rock")
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
		if (result == "Rock")
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


