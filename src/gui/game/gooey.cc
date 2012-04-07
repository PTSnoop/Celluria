#include "gooey.hh"

namespace game {
	void Gooey::clickNoise(core::position2d<s32> noise) {
		for (list<ClickBox*>::iterator it = clickBoxes.begin(); it != clickBoxes.end(); it++) {
			(*it)->clickNoise(noise);
		}
	}
	
	void Gooey::moveNoise(core::position2d<s32> noise) {
		for (list<ClickBox*>::iterator it = clickBoxes.begin(); it != clickBoxes.end(); it++) {
			(*it)->moveNoise(noise);
		}
	}
	
	void Gooey::addBox(ClickBox* box) {
		clickBoxes.push_back(box);
	}
	
	void Gooey::removeBox(ClickBox* box) {
		clickBoxes.remove(box);
	}
}