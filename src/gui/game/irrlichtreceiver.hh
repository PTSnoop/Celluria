#include "irrlicht/irrlicht.h"

#ifndef IRRLICHTRECEIVER_HH
#define IRRLICHTRECEIVER_HH

namespace game {

  using namespace irr;

  class IrrlichtReceiver : public IEventReceiver {
  public:
    virtual bool OnEvent( const SEvent& );
    virtual bool IsKeyDown( EKEY_CODE );
  private:
    bool KeyIsDown[KEY_KEY_CODES_COUNT];
  };

}

#endif
