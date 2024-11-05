#ifndef LASER_BOLTS_H
#define LASER_BOLTS_H

#include "actor.h"
#include "bn_sprite_ptr.h"
#include "bn_vector.h"

class LaserBolts : public Actor
{
public:
    LaserBolts();
    ~LaserBolts() override;

    void update() override;
    void draw() override;

    // Method to fire a new laser bolt
    void fire(int start_x, int start_y);

private:
    bn::vector<bn::sprite_ptr, 32> _active_laser_bolts; // Store up to 32 active laser bolts
    int speed; // Speed of the laser bolts
};

#endif // LASER_BOLTS_H
