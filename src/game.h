#pragma once
#include "enums.h"
#include "figure.h"



using namespace oxygine;

extern int presentTurn;

DECLARE_SMART(game, spgame)
class game: public Actor
{
public:
	game();
	~game();


void INIT();

	void createPlayer(side playerSide);

private:
	void createDeck();
	spSprite createTile(int x, int y, bool color);
	tileCheck checkPos(spSprite Sprite);
	void tileClicked(Event* event);

};
