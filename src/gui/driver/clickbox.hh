#include <irrlicht/irrlicht.h>
using namespace irr;

#include <string>
#include <iostream>
using namespace std;

#ifndef CLICKBOX_HH
#define CLICKBOX_HH

namespace game {

    class ClickBox {
    public:
		ClickBox() {};
		ClickBox(core::rect<s32>);
		
        void setBox(core::rect<s32>);
        bool clickNoise(core::position2d<s32>);
        bool moveNoise(core::position2d<s32>);

        virtual void clicked() {};
        virtual void move() {};
        virtual void unmove() {};

    private:
        core::rect<s32> screenspace;
    };
}

#endif
