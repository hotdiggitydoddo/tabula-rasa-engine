#include "ResourceManager.h"

namespace TabulaRasa
{
TextureCache ResourceManager::_textureCache;

GLTexture ResourceManager::GetTexture(const std::string& filePath)
{
    return _textureCache.GetTexture(filePath);
}
}
