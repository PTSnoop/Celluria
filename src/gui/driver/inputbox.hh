#include <irrlicht/irrlicht.h>
using namespace irr;

#include <string>
using namespace std;

#include "card.hh"

#ifndef INPUTBOX_HH
#define INPUTBOX_HH

namespace game {

	// Something drawn to the screen.
	class InputBox : public Card {
	public:
		
		InputBox(gui::IGUIEnvironment*,core::rect<s32>);

		// Not implemented yet.
		void setPosition(core::position2d<s32>) {};
		void setColour(video::SColor) {};

		// draws the input box to the screen.
		void draw();
		// moves the texture to the optional position (almost), then draws it.
		void draw(core::position2d<s32>);

		void setText(string);
		string getText();

		gui::IGUIEnvironment* env;
		core::rect<s32> clickrect;
		gui::IGUIEditBox* editbox;
	};
}

#endif
