#include "card.h"
#include <cstdlib>
#include <iostream>

/*
You might or might not need these two extra libraries
#include <iomanip>
#include <algorithm>
*/


/* *************************************************
   Card class
   ************************************************* */

/*
   Default constructor for the Card class.
   It could give repeated cards. This is OK.
   Most variations of Blackjack are played with
   several decks of cards at the same time.
*/
Card::Card(){
   int r = 1 + rand() % 4;
   switch (r) {
      case 1: suit = OROS; break;
      case 2: suit = COPAS; break;
      case 3: suit = ESPADAS; break;
      case 4: suit = BASTOS; break;
      default: break;
   }

   r = 1 + rand() % 10;
   switch (r) {
      case  1: rank = AS; break;
      case  2: rank = DOS; break;
      case  3: rank = TRES; break;
      case  4: rank = CUATRO; break;
      case  5: rank = CINCO; break;
      case  6: rank = SEIS; break;
      case  7: rank = SIETE; break;
      case  8: rank = SOTA; break;
      case  9: rank = CABALLO; break;
      case 10: rank = REY; break;
      default: break;
   }
}

// Accessor: returns a string with the suit of the card in Spanish
string Card::get_spanish_suit() const {
   string suitName;
   switch (suit) {
      case OROS:
         suitName = "oros";
     break;
      case COPAS:
         suitName = "copas";
     break;
      case ESPADAS:
         suitName = "espadas";
     break;
      case BASTOS:
         suitName = "bastos";
     break;
      default: break;
   }
   return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish
string Card::get_spanish_rank() const {
   string rankName;
   switch (rank) {
      case AS:
         rankName = "As";
     break;
      case DOS:
         rankName = "Dos";
     break;
      case TRES:
         rankName = "Tres";
     break;
      case CUATRO:
         rankName = "Cuatro";
     break;
      case CINCO:
         rankName = "Cinco";
     break;
      case SEIS:
         rankName = "Seis";
     break;
      case SIETE:
         rankName = "Siete";
     break;
      case SOTA:
         rankName = "Sota";
     break;
      case CABALLO:
         rankName = "Caballo";
     break;
      case REY:
         rankName = "Rey";
     break;
      default: break;
   }
   return rankName;
}



// Accessor: returns a string with the suit of the card in English
// This is just a stub! Modify it to your liking.
string Card::get_english_suit() const {
   string suitName;
   switch (suit) {
      case OROS:
         suitName = "coins";
     break;
      case COPAS:
         suitName = "cups";
     break;
      case ESPADAS:
         suitName = "spades";
     break;
      case BASTOS:
         suitName = "clubs";
     break;
      default: break;
   }
   return suitName;
}

// Accessor: returns a string with the rank of the card in English
// This is just a stub! Modify it to your liking.
string Card::get_english_rank() const {
   string rankName;
   switch (rank) {
      case AS:
         rankName = "Ace";
     break;
      case DOS:
         rankName = "Two";
     break;
      case TRES:
         rankName = "Three";
     break;
      case CUATRO:
         rankName = "Four";
     break;
      case CINCO:
         rankName = "Five";
     break;
      case SEIS:
         rankName = "Six";
     break;
      case SIETE:
         rankName = "Sever";
     break;
      case SOTA:
         rankName = "Jack";
     break;
      case CABALLO:
         rankName = "Knight";
     break;
      case REY:
         rankName = "King";
     break;
      default: break;
   }
   return rankName;
}



// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
   return static_cast<int>(rank) + 1 ;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
   return rank < card2.rank;
}

void Card::card_output(){
    cout << "\t" << get_spanish_rank() << " de " << get_spanish_suit() << "\t (" << get_english_rank() << " of " << get_english_suit() << ")." << endl;
}


/* *************************************************
   Hand class
   ************************************************* */
// Implemente the member functions of the Hand class here.
Hand::Hand(){
    vector<Card> empty;
    cards = empty;
    total = 0;
}

void Hand::add_card(Card c){
    cards.push_back(c); //adds card to the hand
    total += c.get_rank(); //updates the total
}
    
double Hand::get_total(){
    return total; //outputs the total
}

void Hand::hand_output(){
    for(int i = 0; i< cards.size(); i++){
        cout << "\t" << cards[i].get_spanish_rank() << " de " << cards[i].get_spanish_suit() << "\t (" << cards[i].get_english_rank() << " of " << cards[i].get_english_suit() << ")." << endl;
    }
}

void Hand::file_output(ofstream& fout){
    for(int i = 0; i< cards.size(); i++){
        fout << "\t" << cards[i].get_spanish_rank() << " de " << cards[i].get_spanish_suit() << "\t (" << cards[i].get_english_rank() << " of " << cards[i].get_english_suit() << ")." << endl;
    }
}
/* *************************************************
   Player class
   ************************************************* */
// Implemente the member functions of the Player class here.
Player::Player(int& m, Hand& h){
    money = m;
    hand = h;
}
    
int Player::get_money(){
    return money; //outputs the total
}

void Player::who_won(Player& d, int& bet){
    if(hand.get_total() <= 7.5 && d.hand.get_total() <= 7.5){
        if(hand.get_total()>d.hand.get_total()){
            cout << "You win $" << bet << endl;
            money += bet;
            d.money -= bet;
            cout << "You have $" << money;
        }
        else if(hand.get_total()<d.hand.get_total()){
            cout << "You lose $" << bet << endl;
            money -= bet;
            d.money += bet;
            cout << "You have $" << money;
        }
        else{
            cout << "It is a tie." << "You have $" << money;
        }
    }
    else if(hand.get_total() > 7.5 && d.hand.get_total() > 7.5){
        cout << "House advantage. You lose $" << bet << endl;
        money -= bet;
        d.money += bet;
        cout << "You have $" << money;
        
    }
    else if(hand.get_total() <= 7.5 && d.hand.get_total() >7.5){
        cout << "You win $" << bet << endl;
        money += bet;
        d.money -= bet;
        cout << "You have $" << money;
    }
    else if(hand.get_total() > 7.5 && d.hand.get_total() <=7.5){
        cout << "You lose $" << bet << endl;
        money -= bet;
        d.money += bet;
        cout << "You have $" << money;
    }
}
