#include <irrlicht/irrlicht.h>
using namespace irr;

#include <list>
#include <iostream>
using namespace std;

#include "gui/driver/button.hh"

#ifndef GOOEY_HH
#define GOOEY_HH

namespace game {
	
	// Draws things to the screen, handles mouse clicks.
	class Gooey {
	public:
		// Called by the GooeySet; do what they say on the tin.
		virtual void load() {};
		virtual void update() {};
		virtual void draw() {};
		
		// Called when something's clicked on. The vector of ints comes from the button.
		virtual void event(int eventType, vector<int>) {};
		
		// Called from the receiver whenever there's a mouse event anywhere. Goes through the list of ClickBoxes to see if they're relevant.
		void clickNoise(core::position2d<s32>);
		void moveNoise(core::position2d<s32>);
		
		// Add or remove ClickBox*es from the list.
		void addBox(ClickBox*);
		void removeBox(ClickBox*);
		list<ClickBox*> clickBoxes;
	};
}

#endif
