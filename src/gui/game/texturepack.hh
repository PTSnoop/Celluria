#include "irrlicht/irrlicht.h"
#include <map>
#include <string>

#ifndef TEXTUREPACK_HH
#define TEXTUREPACK_HH

namespace game {

  using namespace irr;

  class TexturePack {
  public:
    video::ITexture* getTexture ( string ) ;
    video::SColorf* getColour ( string ) ;
    void addTexture ( string , ITexture* ) ;
    void addColour ( string , SColorf* ) ;
    void readFile ( string ) ;
    
  private:
    map< string ; video::ITexture* > textureBank ;
    map< string ; video::SColorf* > colourBank ;
  };

}

#endif
