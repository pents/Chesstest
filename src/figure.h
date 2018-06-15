#pragma once

#include <vector>
#include "enums.h"
#include "oxygine-framework.h"
#include "res.h"
#include "game.h"
using namespace oxygine;


 extern int royalFigurePos_Iterator;
 extern spSprite selectedFigure;

    extern std::vector<spSprite> _figures;
    extern std::vector<spSprite> tiles;

    extern bool figureSelectedForMooving;

class figure
{
public:



    spSprite createFigure(int x, int y, side playerSide, figures specificFigure);
    spSprite createFigure(int x, int y, side playerSide);
    side whichSide(int posInVector);
    side whichSide(spSprite Sprite);
    void figureClicked(Event* event);


private:
    std::vector<int> royalFigurePos = {ROOK, HORSE, OFFICER, LADY, KING, OFFICER, HORSE, ROOK};

    tileCheck checkPos(spSprite Sprite);

};
