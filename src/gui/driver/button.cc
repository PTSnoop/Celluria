#include "button.hh"

namespace game {
	
	void Button::placeButton() {
		setBox(sourceRect + position);
	}
	
	void Button::clicked() {
		if (usefulPointer) {
			usefulPointer->event(params);
		}
	}
	
	void Button::bind(Gooey* gooey) {
		usefulPointer = gooey;
	}
	
	void Button::setParams(vector<int> pparams) {
		params = pparams;
	}
	
	Button::Button(Gooey* gooey, video::IVideoDriver* ddriver,video::ITexture* ttexture) {
		bind(gooey);
		driver = ddriver;
		texture = ttexture;
		defaults(ttexture);
		placeButton();
	}

	Button::Button(Gooey* gooey, video::IVideoDriver* ddriver, string ttexname) {
		bind(gooey);
		driver = ddriver;
		texture = driver->getTexture(ttexname.c_str());
		defaults(texture);
		placeButton();
		setParams(vector<int>());
	}

	Button::Button(Gooey* gooey, video::IVideoDriver* ddriver,video::ITexture* ttexture,core::rect<s32> pos) {
		bind(gooey);
		driver = ddriver;
		texture = ttexture;
		defaults(ttexture);
		setSourceRect(pos);
		placeButton();
		setParams(vector<int>());
	}

	Button::Button(Gooey* gooey, video::IVideoDriver* ddriver, string ttexname, core::rect<s32> pos) {
		bind(gooey);
		driver = ddriver;
		texture = driver->getTexture(ttexname.c_str());
		defaults(texture);
		setSourceRect(pos);
		placeButton();
		setParams(vector<int>());
	}
}