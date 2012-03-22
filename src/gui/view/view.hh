#include "irrlicht/irrlicht.h"

#ifndef VIEW_HH
#define VIEW_HH

namespace game {
  using namespace irr;
  
  class View {
  public:
    virtual void draw () = 0;
    virtual void handleMouseClick (SEvent) = 0;
  }; 
  
}

#endif
