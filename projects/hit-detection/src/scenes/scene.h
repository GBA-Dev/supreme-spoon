#ifndef SCENE_H
#define SCENE_H

#include <memory>
#include <bn_keypad.h>

class Scene {
public:
    Scene() = default;             // Use the default constructor
    virtual ~Scene() = default;    // Use the default destructor

    virtual void update() = 0;     // Pure virtual function to update the scene
    virtual void draw() = 0;       // Pure virtual function to draw the scene
    virtual bool should_transition(std::unique_ptr<Scene>& next_scene) = 0; // Check if we should transition scenes
    
    // Optional virtual function for handling collisions; default implementation does nothing
    virtual void handle_collisions() {}

    // Optional function for handling specific behavior during a scene transition
    virtual void on_transition() {}
};

#endif // SCENE_H
