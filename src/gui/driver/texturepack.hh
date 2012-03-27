#include "irrlicht/irrlicht.h"
#include <map>
#include <string>
using namespace std;

#include "irrlichtscreen.hh"
#include <irrlicht/irrlicht.h>
using namespace irr;
#include "texturecard.hh"

#ifndef TEXTUREPACK_HH
#define TEXTUREPACK_HH

namespace game {

  struct TextureNode {
	  video::ITexture* texture;
	  core::rect<s32> mask;
  };

  class TexturePack {
  public:
    TexturePack( IrrlichtScreen* );
    video::ITexture* getTexture ( string ) ;
	TextureCard* getCard ( string ) ;
    video::SColorf* getColour ( string ) ;
	
    void addTexture ( string , string ) ;
    void addTexture ( string , video::ITexture* ) ;
	
    void addTexture ( string , string , core::rect<s32>) ;
    void addTexture ( string , video::ITexture* , core::rect<s32>) ;
	
    void addColour ( string , video::SColorf* ) ;
    void readFile ( string ) ;
    
  private:
    IrrlichtScreen* irrscreen;
    map< string , TextureNode > textureBank ;
    map< string , video::SColorf* > colourBank ;
  };

}

#endif
