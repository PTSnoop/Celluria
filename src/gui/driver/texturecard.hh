#include <irrlicht/irrlicht.h>
using namespace irr;

#include <string>
using namespace std;


namespace game {

    class TextureCard {
    public:
        TextureCard(video::IVideoDriver*,video::ITexture*);
        TextureCard(video::IVideoDriver*,string);
        TextureCard(video::IVideoDriver*,video::ITexture*,core::rect<s32>);
        TextureCard(video::IVideoDriver*,string,core::rect<s32>);

        void setDriver(video::IVideoDriver*);

        void setTexture(video::ITexture*);
        void setTexture(string);

        void setPosition(core::position2d<s32>);
        void setRotation(float);
        void setScale(core::vector2df);
        void setOrigin(core::position2d<s32>);
        void setSourceRect(core::rect<s32>);
        void setUseAlpha(bool);
        void setColour(video::SColor);

        void draw();
        void draw(core::position2d<s32>);
        void draw(core::position2d<s32>,float);

    private:
        video::IVideoDriver* driver;

        video::ITexture* texture;
        core::position2d<s32> position;
        float rotation;
        core::vector2df scale;
        core::position2d<s32> origin;
        core::rect<s32> sourceRect;
        bool useAlpha;
        video::SColor colour;

        void defaults(video::ITexture*);
/*
        void anImage(
        string texture, 
        irr::core::position2d<irr::s32> position, 
        irr::f32 rotation = 0, 
        irr::core::vector2df scale = irr::core::vector2df(1,1), 
        irr::core::position2d<irr::s32> offset = irr::core::position2d<irr::s32>(0,0)
        );

        void anImage(
        irr::video::ITexture* texture, 
        irr::core::position2d<irr::s32> position, 
        irr::f32 rotation = 0, 
        irr::core::vector2df scale = irr::core::vector2df(1,1), 
        irr::core::position2d<irr::s32> offset = irr::core::position2d<irr::s32>(0,0)
        );

        void anImage(
        string texture, 
        irr::core::position2d<irr::s32> position, 
        irr::f32 rotation, 
        irr::core::vector2df scale, 
        irr::core::position2d<irr::s32> offset,
        irr::core::rect<irr::s32> sourceRect,
        bool useAlphaChannel = true,
        irr::video::SColor colour = irr::video::SColor(255,255,255,255)
        );

        void anImage(
        irr::video::ITexture* texture, 
        irr::core::position2d<irr::s32> position, 
        irr::f32 rotation, 
        irr::core::vector2df scale, 
        irr::core::position2d<irr::s32> offset,
        irr::core::rect<irr::s32> sourceRect,
        bool useAlphaChannel = true,
        irr::video::SColor colour = irr::video::SColor(255,255,255,255)
        );
*/

        void draw2DImage(irr::video::IVideoDriver *driver, irr::video::ITexture* texture, irr::core::rect<irr::s32> sourceRect, irr::core::position2d<irr::s32> position, irr::core::position2d<irr::s32> rotationPoint, irr::f32 rotation, irr::core::vector2df scale, bool useAlphaChannel, irr::video::SColor color);
        
    };
}

