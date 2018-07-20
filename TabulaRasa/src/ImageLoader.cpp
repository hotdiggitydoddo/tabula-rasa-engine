#include "ImageLoader.h"
#include "picoPNG.h"
#include "IOManager.h"
#include "Errors.h"

namespace TabulaRasa
{
GLTexture ImageLoader::LoadPNG(const std::string& filePath)
{
    // Create a GLTexture and init all the fields to 0
    GLTexture texture = {};

    // This is the input data to decodePNG, which we load from a file
    std::vector<unsigned char> in;
    // This is the output data from decodePNG, which is the pixel data for out texture
    std::vector<unsigned char> out;

    unsigned long width, height;

    // Read in the image file contents into a buffer
    if (!IOManager::ReadFileToBuffer(filePath, in))
    {
        FatalError("Failed to load PNG file \"" + filePath + "\" to buffer!");
    }

    // Decode the .png format into an array of pixels
    int errorCode = decodePNG(out, width, height, &in[0], in.size());
    if (errorCode != 0)
    {
        FatalError("decodePNG filed with error: " + errorCode);
    }

    // Generate the openGL texture object
    glGenTextures(1, &texture.id);

    // Bind the texture object
    glBindTexture(GL_TEXTURE_2D, texture.id);
    // Upload the pixel data to the texture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &out[0]);

    // Set some texture params
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    // Generate the mipmap
    glGenerateMipmap(GL_TEXTURE_2D);

    // Unbind the texture object
    glBindTexture(GL_TEXTURE_2D, 0);

    texture.width = width;
    texture.height = height;

    // Return a copy of the texture data
    return texture;
}
}


