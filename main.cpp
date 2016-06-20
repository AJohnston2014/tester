#include "game.h"
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	bool uPlay = false;
	string fingerPlay;

	do {
		srand((unsigned int)time(NULL));
		string uEnter;
		game iPlay(uEnter);
		iPlay.displayGame();
		cin >> uEnter;
		iPlay.play();
		cout << "Would you like to continue ? Please Enter (Yes or yes) or (No or N)"<< endl;
		cin >> fingerPlay;
		if (fingerPlay == "Yes" || fingerPlay == "yes")
		{
			uPlay = true;
		}
		else
			uPlay = false;
		
	} while (uPlay==true);
}