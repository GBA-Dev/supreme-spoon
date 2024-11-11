#ifndef HERO_H
#define HERO_H

#include "actor.h"
#include "collision_behavior.h"
#include "laser_bolts.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"

class Hero : public Actor
{
public:
    Hero();
    ~Hero() override;

    void update(int hero_x, int hero_y) override;
    void draw() override;

    // Getter methods for laser bolts and hero coordinates
    const LaserBolts& laser_bolts() const;

    int get_x() const;
    int get_y() const;

    // Getter for collision behavior
    const CollisionBehavior *collision_behavior() const override;

    void destroy() override;               // Add destroy method
    void take_damage(int damage) override; // Add take_damage method

    void remove_laser_bolt(const bn::sprite_ptr& bolt);

private:
    bn::sprite_ptr _hero_sprite;
    LaserBolts _laser_bolts;
    CollisionBehavior _collision_behavior; // Collision box for the hero
    bn::sprite_animate_action<2> _hero_action;
    int _debounce;
};

#endif // HERO_H
