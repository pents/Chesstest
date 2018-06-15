#pragma once
#include "figure.h"


 int royalFigurePos_Iterator = 0;
 spSprite selectedFigure;

     std::vector<spSprite> _figures;
     std::vector<spSprite> tiles;

     bool figureSelectedForMooving;

using namespace res;

spSprite figure::createFigure(int x, int y, side playerSide, figures specificFigure)
{
	spSprite fig = new Sprite();

	fig->setResAnim(figuresRes.getResAnim("figures_spr"), specificFigure, playerSide);

	fig->setPosition(x,y);

	//register  click handler to button
	EventCallback cb = CLOSURE(this, &figure::figureClicked);
	fig->addEventListener(TouchEvent::CLICK, cb);

	return fig;
}

spSprite figure::createFigure(int x, int y, side playerSide)
{

        spSprite fig = new Sprite();

        fig->setResAnim(figuresRes.getResAnim("figures_spr"), royalFigurePos[royalFigurePos_Iterator], playerSide);

        fig->setPosition(x,y);

        royalFigurePos_Iterator++;

                //register  click handler to button
        EventCallback cb = CLOSURE(this, &figure::figureClicked);
        fig->addEventListener(TouchEvent::CLICK, cb);

        return fig;
}

side figure::whichSide(int posInVector)
{
	return posInVector < 16 ? WHITE : BLACK;
}

side figure::whichSide(spSprite Sprite)
{
	for (int j = 0; j < _figures.size(); ++j)
	{
	    if (_figures[j] == Sprite)
	    {
		return whichSide(j);
	    }
	}
	return ERROR;
}

void figure::figureClicked(Event* event)
{
	if(figureSelectedForMooving) return;
	//animate button by chaning color
	for (int i = 0; i < _figures.size(); ++i)
	{
	    if ((_figures[i] == event->target) && (whichSide(i)==presentTurn))
	    {
		_figures[i]->setColor(Color::White);
		_figures[i]->addTween(Sprite::TweenColor(Color::Green), 200, 1, false);
		figureSelectedForMooving = true;
		selectedFigure = _figures[i];
		break;
	    }
	}

}


