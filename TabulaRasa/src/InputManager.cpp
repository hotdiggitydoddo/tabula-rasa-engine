#include "InputManager.h"

namespace TabulaRasa
{

InputManager::InputManager() : _mouseCoords(0.0f, 0.0f)
{

}

InputManager::~InputManager()
{

}

void InputManager::PressKey(unsigned int keyId)
{
    _keyMap[keyId] = true;
}

void InputManager::ReleaseKey(unsigned int keyId)
{
    _keyMap[keyId] = false;
}

bool InputManager::IsKeyPressed(unsigned int keyId)
{
    auto iter = _keyMap.find(keyId);

    if (iter != _keyMap.end())
        return iter->second;
    return false;
}

void InputManager::SetMouseCoords(float x, float y)
{
    _mouseCoords.x = x;
    _mouseCoords.y = y;
}

}

