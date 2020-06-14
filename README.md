# siete y medio
## Table of Contents 
* [Functionality](#functionality) 
* [Branching](#branching) 
* [Merging and Conflict Resolution](#merging-and-conflict-resolution) 
* [gitignore](#gitignore)

## Functionality 
### Card Class 
* I used Professor Salazar’s Card class implementation. 
### Hand Class 
* The hand class consists of a vector of cards and double total that keeps track of the total value of the cards in a hand. 
* The default constructor initializes the hand to default values which is then updated by the Player class. 
* There is hand_output() function that outputs a hand to the screen 
* The Player class does most of the operations. 
### Player Class 
* I made Player a friend class of Hand so that it could access its private variables. 
* A player consists of money and a hand of cards. 
Within the player class, there are various member functions that help keep track of the cards, values of cards, and money a player has. 
* There is also a function that determines who wins each round, and outputs it to the screen 

## Branching
*  I have two branches: 
*  Master: my main branch 
*  Experimental: to test file I/O

## Merging and Conflict Resolution
*  In order to do a non-fast-forward merge, I updated both branches and then attempted to merge, the meant I needed to do conflict resolution to tell git with parts of each file I wanted to keep
*  The first conflict resolution corresponds to the “Non-fast froward merging branches and conflict resolution” commit. This was not entirely successful, I fixed the conflict resolution error in “Fixing merge error” commit. 


## gitignore
I had difficulty creating a .gitIgnore file because a lot of the information I found for making an Xcode .gitignore was for older versions of Xcode. 
*  The important things to ignore for Xcode is the .DS_Store file, and xcuserdata/
*  I also decided to ignore .txt files because I did not want to track my file output 
*  Since I created my .gitignore late in my project development I used git rm to remove the files I did not want tracked
