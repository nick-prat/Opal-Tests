#include "scene.hh"

#include <Opal/Components/components.hh>
#include <Opal/Util/util.hh>

#include "sunsystem.hh"

using namespace Opal;

TestScene::TestScene(Display& display, const std::string& name)
: Scene(display, name) {
    m_display.setCursorCapture(true);
    m_display.setCursorPosition({0.0, 0.0});
    m_display.setWireFrame(false);

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

    m_display.bindOnKeyPressed(InputKey::ESC, [&display = m_display] (const InputKey key) {
        display.exit();
    });

    // m_display.setSize(400, 400);

    // m_entityManager.registerSystem<SunSystem>(m_worldLight);

    auto id = m_entityManager.createEntity();
    m_entityManager.createComponent<CRender>(id, m_assetStore.getModel3D("deer"));
    m_entityManager.createComponent<CBody>(id, glm::vec3{0.0f, 0.0f, 0.0f});
}
