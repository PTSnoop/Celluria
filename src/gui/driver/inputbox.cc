#include "inputbox.hh"

namespace game {

	InputBox::InputBox(gui::IGUIEnvironment* eenv, core::rect<s32> cclickrect){
		env = eenv;
		clickrect = cclickrect;
		editbox = env->addEditBox(L"",clickrect,false);
	}

	void InputBox::draw() {
		editbox->draw();
	}
	void InputBox::draw(core::position2d<s32>){
		draw();
	}

	void InputBox::setText(string input) {
		core::stringw setput = input.c_str();
		editbox->setText(setput.c_str());
	}

	string InputBox::getText() {
		core::stringc getput = editbox->getText();
		return getput.c_str();
	}
}

