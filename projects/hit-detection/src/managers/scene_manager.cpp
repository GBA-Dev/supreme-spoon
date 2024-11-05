#include "scene_manager.h"

#include "gameplay_scene.h"
#include "main_menu_scene.h"

SceneManager::SceneManager() {}

SceneManager::~SceneManager() {}

void SceneManager::set_scene(std::unique_ptr<Scene> new_scene) {
    current_scene_ = std::move(new_scene);
}

void SceneManager::update() {
    if(current_scene_) {
        current_scene_->update();
    }
}

void SceneManager::draw() {
    if(current_scene_) {
        current_scene_->draw();

        // Check if the scene should transition dynamically.
        std::unique_ptr<Scene> next_scene;
        if (current_scene_->should_transition(next_scene)) {
            set_scene(std::move(next_scene));
        }
    }
}