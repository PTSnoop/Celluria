#include <irrlicht/irrlicht.h>
using namespace irr;

#include <iostream>
using namespace std;

//#include "irrlichtscreen.hh"
#include "gui/game/gooeyset.hh"

#ifndef IRRLICHTRECEIVER_HH
#define IRRLICHTRECEIVER_HH

namespace game {
	
	struct MouseState {
		core::position2di position;
		bool leftButtonDown;
		MouseState() : leftButtonDown(false) { };
	} ;

	// Receives all mouse and keyboard input, and sends it to the right objects.
	// Warning: this class may contain quantum. Try not to observe it.
	class IrrlichtReceiver : public IEventReceiver {
	public:
		MouseState mouse;
		virtual bool OnEvent(const SEvent&);
		virtual bool IsKeyDown(EKEY_CODE keyCode) const;
		const SEvent::SJoystickEvent & getJoystickState(void) const;
		const MouseState & getMouseState(void) const;
		IrrlichtReceiver();
		void setGooeySet(GooeySet*);
	private:
		GooeySet* gooeySet;
		SEvent::SJoystickEvent joystick;
		bool KeyIsDown[KEY_KEY_CODES_COUNT];
	};

}

#endif
