#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "card.h"
using namespace std;

// Global constants (if any)


// Non member functions declarations (if any)


// Non member functions implementations (if any)


int main() {
    int player_money = 100; //player starts with $100
    int dealer_money = 900; //dealer starts w/ $100
    //game will end when the player has $100 or when the dealer has lost more than $900 dollars meaning dealer_money<0
    Hand player_hand;
    Hand dealer_hand;
    
    Player dealer(dealer_money);
    Player p(player_money);
    int bet;
    
    while(dealer_money>0 && player_money>0){
        cout << "You have $" << player_money;
        cout << ". Enter bet: ";
        cin >> bet;
        Card c; //creating initial player card
        Card d; //creating initial dealer card
        player_hand.add_card(c); //adding card to players hand
        dealer_hand.add_card(d); //adding card to dealer hand
        cout << "Your cards: " << endl;
        c.output(); //outputting the players cards
        cout << "Your total is " << player_hand.get_total(); //outputting the players total
        cout << ". Do you want another card (y/n)? ";
        string another_card;
        cin >> another_card;
        while(another_card != "y" || "n"){ //checking user inputted y or n
            cout << "Your input was not recognized. Please enter either y or n" << endl;
            cin >> another_card;
        }
        while(another_card == "y"){ //keep drawing cards until the player no longer answers yes
            Card c1; //creating new card for the player
            player_hand.add_card(c1); //adding new card to players hand
            cout << "New card: " << endl;
            c1.output(); //outputting the new card
            cout << "Your cards: " << endl;
            player_hand.output(); //outputting all the players cards
            cout << "Your total is " << player_hand.get_total(); //outputting the players total
            cout << "Do you want another card (y/n)? ";
            cin >> another_card; //updating the while condition
            while(another_card != "y" || "n"){ //checking user inputted y or n
                cout << "Your input was not recognized. Please enter either y or n" << endl;
                cin >> another_card;
            }
        }
        //after user has decided to stop adding cards, dealers cards as revealed
        cout << "Dealer's cards:" << endl;
        dealer_hand.output(); //ouputing dealer's cards
        cout << "The dealer's total is " << dealer_hand.get_total(); //outputting the dealer's total
        cout << ".";
        
        //the dealer keeps picking cards until their total is 5.5 or greater
        while(dealer_hand.get_total() < 5.5){
            Card d1; //creating new card for the dealer
            cout << "New Card: ";
            d1.output(); //outputting the new card
            cout << "Dealer's cards: " << endl;
            dealer_hand.output(); //adding the new card to the dealer's hand
            cout << "The dealer's total is " << dealer_hand.get_total() << "."; //outputting the dealer's total
        }
        
        
    }
    
    
    return 0;
}

