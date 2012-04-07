#include <irrlicht/irrlicht.h>
using namespace irr;

#include <vector>
using namespace std;

#include "gooey.hh"

#ifndef GOOEYSET_HH
#define GOOEYSET_HH

namespace game {
	class GooeySet {
	public:
		GooeySet();
		void addGooey(Gooey*);
		void changeToGooey(int);
		Gooey* getCurrent();
		
		void load();
		void update();
		void draw();
		
		vector<Gooey*> set;
		int active;
		
		void clickNoise(core::position2d<s32>);
		void moveNoise(core::position2d<s32>);
	};
}

#endif