#include <irrlicht/irrlicht.h>
using namespace irr;

//#include "irrlichtreceiver.hh"

#ifndef IRRLICHTDRIER_HH
#define IRRLICHTDRIER_HH

namespace game {
  class IrrlichtDriver {
  public:
    IrrlichtDriver();
    IrrlichtDevice* device;
    video::IVideoDriver* driver;
    void setResolution(int,int);
//    void setEventReceiver(IrrlichtReceiver);
    bool run();
    void beginScene();
    void endScene();
//    IrrlichtReceiver receiver;
  };
}

#endif
