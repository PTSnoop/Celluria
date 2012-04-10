#include "mainmenugooey.hh"

namespace game {

	MainButton::MainButton(TexturePack* texpack, core::position2d<s32> pos, string labeltext) {
		left = texpack->getCard("mm_button_left");
		mid = texpack->getCard("mm_button_mid");
		right = texpack->getCard("mm_button_right");
		label = texpack->getTextCard(labeltext);
		setPosition(pos);
	}

	void MainButton::setPosition(core::position2d<s32> pos) {
		left->setPosition(pos);
		mid->setPosition(pos + core::position2d<s32>(32,0));
		mid->setScale(core::vector2df(3.5,1.0));
		right->setPosition(pos + core::position2d<s32>(32+112,0));
		label->setPosition(pos + core::position2d<s32>(8,4));
	}

	void MainButton::draw() {
		left->draw();
		mid->draw();
		right->draw();
		label->draw();
	}
	
	MainMenuGooey::MainMenuGooey(Game* game) {
		parentGame = game;
	}
	
	void MainMenuGooey::load() {
		
		parentGame->texpack->addTexture("mm_button_left","textures/mainmenu/button_left.png");
		parentGame->texpack->addTexture("mm_button_mid","textures/mainmenu/button_mid.png");
		parentGame->texpack->addTexture("mm_button_right","textures/mainmenu/button_right.png");
		//quickgame = new MainButton (parentGame->texpack,core::position2d<s32>(616,896),"Quick Game");
		quickgame = new MainButton (parentGame->texpack,core::position2d<s32>(796,616),"Quick Game");
		/*
		skirmish = new MainButton (texpack,core::position2d<s32>(616,896),"Quick Game");
		multiplayer = new MainButton (texpack,core::position2d<s32>(616,896),"Quick Game");
		options = new MainButton (texpack,core::position2d<s32>(616,896),"Quick Game");
		credits = new MainButton (texpack,core::position2d<s32>(616,896),"Quick Game");
		quit = new MainButton (texpack,core::position2d<s32>(616,896),"Quick Game");*/
	}
	
	void MainMenuGooey::update() {
	}
	
	void MainMenuGooey::draw() {
		quickgame->draw();
	}
	
	void MainMenuGooey::event(vector<int> params) {
		for ( vector<int>::iterator it=params.begin() ; it < params.end(); it++ ) {
			cout << (*it) << "\t";
		}
		cout << endl;
	}
	
}
