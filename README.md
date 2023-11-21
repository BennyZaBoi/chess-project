![image](https://github.com/cs100/final-project-hbui045-lbarr076-azhan061-mpham115/assets/147004786/c997404e-5432-4da9-9e85-4ef502b480f0) # Chess Game
 
Authors: Hien Bui (https://github.com/hbgithubucr), Luis Barrios (https://github.com/LuisBrios), Ben Pham (https://github.com/BennyZaBoi), and Alex Zhang (https://github.com/sAwesomedragon)

## Project Description
* This chess game project is important and interesting to us since it allows us to apply various design patterns and chess solution algorithms that we had never worked with before. Additionally it will give us the chance to learn how to implement the feature of saving and loading a game as well as apply many of the techniques we have learned in this class.
* For this chess game project, we plan to use C++ as our primary coding language, as it is the coding language that each member of the group is most comfortable with and condifent in.
* The chess game will take input from the user through the terminal. The program will take in the coordinates of a chess piece and the coordinates for where to move it. If it is not a valid spot for the chess piece to move, the user will have to keep putting in coordinates until they choose a valid position. The program will then output the current state of the chess board and pieces in the terminal using various characters.
* The features of our chess game will be allowing for two users to play the classsic game of chess against each other, allowing users to undo their moves, and give them the ability to save, load, and continue their incomplete games.

## User Interface Specification

### Navigation Diagram
![Nav](https://github.com/cs100/final-project-hbui045-lbarr076-azhan061-mpham115/assets/130001003/68cd3832-e2ba-4d1b-9b55-bb85b2f86f0f)
This diagram is a really brief overview of our plans for our terminal-based chess game. The main part of our project will prioritize having a functioning chess game with all the specific rules that a chess game has (such as en passant), so there was not much add to our diagram. The diagram indicates that there will be a welcome screen that will start the user off, the main game, then at the end a declaration of which player won. 

### Screen Layouts
The whole entire project we have outlined will, for now, be terminal-based. On the previous navigation diagram, we had only set up 3 screens, to which are respectively the opening screen, the main chess game, and the ennding screen.
 
Opening Screen: At the beginning, once the code is run, the user will simply be greeted with a welcome page. All it would ask for is the user to press a specific key in order to get the game running. We have thoughts of more to implement for this page, but considering the complexity of chess by itself, we will keep it simple for now. If time allows, we plan to extend this page by prompting the user to press another specific key to get help with learning to play chess, and a third specific key to change settings for the game (such as adding a timer or not). We are establishing such a screen simply because it would look more proper (and might be more useful later on as we finish) to have an opening as opposed to simply being directed to the game.
Main Screen: On this screen, we plan to just have the chess game going. It will be exactly the same as chess on a board (same rules, same pieces in their respected positions, etc). Obviously, as this will be on the terminal as opposed to having it displayed graphically, it will be a bit harder to manage an appealing look. We plan to have each square on the board represented by underscores and bars, and are considering just representing the pieces as two. As a finishing touch to the chess game, once you capture a piece, we will show the captured piece on your respective side, as some online chess boards do. We are considering having a timer on the side display as well, but for that to occur we plan to first get the rules and set up of the board done first before adding additional settings, as we understand not everyone plays with a timer anyway.
(Pieces: King - Kg, Queen - Qn, Rook - Rk, Knight - Kn, Bishop - Bp, Pawn - Pn)
End Screen: For this part, once the chess game ends (by classic rules), we plan to simply just declare which player won in a simple outputted statement of "Black wins" or "White wins." 


## Class Diagram
![image](https://github.com/cs100/final-project-hbui045-lbarr076-azhan061-mpham115/assets/147004786/05ef4b73-be82-4d3d-8918-5e71a3d580fc)
![image](https://github.com/cs100/final-project-hbui045-lbarr076-azhan061-mpham115/assets/147004786/e51561e5-0abc-4924-a5f9-12dc34446c07)

Piece class: abstract class that is the parent of all the other classes for the different pieces and contains information that all pieces will need.

SpecialPiece class: abstract class that inherents from the Piece class and adds the boolean "moved" member variable and boolean "hasMoved" member function for pieces that have special properties depending on whether they have moved. Is the parent of the Pawn, Rook, and King classes.

Queen, Bishop, Knight, Pawn, Rook classes: Overload the "moveValid" function from the Piece class in order to check whether they can move to a specific location depending on what type of piece they are.

King class: Same as previous, but also has the boolean "check" member variable and boolean "inCheck" member function to keep track of whether the King is in check.

Square class: Object which stores its location and a Piece. Is used to build up the Chessboard class.

Chessboard class: Contains each of the Squares of the board, and can check whether a particular movement path is clear. Addiitonally can output the board and pieces to the terminal.

Move class: Used in order to store the initial and final information of a particular move so that we can undo the move if the user chooses to.

Player class: Simply stores the uses' names and what color they are.

Game class: Handles the bulk of the overall game, including beginning and ending the game, saving and laoding games, keeping track of the moves that have made, and getting actions from the user 
 
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
 
