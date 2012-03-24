#include "main.hh"

int main() {
    
    IrrlichtDriver * irrdriver = new IrrlichtDriver;

    TexturePack * texpack = new TexturePack(irrdriver);
//    texpack->addTexture("clawbutton", irrdriver->driver->getTexture("textures/cell/unity/buttons/claw.png"));
    texpack->addTexture("clawbutton", "textures/cell/unity/buttons/claw.png");

    Painter * painter = new Painter (irrdriver->driver,texpack);

    while (irrdriver->run()) {
        irrdriver->beginScene();
        painter->anImage("clawbutton",core::position2d<irr::s32>(10,10));
        irrdriver->endScene();
    }
    return 0;
}
