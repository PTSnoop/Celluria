#include "resource.hh"

#ifndef CELL_TRANSPORT_DRIFTER
#define CELL_TRANSPORT_DRIFTER

namespace game{

  class DrifterConsumer{
    public:
      virtual Quantity accept(Resource resource,Quantity quantity)=0;
  };
  
}

#endif
