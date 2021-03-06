#include <irrlicht/irrlicht.h>
using namespace irr;

#include <iostream>
#include <vector>
using namespace std;

#include "gooey.hh"
#include "game.hh"
#include "gui/driver/texturepack.hh"
#include "gui/driver/buttonbox.hh"
#include "useful.hh"

#ifndef TESTGAME_HH
#define TESTGAME_HH

namespace game {

	// A provisional MainButton class.
	// This'll become a Widget.
	class MainButton {
	public:
		MainButton(TexturePack*,core::position2d<s32>,string);
		TextureCard * left;
		TextureCard * mid;
		TextureCard * right;
		TextCard * label;
		void setPosition(core::position2d<s32>);
		void draw();
		void onMouseOver(bool);
		bool isMouseOver;
	};

	// The Gooey for a Main Menu.
	class MainMenuGooey : public Gooey {
	public:
		MainMenuGooey(Game*);
		Game* parentGame;
		void load();
		void update();
		void draw();
		void event(int,vector<int>);

		// For now, I'll just handle the background in the Gooey.
		// Later on, I'll have the things-floating-past as a Widget.
		TextureCard * background;
		TextureCard * bgbar;

		MainButton* quickgame;
		MainButton* skirmish;
		MainButton* multiplayer;
		MainButton* options;
		MainButton* credits;
		MainButton* quit;
	};
	
}

#endif
