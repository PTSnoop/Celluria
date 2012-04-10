#include <irrlicht/irrlicht.h>
using namespace irr;

#include <string>
using namespace std;

#include "card.hh"

#ifndef TEXTURECARD_HH
#define TEXTURECARD_HH

namespace game {

	// Something drawn to the screen.
	class TextureCard : public Card {
	public:
		
		// Can be constructed from an ITexture* or a filename.
		// Optional rect describes part of a larger texture.
		TextureCard() {};
		TextureCard(video::IVideoDriver*,video::ITexture*);
		TextureCard(video::IVideoDriver*,string);
		TextureCard(video::IVideoDriver*,video::ITexture*,core::rect<s32>);
		TextureCard(video::IVideoDriver*,string,core::rect<s32>);
		~TextureCard() {};

		// Change the texture being drawn. Takes ITexture* or filename.
		void setTexture(video::ITexture*);
		void setTexture(string);

		// Change various self-explanatory things.
		void setPosition(core::position2d<s32>);
		void setRotation(float);
		void setScale(core::vector2df);
		void setOrigin(core::position2d<s32>);
		void setSourceRect(core::rect<s32>);
		void setUseAlpha(bool);
		void setColour(video::SColor);

		// draws the texture to the screen.
		void draw();
		// moves the texture to the optional position and rotation, then draws it.
		void draw(core::position2d<s32>);
		void draw(core::position2d<s32>,float);

		video::IVideoDriver* driver;
		void setDriver(video::IVideoDriver*);

		video::ITexture* texture;
		core::position2d<s32> position;
		float rotation;
		core::vector2df scale;
		core::position2d<s32> origin;
		core::rect<s32> sourceRect;
		bool useAlpha;
		video::SColor colour;

		// resets position, rotation, sourceRect etc. to default.
		void defaults(video::ITexture*);
	private:
		void draw2DImage(irr::video::IVideoDriver *driver, irr::video::ITexture* texture, irr::core::rect<irr::s32> sourceRect, irr::core::position2d<irr::s32> position, irr::core::position2d<irr::s32> rotationPoint, irr::f32 rotation, irr::core::vector2df scale, bool useAlphaChannel, irr::video::SColor color);
		
	};
}

#endif
