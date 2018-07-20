#include "Sprite.h"
#include "Vertex.h"
#include "ResourceManager.h"

#include <cstddef>

namespace TabulaRasa
{
Sprite::Sprite()
{
    _x = _y = _width = _height = 0;
    _vboId = 0;
}

Sprite::~Sprite()
{
    if (_vboId != 0)
    {
        glDeleteBuffers(1, &_vboId);
    }
}

void Sprite::Init(float x, float y, float w, float h, const std::string& texturePath)
{
    _x = x;
    _y = y;
    _width = w;
    _height = h;
    _texture = ResourceManager::GetTexture(texturePath);


    if (_vboId == 0)
    {
        glGenBuffers(1, &_vboId);
    }

    Vertex vertexData[6];

    // first triangle
    vertexData[0].setPosition(x + _width, y + _height);
    vertexData[0].setUV(1.0f, 1.0f);

    vertexData[1].setPosition(x, y + _height);
    vertexData[1].setUV(0.0f, 1.0f);


    vertexData[2].setPosition(x, y);
    vertexData[2].setUV(0.0f, 0.0f);

    // second triangle
    vertexData[3].setPosition(x, y);
    vertexData[3].setUV(0.0f, 0.0f);

    vertexData[4].setPosition(x + _width, y);
    vertexData[4].setUV(1.0f, 0.0f);

    vertexData[5].setPosition(x + _width, y + _height);
    vertexData[5].setUV(1.0f, 1.0f);

    for (int i = 0; i < 6; i++)
    {
        vertexData[i].setColor(255, 0, 255, 255);
    }

    vertexData[1].setColor(0, 0, 255, 255);
    vertexData[4].setColor(0, 255, 0, 255);


    glBindBuffer(GL_ARRAY_BUFFER, _vboId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

    // unbind the buffer once vertices are uploaded to GPU
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void Sprite::Draw()
{
    // Bind the texture
    glBindTexture(GL_TEXTURE_2D, _texture.id);

    // Bind the buffer object
    glBindBuffer(GL_ARRAY_BUFFER, _vboId);


    // Draw the 6 vertices to the screen
    glDrawArrays(GL_TRIANGLES, 0, 6);

    // Disable the vertex attrib array.  Not optional.
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);

    // Unbind the VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
}


