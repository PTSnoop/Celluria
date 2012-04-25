#include "mainmenugooey.hh"

namespace game {

	MainButton::MainButton(TexturePack* texpack, core::position2d<s32> pos, string labeltext) {
		left = texpack->getCard("mm_button_left");
		mid = texpack->getCard("mm_button_mid");
		right = texpack->getCard("mm_button_right");
		label = texpack->getTextCard(labeltext);//, core::rect<s32>(0,0,160,160));
		//label->setRightJustified(true);
		setPosition(pos);
		isMouseOver = false;
	}

	void MainButton::setPosition(core::position2d<s32> pos) {
		left->setPosition(pos);
		mid->setPosition(pos + core::position2d<s32>(32,0));
		mid->setScale(core::vector2df(3.5,1.0));
		right->setPosition(pos + core::position2d<s32>(32+112,0));
		label->setPosition(pos + core::position2d<s32>(8,4));
	}

	void MainButton::onMouseOver(bool over) {
		if (over and not isMouseOver) {
			left->setColour(video::SColor(127,127,127,255));
			mid->setColour(video::SColor(127,127,127,255));
			right->setColour(video::SColor(127,127,127,255));
			isMouseOver = true;
		}
		else if (not over and isMouseOver) {
			left->setColour(video::SColor(255,255,255,255));
			mid->setColour(video::SColor(255,255,255,255));
			right->setColour(video::SColor(255,255,255,255));
			isMouseOver = false;
		}
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

		quickgame_box->setParams(vectorOfInts(1));
		skirmish_box->setParams(vectorOfInts(2));
		multiplayer_box->setParams(vectorOfInts(3));
		options_box->setParams(vectorOfInts(4));
		credits_box->setParams(vectorOfInts(5));
		quit_box->setParams(vectorOfInts(6));
/*
		skirmish_box->setParams(vectorOfInts(2));
		multiplayer_box->setParams(vectorOfInts(3));
		options_box->setParams(vectorOfInts(4));
		credits_box->setParams(vectorOfInts(5));
		quit_box->setParams(vectorOfInts(6));
*/
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
	
	void MainMenuGooey::event(int eventType ,vector<int> params) {
		if (eventType == 1) {
			for ( vector<int>::iterator it=params.begin() ; it < params.end(); it++ ) {
				cout << (*it) << "\t";
			}
			cout << endl;
		}
		else if (eventType == 2) {
			int button = params[0];
			switch (button) {
				case 1:
					quickgame->onMouseOver(true);
				break;
				case 2:
					skirmish->onMouseOver(true);
				break;
				case 3:
					multiplayer->onMouseOver(true);
				break;
				case 4:
					options->onMouseOver(true);
				break;
				case 5:
					credits->onMouseOver(true);
				break;
				case 6:
					quit->onMouseOver(true);
			}
		}
		else if (eventType == 3) {
			int button = params[0];
			switch (button) {
				case 1:
					quickgame->onMouseOver(false);
				break;
				case 2:
					skirmish->onMouseOver(false);
				break;
				case 3:
					multiplayer->onMouseOver(false);
				break;
				case 4:
					options->onMouseOver(false);
				break;
				case 5:
					credits->onMouseOver(false);
				break;
				case 6:
					quit->onMouseOver(false);
			}
		}
	}
	
}
