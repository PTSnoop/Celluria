#include <irrlicht/irrlicht.h>
using namespace irr;

#include <string>
using namespace std;

#ifndef CARD_HH
#define CARD_HH

namespace game {

	// Something drawn to the screen.
	class Card {
	public:
		
		// Change various self-explanatory things.
		virtual void setPosition(core::position2d<s32>)=0;
		virtual void setColour(video::SColor)=0;

		// draws the texture to the screen.
		virtual void draw()=0;
		// moves the texture to the optional position and rotation, then draws it.
		virtual void draw(core::position2d<s32>)=0;

	};
}

#endif
