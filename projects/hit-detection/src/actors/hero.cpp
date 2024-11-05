#include "hero.h"
#include "bn_log.h"
#include "bn_keypad.h"

#include "bn_sprite_items_hero_tile.h"

Hero::Hero() : _hero_sprite(bn::sprite_items::hero_tile.create_sprite()), _laser_bolts()
{
    // Initialization logic for the Hero actor, if needed.
    BN_LOG("Hero created.");
}

Hero::~Hero()
{
    // Cleanup logic for the Hero actor, if needed.
}

void Hero::update()
{
    // Update logic for the Hero, such as handling Hero input and movement.
}

void Hero::draw()
{
    _laser_bolts.draw();

    // Draw logic for the Hero, such as rendering the Hero sprite.
    // Handle directional input for hero movement
    if (bn::keypad::left_held())
    {
        _hero_sprite.set_x(_hero_sprite.x() - 1);
        // action = bn::create_sprite_animate_action_forever(
        //             hero, 16, bn::sprite_items::hero_tile.tiles_item(), 0, 1);
    }
    if (bn::keypad::right_held())
    {
        _hero_sprite.set_x(_hero_sprite.x() + 1);
        // action = bn::create_sprite_animate_action_forever(
        //             hero, 16, bn::sprite_items::hero_tile.tiles_item(), 2, 3);
    }
    if (bn::keypad::up_held())
    {
        _hero_sprite.set_y(_hero_sprite.y() - 1);
        // action = bn::create_sprite_animate_action_forever(
        //             hero, 16, bn::sprite_items::hero_tile.tiles_item(), 4, 5);
    }
    if (bn::keypad::down_held())
    {
        _hero_sprite.set_y(_hero_sprite.y() + 1);
        // action = bn::create_sprite_animate_action_forever(
        //             hero, 16, bn::sprite_items::hero_tile.tiles_item(), 6, 7);
    }

    if (bn::keypad::a_pressed())
    {
        _laser_bolts.fire(_hero_sprite.x().right_shift_integer(), _hero_sprite.y().right_shift_integer());
    }
}
