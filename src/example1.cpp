#pragma once
#include "oxygine-framework.h"
#include "res.h"
#include "game.h"
#include "figure.h"
#include "enums.h"

using namespace oxygine;



void example_preinit()
{
}

void example_init()
{
    //load resources
    res::load();
    spgame actor = new game;
    getStage()->addChild(actor);
}

void example_update()
{

}

void example_destroy()
{
    res::free();
}
