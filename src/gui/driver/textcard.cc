#include "textcard.hh"

namespace game {

	TextCard::TextCard() {
	}

	TextCard::TextCard(video::IVideoDriver* ddriver, gui::IGUIFont* ffont, string ttext) {
		driver = ddriver;
		text = ttext;
		font = ffont;
		setPosition(core::position2d<s32>(0,0));
		setColour(video::SColor(255,255,255,255));
	}

	void TextCard::setPosition(core::position2d<s32> ppos) {
		pos = ppos;
		// Warning: evil bug, that won't rear its ugly head until you
		// try resolutions greater than 1024x768.
		// TODO: fix.
		posrect = core::rect<s32>(pos, core::position2d<s32>(1024,768));
	}

	void TextCard::setColour(video::SColor ccolour) {
		colour = ccolour;
	}

	void TextCard::draw() {
		font->draw(text.c_str(),posrect,colour);
	}
	// moves the texture to the optional position, then draws it.
	void TextCard::draw(core::position2d<s32>) {
		setPosition(core::position2d<s32>(0,0));
		draw();
	}

	void TextCard::setDriver(video::IVideoDriver* ddriver) {
		driver = ddriver;
	}

	void TextCard::setFont(gui::IGUIFont* ffont) {
		font = ffont;
	}

}
