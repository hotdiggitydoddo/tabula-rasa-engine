#pragma once

#include <unordered_map>
#include <glm/glm.hpp>

namespace TabulaRasa
{

class InputManager
{
public:
    InputManager();
    ~InputManager();

    void PressKey(unsigned int keyId);
    void ReleaseKey(unsigned int keyId);

    bool IsKeyPressed(unsigned int keyId);

    void SetMouseCoords(float x, float y);

    // getters
    glm::vec2 GetMouseCoords() const { return _mouseCoords; }

private:
    glm::vec2 _mouseCoords;
    std::unordered_map<unsigned int, bool> _keyMap;
};

}


