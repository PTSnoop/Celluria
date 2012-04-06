#include <irrlicht/irrlicht.h>
using namespace irr;

#include <iostream>
using namespace std;

#include "clickbox.hh"
#include "texturecard.hh"
//#include "gui/game/gooey.hh"

#ifndef BUTTON_HH
#define BUTTON_HH

namespace game {
	
	class Button: public ClickBox, public TextureCard {
	public:
        Button(video::IVideoDriver*,video::ITexture*);
        Button(video::IVideoDriver*,string);
        Button(video::IVideoDriver*,video::ITexture*,core::rect<s32>);
        Button(video::IVideoDriver*,string,core::rect<s32>);
		
		void placeButton();
		void clicked();
		//Gooey* usefulpointer;
		//void bind(Gooey*);
	};
	
}

#endif