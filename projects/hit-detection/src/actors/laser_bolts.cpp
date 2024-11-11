#include "laser_bolts.h"
#include "bn_sprite_items_laser_bolts_tile.h"
#include "bn_sprite_animate_actions.h"

LaserBolts::LaserBolts() : speed(5), _collision_behavior(16, 16) // Assuming the Nerd sprite is 16x16
{
}

LaserBolts::~LaserBolts()
{
}

void LaserBolts::fire(int start_x, int start_y)
{
    if (_active_laser_bolts.full())
    {
        return;
    }

    // Create a new sprite for the laser bolt
    bn::sprite_ptr new_laser_bolt_sprite = bn::sprite_items::laser_bolts_tile.create_sprite(start_x, start_y);
    bn::sprite_animate_action<2> action = bn::create_sprite_animate_action_forever(
            new_laser_bolt_sprite, 16, bn::sprite_items::laser_bolts_tile.tiles_item(), 0, 1);
    _active_laser_bolts_actions.push_back(action);
    _active_laser_bolts.push_back(new_laser_bolt_sprite);

    // Create a new collision box for the laser bolt (assuming size 8x8 for the sprite)
    CollisionBehavior new_collision_behavior(8, 8);
    new_collision_behavior.set_position(start_x, start_y);
    _collision_behaviors.push_back(new_collision_behavior);
}

void LaserBolts::update(int, int)
{

    // Iterate over laser bolts and update their positions
    for (int i = _active_laser_bolts.size() - 1; i >= 0; --i)
    {
        _active_laser_bolts_actions[i].update();
        
        bn::sprite_ptr &laser_bolt = _active_laser_bolts[i];
        // Move the laser bolt to the right by the defined speed
        laser_bolt.set_x(laser_bolt.x() + speed);

        // Update the collision box position
        _collision_behaviors[i].set_position(laser_bolt.x().right_shift_integer(), laser_bolt.y().right_shift_integer());

        // Remove laser bolts that go out of bounds
        if (laser_bolt.x().right_shift_integer() > 120)
        {
            laser_bolt.set_visible(false);
            _active_laser_bolts.erase(_active_laser_bolts.begin() + i);
            _collision_behaviors.erase(_collision_behaviors.begin() + i);
            _active_laser_bolts_actions.erase(_active_laser_bolts_actions.begin() + i);
        }
    }
}

void LaserBolts::draw()
{
}

// Getter implementation for collision behavior in derived classes
const CollisionBehavior *LaserBolts::collision_behavior() const
{
    return &_collision_behavior;
}

const bn::vector<CollisionBehavior, 32> &LaserBolts::collision_behaviors() const
{
    return _collision_behaviors;
}

void LaserBolts::destroy()
{
    // Add destruction logic
}

void LaserBolts::take_damage(int)
{
    // Add damage handling logic here
}

// Getter for active laser bolts
const bn::vector<bn::sprite_ptr, 32>& LaserBolts::get_active_bolts() const
{
    return _active_laser_bolts;
}

void LaserBolts::remove_bolt(const bn::sprite_ptr& bolt)
{
    for (int i = 0; i < _active_laser_bolts.size(); ++i)
    {
        if (_active_laser_bolts[i] == bolt)
        {
            _active_laser_bolts.erase(_active_laser_bolts.begin() + i);
            _collision_behaviors.erase(_collision_behaviors.begin() + i);
            break;
        }
    }
}