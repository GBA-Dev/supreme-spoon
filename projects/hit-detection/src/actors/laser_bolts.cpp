#include "laser_bolts.h"
#include "bn_sprite_items_laser_bolts_tile.h"

// Constructor
LaserBolts::LaserBolts() : speed(5) // Set default speed
{
    // No laser bolts created at instantiation
}

// Destructor
LaserBolts::~LaserBolts()
{
    // No manual clean-up needed as bn::sprite_ptr is managed automatically
}

// Fire method to add a new laser bolt sprite
void LaserBolts::fire(int start_x, int start_y)
{
    if (_active_laser_bolts.full())
    {
        return; // Do nothing if vector is full, avoid overflow
    }

    // Create a new sprite for the laser bolt
    bn::sprite_ptr new_laser_bolt_sprite = bn::sprite_items::laser_bolts_tile.create_sprite(start_x, start_y);

    // Add the new sprite to the list of active laser bolts
    _active_laser_bolts.push_back(new_laser_bolt_sprite);
}

// Update method to move the laser bolts and remove them if they are off-screen
void LaserBolts::update()
{

}


// Draw method (if needed)
void LaserBolts::draw()
{
    // Drawing may be handled automatically by bn::sprite_ptr, so this can remain empty if not required
    for (int i = _active_laser_bolts.size() - 1; i >= 0; --i)
    {
        bn::sprite_ptr& laser_bolt = _active_laser_bolts[i];
        // Update the position of the laser bolt to move right
        laser_bolt.set_x(laser_bolt.x() + speed);

        // If the laser bolt is off-screen, remove it
        if (laser_bolt.x().right_shift_integer() > 120) // Assuming 120 is off-screen for the right side
        {
            laser_bolt.set_visible(false);
            _active_laser_bolts.erase(_active_laser_bolts.begin() + i); // Use iterator to erase
        }
    }
}
