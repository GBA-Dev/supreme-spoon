#include "scene_manager.h"

#include "gameplay_scene.h"
#include "main_menu_scene.h"

SceneManager::SceneManager() : transitioning_(false) {}

SceneManager::~SceneManager() {}

void SceneManager::set_scene(std::unique_ptr<Scene> new_scene) {
    current_scene_ = std::move(new_scene);
}

void SceneManager::update() {
    // Check if currently transitioning
    if (transitioning_) {
        // Complete the transition: instantiate the new scene
        set_scene(std::move(next_scene_));
        transitioning_ = false;  // Reset transition state
    }

    if(current_scene_) {
        current_scene_->update();
    }
}

void SceneManager::draw() {
    if(current_scene_) {
        current_scene_->draw();

        // Check if the scene should transition dynamically.
        if (!transitioning_ && current_scene_->should_transition(next_scene_)) {
            // Initiate the transition by cleaning up the current scene
            current_scene_.reset();  // Destroy the current scene
            transitioning_ = true;   // Mark as transitioning to the next scene
        }
    }
}