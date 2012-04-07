#include "testgame.hh"

namespace game {
	
	OnlyGooey::OnlyGooey(TestGame* game) {
		parentGame = game;
	}
	
	void OnlyGooey::load() {
		apple = new Button(parentGame->irrscreen->driver,"textures/cell/unity/buttons/apple.png");
		apple->setPosition( core::position2d<s32>(400,248) );
		addBox(apple);
	}
	
	void OnlyGooey::update() {
	}
	
	void OnlyGooey::draw() {
		apple->draw();
	}
	
	TestGame::TestGame(IrrlichtScreen* iirrscreen, TexturePack* ttexpack) {
		irrscreen = iirrscreen;
		texpack = ttexpack;
		
		//setWorld(new World ());
		setGooeySet(new GooeySet ());
		bindReceiver(irrscreen->receiver);
		
		Gooey* onlyGooey = new OnlyGooey (this);
		gooeySet->addGooey(onlyGooey);
		
		gooeySet->changeToGooey(0);
	}
	
}