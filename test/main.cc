#include <iostream>
#include <memory>

#include <Opal/Core/display.hh>
#include <Opal/Util/exceptions.hh>
#include <Opal/Util/log.hh>
#include <Opal/Core/glcore.hh>

#include "scene.hh"

// TODO Ensure const correctness is follwed in whole project
// TODO Implement some sort of collsion detection (bullet physics library?)

int main(int argc, char* argv[]) {
    if(argc != 2) {
        Log::getErrorLog() << "Arguments are invalid, use:\n\t" << argv[0] << " [scene_name]\n";
        return -1;
    }

    const std::string scenename = argv[1];
    const std::string title = "OpenGL Project";
    constexpr int width = 1024;
    constexpr int height = 576;

    GLCore glCore;
    try {
        glCore = GLCore(width, height, title);
    } catch(GenericException& error) {
        error.printError();
        return 1;
    }

    glCore.getDisplay().setMouseCapture(false);
    glCore.getDisplay().setClearColor(glm::vec4(0.0f));
    glCore.getDisplay().setVsync(true);

    glCore.loadScene<TestScene>(scenename);
    glCore.start();

    return 0;
}
