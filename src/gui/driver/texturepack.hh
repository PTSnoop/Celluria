#include "irrlicht/irrlicht.h"
#include <map>
#include <string>
using namespace std;

#include "irrlichtscreen.hh"

#ifndef TEXTUREPACK_HH
#define TEXTUREPACK_HH

namespace game {

  using namespace irr;

  class TexturePack {
  public:
    TexturePack( IrrlichtScreen* );
    video::ITexture* getTexture ( string ) ;
    video::SColorf* getColour ( string ) ;
    void addTexture ( string , string ) ;
    void addTexture ( string , video::ITexture* ) ;
    void addColour ( string , video::SColorf* ) ;
    void readFile ( string ) ;
    
  private:
    IrrlichtScreen* irrscreen;
    map< string , video::ITexture* > textureBank ;
    map< string , video::SColorf* > colourBank ;
  };

}

#endif
