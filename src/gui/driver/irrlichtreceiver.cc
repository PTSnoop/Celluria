#include "irrlichtreceiver.hh"

namespace game {


bool AyEventReceiver::OnEvent(const SEvent& event)
{

		// Remember the mouse state
		if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
		{
				switch(event.MouseInput.Event)
				{
				case EMIE_LMOUSE_PRESSED_DOWN:
						MouseState.LeftButtonDown = true;
						break;

				case EMIE_LMOUSE_LEFT_UP:
						MouseState.LeftButtonDown = false;
	printf("EVENT\n");
						break;

				case EMIE_MOUSE_MOVED:
						MouseState.Position.X = event.MouseInput.X;
						MouseState.Position.Y = event.MouseInput.Y;
						break;

				default:
						// We won't use the wheel
						break;
				}
		}

		// The state of each connected joystick is sent to us
		// once every run() of the Irrlicht device.  Store the
		// state of the first joystick, ignoring other joysticks.
		// This is currently only supported on Windows and Linux.
		if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT
				&& event.JoystickEvent.Joystick == 0)
		{
				JoystickState = event.JoystickEvent;
		}

		return false;
}

const SEvent::SJoystickEvent & AyEventReceiver::GetJoystickState(void) const
{
		return JoystickState;
}

const SMouseState & AyEventReceiver::GetMouseState(void) const
{
		return MouseState;
}


AyEventReceiver::AyEventReceiver()
{
	cout << "BOOM" << endl;
}
	
}

