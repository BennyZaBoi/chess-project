#ifndef SPECIALPIECE_H
#define SPECIALPIECE_H

#include "Piece.h"


class SpecialPiece : public Piece{
    protected:
        bool moved;
    public:
        SpecialPiece(Color, Type, int, int);
        const bool hasMoved();
        void setMoved();
};


#endif
