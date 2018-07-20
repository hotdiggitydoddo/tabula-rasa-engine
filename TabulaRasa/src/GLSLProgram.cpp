#include "GLSLProgram.h"

#include <fstream>
#include <vector>

namespace TabulaRasa
{
GLSLProgram::GLSLProgram()
    : _numAttributes(0), _programId(0), _vertexShaderId(0), _fragmentShaderId(0)
{
}

GLSLProgram::~GLSLProgram()
{

}

void GLSLProgram::CompileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath)
{
    _programId = glCreateProgram();

    _vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
    if (_vertexShaderId == 0)
    {
        FatalError("Vertex shader failed to be created!");
    }

    _fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
    if (_fragmentShaderId == 0)
    {
        FatalError("Fragment shader failed to be created!");
    }

    CompileShader(vertexShaderFilePath, _vertexShaderId);
    CompileShader(fragmentShaderFilePath, _fragmentShaderId);
}

void GLSLProgram::LinkShaders()
{
    glAttachShader(_programId, _vertexShaderId);
    glAttachShader(_programId, _fragmentShaderId);

    glLinkProgram(_programId);

    GLint isLinked = 0;
    glGetProgramiv(_programId, GL_LINK_STATUS, (int*) &isLinked);
    if (isLinked == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetProgramiv(_programId, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<GLchar> infoLog(maxLength);
        glGetProgramInfoLog(_programId, maxLength, &maxLength, &infoLog[0]);

        glDeleteProgram(_programId);
        std::printf("%s\n", &infoLog[0]);
        FatalError("Shader program failed to link!");
    }

    glDetachShader(_programId, _vertexShaderId);
    glDetachShader(_programId, _fragmentShaderId);
    glDeleteShader(_vertexShaderId);
    glDeleteShader(_fragmentShaderId);
}

void GLSLProgram::CompileShader(const std::string& filePath, GLuint& id)
{
    std::ifstream shaderFile(filePath);
    if (shaderFile.fail())
    {
        perror(filePath.c_str());
        FatalError("Failed to open " + filePath);
    }

    std::string fileContents = "";
    std::string line;

    while (std::getline(shaderFile, line))
    {
        fileContents += line + "\n";
    }

    shaderFile.close();

    const char* contents = fileContents.c_str();
    glShaderSource(id, 1, &contents, nullptr);

    glCompileShader(id);

    GLint success = 0;
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<char> errorLog(maxLength);
        glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

        glDeleteShader(id);

        std::printf("%s\n", &errorLog[0]);
        FatalError("Shader " + filePath + " failed to compile!");
    }

}

void GLSLProgram::AddAttribute(const std::string& attributeName)
{
    glBindAttribLocation(_programId, _numAttributes++, attributeName.c_str());
}

void GLSLProgram::Use()
{
    glUseProgram(_programId);
    for (int i = 0; i < _numAttributes; i++)
    {
        glEnableVertexAttribArray(i);
    }
}

void GLSLProgram::Unuse()
{
    glUseProgram(0);
    for (int i = 0; i < _numAttributes; i++)
    {
        glDisableVertexAttribArray(i);
    }
}

GLint GLSLProgram::GetUniformLocation(const std::string& uniformName)
{
    GLint location = glGetUniformLocation(_programId, uniformName.c_str());

    if (location == GL_INVALID_INDEX)
    {
        FatalError("Uniform " + uniformName + " not found in shader!");
    }

    return location;
}
}

