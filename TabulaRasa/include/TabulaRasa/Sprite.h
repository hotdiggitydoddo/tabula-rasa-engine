#pragma once

#include <OpenGL/gl3.h>
#include <string>
#include "GLTexture.h"

namespace TabulaRasa
{
class Sprite
{
public:
    Sprite();
    ~Sprite();

    void Init(float x, float y, float w, float h, const std::string& texturePath);
    void Draw();

private:
    float _width, _height;
    float _x, _y;
    GLuint _vboId;
    GLTexture _texture;
};
}


