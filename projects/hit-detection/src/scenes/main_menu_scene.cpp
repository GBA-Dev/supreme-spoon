#include "main_menu_scene.h"
#include "gameplay_scene.h"
#include "nerd.h"
#include "scene_manager.h" // Include SceneManager header

#include "bn_keypad.h"
#include "bn_log.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"
#include "common_variable_8x16_sprite_font.h"

MainMenuScene::MainMenuScene() : _background(), _nerd()
{
    // Initialize the text generator and create the "Start Game" text
    bn::sprite_text_generator text_generator(common::variable_8x16_sprite_font);
    text_generator.set_center_alignment();
    text_generator.generate(0, 40, "Start Game", _text_sprites);
}

MainMenuScene::~MainMenuScene()
{
    BN_LOG("MainMenuScene destroyed");
}

void MainMenuScene::update()
{
    // Update background and Nerd actor
    _background.update(0, 0);
    _nerd.update(0, 0);
}

void MainMenuScene::draw()
{
    // No specific draw logic required; Butano handles sprite rendering.
}

bool MainMenuScene::should_transition(SceneManagerNamespace::SceneType &next_scene_type)
{
    // Transition to the next scene if the start button is pressed
    if (bn::keypad::start_pressed())
    {
        next_scene_type = SceneManagerNamespace::SceneType::Gameplay;
        return true;
    }
    return false;
}

void MainMenuScene::handle_collisions()
{
    // No collisions to handle in the main menu scene.
    // Keeping the function for consistency and to fulfill interface requirements.
}
