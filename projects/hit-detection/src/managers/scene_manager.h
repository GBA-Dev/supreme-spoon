#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "scene.h"
#include <memory>

namespace SceneManagerNamespace {
    enum class SceneType {
        MainMenu,
        Gameplay,
        None  // No transition
    };
}

class SceneManager
{
public:
    SceneManager();
    ~SceneManager();

    void set_scene(std::unique_ptr<Scene> new_scene);
    void update();
    void draw();

private:
    std::unique_ptr<Scene> current_scene_;
    SceneManagerNamespace::SceneType next_scene_type_;
    bool transitioning_;
};

#endif // SCENE_MANAGER_H
