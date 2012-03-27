#include "main.hh"

int main() {
    
    IrrlichtScreen * irrscreen = new IrrlichtScreen;

    TexturePack * texpack = new TexturePack(irrscreen);
    texpack->addTexture("clawbutton", "textures/cell/unity/buttons/claw.png");


    TextureCard * clawtex = new TextureCard(irrscreen->driver,"textures/cell/unity/buttons/claw.png");
    clawtex->setPosition( core::position2d<s32>(48,48) );

    float r = 0;
    while (irrscreen->run()) {
        
        r += 0.001;        

        irrscreen->beginScene();

        clawtex->draw();

        irrscreen->endScene();
    }
    return 0;
}
