#include "mainmenugooey.hh"

namespace game {

	MainButton::MainButton(TexturePack* texpack, core::position2d<s32> pos, string labeltext) {
		left = texpack->getCard("mm_button_left");
		mid = texpack->getCard("mm_button_mid");
		right = texpack->getCard("mm_button_right");
		label = texpack->getTextCard(labeltext);//, core::rect<s32>(0,0,160,160));
		//label->setRightJustified(true);
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
		parentGame->texpack->addTexture("mm_bg1","textures/mainmenu/mmbg1.png");

		quickgame = new MainButton (parentGame->texpack,core::position2d<s32>(616,600-96-26),"Quick Game");
		skirmish = new MainButton (parentGame->texpack,core::position2d<s32>(616,600-61-26),"Skirmish");
		multiplayer = new MainButton (parentGame->texpack,core::position2d<s32>(616,600-28-26),"Multiplayer");
		options = new MainButton (parentGame->texpack,core::position2d<s32>(816,600-96-26),"Options");
		credits = new MainButton (parentGame->texpack,core::position2d<s32>(816,600-61-26),"Credits");
		quit = new MainButton (parentGame->texpack,core::position2d<s32>(816,600-28-26),"Quit");

		background = parentGame->texpack->getCard("mm_bg1");
		background->setScale(core::vector2df((1024+60)/32,768/32));
		background->setPosition(core::vector2d<s32>(-5,-100));

		bgbar = parentGame->texpack->getCard("rect");
		bgbar->setScale(core::vector2df(1024,168));
		bgbar->setPosition(core::position2d<s32>(0,600-148));
		bgbar->setColour(video::SColor(255,59,59,59));

		ButtonBox* quickgame_box = new ButtonBox (this,core::rect<s32>(616,600-96-26,616+175,600-96));
		ButtonBox* skirmish_box = new ButtonBox (this,core::rect<s32>(616,600-61-26,616+175,600-61));
		ButtonBox* multiplayer_box = new ButtonBox (this,core::rect<s32>(616,600-28-26,616+175,600-26));
		ButtonBox* options_box = new ButtonBox (this,core::rect<s32>(816,600-96-26,816+175,600-96));
		ButtonBox* credits_box = new ButtonBox (this,core::rect<s32>(816,600-61-26,816+175,600-61));
		ButtonBox* quit_box = new ButtonBox (this,core::rect<s32>(816,600-28-26,816+175,600-28));

		vector<int> nullparams;
		vector<int> quitparams;

		nullparams.push_back(0);
		quitparams.push_back(6);

		quickgame_box->setParams(nullparams);
		skirmish_box->setParams(nullparams);
		multiplayer_box->setParams(nullparams);
		options_box->setParams(nullparams);
		credits_box->setParams(nullparams);
		quit_box->setParams(quitparams);

		addBox(quickgame_box);
		addBox(skirmish_box);
		addBox(multiplayer_box);
		addBox(options_box);
		addBox(credits_box);
		addBox(quit_box);
	}
	
	void MainMenuGooey::update() {
	}
	
	void MainMenuGooey::draw() {
		background->draw();
		bgbar->draw();

		quickgame->draw();
		skirmish->draw();
		multiplayer->draw();
		options->draw();
		credits->draw();
		quit->draw();
	}
	
	void MainMenuGooey::event(vector<int> params) {
		for ( vector<int>::iterator it=params.begin() ; it < params.end(); it++ ) {
			cout << (*it) << "\t";
		}
		cout << endl;
	}
	
}
