#include "main_menu_scene.h"
#include "gameplay_scene.h"
#include "nerd.h"

#include "bn_keypad.h"
#include "bn_log.h"

#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"

#include "common_variable_8x16_sprite_font.h"

MainMenuScene::MainMenuScene() : _background(), _nerd()
{
    bn::sprite_text_generator text_generator(common::variable_8x16_sprite_font);
    text_generator.set_center_alignment();
    text_generator.generate(0, 40, "Start Game", _text_sprites);
}

MainMenuScene::~MainMenuScene()
{
}

void MainMenuScene::update()
{
    _background.update();
    _nerd.update();
}

void MainMenuScene::draw()
{
    _background.draw();
    _nerd.draw();
}

bool MainMenuScene::should_transition(std::unique_ptr<Scene> &next_scene)
{
    // Logic to determine if the scene should transition.
    // For now, let's just return true if a specific condition is met, e.g., pressing start button.
    if (bn::keypad::start_pressed())
    {
        BN_LOG("Start button pressed. Transitioning to the next scene.");
        next_scene = std::make_unique<GameplayScene>();
        return true;
    }
    return false;
}
