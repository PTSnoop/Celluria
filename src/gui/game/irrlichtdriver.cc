#include "irrlichtdriver.hh"

namespace game {

    void IrrlichtDriver::setResolution(int xres,int yres) {
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

//    void IrrlichtDriver::setEventReceiver(IrrlichtReceiver receiver) {
//        device->setEventReceiver(&receiver);
//    }

    IrrlichtDriver::IrrlichtDriver() {
        setResolution(1024,768);
//        receiver = new IrrlichtReceiver();
//        setEventReceiver(receiver);
    }

    bool IrrlichtDriver::run() {
        if (!driver)
            return false;
        if (!device->run())
            return false;

        return true;
    }

    void IrrlichtDriver::beginScene() {
        driver->beginScene(true, true, video::SColor(0,0,0,0));
    }

    void IrrlichtDriver::endScene() {
        driver->endScene();
    }

}
