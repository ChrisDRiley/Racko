#include "gameController.h"
#include "deck.h"
#include "linked_list.h"
#include <iostream>
#ifndef GAMECONTROLLER_CPP
#define GAMECONTROLLER_CPP

void gameController::displayMenu(){
	cout << "Welcome to Racko HUUUUMMAANNN! Rack the best Rack to win!" << endl;
	cout << "To win, make it so the cards in your rack are sorted, top to bottom, from lowest to highest number" << endl << endl;
	cout << "You will be dealt a rack of 10 cards, during your turn, you can draw a card from the deck, or take" << endl;
	cout << "the top card from the discard pile. Swap that card with a card in your rack, and put that card in" << endl;
	cout << "the discard pile." << endl;
	cout << "If you take a card from the deck, you can immediately put it in the discard pile" << endl << endl;
}
void gameController::playGame(){
	cout << "We will now draw to see who goes first!" << endl;
	gameDeck.shuffle();
	int pCard = gameDeck.dealCard();
	int cCard = gameDeck.dealCard();
	cout << "PLAYER DREW:" << pCard << endl;
	cout << "COMPUTER DREW:" << cCard << endl;
	if(pCard > cCard){
		cout << "Player goes first!" << endl;
		playing = true;
	}
	else{
		cout << "Computer goes first!" << endl;
		playing = false;
	}
	gameDeck.shuffle();
	deal_initial_hands();
	int firstCard = gameDeck.dealCard();
	gameDeck.addCardToDiscard(firstCard);
	while(!check_racko(0) && !check_racko(1)){
		if(playing){
			cout << "YOUR RACK" << endl;
			print_top_to_bottom(0);
			gameDeck.display();
			bool valid = false;
			int choice;
			while(!valid){
				cout << "Choose an option from the following:" << endl;
				cout << "1 - Take a card from the top of the deck" << endl;
				cout << "2 - Take the card on the top of the discard pile" << endl;
				cout << "Enter your choice:" << endl;
				cin >> choice;
				if(choice != 1 && choice != 2){
					cout << "HEY, choose a VALID option!" << endl;
				}
				else{
					valid = true;
				}
			}
			int cardInHand;
			if(choice == 1){
				cardInHand = gameDeck.dealCard();
			}
			else{
				cardInHand = gameDeck.getDiscard();
			}
			cout << "CARD IN HAND: " << cardInHand << endl;
			valid = false;
			if(choice == 1){
				while(!valid){
					cout << "Do you want to discard this card? (1) - yes, (2) - no: " << endl;
					cin >> choice;
					if(choice != 1 && choice != 2){
						cout << "READ THE DIRECTIONS, choose a VALID number" << endl;
					}
					else{
						valid = true;
					}
				}
				if(choice == 1){
					gameDeck.addCardToDiscard(cardInHand);
				}
			}
			if(choice == 2){
				valid = false;
				int cardToReplace;
				while(!valid){
					cout << "What card in your rack do you want to replace?" << endl;
					cin >> cardToReplace;
					if(findAndReplace(cardInHand,cardToReplace,0)){
						gameDeck.addCardToDiscard(cardToReplace);
						valid = true;
					}
					else{
						cout << "THAT ISNT A CARD IN YOUR RACK BLOCKHEAD, TRY AGAIN" << endl;
					}
				}
				
			}
			playing = false;
		}
		else{
			AITurn();
		}
	}
	if(check_racko(0)){
		cout << "CONGRATULATIONS HUMAN, YOU DID A RACKO" << endl;
	}
	else{
		cout << "NICE TRY HUMAN, NO ONE RACKO'S BETTER THAN A ROBOT" << endl;
	}	
}	
void gameController::AITurn(){
	int discard = gameDeck.display();
	int lowest = stored.at(9);
	int second = stored.at(8);
	int third = stored.at(7);
	int fourth = stored.at(6);
	int fifth = stored.at(5);
	int sixth = stored.at(4);
	int seventh = stored.at(3);
	int eighth = stored.at(2);
	int ninth = stored.at(1);
	int highest = stored.at(0);
	if(discard > highest && discard >= 50 && discard > ninth){
		gameDeck.getDiscard();
		findAndReplace(discard,highest,1);
		gameDeck.addCardToDiscard(highest);
		stored.at(0) = discard;
	}
	else if(discard < lowest && discard <= 10 && discard < second){
		gameDeck.getDiscard();
		findAndReplace(discard,lowest,1);
		gameDeck.addCardToDiscard(lowest);
		stored.at(9) = discard;
	}
	else if(discard < second && discard-lowest < 5 && discard <= 15){
		gameDeck.getDiscard();
		findAndReplace(discard,second,1);
		gameDeck.addCardToDiscard(second);
		stored.at(8) = discard;
	}
	else if(discard < third && discard-second < 5 && discard <= 20){
		gameDeck.getDiscard();
		findAndReplace(discard,third,1);
		gameDeck.addCardToDiscard(third);
		stored.at(7) = discard;
	}
	else if(discard < fourth && discard-third < 5 && discard <= 25){
		gameDeck.getDiscard();
		findAndReplace(discard,fourth,1);
		gameDeck.addCardToDiscard(fourth);
		stored.at(6) = discard;
	}
	else if(discard < fifth && discard-fourth < 5 && discard <= 30){
		gameDeck.getDiscard();
		findAndReplace(discard,fifth,1);
		gameDeck.addCardToDiscard(fifth);
		stored.at(5) = discard;
	}
	else if(discard > sixth && discard-fifth < 5 && discard >= 35){
		gameDeck.getDiscard();
		findAndReplace(discard,sixth,1);
		gameDeck.addCardToDiscard(sixth);
		stored.at(4) = discard;
	}
	else if(discard > seventh && discard-sixth < 5 && discard >= 40){
		gameDeck.getDiscard();
		findAndReplace(discard,seventh,1);
		gameDeck.addCardToDiscard(seventh);
		stored.at(3) = discard;
	}
	else if(discard > eighth && discard-seventh < 5 && discard >= 45){
		gameDeck.getDiscard();
		findAndReplace(discard,eighth,1);
		gameDeck.addCardToDiscard(eighth);
		stored.at(2) = discard;
	}
	else if(discard > ninth && discard-eighth < 5 && discard >= 50){
		gameDeck.getDiscard();
		findAndReplace(discard,ninth,1);
		gameDeck.addCardToDiscard(ninth);
		stored.at(1);
	}
	else{
		int dealt = gameDeck.dealCard();
		if(dealt < lowest && dealt < second){
			findAndReplace(dealt,lowest,1);
			gameDeck.addCardToDiscard(lowest);
			stored.at(9) = dealt;
		}
		else if(dealt < second && dealt <= 20){
			findAndReplace(dealt,second,1);
			gameDeck.addCardToDiscard(second);
			stored.at(8) = dealt;
		}
		else if(dealt < third && dealt <= 20){
			findAndReplace(dealt,third,1);
			gameDeck.addCardToDiscard(third);
			stored.at(7) = dealt;
		}
		else if(dealt < fourth && dealt <= 30){
			findAndReplace(dealt,fourth,1);
			gameDeck.addCardToDiscard(fourth);
			stored.at(6) = dealt;
		}
		else if(dealt < fifth && dealt >= 30){
			findAndReplace(dealt,fifth,1);
			gameDeck.addCardToDiscard(fifth);
			stored.at(5) = dealt;
		}
		else if(dealt > sixth && dealt >= 30){
			findAndReplace(dealt,sixth,1);
			gameDeck.addCardToDiscard(sixth);
			stored.at(4) = dealt;
		}
		else if(dealt > seventh && dealt >= 30){
			findAndReplace(dealt,seventh,1);
			gameDeck.addCardToDiscard(seventh);
			stored.at(3) = dealt;
		}
		else if(dealt > eighth && dealt >= 40) {
			findAndReplace(dealt,eighth,1);
			gameDeck.addCardToDiscard(eighth);
			stored.at(2) = dealt;
		}
		else if(dealt > ninth && dealt >= 40){
			findAndReplace(dealt,ninth,1);
			gameDeck.addCardToDiscard(ninth);
			stored.at(1) = dealt;
		}
		else if(dealt > highest && dealt >= 50){
			findAndReplace(dealt,highest,1);
			gameDeck.addCardToDiscard(highest);
			stored.at(0) = dealt;
		}
		else{
			gameDeck.addCardToDiscard(dealt);
		}
	}
	cout << "AI RACK AFTER PLAY" << endl;
	print_top_to_bottom(1);
	playing = true;
	
}	
void gameController::print_top_to_bottom(int player){
	if(player == 0){
		humanRack.PrintReverse();
	}
	else{
		AIRack.PrintReverse();
	}
}
void gameController::deal_initial_hands(){
	for(int i = 0; i < 10; i++){
		int pCard = gameDeck.dealCard();
		int cCard = gameDeck.dealCard();
		humanRack.InsertLast(pCard);
		AIRack.InsertLast(cCard);
		stored.push_back(cCard);
	}
}
bool gameController::findAndReplace(int newCard, int cardToBeReplaced, int player){
	if(player == 0){
		return humanRack.Replace(cardToBeReplaced, newCard);
	}
	else{
		return AIRack.Replace(cardToBeReplaced, newCard);
	}
}
bool gameController::check_racko(int player){
	if(player == 0){
		return humanRack.IsListSorted();
	}
	else{
		return AIRack.IsListSorted();
	}
}
#endif	
