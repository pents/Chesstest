#include "res.h"

namespace res
{
Resources gameResources;
Resources figuresRes;

    void load()
    {
        //load xml file with resources definition
        gameResources.loadXML("res.xml");
        figuresRes.loadXML("figRes.xml");
    }

    void free()
    {
        gameResources.free();
	figuresRes.free();

    }
}
