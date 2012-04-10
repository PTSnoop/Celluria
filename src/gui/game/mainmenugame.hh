#include <iostream>
using namespace std;

#include "gooey.hh"
#include "game.hh"
#include "mainmenugooey.hh"

#ifndef MAINMENUGAME_HH
#define MAINMENUGAME_HH

namespace game {
	
	// An example Game, with only one Gooey.
	class MainMenuGame : public Game {
	public:
		MainMenuGame(IrrlichtScreen* , TexturePack*);
		IrrlichtScreen* irrscreen;
	};
}

#endif
