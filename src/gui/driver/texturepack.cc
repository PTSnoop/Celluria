#include "texturepack.hh"

namespace game {

    TexturePack::TexturePack (IrrlichtDriver* irrlichtdriver) {
        irrdriver = irrlichtdriver;
    }

    void TexturePack::addTexture(string texname, string intexture) {
        textureBank.insert( pair<string,video::ITexture*>(texname,irrdriver->driver->getTexture(intexture.c_str())) );
    }

    void TexturePack::addTexture(string texname, video::ITexture* intexture) {
        textureBank.insert( pair<string,video::ITexture*>(texname,intexture) );
    }

    void TexturePack::addColour(string colourname, video::SColorf* incolour) {
        colourBank.insert( pair<string,video::SColorf*>(colourname,incolour) );
    }

    void TexturePack::readFile(string filename) {
        
    }

    video::ITexture* TexturePack::getTexture(string texname) {
        map<string,video::ITexture*>::iterator pick = textureBank.find(texname);
        if (pick != textureBank.end() )
            return (*pick).second;
        return 0;
    }

    video::SColorf* TexturePack::getColour(string colname) {
        map<string,video::SColorf*>::iterator pick = colourBank.find(colname);
        if (pick != colourBank.end() )
            return (*pick).second;
        return 0;
    }

}
