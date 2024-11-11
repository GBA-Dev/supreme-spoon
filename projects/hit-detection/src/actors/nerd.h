#ifndef NERD_H
#define NERD_H

#include "actor.h"
#include "wave_movement_behavior.h"
#include "collision_behavior.h"
#include "bn_sprite_ptr.h"

class Nerd : public Actor
{
public:
    Nerd();
    ~Nerd() override;

    void update(int hero_x, int hero_y) override;
    void draw() override;
    // Updated getter for collision behavior
    const CollisionBehavior *collision_behavior() const override;

    void destroy() override;               // Add destroy method
    void take_damage(int damage) override; // Add take_damage method

private:
    bn::sprite_ptr _nerd_sprite;
    WaveMovementBehavior _wave_behavior; // Composition: Use wave movement behavior
    CollisionBehavior _collision_behavior; // Collision box for Nerd
};

#endif // NERD_H