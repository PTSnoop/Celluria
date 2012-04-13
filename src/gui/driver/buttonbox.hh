#include <irrlicht/irrlicht.h>
using namespace irr;

#include <iostream>
#include <vector>
using namespace std;

#ifndef BUTTONBOX_HH
#define BUTTONBOX_HH

#include "clickbox.hh"
#include "texturecard.hh"
#include "gui/game/gooey.hh"

namespace game {
	
	// An empty clickbox.
	// Warning: not tested with rotations, cropping, or really anything beyond vanilla here's-an-image. Be careful.
	class ButtonBox: public ClickBox {
	public:
		
		ButtonBox(Gooey*,core::rect<s32>);
		ButtonBox(Gooey*,core::rect<s32>, vector<int>);
		
		// Called whenever the buttonbox's clicked. Passes params up to the Gooey.
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
