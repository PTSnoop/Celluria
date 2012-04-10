#include "irrlichtscreen.hh"

namespace game {

	void IrrlichtScreen::setResolution(int xxres,int yyres) {
		if (xres == 0) { // automatically find screen resolution

			// create temporary device
			IrrlichtDevice *nulldevice = createDevice(video::EDT_NULL);
			core::dimension2d<u32> deskres = nulldevice->getVideoModeList()->getDesktopResolution();
			xres = deskres.X;
			yres = deskres.Y;
			nulldevice -> drop();
			// create real device (leaving as windowed for now)
			device = createDevice(video::EDT_OPENGL, deskres, 32, false);

		} else { // use given resolution
			xres = xxres;
			yres = yyres;
			device = createDevice(video::EDT_OPENGL, core::dimension2d<u32>(xres,yres), 32, false);
			driver = device->getVideoDriver();
		}
		receiver = new IrrlichtReceiver;
		device->setEventReceiver(receiver);
	}

	void IrrlichtScreen::setEventReceiver(IrrlichtReceiver* rreceiver) {
		device->setEventReceiver(rreceiver);
	}

	IrrlichtScreen::IrrlichtScreen() {
		setResolution(0,0);
	}

	IrrlichtScreen::IrrlichtScreen(int xres, int yres) {
		setResolution(xres,yres);
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
