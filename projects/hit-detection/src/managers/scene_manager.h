#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "scene.h"
#include <memory>

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
    // transitioning_
    std::unique_ptr<Scene> next_scene_;
    bool transitioning_;
};

#endif // SCENE_MANAGER_H
