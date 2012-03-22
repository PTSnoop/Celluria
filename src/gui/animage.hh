#include <irrlicht.h>

void anImage(
irr::video::IVideoDriver* driver, 
irr::video::ITexture* texture, 
irr::core::position2d<irr::s32> position, 
irr::f32 rotation = 0, 
irr::core::vector2df scale = irr::core::vector2df(1,1), 
irr::core::position2d<irr::s32> offset = irr::core::position2d<irr::s32>(0,0)
);

void anImage(
irr::video::IVideoDriver* driver, 
irr::video::ITexture* texture, 
irr::core::position2d<irr::s32> position, 
irr::f32 rotation, 
irr::core::vector2df scale, 
irr::core::position2d<irr::s32> offset,
irr::core::rect<irr::s32> sourceRect,
bool useAlphaChannel = true,
irr::video::SColor colour = irr::video::SColor(255,255,255,255)
);

void draw2DImage(irr::video::IVideoDriver *driver, irr::video::ITexture* texture, irr::core::rect<irr::s32> sourceRect, irr::core::position2d<irr::s32> position, irr::core::position2d<irr::s32> rotationPoint, irr::f32 rotation, irr::core::vector2df scale, bool useAlphaChannel, irr::video::SColor color);
