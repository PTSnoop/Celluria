#include "main.hh"

int main() {
    
    IrrlichtDriver * irrdriver = new IrrlichtDriver;

    TexturePack * texpack = new TexturePack(irrdriver);
//    texpack->addTexture("clawbutton", irrdriver->driver->getTexture("textures/cell/unity/buttons/claw.png"));
    texpack->addTexture("clawbutton", "textures/cell/unity/buttons/claw.png");


    TextureCard * clawtex = new TextureCard(irrdriver->driver,"textures/cell/unity/buttons/claw.png");
    clawtex->setPosition( core::position2d<s32>(48,48) );

    float r = 0;
    while (irrdriver->run()) {
        
        r += 0.001;        

        irrdriver->beginScene();

        clawtex->draw();

        irrdriver->endScene();
    }
    return 0;
}
