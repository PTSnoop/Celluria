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
        clawtex2->draw();

        irrscreen->endScene();
    }
    return 0;
}
