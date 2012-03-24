#include "irrlicht/irrlicht.h"

#include "irrlichtreceiver.hh"
#include "texturepack.hh"

#ifndef GAMEHANDLER_HH
#define GAMEHANDLER_HH

namespace game{

  class GameHandler {
  public:
    GameHandler ();
    void load();
    void update();
    void draw();

    void quitToMainMenu();
    void skirmish();
  };

}

#endif
