#include "main.hh"

int main() {
    
    IrrlichtScreen * irrscreen = new IrrlichtScreen;

    TexturePack * texpack = new TexturePack(irrscreen);
    texpack->addTexture("clawbutton", "textures/cell/unity/buttons/claw.png");

    TextureCard* clawtex = texpack->getCard("clawbutton");
    TextureCard* clawtex2 = texpack->getCard("clawbutton");

    clawtex->setPosition( core::position2d<s32>(48,48) );
    clawtex2->setPosition( core::position2d<s32>(148,148) );

    float r = 0;
    while (irrscreen->run()) {
        
        r += 0.001;        

        irrscreen->beginScene();

        clawtex->draw();
		
		if (irrscreen->receiver->mouse.leftButtonDown)
			clawtex2->draw();

        irrscreen->endScene();

        int fps = irrscreen->driver->getFPS();
        core::stringw str = L"Celluria - FPS:";
        str += irrscreen->driver->getFPS();
        irrscreen->device->setWindowCaption(str.c_str());

    }
    return 0;
}
