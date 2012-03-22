#include "view.hh"

#ifndef GOOEY_HH
#define GOOEY_HH

namespace game {
  using namespace irr;

  class Gooey: public View {
    virtual void onEvent (SEvent)=0;
  };

}

#endif
