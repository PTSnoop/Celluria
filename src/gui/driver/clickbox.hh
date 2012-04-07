#include <irrlicht/irrlicht.h>
using namespace irr;

#include <string>
#include <iostream>
using namespace std;

#ifndef CLICKBOX_HH
#define CLICKBOX_HH

namespace game {

	// An area of the screen that does things when clicked on.
	class ClickBox {
	public:
		ClickBox() {};
		ClickBox(core::rect<s32>);
		
		// sets the position and area of the clickbox.
		void setBox(core::rect<s32>);
		
		// called by the Gooey; passes events on to clicked() etc.
		bool clickNoise(core::position2d<s32>);
		bool moveNoise(core::position2d<s32>);

		// called when the clickbox is clicked
		virtual void clicked() {};
		
		// called when the mouse is moved over the clickbox
		virtual void move() {};
		
		//called when the mouse is moved, but isn't over the clickbox
		virtual void unmove() {};

	private:
		core::rect<s32> screenspace;
	};
}

#endif
