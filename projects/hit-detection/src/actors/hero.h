#ifndef HERO_H
#define HERO_H

#include "actor.h"

#include "laser_bolts.h"
#include "bn_sprite_ptr.h"

class Hero : public Actor
{
public:
    Hero();
    ~Hero() override;

    void update() override;
    void draw() override;

private:
    bn::sprite_ptr _hero_sprite;
    LaserBolts _laser_bolts;
};

#endif // HERO_H
