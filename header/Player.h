#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <string>
#include "../header/Color.h"

using namespace std;

class Player{
    private: 
        string name;
        bool firstMove;
        enum Color playColor;
    
    public:
        Player();
        Player(const string& playername);

        void setName(string newname);
        void setFirstMove(bool tf);
        void setColorChoice(Color c);

        string returnName() const;
        int returnFirstMove() const;
        char returnColorChoice() const;
};

#endif 