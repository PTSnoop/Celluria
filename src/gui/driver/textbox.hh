#include <irrlicht/irrlicht.h>
using namespace irr;

#include <string>
using namespace std;

#include "card.hh"

#ifndef TEXTBOX_HH
#define TEXTBOX_HH

namespace game {

	// Something drawn to the screen.
	class TextBox : public Card {
	public:
		
		TextBox(gui::IGUIEnvironment*,string, core::rect<s32>);

		// Not implemented yet.
		void setPosition(core::position2d<s32>);
		void setColour(video::SColor) {};

		// draws the input box to the screen.
		void draw();
		// moves the texture to the optional position (almost), then draws it.
		void draw(core::position2d<s32>);

		void setText(string);
		string getText();

		void setRightJustified(bool);

		gui::IGUIEnvironment* env;
		core::rect<s32> clickrect;
		gui::IGUIStaticText* textbox;
		bool rightJustified;
	};
}

#endif
