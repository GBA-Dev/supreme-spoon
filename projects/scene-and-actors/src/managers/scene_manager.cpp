// scene_manager.cpp ------------------------------------------------------------
#include "scene_manager.h"

SceneManager::SceneManager() : current_scene_(nullptr) {
    // Initialization logic for the scene manager, if needed.
}

SceneManager::~SceneManager() {
    // Cleanup logic for the scene manager, if needed.
}

void SceneManager::set_scene(std::unique_ptr<Scene> new_scene) {
    current_scene_ = std::move(new_scene);
}

void SceneManager::update() {
    if (current_scene_) {
        current_scene_->update();
    }
}

void SceneManager::draw() {
    if (current_scene_) {
        current_scene_->draw();
    }
}
