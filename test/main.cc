#include <iostream>
#include <memory>

#include <Opal/Core/display.hh>
#include <Opal/Util/exceptions.hh>
#include <Opal/Util/log.hh>
#include <Opal/Core/glcore.hh>

#include "scene.hh"

using namespace Opal;

// TODO Ensure const correctness is follwed in whole project
// TODO Implement some sort of collsion detection (bullet physics library?)

int main(int argc, char* argv[]) {
    std::string const scenename = "test";
    std::string const title = "OpenGL Project";
    constexpr int width = 1024;
    constexpr int height = 576;

    GLCore glCore{width, height, title};

    auto& display = glCore.getDisplay();
    display.setCursorCapture(true);
    display.setClearColor(glm::vec4(0.0f));
    display.setVsync(true);

    glCore.loadScene<TestScene>(scenename);
    glCore.start();

    return 0;
}
