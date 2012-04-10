#include "testgame.hh"

namespace game {
	
	OnlyGooey::OnlyGooey(TestGame* game) {
		parentGame = game;
	}
	
	void OnlyGooey::load() {
		parentGame->texpack->addTexture("apple","textures/cell/unity/buttons/apple.png");
		apple = parentGame->texpack->getButton(this,"apple");

		//apple = new Button(this, parentGame->irrscreen->driver,"textures/cell/unity/buttons/apple.png");
		
		apple->setPosition( core::position2d<s32>(400,248) );
		apple->placeButton();
		
		vector<int> appleParams;
		appleParams.push_back(2);
		appleParams.push_back(3);
		apple->setParams( appleParams );
		
		addBox(apple);

		label = parentGame->texpack->getTextCard("This is text!");
		label->setPosition(core::position2d<s32>(10,10));

		label2 = parentGame->texpack->getTextCard("This is some more text.");
		label2->setPosition(core::position2d<s32>(10,70));

		inbox = parentGame->texpack->getInputBox(core::rect<s32>(10,130,300,150));
		inbox->setText("Type here");
	}
	
	void OnlyGooey::update() {
		cout << inbox->getText() << endl;
	}
	
	void OnlyGooey::draw() {
		apple->draw();
		label->draw();
		label2->draw();
		inbox->draw();
	}
	
	void OnlyGooey::event(vector<int> params) {
		for ( vector<int>::iterator it=params.begin() ; it < params.end(); it++ ) {
			cout << (*it) << "\t";
		}
		cout << endl;
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
