#ifndef LASER_BOLTS_H
#define LASER_BOLTS_H

#include "actor.h"
#include "collision_behavior.h"
#include "bn_sprite_ptr.h"
#include "bn_vector.h"
#include "bn_sprite_animate_actions.h"

class LaserBolts : public Actor
{
public:
    LaserBolts();
    ~LaserBolts() override;

    void update(int hero_x, int hero_y) override;
    void draw() override;

    // Method to fire a new laser bolt
    void fire(int start_x, int start_y);
    // Getter to return active laser bolts
    const bn::vector<bn::sprite_ptr, 32>& get_active_bolts() const;

    const CollisionBehavior *collision_behavior() const override;

    // Getter for the collision behaviors of the active laser bolts
    const bn::vector<CollisionBehavior, 32> &collision_behaviors() const;

    void destroy() override;               // Add destroy method
    void take_damage(int damage) override; // Add take_damage method

    void remove_bolt(const bn::sprite_ptr& bolt);

private:
    bn::vector<bn::sprite_ptr, 32> _active_laser_bolts;
    bn::vector<bn::sprite_animate_action<2>, 32> _active_laser_bolts_actions;
    bn::vector<CollisionBehavior, 32> _collision_behaviors; // Track collision boxes for each laser bolt
    int speed;
    CollisionBehavior _collision_behavior; // Collision box for Nerd
};

#endif // LASER_BOLTS_H
