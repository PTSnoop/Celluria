#include "animage.hh"

void anImage(
irr::video::IVideoDriver* driver, 
irr::video::ITexture* texture, 
irr::core::position2d<irr::s32> position, 
irr::f32 rotation, 
irr::core::vector2df scale, 
irr::core::position2d<irr::s32> offset,
irr::core::rect<irr::s32> sourceRect,
bool useAlphaChannel,
irr::video::SColor colour) 
{
/*
    if (rotation < 0.01 and rotation > -0.01) {
        driver->draw2DImage (
            texture, 
            position, 
            sourceRect, 
            0, 
            colour, 
            useAlphaChannel
        ); // doesn't scale yet - fix this

    } else {
*/
        draw2DImage(
            driver, 
            texture, 
            sourceRect, 
            position, 
            position+offset, 
            -rotation * (180.0/M_PI), 
            scale, 
            useAlphaChannel, 
            colour);
//    }
}

void anImage(
irr::video::IVideoDriver* driver, 
irr::video::ITexture* texture, 
irr::core::position2d<irr::s32> position, 
irr::f32 rotation, 
irr::core::vector2df scale, 
irr::core::position2d<irr::s32> offset
) {
    irr::core::dimension2d<irr::u32> texsize = texture->getSize();
    irr::core::rect<irr::s32> sourceRect = irr::core::rect<irr::s32>(0,0,texsize.Width,texsize.Height);
    anImage(
        driver, 
        texture, 
        position, 
        rotation, 
        scale, 
        offset,
        irr::core::rect<irr::s32>(0,0,texsize.Width,texsize.Height),
        true,
        irr::video::SColor(255,255,255,255)
    );
};

void draw2DImage(irr::video::IVideoDriver *driver, irr::video::ITexture* texture, irr::core::rect<irr::s32> sourceRect, irr::core::position2d<irr::s32> position, irr::core::position2d<irr::s32> rotationPoint, irr::f32 rotation, irr::core::vector2df scale, bool useAlphaChannel, irr::video::SColor color) {
 
        // Store and clear the projection matrix
        irr::core::matrix4 oldProjMat = driver->getTransform(irr::video::ETS_PROJECTION);
        driver->setTransform(irr::video::ETS_PROJECTION,irr::core::matrix4());
        
        // Store and clear the view matrix
        irr::core::matrix4 oldViewMat = driver->getTransform(irr::video::ETS_VIEW);
        driver->setTransform(irr::video::ETS_VIEW,irr::core::matrix4());
 
        // Store and clear the world matrix
        irr::core::matrix4 oldWorldMat = driver->getTransform(irr::video::ETS_WORLD);
        driver->setTransform(irr::video::ETS_WORLD,irr::core::matrix4());
 
        // Find horizontal and vertical axes after rotation
        irr::f32 c = cos(-rotation*irr::core::DEGTORAD);
        irr::f32 s = sin(-rotation*irr::core::DEGTORAD);
        irr::core::vector2df horizontalAxis(c,s);
        irr::core::vector2df verticalAxis(s,-c);
 
        // First, we'll find the offset of the center and then where the center would be after rotation
        irr::core::vector2df centerOffset(position.X+sourceRect.getWidth()/2.0f*scale.X-rotationPoint.X,position.Y+sourceRect.getHeight()/2.0f*scale.Y-rotationPoint.Y);
        irr::core::vector2df center = centerOffset.X*horizontalAxis - centerOffset.Y*verticalAxis;
        center.X += rotationPoint.X;
        center.Y += rotationPoint.Y;
 
        // Now find the corners based off the center
        irr::core::vector2df cornerOffset(sourceRect.getWidth()*scale.X/2.0f,sourceRect.getHeight()*scale.Y/2.0f);
        verticalAxis *= cornerOffset.Y;
        horizontalAxis *= cornerOffset.X;
        irr::core::vector2df corner[4];
        corner[0] = center + verticalAxis - horizontalAxis;
        corner[1] = center + verticalAxis + horizontalAxis;
        corner[2] = center - verticalAxis - horizontalAxis;
        corner[3] = center - verticalAxis + horizontalAxis;
 
        // Find the uv coordinates of the sourceRect
        irr::core::vector2df textureSize(texture->getSize().Width, texture->getSize().Height);
        irr::core::vector2df uvCorner[4];
        uvCorner[0] = irr::core::vector2df(sourceRect.UpperLeftCorner.X,sourceRect.UpperLeftCorner.Y);
        uvCorner[1] = irr::core::vector2df(sourceRect.LowerRightCorner.X,sourceRect.UpperLeftCorner.Y);
        uvCorner[2] = irr::core::vector2df(sourceRect.UpperLeftCorner.X,sourceRect.LowerRightCorner.Y);
        uvCorner[3] = irr::core::vector2df(sourceRect.LowerRightCorner.X,sourceRect.LowerRightCorner.Y);
        for (irr::s32 i = 0; i < 4; i++) 
                uvCorner[i] /= textureSize;
                
        // Vertices for the image
        irr::video::S3DVertex vertices[4];
        irr::u16 indices[6] = { 0, 1, 2, 3 ,2 ,1 };
 
        // Convert pixels to world coordinates
        irr::core::vector2df screenSize(driver->getViewPort().getWidth(), driver->getViewPort().getHeight());
        for (irr::s32 i = 0; i < 4; i++) {
                vertices[i].Pos = irr::core::vector3df(((corner[i].X/screenSize.X)-0.5f)*2.0f,((corner[i].Y/screenSize.Y)-0.5f)*-2.0f,1);
                vertices[i].TCoords = uvCorner[i];
                vertices[i].Color = color;
        }
 
        // Create the material
        // IMPORTANT: For irrlicht 1.8 and above you MUST ADD THIS LINE:
        // material.BlendOperation = irr::video::EBO_ADD;
        irr::video::SMaterial material;
        material.Lighting = false;
        material.ZWriteEnable = false;
        material.ZBuffer = false;
        material.BackfaceCulling = false;
        material.TextureLayer[0].Texture = texture;
        material.MaterialTypeParam = irr::video::pack_texureBlendFunc(irr::video::EBF_SRC_ALPHA, irr::video::EBF_ONE_MINUS_SRC_ALPHA, irr::video::EMFN_MODULATE_1X, irr::video::EAS_TEXTURE | irr::video::EAS_VERTEX_COLOR); 
        //material.BlendOperation = irr::video::EBO_ADD;
        if (useAlphaChannel)
                material.MaterialType = irr::video::EMT_ONETEXTURE_BLEND;
        else
                material.MaterialType = irr::video::EMT_SOLID;
 
        driver->setMaterial(material);
        driver->drawIndexedTriangleList(&vertices[0],4,&indices[0],2);
 
        // Restore projection, world, and view matrices
        driver->setTransform(irr::video::ETS_PROJECTION,oldProjMat);
        driver->setTransform(irr::video::ETS_VIEW,oldViewMat);
        driver->setTransform(irr::video::ETS_WORLD,oldWorldMat);
}
 
