#include "gooey.hh"
#include "game.hh"

#ifndef TESTGAME_HH
#define TESTGAME_HH

namespace game {
	
	class TestGame : public Game {
	public:
		TestGame(IrrlichtScreen* , TexturePack*);
		IrrlichtScreen* irrscreen;
		TexturePack* texpack;
	};
	
	class OnlyGooey : public Gooey {
	public:
		OnlyGooey(TestGame*);
		TestGame* parentGame;
		void load();
		void update();
		void draw();
		void event(vector<int>);
		Button * apple;
	};
	


}

#endif