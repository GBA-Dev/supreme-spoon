#ifndef ACTOR_H
#define ACTOR_H

#include "collision_behavior.h"

class Actor {
public:
    Actor() = default;
    virtual ~Actor() = default;

    virtual void update(int hero_x, int hero_y) = 0;
    virtual void draw() = 0;

    // Collision getter
    virtual const CollisionBehavior* collision_behavior() const { return nullptr; }

    // New pure virtual functions for actors that can be destroyed or take damage
    virtual void destroy() = 0;
    virtual void take_damage(int damage) = 0;
};

#endif // ACTOR_H
