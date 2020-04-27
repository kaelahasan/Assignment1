#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "card.h"
using namespace std;

/*
 TO DO:
still need to fix random - always gives the same cards
need to reset the hands/totals after every game
fix output look as far as spacing, lines, and periods
 */



// Global constants (if any)
ofstream fout; //file output

// Non member functions declarations (if any)

// Non member functions implementations (if any)


int main() {
    fout.open("gamelog.txt"); //opening output file
    int player_money = 100; //player starts with $100
    int dealer_money = 900; //dealer starts w/ $900
    //game will end when the player has run out of money (has $0) or when the dealer has lost more than $900 dollars meaning dealer_money<0
    int bet = 0;
    int game_number = 1;
    Hand player_hand;
    Hand dealer_hand;
    
    Player dealer(dealer_money, dealer_hand);
    Player p(player_money, player_hand); //player
    
    while(dealer_money>0 && player_money>0){
         
        cout << "You have $" << player_money;
        cout << ". Enter bet: ";
        cin >> bet;
        while(bet>player_money){ //ensuring the user does not bet more money than they have
            cout << "You do not have enough money to make this bet. Please enter an appproate bet: ";
            cin >> bet;
        }
        
        //file output part
        fout << endl << "-----------------------------------------------" << endl << endl;
        fout << "Game number: " << game_number << "\t\t" << "Money left: " << p.get_money()  << endl;
        fout << "Bet: " << bet;
        
        Card c; //creating initial player card
        Card d; //creating initial dealer card
        player_hand.add_card(c); //adding card to players hand
        dealer_hand.add_card(d); //adding card to dealer hand
        cout << "Your cards: " << endl;
        fout << "Your cards: " << endl;
        c.card_output(); //outputting the players cards
        cout << "Your total is " << player_hand.get_total(); //outputting the players total
        cout << ". Do you want another card (y/n)? ";
        string another_card;
        cin >> another_card;
        while(another_card != "y" && another_card != "n"){ //checking user inputted y or n
            cout << "Your input was not recognized. Please enter either y or n: " << endl;
            cin >> another_card;
        }
        while(another_card == "y"){ //keep drawing cards until the player no longer answers yes
            Card c1; //creating new card for the player
            player_hand.add_card(c1); //adding new card to players hand
            cout << "New card: " << endl;
            c1.card_output(); //outputting the new card
            cout << "Your cards: " << endl;
            player_hand.hand_output(); //outputting all the players cards
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
        dealer_hand.hand_output(); //ouputing dealer's cards
        cout << "The dealer's total is " << dealer_hand.get_total(); //outputting the dealer's total
        cout << ".";
        
        //the dealer keeps picking cards until their total is 5.5 or greater
        while(dealer_hand.get_total() < 5.5){
            Card d1; //creating new card for the dealer
            cout << "New Card: ";
            d1.card_output(); //outputting the new card
            cout << "Dealer's cards: " << endl;
            dealer_hand.hand_output(); //adding the new card to the dealer's hand
            cout << "The dealer's total is " << dealer_hand.get_total() << "."; //outputting the dealer's total
        }
        
        //working on file output
        fout << "Your cards: " <<endl;
        player_hand.file_output(fout);
        fout << "Your total: " << player_hand.get_total() << "." << endl << endl;
        fout << "Dealer's cards: " << endl;
        dealer_hand.file_output(fout);
        fout << "Dealer's cards: " << dealer_hand.get_total() << "." << endl;
        
        game_number++; //updating game number
        p.who_won(dealer, bet);
    }
    
    if(p.get_money()>0){
        cout << "You win $" << p.get_money() <<endl;
        cout << "Congratualations. You beat the casino!" << endl << "Bye!";
    }
    else{
        cout << "You have $0. GAME OVER!" <<endl << "Come back when you have more money." << endl << "Bye!"; 
    }
    
    
    fout.close(); //closeing output file
    return 0;
}

