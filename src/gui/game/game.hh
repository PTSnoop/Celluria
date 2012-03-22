#include "irrlicht/irrlicht.h"

#include "irrlichtreceiver.hh"
#include "texturepack.hh"

#include "cell.hh"
#include "world.hh"

#ifndef GAME_HH
#define GAME_HH

namespace game{

  class Game {
  public:
    Game::Game ();
    void load();
    void update();
    IrrlichtReceiver* receiver ;

  private:
    Cell* cell ;
    World* cell ;
    CellGooey* cellFace ;
    WorldGooey* worldFace ;
    MainMenuGooey* mainMenuFace ;
    TexturePack* texPack ;
  };

}

#endif
