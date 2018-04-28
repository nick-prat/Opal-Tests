#include "systems.hh"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

SunSystem::SunSystem(Opal::WorldLight& worldLight)
: m_worldLight(worldLight) {}

void SunSystem::update(Emerald::EntityManager& entMan) {
    m_angle += 0.01;
    m_worldLight.setSunLocation({glm::sin(m_angle), glm::cos(m_angle), 1.0f});
}

XYZSystem::XYZSystem(Opal::Shader const& shader, Opal::Display const& display)
: RenderSystem(shader, display) {
    glGenVertexArrays(1, &m_vao);
    glGenBuffers(1, &m_ibo);
    glGenBuffers(1, &m_vbo);

    std::array<glm::vec3, 6> const data {{
        {-1000.0f, 0.0f, 0.0f}, {1000.0f, 0.0f, 0.0f},
        {0.0f, -1000.0f, 0.0f}, {0.0f, 1000.0f, 0.0f},
        {0.0f, 0.0f, -1000.0f}, {0.0f, 0.0f, 1000.0f}
    }};

    std::array<unsigned int, 6> const indices {{
        0, 1, 2, 3, 4, 5
    }};

    glBindVertexArray(m_vao);

    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * data.size(), data.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), indices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), 0);
    glEnableVertexAttribArray(0);
}

void XYZSystem::update(Emerald::EntityManager& entMan) {
    m_shader.useProgram();
    auto pv = m_display.getProjectionMatrix() * m_display.getCamera().getViewMatrix();
    glUniformMatrix4fv(m_shader.getUniformLocation("gMVP"), 1, GL_FALSE, glm::value_ptr(pv));
    glBindVertexArray(m_vao);
    glDrawElements(GL_LINES, (GLsizei)m_indexCount, GL_UNSIGNED_INT, nullptr);
}
