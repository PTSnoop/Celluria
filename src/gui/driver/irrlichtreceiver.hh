#include <irrlicht/irrlicht.h>
using namespace irr;

#include <iostream>
using namespace std;

//#include "irrlichtscreen.hh"

#ifndef IRRLICHTRECEIVER_HH
#define IRRLICHTRECEIVER_HH

namespace game {
  
//  struct ReceiverContext {
//	  IrrlichtScreen* screen;
//  }

	struct MouseState {
		core::position2di position;
		bool leftButtonDown;
		MouseState() : leftButtonDown(false) { };
	} ;

	class IrrlichtReceiver : public IEventReceiver {
	public:
		MouseState mouse;
		virtual bool OnEvent(const SEvent&);
		virtual bool IsKeyDown(EKEY_CODE keyCode) const;
		const SEvent::SJoystickEvent & getJoystickState(void) const;
		const MouseState & getMouseState(void) const;
		IrrlichtReceiver();
	private:
		SEvent::SJoystickEvent joystick;
		bool KeyIsDown[KEY_KEY_CODES_COUNT];
	};

}

#endif
