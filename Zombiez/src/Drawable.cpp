#include "Drawable.h"

#include <TabulaRasa/ResourceManager.h>

Drawable::Drawable(glm::vec2 pos, const std::string& texturePath, float scale, TabulaRasa::Color color)
    : _scale(scale), _color(color)
{
    _position = pos;
    _texture = TabulaRasa::ResourceManager::GetTexture(texturePath);
}

void Drawable::Draw(TabulaRasa::SpriteBatch& spriteBatch)
{
    glm::vec2 origin = GetOrigin();
    glm::vec4 pos((_position.x) * _scale, (_position.y) * _scale, _texture.width * _scale, _texture.height * _scale);
    glm::vec4 uv(0.0f, 0.0f, 1.0f, 1.0f);

    spriteBatch.Draw(pos, uv, _texture.id, 0.0f, _color);
}

Drawable::Drawable()
{

}

glm::vec2 Drawable::GetOrigin()
{
    return glm::vec2((_texture.width / 2) * _scale, (_texture.height / 2) * _scale);
}
