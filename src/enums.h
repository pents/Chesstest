#pragma once


enum figures
{
    LADY = 3,
    KING = 4,
    OFFICER = 2,
    HORSE = 1,
    ROOK = 0,
    PAWN = 5
};

enum side
{
    WHITE = 0,
    BLACK = 1,
    ERROR = 2
};

enum tileCheck
{
    FREE = 0,
    ALLY = 1,
    ENEM = 2
};

extern side playerSide;
