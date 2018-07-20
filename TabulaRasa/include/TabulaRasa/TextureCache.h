#pragma once

#include <map>
#include "GLTexture.h"

namespace TabulaRasa
{
class TextureCache
{
public:
    TextureCache();
    ~TextureCache();
    GLTexture GetTexture(const std::string& filePath);

private:
    std::map<std::string, GLTexture> _textureMap;
};
}

