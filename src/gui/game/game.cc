#include "game.hh"

namespace game {
	void Game::load() {
		gooeySet->load();
	}
	
	void Game::update() {
		gooeySet->update();
	}
	
	void Game::draw() {
		gooeySet->draw();
	}
	
	void Game::bindReceiver(IrrlichtReceiver* reciv) {
		receiver = reciv;
		receiver->setGooeySet(gooeySet);
	}
	
	void Game::bindReceiver() {
		receiver->setGooeySet(gooeySet);
	}
	
	//void Game::setWorld(World* wworld) {
	//	world = wworld;
	//}
	
	void Game::setGooeySet(GooeySet* ggooeySet) {
		gooeySet = ggooeySet;
	}
}