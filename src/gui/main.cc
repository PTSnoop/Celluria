#include "main.hh"

int main() {
	
	IrrlichtScreen * irrscreen = new IrrlichtScreen (1024,768);

    TexturePack * texpack = new TexturePack(irrscreen);
	texpack->setFont("fonts/Gudea14/font.xml");
	texpack->addTexture("rect","textures/rect.png");	
	cout << texpack << endl;
	
	MainMenuGame * game = new MainMenuGame (irrscreen, texpack);
	game->load();
    
    while (irrscreen->run()) {      

        irrscreen->beginScene();

		game->update();
		game->draw();

        irrscreen->endScene();

        int fps = irrscreen->driver->getFPS();
        core::stringw str = L"Celluria - FPS:";
        str += irrscreen->driver->getFPS();
        irrscreen->device->setWindowCaption(str.c_str());

    }
    
    return 0;
}
