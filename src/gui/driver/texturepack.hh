#include <irrlicht/irrlicht.h>
using namespace irr;

#include <map>
#include <string>
using namespace std;

#include "irrlichtscreen.hh"
#include "texturecard.hh"
#include "button.hh"
#include "gui/game/gooey.hh"

#ifndef TEXTUREPACK_HH
#define TEXTUREPACK_HH

namespace game {

	struct TextureNode {
		video::ITexture* texture;
		core::rect<s32> mask;
	};

	// Recalls ITextures, TextureCards and Colours from strings.
	// Maybe I'll make one for Buttons at some point.
	class TexturePack {
	public:
		TexturePack( IrrlichtScreen* );
		
		// Get an ITexture, Button, TextureCard or SColorf from a string.
		video::ITexture* getTexture ( string ) ;
		Button* getButton( Gooey*, string );
		TextureCard* getCard ( string ) ;
		video::SColorf* getColour ( string ) ;
	
		// Add a texture to the texture bank.
		// Inputs: key string, filename (or ITexture), optional part of texture.
		void addTexture ( string , string ) ;
		void addTexture ( string , video::ITexture* ) ;
	
		void addTexture ( string , string , core::rect<s32>) ;
		void addTexture ( string , video::ITexture* , core::rect<s32>) ;
	
		// Add a colour to the colour bank.
		void addColour ( string , video::SColorf* ) ;
		
		// Read a texture pack from a file. Not implemented yet.
		void readFile ( string ) ;
		
	private:
		IrrlichtScreen* irrscreen;
		map< string , TextureNode > textureBank ;
		map< string , video::SColorf* > colourBank ;
	};

}

#endif
