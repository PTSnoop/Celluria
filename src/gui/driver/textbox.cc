#include "textbox.hh"

namespace game {

	TextBox::TextBox(gui::IGUIEnvironment* eenv,string text, core::rect<s32> cclickrect) {
		rightJustified = false;
		env = eenv;
		clickrect = cclickrect;
		core::stringw boxtext = text.c_str();
		textbox = env->addStaticText(boxtext.c_str(),clickrect);
	}

	void TextBox::setPosition(core::position2d<s32> ppos) {
		textbox->setRelativePosition(ppos);
	}

	void TextBox::draw() {
		textbox->draw();
	}
	void TextBox::draw(core::position2d<s32>){
		draw();
	}

	void TextBox::setText(string input) {
		core::stringw setput = input.c_str();
		textbox->setText(setput.c_str());
	}

	string TextBox::getText() {
		core::stringc getput = textbox->getText();
		return getput.c_str();
	}

	void TextBox::setRightJustified(bool rj) {
		rightJustified = rj;
		if (rightJustified)
			textbox->setTextAlignment(gui::EGUIA_LOWERRIGHT,gui::EGUIA_UPPERLEFT);
		else
			textbox->setTextAlignment(gui::EGUIA_UPPERLEFT,gui::EGUIA_UPPERLEFT);

	}
}

