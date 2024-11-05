#include "nerd.h"

#include "bn_sprite_ptr.h"
#include "bn_sprite_items_nerd_tile.h"
#include "wave_movement_behavior.h"

Nerd::Nerd() : _nerd_sprite(bn::sprite_items::nerd_tile.create_sprite(0, -32)),
               _wave_behavior(_nerd_sprite, 0.006, {100, 10})
{
    // Initialization logic for the Nerd actor, if needed.
}

Nerd::~Nerd()
{
    // Cleanup logic for the Nerd actor, if needed.
}

void Nerd::update()
{
}

void Nerd::draw()
{
    _wave_behavior.update(); // Delegate the update logic to the behavior
    // The sprite management is automatic by Butano, so no explicit draw call is needed.
}
