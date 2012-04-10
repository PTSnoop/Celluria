#include <iostream>
using namespace std;

#include "gooey.hh"
#include "game.hh"

#ifndef TESTGAME_HH
#define TESTGAME_HH

namespace game {
	
	// An example Game, with only one Gooey.
	class TestGame : public Game {
	public:
		TestGame(IrrlichtScreen* , TexturePack*);
		IrrlichtScreen* irrscreen;
		TexturePack* texpack;
	};
	
	// The example Gooey for a TestGame, with only one Button.
	class OnlyGooey : public Gooey {
	public:
		OnlyGooey(TestGame*);
		TestGame* parentGame;
		void load();
		void update();
		void draw();
		void event(vector<int>);
		Button * apple;
		TextCard * label;
		TextCard * label2;
		InputBox * inbox;
	};
	
}

#endif
