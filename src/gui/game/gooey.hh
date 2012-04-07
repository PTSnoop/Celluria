#include <irrlicht/irrlicht.h>
using namespace irr;

#include <list>
#include <iostream>
using namespace std;

#include "gui/driver/button.hh"

#ifndef GOOEY_HH
#define GOOEY_HH

namespace game {
	class Gooey {
	public:
		virtual void load() {};
		virtual void update() {};
		virtual void draw() {};
		virtual void event(vector<int>) {};
		
		void clickNoise(core::position2d<s32>);
		void moveNoise(core::position2d<s32>);
		
		void addBox(ClickBox*);
		void removeBox(ClickBox*);
		list<ClickBox*> clickBoxes;
	};
}

#endif