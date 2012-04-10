#include <irrlicht/irrlicht.h>
using namespace irr;

#include "irrlichtreceiver.hh"

#ifndef IRRLICHTSCREEN_HH
#define IRRLICHTSCREEN_HH

namespace game {
	
	// The window that the player sees, and things pertaining thereto.
	class IrrlichtScreen {
	public:
		IrrlichtScreen();
		IrrlichtScreen(int,int);
		IrrlichtDevice* device;
		video::IVideoDriver* driver;
		void setEventReceiver(IrrlichtReceiver*);
		IrrlichtReceiver* receiver;
		
		// this one's not really tested yet.
		void setResolution(int,int);
		int resx;
		int resy;
		
		// To show something to the screen, do run(), beginScene(), draw whatever you want to draw, endScene().
		bool run();
		void beginScene();
		void endScene();
	};
}

#endif
