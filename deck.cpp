#include "deck.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#ifndef DECK_CPP
#define DECK_CPP

using namespace std;

Deck::Deck(){
	for(int i = 1; i < 61; i++){
		drawPile.push_back(i);
	}
	srand (time(NULL));
}
void Deck::shuffle(){
	for(int i = 0; i < drawPile.size(); i++){
		addCardToDiscard(drawPile.at(i));
	}
	drawPile = discardPile;
	discardPile.clear();
	random_shuffle(drawPile.begin(),drawPile.end());
}
int Deck::display(){
	cout << "TOP OF DISCARD: " << discardPile.back() << endl;
	return discardPile.back();
}
int Deck::getDiscard(){
	if(discardPile.size() == 0){
		return -1;
	}
	else{
		int card = discardPile.back();
		discardPile.pop_back();
		return card;
	}
}
int Deck::dealCard(){
	int card = drawPile.back();
	drawPile.pop_back();
	if(drawPile.size() == 0){
		shuffle();
	}
	return card;
}	
void Deck::addCardToDiscard(int card){
	discardPile.push_back(card);
}
	
#endif
