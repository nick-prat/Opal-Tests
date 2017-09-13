#include "scene.hh"

using namespace Opal;

TestScene::TestScene(Display& display, const std::string& name)
: Scene(display, name) {
    m_display.setCursorCapture(true);
    m_display.setCursorPosition({0.0, 0.0});

    m_display.bindCursorUpdate([&display = m_display](int xpos, int ypos) {
        display.getCamera().rotateCamera({ypos / 500.0f, xpos / 500.0f, 0.0f});
        display.setCursorPosition({0.0f, 0.0f});
    });

    m_display.bindWhileKeyPressed(InputKey::D, [&camera = m_display.getCamera()](InputKey key) {
        auto dir = camera.getDirection();
        camera.moveCamera({-dir.z * 0.1f, 0.0f, dir.x * 0.1f});
    });

    m_display.bindWhileKeyPressed(InputKey::A, [&camera = m_display.getCamera()](InputKey key) {
        auto dir = camera.getDirection();
        camera.moveCamera({dir.z * 0.1f, 0.0f, -dir.x * 0.1f});
    });

    m_display.setWireFrame(true);
    m_entityManager.registerSystem<NormalRenderSystem>(m_assetStore.getShader(NormalRenderSystem::shaderName), m_display, m_worldLight);
}
