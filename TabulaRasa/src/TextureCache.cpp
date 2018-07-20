#include "TextureCache.h"
#include "ImageLoader.h"

namespace TabulaRasa
{
TextureCache::TextureCache()
{

}

TextureCache::~TextureCache()
{

}

GLTexture TextureCache::GetTexture(const std::string& filePath)
{
    // Lookup the texture and see if it's in the map
    auto iter = _textureMap.find(filePath);

    // Check if it's not in the map
    if (iter == _textureMap.end())
    {
        // Load and insert it into the map
        GLTexture newTexture = ImageLoader::LoadPNG(filePath);
        _textureMap.insert(make_pair(filePath, newTexture));

        return newTexture;
    }

    return iter->second;
}
}


