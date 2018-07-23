#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Drawable.h"

namespace TabulaRasa
{
class Camera2D
{
public:
    Camera2D();
    ~Camera2D();

    // Sets up the orthographic matrix and dimensions
    void Init(int screenWidth, int screenHeight);

    // Updates the camera matrix if needed
    void Update();

    glm::vec2 ScreenToWorld(glm::vec2 screenCoords);
    void SetTarget(Drawable* drawable);

    // setters
    void SetPosition(const glm::vec2& newPos)
    {
        _position = newPos;
        _needsMatrixUpdate = true;
    }
    void SetScale(float newScale)
    {
        _scale = newScale;
        _needsMatrixUpdate = true;
    }
    void SetBounds(glm::vec4 bounds)
    {
        _worldBounds = bounds;
    }


    // getters
    glm::vec2 GetPosition()
    { return _position; }
    float GetScale()
    { return _scale; }
    glm::mat4 GetCameraMatrix()
    { return _cameraMatrix; }
    glm::vec2 GetOrigin()
    { return glm::vec2(_screenWidth * .5f, _screenHeight * .5f);}

private:
    void ClampCameraToWorldBounds();

    int _screenWidth, _screenHeight;
    bool _needsMatrixUpdate;
    glm::vec4 _worldBounds;
    glm::vec2 _position;
    glm::mat4 _cameraMatrix;
    glm::mat4 _orthoMatrix;
    float _scale;
    Drawable* _target;
};
}


