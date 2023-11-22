#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <string>

using namespace std;

class Player{
    private: 
        string name;
        bool firstMove;
        char colorChoice;
    
    public:
        Player();
        Player(const string& playername);

        void setName(string newname);
        void setFirstMove(bool tf);
        void setColorChoice(char z);

        string returnName() const;
        int returnFirstMove() const;
        char returnColorChoice() const;
};

#endif 