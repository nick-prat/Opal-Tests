#include "sunsystem.hh"

#include <glm/glm.hpp>

SunSystem::SunSystem(Opal::WorldLight& worldLight)
: m_worldLight(worldLight) {}

void SunSystem::update(Emerald::EntityManager& entMan) {
    m_angle += 0.01;
    m_worldLight.setSunLocation({glm::sin(m_angle), glm::cos(m_angle), 1.0f});
}
