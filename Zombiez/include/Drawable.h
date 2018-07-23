#pragma once

#include <TabulaRasa/SpriteBatch.h>
#include <TabulaRasa/GLTexture.h>
#include <TabulaRasa/Vertex.h>
#include <string>
#include <glm/glm.hpp>
#include "GameObject.h"

class Drawable : public GameObject
{
public:
    Drawable();
    Drawable(glm::vec2 pos, const std::string& texturePath, float scale = 1, TabulaRasa::Color color = {255, 255, 255, 255});
    void Draw(TabulaRasa::SpriteBatch& spriteBatch);

    glm::vec2 GetOrigin();

protected:
    float _scale;
    TabulaRasa::Color _color;

private:
    TabulaRasa::GLTexture _texture;

};