#include "irrlicht/irrlicht.h"
using namespace irr;

#include <vector>
#include <iostream>
using namespace std;

#include "gui/driver/texturepack.hh"

#include "gooey.hh"
#include "gooeyset.hh"
//#include "world/world.hh"
#include "gui/driver/irrlichtreceiver.hh"

#ifndef GAME_HH
#define GAME_HH

namespace game{

	// A game. Contains a World and some Gooeys.
	class Game {
	public:
		
		// Loads all Gooeys in the GooeySet.
		void load();
		// Updates all Gooeys in the GooeySet. Should probably have a dt.
		void update();
		// Draws the current Gooey in the GooeySet.
		void draw();
	
		IrrlichtReceiver* receiver ;
		//void setWorld(World*);
		
		// Sets the GooeySet.
		void setGooeySet(GooeySet*);
		
		// Points the IrrlichtReceiver to send commands to the right GooeySet.
		void bindReceiver(IrrlichtReceiver*);
		void bindReceiver();

		//World* world ;
		GooeySet* gooeySet ;
		TexturePack* texpack ;
	};

}

#endif
