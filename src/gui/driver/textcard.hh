#include <irrlicht/irrlicht.h>
using namespace irr;

#include <string>
using namespace std;

#include "card.hh"

#ifndef TEXTCARD_HH
#define TEXTCARD_HH

namespace game {

	// Something drawn to the screen.
	class TextCard : public Card {
	public:
		
		TextCard();
		TextCard(video::IVideoDriver*,gui::IGUIFont*,string);

		// Change various self-explanatory things.
		void setPosition(core::position2d<s32>);
		// Not implemented yet
		void setColour(video::SColor);

		// draws the texture to the screen.
		void draw();
		// moves the texture to the optional position, then draws it.
		void draw(core::position2d<s32>);

		video::IVideoDriver* driver;
		void setDriver(video::IVideoDriver*);
		void setFont(gui::IGUIFont*);

		gui::IGUIFont* font;
		string text;
		core::position2d<s32> pos;
		core::rect<s32> posrect;
		video::SColor colour;
	};
}

#endif
