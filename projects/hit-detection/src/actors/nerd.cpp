#include "nerd.h"

#include "bn_sprite_ptr.h"
#include "bn_sprite_items_nerd_tile.h"
#include "wave_movement_behavior.h"

Nerd::Nerd() : _nerd_sprite(bn::sprite_items::nerd_tile.create_sprite(0, -32)),
               _wave_behavior(_nerd_sprite, 0.006, {100, 10}),
               _collision_behavior(16, 16) // Assuming the Nerd sprite is 16x16
{
    // Initialize the collision box position to match the initial sprite position
    _collision_behavior.set_position(_nerd_sprite.x().right_shift_integer(), _nerd_sprite.y().right_shift_integer());
}

Nerd::~Nerd()
{
}

void Nerd::update(int, int)
{
    // Update the wave behavior to animate the nerd
    _wave_behavior.update();

    // Update the collision box position to match the nerd's current position
    _collision_behavior.set_position(_nerd_sprite.x().right_shift_integer(), _nerd_sprite.y().right_shift_integer());
}

void Nerd::draw()
{
    // The wave behavior already updates the sprite position, Butano handles the drawing automatically
}

// Getter implementation for collision behavior in derived classes
const CollisionBehavior *Nerd::collision_behavior() const
{
    return &_collision_behavior;
}

void Nerd::destroy()
{
    // Add destruction logic
}

void Nerd::take_damage(int damage)
{
    // Add damage handling logic here
}
