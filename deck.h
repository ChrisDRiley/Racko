#include <vector>
#ifndef DECK_H
#define DECK_H

class Deck{
	public:
		Deck();
		void shuffle();
		int display();
		int getDiscard();
		int dealCard();
		void addCardToDiscard(int currentCard);
	private:
		std::vector<int> drawPile;
		std::vector<int> discardPile;
};
#endif
