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

	struct SMouseState {
		core::position2di Position;
		bool LeftButtonDown;
		SMouseState() : LeftButtonDown(false) { };
	} ;

	class AyEventReceiver : public IEventReceiver {
	public:
		SMouseState MouseState;
		virtual bool OnEvent(const SEvent&);
		const SEvent::SJoystickEvent & GetJoystickState(void) const;
		const SMouseState & GetMouseState(void) const;
		AyEventReceiver();
	private:
		SEvent::SJoystickEvent JoystickState;
	};

}

#endif
