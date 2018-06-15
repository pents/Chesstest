#pragma once
#include "game.h"
#include "figure.h"
using namespace res;

side playerSide = ERROR;

figure sample;

int presentTurn = WHITE;

game::game()
{
	INIT();
}

game::~game()
{

}

void game::INIT()
{
    presentTurn = WHITE;


	createDeck();
	createPlayer(WHITE);
        createPlayer(BLACK);
}

void game::createPlayer(side playerSide)
{
        for(int j = 0; j < 8; ++j)
        {
            _figures.push_back(sample.createFigure(125*j, playerSide == WHITE ? 750 : 125, playerSide, PAWN));
            addChild(_figures.back());
            _figures.push_back(sample.createFigure(125*j, playerSide == WHITE ? 875 : 0, playerSide));
            addChild(_figures.back());
        }
        royalFigurePos_Iterator = 0;
}

void game::createDeck()
{
        int x=0, y=0;
        bool color = false; // false - white, true - black
        for(int i = 0; i < 8; ++i) // going Y way
        {
            for(int j = 0; j < 8; ++j) // going X way
            {   //attach button as child to current actor
                tiles.push_back(createTile(125*j, 125*i, color));
                addChild(tiles.back());
                color = !color;
            }
	    color = !color;
        }
}

spSprite game::createTile(int x, int y, bool color)
{
	//create button Sprite
        spSprite tile = new Sprite();

        //setup it:
        //set button.png image. Resource 'button' defined in 'res.xml'
        tile->setResAnim(gameResources.getResAnim(color ? "blackSide" : "whiteSide"));

        //place tile on screen
        //Vector2 pos(x,y)
        tile->setPosition(x,y);

        EventCallback cb = CLOSURE(this, &game::tileClicked);
        tile->addEventListener(TouchEvent::CLICK, cb);

        return tile;
}

tileCheck game::checkPos(spSprite Sprite)
{
        side movingSprite = sample.whichSide(selectedFigure);
        side givenSprite = ERROR;
        for (int j = 0; j < _figures.size(); ++j)
        {
            if (_figures[j]->getPosition() == Sprite->getPosition())
            {
                givenSprite = sample.whichSide(_figures[j]);
                return givenSprite==movingSprite ? ALLY : ENEM;
            }
        }
        return FREE;
}

void game::tileClicked(Event* event)
    {
        if(figureSelectedForMooving)
        {
            for (spSprite i : tiles)
            {
                if (i == event->target)
                {
                    switch(this->checkPos(i))
                    {
                        case ENEM:
                        {
                            for (int j = 0; j < _figures.size(); ++j)
                            {
                                if (_figures[j]->getPosition() == i->getPosition())
                                {
                                    auto temp = _figures[j];
                                    _figures.erase(_figures.begin()+j);
                                    temp->addTween(Sprite::TweenAlpha(0), 50);
                                    break;
                                }
                            }
                        }
                        case FREE:
                        {
                            selectedFigure->addTween(Sprite::TweenColor(Color::White), 100, 1, false);
                            selectedFigure->addTween(Sprite::TweenPosition(i->getPosition()), 700, 1);
                            figureSelectedForMooving = false;
                            selectedFigure = NULL;
                            presentTurn = presentTurn == WHITE ? BLACK : WHITE;
                            break;
                        }
                        case ALLY:
                        {
                            break;
                        }
                    }

                    break;
                }


            }
        }


    }

