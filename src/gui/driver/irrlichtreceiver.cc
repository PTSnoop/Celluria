#include "irrlichtreceiver.hh"

namespace game {
	
	bool IrrlichtReceiver::OnEvent(const SEvent& event) {
		
		// Remember the mouse state
		if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
		{
			switch(event.MouseInput.Event)
			{
			case EMIE_LMOUSE_PRESSED_DOWN:
				mouse.leftButtonDown = true;
				if (gooeySet) {
					gooeySet->clickNoise(mouse.position);
				}
				break;
			case EMIE_LMOUSE_LEFT_UP:
				mouse.leftButtonDown = false;
				break;
			case EMIE_MOUSE_MOVED:
				mouse.position.X = event.MouseInput.X;
				mouse.position.Y = event.MouseInput.Y;
				if (gooeySet) {
					gooeySet->moveNoise(mouse.position);
				}
				break;
			default:
				// We won't use the wheel
				break;
			}
		}
		else if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
			KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
		}
		// The state of each connected joystick is sent to us
		// once every run() of the Irrlicht device.  Store the
		// state of the first joystick, ignoring other joysticks.
		// This is currently only supported on Windows and Linux.
		else if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT
			&& event.JoystickEvent.Joystick == 0)
		{
			joystick = event.JoystickEvent;
		}
		return false;
	}
	
	bool IrrlichtReceiver::IsKeyDown(EKEY_CODE keyCode) const {
		return KeyIsDown[keyCode];
	}

	const SEvent::SJoystickEvent & IrrlichtReceiver::getJoystickState(void) const {
		return joystick;
	}

	const MouseState & IrrlichtReceiver::getMouseState(void) const {
		return mouse;
	}


	IrrlichtReceiver::IrrlichtReceiver() {
		for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
			KeyIsDown[i] = false;
	}
	
	void IrrlichtReceiver::setGooeySet(GooeySet* gs) {
		gooeySet = gs;
	}
	
}

