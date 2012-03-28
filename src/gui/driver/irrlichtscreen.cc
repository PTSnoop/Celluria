#include "irrlichtscreen.hh"

namespace game {

    void IrrlichtScreen::setResolution(int xres,int yres) {
        if (xres == 0) { // automatically find screen resolution

            // create temporary device
            IrrlichtDevice *nulldevice = createDevice(video::EDT_NULL);
            core::dimension2d<u32> deskres = nulldevice->getVideoModeList()->getDesktopResolution();
            nulldevice -> drop();
            // create real device (leaving as windowed for now)
            device = createDevice(video::EDT_OPENGL, deskres, 32, false);

        } else { // use given resolution
            device = createDevice(video::EDT_OPENGL, core::dimension2d<u32>(xres,yres), 32, false);
            driver = device->getVideoDriver();
        }
    }

    void IrrlichtScreen::setEventReceiver(AyEventReceiver* rreceiver) {
        device->setEventReceiver(rreceiver);
    }

    IrrlichtScreen::IrrlichtScreen() {
        setResolution(1024,768);
		printf("new\n");
		receiver = new AyEventReceiver;
		printf("set\n");
        device->setEventReceiver(receiver);
		printf("setdone\n");
    }

    bool IrrlichtScreen::run() {
        if (!driver)
            return false;
        if (!device->run())
            return false;

        return true;
    }

    void IrrlichtScreen::beginScene() {
        driver->beginScene(true, true, video::SColor(0,0,0,0));
    }

    void IrrlichtScreen::endScene() {
        driver->endScene();
    }

}
