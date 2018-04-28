#ifndef _SUN_SYSTEM_H
#define _SUN_SYSTEM_H

#include <Opal/Render/light.hh>
#include <Emerald/emerald.hh>
#include <Opal/Systems/rendersystem.hh>

class SunSystem : public Emerald::ISystem<SunSystem> {
public:
    SunSystem(Opal::WorldLight& worldLight);

    void update(Emerald::EntityManager& entMan) override final;

private:
    Opal::WorldLight& m_worldLight;
    float m_angle;
};

class XYZSystem : public Opal::RenderSystem<XYZSystem> {
public:
    XYZSystem(Opal::Shader const& shader, Opal::Display const& display);

    void update(Emerald::EntityManager& entMan) override final;

private:
    GLuint m_vbo, m_ibo, m_vao;
    static constexpr int m_indexCount = 6;
};

#endif // _SUN_SYSTEM_H
