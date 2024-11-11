#ifndef ENEMY_SMALL_H
#define ENEMY_SMALL_H

#include "actor.h"
#include "bn_sprite_ptr.h"
#include "collision_behavior.h"
#include "bn_sprite_animate_actions.h"

class EnemySmall : public Actor
{
public:
    EnemySmall(int start_x, int start_y);
    ~EnemySmall() override;

    void update(int hero_x, int hero_y) override;
    void draw() override;

    const CollisionBehavior *collision_behavior() const override;

    void destroy() override;               // Add destroy method
    void take_damage(int damage) override; // Add take_damage method

private:
    bn::sprite_ptr _enemy_small;           // The sprite representing the enemy
    CollisionBehavior _collision_behavior; // Collision box for the enemy
    bn::sprite_animate_action<2> _enemy_small_action;
    bool _is_approaching;
    int _flee_phase;
};

#endif // ENEMY_SMALL_H
