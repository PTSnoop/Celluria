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
                break;
            case EMIE_LMOUSE_LEFT_UP:
                mouse.leftButtonDown = false;
                break;
            case EMIE_MOUSE_MOVED:
                mouse.position.X = event.MouseInput.X;
                mouse.position.Y = event.MouseInput.Y;
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
            joystick = event.JoystickEvent;
        }
        return false;
    }

    const SEvent::SJoystickEvent & IrrlichtReceiver::getJoystickState(void) const
    {
        return joystick;
    }

    const MouseState & IrrlichtReceiver::getMouseState(void) const
    {
        return mouse;
    }


    IrrlichtReceiver::IrrlichtReceiver()
    {
    }
    
}

