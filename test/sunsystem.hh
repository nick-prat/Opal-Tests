#ifndef _SUN_SYSTEM_H
#define _SUN_SYSTEM_H

#include <Opal/Render/light.hh>
#include <Emerald/emerald.hh>

class SunSystem : public Emerald::ISystem<SunSystem> {
public:
    SunSystem(Opal::WorldLight& worldLight);

    void update(Emerald::EntityManager& entMan) override final;

private:
    Opal::WorldLight& m_worldLight;
    float m_angle;
};

#endif // _SUN_SYSTEM_H
