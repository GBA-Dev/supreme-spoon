#include "hero.h"
#include "bn_log.h"
#include "bn_keypad.h"
#include "bn_sprite_items_hero_tile.h"
#include "bn_sprite_animate_actions.h"

// Constructor
Hero::Hero() : _hero_sprite(bn::sprite_items::hero_tile.create_sprite()),
               _laser_bolts(),
               _debounce(0),
               _collision_behavior(16, 16),
               _hero_action(bn::create_sprite_animate_action_forever(
                   _hero_sprite, 16, bn::sprite_items::hero_tile.tiles_item(), 0, 1))
{
    _collision_behavior.set_position(_hero_sprite.x().right_shift_integer(), _hero_sprite.y().right_shift_integer());
}

// Destructor
Hero::~Hero()
{
}

// Update Function
void Hero::update(int, int)
{
    // Handle directional input for hero movement
    if (bn::keypad::left_held())
    {
        _hero_sprite.set_x(_hero_sprite.x() - 1);
        _hero_action = bn::create_sprite_animate_action_forever(
            _hero_sprite, 16, bn::sprite_items::hero_tile.tiles_item(), 0, 1);
    }
    if (bn::keypad::right_held())
    {
        _hero_sprite.set_x(_hero_sprite.x() + 1.5);
        _hero_action = bn::create_sprite_animate_action_forever(
            _hero_sprite, 16, bn::sprite_items::hero_tile.tiles_item(), 2, 3);
    }
    if (bn::keypad::up_held())
    {
        _hero_sprite.set_y(_hero_sprite.y() - 1.5);
        _hero_action = bn::create_sprite_animate_action_forever(
            _hero_sprite, 16, bn::sprite_items::hero_tile.tiles_item(), 4, 5);
    }
    if (bn::keypad::down_held())
    {
        _hero_sprite.set_y(_hero_sprite.y() + 1.5);
        _hero_action = bn::create_sprite_animate_action_forever(
            _hero_sprite, 16, bn::sprite_items::hero_tile.tiles_item(), 6, 7);
    }

    // Update collision behavior position to follow the hero
    _collision_behavior.set_position(_hero_sprite.x().right_shift_integer(), _hero_sprite.y().right_shift_integer());

    // Handle laser bolts firing
    if (bn::keypad::a_held())
    {
        // Need back presure to limit the time between the bolts fired (debounce)
        _debounce++;
        if (_debounce >= 7)
        {
            _debounce = 0;
            _laser_bolts.fire(_hero_sprite.x().right_shift_integer(), _hero_sprite.y().right_shift_integer());
        }
    }

    // Update laser bolts
    _laser_bolts.update(0, 0);
    _hero_action.update();
}

// Draw Function
void Hero::draw()
{
    _laser_bolts.draw();
}

// Getter for laser bolts
const LaserBolts &Hero::laser_bolts() const
{
    return _laser_bolts;
}

// Getter for collision behavior
const CollisionBehavior *Hero::collision_behavior() const
{
    return &_collision_behavior;
}

// Getter for x-coordinate
int Hero::get_x() const
{
    return _hero_sprite.x().right_shift_integer();
}

// Getter for y-coordinate
int Hero::get_y() const
{
    return _hero_sprite.y().right_shift_integer();
}

void Hero::remove_laser_bolt(const bn::sprite_ptr &bolt)
{
    _laser_bolts.remove_bolt(bolt);
}

void Hero::destroy()
{
    // Add destruction logic
}

void Hero::take_damage(int)
{
    // Add damage handling logic here
}
