#include "clickbox.hh"

namespace game {

    void ClickBox::setBox(core::rect<s32> bbox) {
        screenspace = bbox;
    }

    bool ClickBox::clickNoise(core::position2d<s32> click) {
        if (screenspace.isPointInside(click)) {
            clicked();
            return true;
        } 
        else {
            return false;
        }
    }

    bool ClickBox::moveNoise(core::position2d<s32> move) {
        if (screenspace.isPointInside(click)) {
            move();
            return true;
        }
        else {
            unmove();
            return false;
        }
    }
}
