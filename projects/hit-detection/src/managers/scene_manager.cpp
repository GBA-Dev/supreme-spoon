#include "scene_manager.h"
#include "gameplay_scene.h"
#include "main_menu_scene.h"

SceneManager::SceneManager() 
    : transitioning_(false), next_scene_type_(SceneManagerNamespace::SceneType::None) {}

SceneManager::~SceneManager() {}

void SceneManager::set_scene(std::unique_ptr<Scene> new_scene) {
    current_scene_ = std::move(new_scene);
}

void SceneManager::update() {
    // If we're in a transitioning state, instantiate the next scene now
    if (transitioning_) {
        switch (next_scene_type_) {
            case SceneManagerNamespace::SceneType::Gameplay:
                set_scene(std::make_unique<GameplayScene>());
                break;
            case SceneManagerNamespace::SceneType::MainMenu:
                set_scene(std::make_unique<MainMenuScene>());
                break;
            case SceneManagerNamespace::SceneType::None:
            default:
                break;
        }

        transitioning_ = false;  // Reset transition state
        next_scene_type_ = SceneManagerNamespace::SceneType::None;
    }

    if (current_scene_) {
        current_scene_->update();
    }
}

void SceneManager::draw() {
    if (current_scene_) {
        current_scene_->draw();

        // Check if the scene should transition dynamically.
        SceneManagerNamespace::SceneType next_type = SceneManagerNamespace::SceneType::None;
        if (!transitioning_ && current_scene_->should_transition(next_type)) {
            // Mark the transition and destroy the current scene
            current_scene_.reset();  // Destroy the current scene and release resources
            transitioning_ = true;   // Mark as transitioning to the next scene
            next_scene_type_ = next_type;
        }
    }
}