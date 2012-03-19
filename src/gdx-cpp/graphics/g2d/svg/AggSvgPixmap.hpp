/*
 *  Copyright 2011 Aevum Software aevum @ aevumlab.com
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  @author Victor Vicente de Carvalho victor.carvalho@aevumlab.com
 *  @author Ozires Bortolon de Faria ozires@aevumlab.com
 *  @author aevum team
 */

#ifndef GDX_CPP_GRAPHICS_G2D_AGGSVGPIXMAP_HPP
#define GDX_CPP_GRAPHICS_G2D_AGGSVGPIXMAP_HPP

#include <stdexcept>

#include "SvgPixmapInterface.hpp"
#include "gdx-cpp/graphics/Pixmap.hpp"
#include "gdx-cpp/Files.hpp"
#include "gdx-cpp/utils/XmlReader.hpp"
#include "SvgParser.hpp"


namespace gdx_cpp {

namespace graphics {

namespace g2d {

namespace svg {

/** Implements the SvgPixmapInterface using the AntiGrains Svg backend
 *
 */
class AggSvgPixmap : public SvgPixmapInterface
{
public:
    static AggSvgPixmap* newFromFile(const files::FileHandle::ptr& file) {
        static utils::XmlReader reader;

        AggSvgPixmap* pix = new AggSvgPixmap;
        SvgParser::render(reader.parse(*file).get(), pix);

        return pix;
    }

    AggSvgPixmap();

    AggSvgPixmap(int width, int height);

    void setImageDimension(int width, int height) ;

    void begin() ;

    void beginPath() ;

    void closeSubPath() ;

    void curve3(float x, float y, bool relative = false) ;

    void curve3(float x, float y, float x1, float y1, bool relative = false) ;

    void curve4(float x2, float y2, float x, float y, bool relative = false) ;

    void curve4(float x1, float y1, float x2, float y2, float x, float y, bool relative = false) ;

    void end() ;

    void endPath() ;

    virtual void fill();

    void fillNone() ;

    void fillOpacity(float opactiy) ;

    void horizontalLineTo(float x, bool relative = false) ;

    void lineTo(float x, float y, bool relative = false) ;

    void moveTo(float x, float y, bool relative = false) ;

    void setLineCap(LineCap cap) ;

    void setLineJoin(LineJoin join) ;

    void setMiterLimit(float limit) ;

    void setSkew(float skewX, float skewY) ;

    void setStrokeOpacity(float opacit) ;

    void setStrokeWidth(float width) ;

    void stroke(Color color) ;

    void strokeNone() ;

    void verticalLineTo(float y, bool relative = false) ;

    void setScale(float scaleX, float scaleY) ;

    void dispose() ;

    void drawCircle(int x, int y, int radius) ;

    void drawLine(int x, int y, int x2, int y2) ;

    void drawPixel(int x, int y) ;

    void drawPixmap(const gdx_cpp::graphics::Pixmap& pixmap, int x, int y, int srcx, int srcy, int srcWidth, int srcHeight) ;

    void drawPixmap(const gdx_cpp::graphics::Pixmap& pixmap, int srcx, int srcy, int srcWidth, int srcHeight, int dstx, int dsty, int dstWidth, int dstHeight) ;

    void drawRectangle(int x, int y, int width, int height) ;

    void fill(Color color) ;

    void fillCircle(int x, int y, int radius) ;

    void fillRectangle(int x, int y, int width, int height) ;

    const gdx_cpp::graphics::Pixmap::Format& getFormat() ;

    int getGLFormat() const ;

    int getGLInternalFormat() const ;

    int getGLType() const ;

    int getHeight() const ;

    int getPixel(int x, int y) const ;

    const unsigned char* getPixels() ;

    void setColor(float r, float g, float b, float a) ;

    virtual void fillRadialGradient(const gdx_cpp::utils::SvgRendererHandler::RadialGradient& gradient) ;

    virtual void fillLinearGradient(const gdx_cpp::utils::SvgRendererHandler::LinearGradient& gradient) ;

    void setColor(const gdx_cpp::graphics::Color& color) ;

    PixmapType getType() const ;

    int getWidth() const ;

    void setStrokeWidth(int width) ;

    ~AggSvgPixmap() ;

    virtual transform* createTransform() ;

    virtual transform& currentTransform() ;

private:
    AggSvgPixmap(const AggSvgPixmap& other);
    
    struct impl;
    impl* pimpl;

    float scaleX,scaleY;
    int width;
    int height;
    unsigned char* data;
};

}

}

}

}
#endif // GDX_CPP_GRAPHICS_G2D_AGGSVGPIXMAP_HPP
