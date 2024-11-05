#ifndef SCENE_H
#define SCENE_H

#include <memory>
#include <bn_keypad.h>

class Scene {
public:
    Scene();
    virtual ~Scene();

    virtual void update() = 0;
    virtual void draw() = 0;
    virtual bool should_transition(std::unique_ptr<Scene>& next_scene) = 0;
};

#endif // SCENE_H