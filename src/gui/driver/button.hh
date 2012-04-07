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
	
	// An image with a clickbox.
	// Warning: not tested with rotations, cropping, or really anything beyond vanilla here's-an-image. Be careful.
	class Button: public ClickBox, public TextureCard {
	public:
		
		// Can be constructed from either an ITexture* or a filename.
		// Optional rect describes part of a larger texture.
		Button(Gooey*,video::IVideoDriver*,video::ITexture*);
		Button(Gooey*,video::IVideoDriver*,string);
		Button(Gooey*,video::IVideoDriver*,video::ITexture*,core::rect<s32>);
		Button(Gooey*,video::IVideoDriver*,string,core::rect<s32>);
		
		// Aligns clickbox, based on texturecard position and size.
		void placeButton();
		// Called whenever the button's clicked. Passes params up to the Gooey.
		void clicked();
		// The params that get given to the Gooey when clicked.
		vector<int> params;
		void setParams(vector<int>);
		
		// A pointer to the Gooey, to pass events upwards.
		Gooey* usefulPointer;
		void bind(Gooey*);
	};
	
}

#endif