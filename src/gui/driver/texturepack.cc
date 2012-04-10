#include "texturepack.hh"

namespace game {

	TexturePack::TexturePack (IrrlichtScreen* irrlichtscreen) {
		irrscreen = irrlichtscreen;
		env = irrscreen->device->getGUIEnvironment();
		font = env->getBuiltInFont();
	}
	
	void TexturePack::addTexture(string texname, string intexture) {
		TextureNode tmpnode;
		tmpnode.texture = irrscreen->driver->getTexture(intexture.c_str());
		
		core::dimension2d<irr::u32> texsize = tmpnode.texture->getSize();
		tmpnode.mask = irr::core::rect<irr::s32>(0,0,texsize.Width,texsize.Height);
		
		textureBank.insert( pair<string,TextureNode>(texname,tmpnode ) );
	}

	void TexturePack::addTexture(string texname, video::ITexture* intexture) {		
		TextureNode tmpnode;
		tmpnode.texture = intexture;
		
		core::dimension2d<irr::u32> texsize = tmpnode.texture->getSize();
		tmpnode.mask = irr::core::rect<irr::s32>(0,0,texsize.Width,texsize.Height);
		
		textureBank.insert( pair<string,TextureNode>(texname,tmpnode ) );
	}

	void TexturePack::addTexture(string texname, string intexture, core::rect<s32> inmask) {
		TextureNode tmpnode;
		tmpnode.texture = irrscreen->driver->getTexture(intexture.c_str());
		tmpnode.mask = inmask;
		
		textureBank.insert( pair<string,TextureNode>(texname,tmpnode ) );
	}

	void TexturePack::addTexture(string texname, video::ITexture* intexture, core::rect<s32> inmask) {		
		TextureNode tmpnode;
		tmpnode.texture = intexture;
		tmpnode.mask = inmask;
		
		textureBank.insert( pair<string,TextureNode>(texname,tmpnode ) );
	}

	void TexturePack::addColour(string colourname, video::SColorf* incolour) {
		colourBank.insert( pair<string,video::SColorf*>(colourname,incolour) );
	}

	void TexturePack::setFont(string fontname) {
		gui::IGUISkin* skin = env->getSkin();
		font = env->getFont(fontname.c_str());
		if (font) { 
			skin->setFont(font);
			env->getSkin()->setColor(gui::EGDC_BUTTON_TEXT,video::SColor(255,255,255,255));
		}
		else {
			font = env->getBuiltInFont();
			skin->setFont(font);
		}
	}

	void TexturePack::readFile(string filename) {
		
	}

	video::ITexture* TexturePack::getTexture(string texname) {
		map<string,TextureNode>::iterator pick = textureBank.find(texname);
		if (pick != textureBank.end() )
			return (*pick).second.texture;
		return 0;
	}

	Button* TexturePack::getButton(Gooey* gooey, string texname) {
		map<string,TextureNode>::iterator pick = textureBank.find(texname);
		if (pick != textureBank.end() )
			return new Button (gooey, irrscreen->driver, (*pick).second.texture);//,(*pick).second.mask);
		return 0;
	}
	
	TextureCard* TexturePack::getCard(string texname) {
		map<string,TextureNode>::iterator pick = textureBank.find(texname);
		if (pick != textureBank.end() )
			return new TextureCard (irrscreen->driver, (*pick).second.texture,(*pick).second.mask);
		return 0;
	}

	TextCard* TexturePack::getTextCard(string cardtext) {
		return new TextCard ( irrscreen->driver, font, cardtext);
	}

	InputBox* TexturePack::getInputBox(core::rect<s32> inrect) {
		return new InputBox (env, inrect);
	}

	video::SColorf* TexturePack::getColour(string colname) {
		map<string,video::SColorf*>::iterator pick = colourBank.find(colname);
		if (pick != colourBank.end() )
			return (*pick).second;
		return 0;
	}

}
