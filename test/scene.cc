#include "scene.hh"

#include <Opal/Components/components.hh>

using namespace Opal;

TestScene::TestScene(Display& display, const std::string& name)
: Scene(display, name) {
    m_display.setCursorCapture(true);
    m_display.setCursorPosition({0.0, 0.0});

    m_display.bindCursorUpdate([&display = m_display](const float xpos, const float ypos) {
        display.getCamera().rotateCamera({ypos / 500.0f, xpos / 500.0f, 0.0f});
        display.setCursorPosition({0.0f, 0.0f});
    });

    m_display.bindWhileKeyPressed(InputKey::W, [&camera = m_display.getCamera()] (const InputKey key) {
        camera.moveCamera(camera.getDirection());
    });

    m_display.bindWhileKeyPressed(InputKey::S, [&camera = m_display.getCamera()] (const InputKey key) {
        camera.moveCamera(camera.getDirection() * -1.0f);
    });

    m_display.bindWhileKeyPressed(InputKey::D, [&camera = m_display.getCamera()] (const InputKey key) {
        camera.moveCamera(glm::cross(camera.getDirection(), camera.getUpDirection()));
    });

    m_display.bindWhileKeyPressed(InputKey::A, [&camera = m_display.getCamera()] (const InputKey key) {
        camera.moveCamera(glm::cross(camera.getUpDirection(), camera.getDirection()));
    });

    m_display.setWireFrame(true);

    const auto& textures = m_assetStore.getTextures();
    for(const auto& [name, tex] : textures) {
        std::cout << name << '\n';
    }

    auto id = m_entityManager.createEntity();
    m_entityManager.createComponent<CRender>(id, m_assetStore.getModel3D("deer"));
    m_entityManager.createComponent<CBody>(id, glm::vec3{0.0f, 0.0f, 0.0f});
}
