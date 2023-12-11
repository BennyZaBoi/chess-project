#include <iostream>
#include "../header/customize.h"
#include "../header/Player.h"
using namespace std;

void customizeScreen(Player p1, Player p2) {
    string p1Name;
    string p1Color;

    cout << "Enter Player 1 name:" << endl;
    cin >> p1Name;
    p1.setName(p1Name);
    cout << "Enter Player 1 color:" << endl;
    cout << "You can choose from: \033[30m black, \033[31m red, \033[32m green, \033[33m yellow, \033[34m blue, \033[35m magenta, \033[36m cyan, \033[37m white" << endl;
    cin >> p1Color;
    if (p1Color == "black") {
        p1.setColorChoice(black);
    }
    else if (p1Color == "red") {
        p1.setColorChoice(red);
    }
    else if (p1Color == "green") {
        p1.setColorChoice(green);
    }
    else if (p1Color == "yellow") {
        p1.setColorChoice(yellow);
    }
    else if (p1Color == "blue") {
        p1.setColorChoice(blue);
    }
    else if (p1Color == "magenta") {
        p1.setColorChoice(magenta);
    }
    else if (p1Color == "cyan") {
        p1.setColorChoice(cyan);
    }
    else if (p1Color == "white") {
        p1.setColorChoice(white);
    }

    string p2Name;
    string p2Color;
    
    cout << "Enter Player 2 name:" << endl;
    cin >> p2Name;
    p2.setName(p2Name);
    cout << "Enter Player 2 color:" << endl;
    cout << "You can choose from: \033[30m black, \033[31m red, \033[32m green, \033[33m yellow, \033[34m blue, \033[35m magenta, \033[36m cyan, \033[37m white" << endl;
    cin >> p2Color;
    p2.setFirstMove(false);
    if (p2Color == "black") {
        p2.setColorChoice(black);
    }
    else if (p2Color == "red") {
        p2.setColorChoice(red);
    }
    else if (p2Color == "green") {
        p2.setColorChoice(green);
    }
    else if (p2Color == "yellow") {
        p2.setColorChoice(yellow);
    }
    else if (p2Color == "blue") {
        p2.setColorChoice(blue);
    }
    else if (p2Color == "magenta") {
        p2.setColorChoice(magenta);
    }
    else if (p2Color == "cyan") {
        p2.setColorChoice(cyan);
    }
    else if (p2Color == "white") {
        p2.setColorChoice(white);
    }
}