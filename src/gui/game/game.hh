#include "irrlicht/irrlicht.h"

#include <vector>
using namespace std;

#include "irrlichtreceiver.hh"
#include "texturepack.hh"

#include "gooey.hh"
#include "world.hh"

#ifndef GAME_HH
#define GAME_HH

namespace game{

  class Game {
  public:
    virtual Game::Game () =0;
    virtual void load() =0;
    virtual void update() =0;
    virtual void draw() =0;
    IrrlichtReceiver* receiver ;

  private:
    World* world ;
    vector<Gooey*> gooeySet ;
    TexturePack* texPack ;
  };

}

#endif
