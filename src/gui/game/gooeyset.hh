#include <irrlicht/irrlicht.h>
using namespace irr;

#include <vector>
#include <iostream>
using namespace std;

#include "gooey.hh"

#ifndef GOOEYSET_HH
#define GOOEYSET_HH

namespace game {
	
	// Keeps track of what Gooey is being shown at the moment.
	class GooeySet {
	public:
		GooeySet();
		
		// add a Gooey to the set.
		void addGooey(Gooey*);
		
		// Change the Gooey being displayed.
		void changeToGooey(int);
		
		// Return the Gooey being displayed.
		Gooey* getCurrent();
		
		// Load all the Gooeys.
		void load();
		// Update all the Gooeys.
		void update();
		// Draw the current Gooey to the screen.
		void draw();
		
		// The vector of all Gooeys in the set, plus the index of the active one.
		vector<Gooey*> set;
		int active;
		
		// These get passed to the active Gooey.
		void clickNoise(core::position2d<s32>);
		void moveNoise(core::position2d<s32>);
	};
}

#endif