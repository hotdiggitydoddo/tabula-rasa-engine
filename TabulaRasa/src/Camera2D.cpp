#include "Camera2D.h"
#include "../../Zombiez/include/Drawable.h"

namespace TabulaRasa
{
Camera2D::Camera2D()
    :
    _position(0.0f, 0.0f),
    _cameraMatrix(1.0f),
    _orthoMatrix(1.0f),
    _scale(1.0f),
    _needsMatrixUpdate(true),
    _screenWidth(500),
    _screenHeight(500)
{
}

Camera2D::~Camera2D()
{
}

void SetTarget(const Drawable& drawable)
{

}

void Camera2D::Update()
{
    if (!_needsMatrixUpdate)
        return;

    // Camera Translation
    //glm::vec3 translate(-_position.x + _screenWidth / 2, -_position.y + _screenHeight / 2, 0.0f);
    glm::vec3 translate(-_position.x, -_position.y, 0.0f);
    _cameraMatrix = glm::translate(_orthoMatrix, translate);

    // Camera Scale
    glm::vec3 scale(_scale, _scale, 0.0f);
    _cameraMatrix = glm::scale(glm::mat4(1.0f), scale) * _cameraMatrix;
    _cameraMatrix = glm::translate(_orthoMatrix, glm::vec3(_screenWidth * .5f, _screenHeight * .5f, 0.0f));

    _needsMatrixUpdate = false;
}

void Camera2D::Init(int screenWidth, int screenHeight)
{
    _screenWidth = screenWidth;
    _screenHeight = screenHeight;
    //_orthoMatrix = glm::ortho(0.0f, static_cast<float>(_screenWidth), 0.0f, (float) static_cast<float>(_screenHeight));
    _orthoMatrix = glm::ortho(0.0f, static_cast<float>(_screenWidth), (float) static_cast<float>(_screenHeight), 0.0f);

}

glm::vec2 Camera2D::ScreenToWorld(glm::vec2 screenCoords)
{
    // Invert Y direction
    screenCoords.y   = _screenHeight - screenCoords.y;
    // make it so 0 is the center
    screenCoords -= glm::vec2(_screenWidth / 2, _screenHeight / 2);

    // scale the coords
    screenCoords /= _scale;

    // translate with the camera position
    screenCoords += _position;

    return screenCoords;
}

}
