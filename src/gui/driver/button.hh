#include <irrlicht/irrlicht.h>
using namespace irr;

#include <iostream>
#include <vector>
using namespace std;

#ifndef BUTTON_HH
#define BUTTON_HH

#include "clickbox.hh"
#include "texturecard.hh"
#include "gui/game/gooey.hh"

namespace game {
	
	class Button: public ClickBox, public TextureCard {
	public:
        Button(Gooey*,video::IVideoDriver*,video::ITexture*);
        Button(Gooey*,video::IVideoDriver*,string);
        Button(Gooey*,video::IVideoDriver*,video::ITexture*,core::rect<s32>);
        Button(Gooey*,video::IVideoDriver*,string,core::rect<s32>);
		
		void placeButton();
		void clicked();
		vector<int> params;
		void setParams(vector<int>);
		
		Gooey* usefulPointer;
		void bind(Gooey*);
	};
	
}

#endif