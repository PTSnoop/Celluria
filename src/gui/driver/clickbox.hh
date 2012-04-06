#include <irrlicht/irrlicht.h>
using namespace irr;

#include <string>
using namespace std;

#ifndef CLICKBOX_HH
#define CLICKBOX_HH

namespace game {

    class ClickBox {
    public:
        void setBox(core::rect<s32>);
        bool clickNoise(core::position2d<s32>);
        bool moveNoise(core::position2d<s32>);

        virtual clicked();
        virtual move();
        virtual unmove();

    private:
        core::rect<s32> screenspace;
    };
}

#endif
