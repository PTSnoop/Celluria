#include "clickbox.hh"

namespace game {
	
	ClickBox::ClickBox(core::rect<s32> bbox) {
		setBox(bbox);
	}

	void ClickBox::setBox(core::rect<s32> bbox) {
		screenspace = bbox;
	}

	bool ClickBox::clickNoise(core::position2d<s32> noise) {
		if (screenspace.isPointInside(noise)) {
			clicked();
			return true;
		} 
		else {
			return false;
		}
	}

	bool ClickBox::moveNoise(core::position2d<s32> noise) {
		if (screenspace.isPointInside(noise)) {
			move();
			return true;
		}
		else {
			unmove();
			return false;
		}
	}
}
