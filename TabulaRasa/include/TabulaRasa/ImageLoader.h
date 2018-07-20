#pragma once

#include <string>
#include "GLTexture.h"

namespace TabulaRasa
{
class ImageLoader
{
public:
    static GLTexture LoadPNG(const std::string& filePath);
};
}


