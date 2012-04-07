#include "irrlicht/irrlicht.h"

#include "gui/driver/irrlichtreceiver.hh"
#include "gui/driver/texturepack.hh"

#ifndef GAMEHANDLER_HH
#define GAMEHANDLER_HH

namespace game{
	
	// Not implemented yet.
	class GameHandler {
	public:
		GameHandler ();
		void load();
		void update();
		void draw();

		void quitToMainMenu();
		void skirmish();
		Game* game;
	};

}

#endif
