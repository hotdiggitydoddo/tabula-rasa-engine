#pragma once

#include <string>
#include <OpenGl/gl3.h>
#include "Errors.h"

namespace TabulaRasa
{
class GLSLProgram
{
public:
    GLSLProgram();
    ~GLSLProgram();

    void CompileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath);
    void LinkShaders();
    void AddAttribute(const std::string& attributeName);
    void Use();
    void Unuse();
    GLint GetUniformLocation(const std::string& uniformName);

private:
    GLuint _programId;
    GLuint _vertexShaderId;
    GLuint _fragmentShaderId;

    int _numAttributes;

    void CompileShader(const std::string& filePath, GLuint& id);
};
}

