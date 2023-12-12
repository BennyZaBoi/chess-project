# Chess Game
 
Authors: Hien Bui (https://github.com/hbgithubucr), Luis Barrios (https://github.com/LuisBrios), Ben Pham (https://github.com/BennyZaBoi), and Alex Zhang (https://github.com/sAwesomedragon)

## Project Description
* This chess game project is important and interesting to us since it allows us to apply various design patterns and chess solution algorithms that we had never worked with before. Additionally it will give us the chance to learn how to implement the feature of saving and loading a game as well as apply many of the techniques we have learned in this class.
* For this chess game project, we plan to use C++ as our primary coding language, as it is the coding language that each member of the group is most comfortable with and condifent in.
* The chess game will take input from the user through the terminal. The program will take in the coordinates of a chess piece and the coordinates for where to move it. If it is not a valid spot for the chess piece to move, the user will have to keep putting in coordinates until they choose a valid position. The program will then output the current state of the chess board and pieces in the terminal using various characters.
* The features of our chess game will be allowing for two users to play the classsic game of chess against each other, allowing users to undo their moves, and give them the ability to save, load, and continue their incomplete games.

## User Interface Specification

### Navigation Diagram
![NavDiaFinal](https://github.com/cs100/final-project-hbui045-lbarr076-azhan061-mpham115/assets/130001003/785aacbf-4c11-4ee1-a7f9-2bbfeb07b8c0)
This diagram is an overview of the changes and updates that can occur within our terminal-based chess game. The three main screens for this project are the welcome screen, the "print the board" screen, and the winning screen. The welcome screen will provide us with two options, either to start the game as is, or to "get help" understanding how to play chess. To perform either action, you will need to press a key, which will be displayed on the terminal. When the board is printed, all the pieces will show where they initially stand, and thus the game of chess will officially begin. We are, at the moment, simply making it so that in order to win, you must take the king. Once that is done, then the winning screen will pop up, indicating which of the players had won, based on which color they are. 

### Screen Layouts
The whole entire project we have outlined will, for now, be terminal-based. The three main screens for this project are the welcome screen, the "print the board" screen, and the winning screen. The help screen, for now, is extra. Asking the user for a move and updating the chessboard aren't necessarily screens, but actions that will be performed as the game progresses. 
 
Welcome Screen: At the beginning, once the code is run, the user will simply be greeted with a welcome page. All it would ask for is the user to press a specific key in order to get the game running, or, later on, to ask for help with how to play. We have thoughts of more to implement for this page, but considering the complexity of chess by itself, we will keep it simple for now. If time allows, we plan to extend this page by prompting the user to press a third specific key to change settings for the game (such as adding a timer or not). We are establishing such a screen simply because it would look more proper (and might be more useful later on as we finish) to have an opening as opposed to simply being directed to the game.

Help Screen: This screen will simply provide the user with assistance on chess rules, how pieces can move, and basic information. It is likely that we will provide a link to which the user may open to get more specifics on the properties and special rules of chess, but for now, this is an additional feature we want to implement after we finish the game. 

Main Screens (Print the Board, Ask the User for a Move, Update Chessboard): On this screen, we plan to just have the chess game going. It will be exactly the same as chess on a board (same pieces in their respected positions), apart from the fact that we do not currently plan to implement a checking system. That will be additional for us; currently, we plan to just make it so the winner is whoever manages to take the opponent's king piece first. Obviously, as this will be on the terminal as opposed to having it displayed graphically, it will be a bit harder to manage an appealing look. We plan to have each square on the board represented by underscores and bars, and are considering just representing the pieces as two letters. As a finishing touch to the chess game, once you capture a piece, we will show the captured piece on your respective side, as some online chess boards do. We are considering having a timer on the side display as well, but for that to occur we plan to first get the rules and set up of the board done first before adding additional settings, as we understand not everyone plays with a timer anyway.
(Pieces: King - Kg, Queen - Qn, Rook - Rk, Knight - Kn, Bishop - Bp, Pawn - Pn)

Print The Board: This screen will simply display the board after each turn. The only exception to when the board won't be printed is if the king piece is taken on either end, then, in that case, the winning screen will simply show.

Ask the User for a Move: For this, there will not be much. After the board is printed, there will simply be a line of text that states "(Color)'s move" then waits for a user's input. Once there is input, it will check if the input is valid or not based on the position of the current pieces and if the move is even on the board. If it is valid, the chessboard updates. If not, then the user is asked once again to make a move.

Update Chessboard: Once a move is performed, then the chessboard will be updated. If the king piece has not been taken, then the board will be printed again. If the king piece has been taken, then the screen will simply progress to the winning screen. The main purpose of this screen is simply to check whether or not the game should continue, and if it should, then the screen will be printed once again, with the updated movements, continuing the game. 

End Screen: For this part, once the chess game ends (by whoever manages to take the opponent's King Piece first), we plan to simply just declare which player won in a simple outputted statement of "Black wins" or "White wins." 


## Class Diagram
![image](https://github.com/cs100/final-project-hbui045-lbarr076-azhan061-mpham115/assets/147004786/6c1d7d4d-cc59-4fd3-a656-44c4f1f2ba04)

Piece class: abstract class that is the parent of all the other classes for the different pieces and contains information that all pieces will need.

SpecialPiece class: abstract class that inherents from the Piece class and adds the boolean "moved" member variable and boolean "hasMoved" member function for pieces that have special properties depending on whether they have moved. Is the parent of the Pawn, Rook, and King classes.

Queen, Bishop, Knight, Pawn, Rook classes: Overload the "moveValid" function from the Piece class in order to check whether they can move to a specific location depending on what type of piece they are.

King class: Same as previous, but also has the boolean "check" member variable and boolean "inCheck" member function to keep track of whether the King is in check.

Squares class: Object which stores its location and a Piece. Is used to build up the Chessboard class.

Chessboard class: Contains each of the Squares of the board, and can check whether a particular movement path is clear. 

ChessboardDisplay class : Output the board and pieces to the terminal.

Move class: Used in order to store the initial and final information of a particular move so that we can undo the move if the user chooses to.

Player class: Simply stores the users' names, whether they moved first, and what color they are.

## SOLID Class Diagram Updates

Update 1

* What SOLID principle(s) did you apply? Single Responsibility Principle.

* How did you apply it? Separated displayBoard function from Chessboard and class and put it into its own ChessboardDisplay class.

* How did this change help you write better code? Easier to distinguish what each board does, that way we won't get confused when we refer to a display class

Update 2

* What SOLID principle(s) did you apply? Single Responsibilty Principle.

* How did you apply it? Made Game class into GameManager and GameController classes. GameManager class handles storing and setting different parts of the game. GameController class handles how the overall game works and runs.

* How did this change help you write better code? We refactored the original Game class into two independent classes using the Single Responsibility Principle: GameManager and GameController. The GameManager is now solely responsible for the storage and manipulation of various game components, while the GameController is in charge of the overall flow and execution of the game. 


Update 3

* What SOLID principle(s) did you apply? Interface Segregation Principle.

* How did you apply it? Separated capturedPiece member variable and getCapturedPiece function from Move class and put them into their own Capture class.

* How did this change help you write better code? Better organization so we can find where the captured pieces are easier.
 
 ## Final deliverable 

 ## Screenshots
 <img width="710" alt="image" src="https://github.com/cs100/final-project-hbui045-lbarr076-azhan061-mpham115/assets/147004786/e587944a-7913-4137-a92d-436c24cb4623">
 <img width="520" alt="image" src="https://github.com/cs100/final-project-hbui045-lbarr076-azhan061-mpham115/assets/147004786/a3475f69-e76f-45fd-b2c5-24aaf06c3e37">
 <img width="434" alt="image" src="https://github.com/cs100/final-project-hbui045-lbarr076-azhan061-mpham115/assets/147004786/fb68280b-462d-4a01-85e7-cc804998ace6">
 
 ## Installation/Usage
 Instructions on installing and running your application
 1. Clone the repository to your machine
 2. Go to the correct directory
 3. In your terminal run the Cmake and make files
 4. Run the executable called runGame
 5. Game should run
 6. Follow game prompts
 7. Have fun
    
 ## Testing
 The way our project was tested/validated was that through the use of googletest. Before we merged any opened pull requests, we made sure that the tests for their specific parts that were changed all passed. After merging, we pulled the updated  master branch and ran   all the tests again to make sure that all the tests for the project still passed.
 
