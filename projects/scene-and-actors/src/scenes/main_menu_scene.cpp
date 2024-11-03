#include "main_menu_scene.h"
#include "background_actor.h"
#include "nerd.h"

#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"

#include "common_variable_8x16_sprite_font.h"

MainMenuScene::MainMenuScene() : _background(), _nerd() {
    bn::sprite_text_generator text_generator(common::variable_8x16_sprite_font);
    text_generator.set_center_alignment();
    text_generator.generate(0, 16, "Hello", _text_sprites);
}

MainMenuScene::~MainMenuScene() {
}

void MainMenuScene::update() {
    _background.update();
    _nerd.update();
}

void MainMenuScene::draw() {
    _background.draw();
    _nerd.draw();
}
