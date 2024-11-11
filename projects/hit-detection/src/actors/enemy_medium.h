#ifndef ENEMY_MEDIUM_H
#define ENEMY_MEDIUM_H

#include "actor.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"
#include "collision_behavior.h"

class EnemyMedium : public Actor
{
public:
    EnemyMedium(int start_x, int start_y);
    ~EnemyMedium() override;

    void update(int hero_x, int hero_y) override;
    void draw() override;

    // Updated getter for collision behavior
    const CollisionBehavior *collision_behavior() const override;

    void destroy() override;               // Add destroy method
    void take_damage(int damage) override; // Add take_damage method

private:
    bn::sprite_ptr _enemy_medium;
    bn::sprite_animate_action<2> _enemy_medium_action;
    CollisionBehavior _collision_behavior; // Collision box for the enemy
    bool _is_approaching;
    int _flee_phase;

};

#endif // ENEMY_MEDIUM_H
