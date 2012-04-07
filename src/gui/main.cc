#include "main.hh"

int main() {
	
	IrrlichtScreen * irrscreen = new IrrlichtScreen;

    TexturePack * texpack = new TexturePack(irrscreen);
	
	TestGame * game = new TestGame (irrscreen, texpack);
	game->load();
    
    while (irrscreen->run()) {      

        irrscreen->beginScene();

		game->draw();

        irrscreen->endScene();

        int fps = irrscreen->driver->getFPS();
        core::stringw str = L"Celluria - FPS:";
        str += irrscreen->driver->getFPS();
        irrscreen->device->setWindowCaption(str.c_str());

    }
    
    return 0;
}