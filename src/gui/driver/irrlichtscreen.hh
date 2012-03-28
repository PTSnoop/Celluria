#include <irrlicht/irrlicht.h>
using namespace irr;

#include "irrlichtreceiver.hh"

#ifndef IRRLICHTSCREEN_HH
#define IRRLICHTSCREEN_HH

namespace game {
  class IrrlichtScreen {
  public:
    IrrlichtScreen();
    IrrlichtDevice* device;
    video::IVideoDriver* driver;
    void setResolution(int,int);
    void setEventReceiver(IrrlichtReceiver*);
    bool run();
    void beginScene();
    void endScene();
    IrrlichtReceiver* receiver;
  };
}

#endif