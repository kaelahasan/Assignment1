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
        Card c;
        Card d;
        player_hand.add_card(c);
        dealer_hand.add_card(d);
        cout << "Your cards: " << endl;
        cout << "\t" << c.get_spanish_rank() << " de " << c.get_spanish_suit() << "\t (" << c.get_english_rank() << " of " << c.get_spanish_rank() << ")." << endl;
        cout << "Your total is ";
        player_hand.get_total();
        cout << ". Do you want another card (y/n)? ";
        string another_card;
        cin >> another_card;
        if(another_card == "y" || "Y"){
            
        }
        else if(another_card == "n" || "N"){
            
        }
        else{
            
        }
        
        
        
    }
    
    
    return 0;
}
