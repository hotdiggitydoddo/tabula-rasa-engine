#pragma once

#include "TextureCache.h"
#include<string>

namespace TabulaRasa
{
class ResourceManager
{
public:
    static GLTexture GetTexture(const std::string& filePath);

private:
    static TextureCache _textureCache;
};
}

