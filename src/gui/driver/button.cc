#include "button.hh"

namespace game {
	
	void Button::placeButton() {
		setBox(sourceRect + position);
	}
	
	void Button::clicked() {
		cout << "CLICKED" << endl;
	}
	//void bind(Gooey* gooey) {
	//	usefulpointer = gooey;
	//}
	
	Button::Button(video::IVideoDriver* ddriver,video::ITexture* ttexture) {
		driver = ddriver;
		texture = ttexture;
		defaults(ttexture);
		placeButton();
	}

	Button::Button(video::IVideoDriver* ddriver, string ttexname) {
		driver = ddriver;
		texture = driver->getTexture(ttexname.c_str());
		defaults(texture);
		placeButton();
	}

	Button::Button(video::IVideoDriver* ddriver,video::ITexture* ttexture,core::rect<s32> pos) {
		driver = ddriver;
		texture = ttexture;
		defaults(ttexture);
		setSourceRect(pos);
		placeButton();
	}

	Button::Button(video::IVideoDriver* ddriver, string ttexname, core::rect<s32> pos) {
		driver = ddriver;
		texture = driver->getTexture(ttexname.c_str());
		defaults(texture);
		setSourceRect(pos);
		placeButton();
	}
}