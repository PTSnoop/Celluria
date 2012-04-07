#include "irrlicht/irrlicht.h"
using namespace irr;

#include <vector>
#include <iostream>
using namespace std;

#include "gui/driver/texturepack.hh"

#include "gooey.hh"
#include "gooeyset.hh"
//#include "world/world.hh"
#include "gui/driver/irrlichtreceiver.hh"

#ifndef GAME_HH
#define GAME_HH

namespace game{

  class Game {
  public:
    void load();
    void update();
    void draw();
	
    IrrlichtReceiver* receiver ;
	//void setWorld(World*);
	void setGooeySet(GooeySet*);
	void setReceiver(IrrlichtReceiver*);
	void bindReceiver(IrrlichtReceiver*);
	void bindReceiver();

    //World* world ;
    GooeySet* gooeySet ;
    TexturePack* texPack ;
  };

}

#endif
