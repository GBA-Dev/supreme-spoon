#include "gameplay_scene.h"
#include "main_menu_scene.h"
#include "hero.h"
#include "bn_log.h"

GameplayScene::GameplayScene() : _hero()
{
    // Initialization logic for the gameplay scene, if needed.
    // Creating a new hero instance and adding it to the actor list.
    _actors.push_back(&_hero);
    BN_LOG("GameplayScene created.");
}

GameplayScene::~GameplayScene()
{
    // Cleanup logic for the gameplay scene, if needed.
    // delete _hero;
}

void GameplayScene::update()
{
    // Update logic for the gameplay scene, such as handling actors' updates.
    for (Actor* actor : _actors) {
        actor->update();
    }
}

void GameplayScene::draw()
{
    // Draw logic for the gameplay scene, such as rendering actors.
    for (Actor* actor : _actors) {
        actor->draw();
    }
}

bool GameplayScene::should_transition(std::unique_ptr<Scene> &next_scene)
{
    // Logic to determine if the scene should transition.
    // For now, let's just return true if a specific condition is met, e.g., pressing start button.
    if (bn::keypad::start_pressed())
    {
        BN_LOG("Start button pressed. Transitioning to the next scene.");
        next_scene = std::make_unique<MainMenuScene>();
        return true;
    }
    return false;
}