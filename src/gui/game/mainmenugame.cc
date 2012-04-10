#include "mainmenugame.hh"

namespace game {
	
	MainMenuGame::MainMenuGame(IrrlichtScreen* iirrscreen, TexturePack* ttexpack) {
		irrscreen = iirrscreen;
		texpack = ttexpack;	
		cout << texpack << endl;
		texpack->addTexture("mm_button_left","textures/mainmenu/button_left.png");
		texpack->addTexture("mm_button_mid","textures/mainmenu/button_mid.png");
		texpack->addTexture("mm_button_right","textures/mainmenu/button_right.png");
		
		//setWorld(new World ());
		setGooeySet(new GooeySet ());
		bindReceiver(irrscreen->receiver);
		
		Gooey* mainMenuGooey = new MainMenuGooey (this);
		gooeySet->addGooey(mainMenuGooey);
		
		gooeySet->changeToGooey(0);
	}
	
}
