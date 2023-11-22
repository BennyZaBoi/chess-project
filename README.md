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
![image](https://github.com/cs100/final-project-hbui045-lbarr076-azhan061-mpham115/assets/147004786/5a36b92e-b5a3-41e5-848f-323277e6fc50)

Piece class: abstract class that is the parent of all the other classes for the different pieces and contains information that all pieces will need.

SpecialPiece class: abstract class that inherents from the Piece class and adds the boolean "moved" member variable and boolean "hasMoved" member function for pieces that have special properties depending on whether they have moved. Is the parent of the Pawn, Rook, and King classes.

Queen, Bishop, Knight, Pawn, Rook classes: Overload the "moveValid" function from the Piece class in order to check whether they can move to a specific location depending on what type of piece they are.

King class: Same as previous, but also has the boolean "check" member variable and boolean "inCheck" member function to keep track of whether the King is in check.

Square class: Object which stores its location and a Piece. Is used to build up the Chessboard class.

Chessboard class: Contains each of the Squares of the board, and can check whether a particular movement path is clear. 

ChessboardDisplay class : Output the board and pieces to the terminal.

Move class: Used in order to store the initial and final information of a particular move so that we can undo the move if the user chooses to.

Capture class : If a move captured an opponent's piece, also stores the captured piece

Player class: Simply stores the uses' names and what color they are.

GameManager class: Stores and maintains most of the different parts of the chess game.

GameController class : Handles the bulk of how the game runs, including beginning and ending the game, saving and laoding games, keeping track of the moves that have made, and getting actions from the user

## SOLID Class Diagram Updates

Update 1

* What SOLID principle(s) did you apply?

* How did you apply it? Seperated displayBoard function form Chessboard and class and put it into its own ChessboardDisplay class.

* How did this change help you write better code?

Update 2

* What SOLID principle(s) did you apply?

* How did you apply it? Made Game class into GameManager and GameController classes. GameManager class handles storing and setting different parts of the game. GameController class handles how the overall game works and runs.

* How did this change help you write better code?

Update 3

* What SOLID principle(s) did you apply?

* How did you apply it? Seperated capturedPiece member variable and getCapturedPiece function from Move class and put them into their own Capture class.

* How did this change help you write better code?
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on Zoom and should be conducted by Wednesday of week 8.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
