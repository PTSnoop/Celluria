#include "buttonbox.hh"

namespace game {

	void ButtonBox::clicked() {
		if (usefulPointer) {
			usefulPointer->event(1,params);
		}
	}
	
	void ButtonBox::moved() {
		if (usefulPointer) {
			usefulPointer->event(2,params);
		}
	}
	
	void ButtonBox::notmoved() {
		if (usefulPointer) {
			usefulPointer->event(3,params);
		}
	}
	
	void ButtonBox::bind(Gooey* gooey) {
		usefulPointer = gooey;
	}
	
	void ButtonBox::setParams(vector<int> pparams) {
		params = pparams;
	}
	
	ButtonBox::ButtonBox(Gooey* gooey, core::rect<s32> pos) {
		bind(gooey);
		setBox(pos);
		setParams(vector<int>());
	}

	ButtonBox::ButtonBox(Gooey* gooey, core::rect<s32> pos, vector<int> pparams) {
		bind(gooey);
		setBox(pos);
		setParams(pparams);
	}
}
