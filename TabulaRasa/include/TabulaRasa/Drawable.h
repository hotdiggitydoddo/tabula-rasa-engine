#pragma once

#include "SpriteBatch.h"
#include "GLTexture.h"
#include "Vertex.h"
#include <string>
#include <glm/glm.hpp>
#include "GameObject.h"

namespace TabulaRasa
{
class Drawable : public GameObject
{
public:
    Drawable();
    Drawable(glm::vec2 pos, const std::string& texturePath, float scale = 1, Color color = {255, 255, 255, 255});
    void Draw(SpriteBatch& spriteBatch);

    glm::vec2 GetOrigin() const;

protected:
    float _scale;
    TabulaRasa::Color _color;

private:
    TabulaRasa::GLTexture _texture;

};
}
