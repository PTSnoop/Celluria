#include "main.hh"

int main() {
    
    IrrlichtScreen * irrscreen = new IrrlichtScreen;

    TexturePack * texpack = new TexturePack(irrscreen);
    texpack->addTexture("clawbutton", "textures/cell/unity/buttons/claw.png");

    TextureCard* clawtex = texpack->getCard("clawbutton");
    TextureCard* clawtex2 = texpack->getCard("clawbutton");
	
	Button * apple = new Button(irrscreen->driver,"textures/cell/unity/buttons/apple.png");
	
	apple->setPosition( core::position2d<s32>(248,248) );

    clawtex->setPosition( core::position2d<s32>(48,48) );
    clawtex2->setPosition( core::position2d<s32>(148,48) );

    float r = 0;
    while (irrscreen->run()) {
        
        r += 0.001;        

        irrscreen->beginScene();

        clawtex->draw(core::position2d<s32>(48,48));

		if (irrscreen->receiver->mouse.leftButtonDown)
			clawtex->draw(core::position2d<s32>(148,48));

		if (irrscreen->receiver->IsKeyDown(KEY_SPACE))
			clawtex->draw(core::position2d<s32>(248,48));
		
		apple->draw();

        irrscreen->endScene();

        int fps = irrscreen->driver->getFPS();
        core::stringw str = L"Celluria - FPS:";
        str += irrscreen->driver->getFPS();
        irrscreen->device->setWindowCaption(str.c_str());

    }
    return 0;
}