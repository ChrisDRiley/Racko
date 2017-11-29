#include "deck.h"
#include "linked_list.h"
#include <vector>
#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

class gameController{
	public:
		void displayMenu();
		void playGame();
		void AITurn();
		bool check_racko(int player);
		void deal_initial_hands();
		void print_top_to_bottom(int player);
		bool findAndReplace(int newCard, int cardToBeReplaced, int player);
	private:
		linked_list<int> humanRack;
		linked_list<int> AIRack;
		std::vector<int> stored;
		bool playing;
		Deck gameDeck;
};
#endif
		
