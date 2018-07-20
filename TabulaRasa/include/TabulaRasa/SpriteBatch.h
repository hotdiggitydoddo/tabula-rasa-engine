#pragma once

#include <OpenGL/gl3.h>
#include <glm/glm.hpp>
#include <vector>
#include "Vertex.h"

namespace TabulaRasa
{

enum class GlyphSortType
{
    NONE,
    FRONT_TO_BACK,
    BACK_TO_FRONT,
    TEXTURE
};

struct Glyph
{
    GLuint texture;
    float depth;

    Vertex topLeft;
    Vertex bottomLeft;
    Vertex topRight;
    Vertex bottomRight;
};

struct RenderBatch
{
    RenderBatch(GLuint offset, GLuint numVertices, GLuint texture)
        : offset(offset), numVertices(numVertices), texture(texture) { }

    GLuint offset;
    GLuint numVertices;
    GLuint texture;
};

class SpriteBatch
{
public:
    SpriteBatch();
    ~SpriteBatch();

    void Init();

    void Begin(GlyphSortType sortType = GlyphSortType::TEXTURE);
    void End();

    void Draw(const glm::vec4& destRect, const glm::vec4& uvRect, GLuint texture, float depth, const Color& color);

    void Render();

private:
    void CreateRenderBatches();
    void CreateVertexArray();
    void SortGlyphs();

    GLuint _vbo;
    GLuint _vao;

    GlyphSortType _sortType;

    std::vector<Glyph*> _glyphs;
    std::vector<RenderBatch> _renderBatches;
};
}


