#include "gameController.h"
#include <iostream>
#include <string>
#ifndef MAIN_CPP
#define MAIN_CPP

int main(){
	char again = 'y';
	while(again != 'n'){
		gameController game;
		game.displayMenu();
		game.playGame();
		cout << "WOULD YOU LIKE TO ENGAGE IN FURTHER RACKING HUMAN?!" << endl;
		cout << "(y) - play again (n) - quit" << endl;
		bool valid = false;
		while(!valid){
			cin >> again;
			if(again != 'y' && again != 'n'){
				cout << "INVALID COMMAND, COMMANDS ARE (y) - play again, (n) - quit" << endl;
			}
			else{
				valid = true;
			}
		}
			
	}
	return 0;
}
#endif
