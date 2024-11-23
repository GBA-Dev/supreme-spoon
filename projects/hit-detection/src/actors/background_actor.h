#ifndef BACKGROUND_ACTOR_H
#define BACKGROUND_ACTOR_H

#include "actor.h"
#include "bn_regular_bg_ptr.h"
#include "collision_behavior.h"

class BackgroundActor : public Actor
{
public:
    BackgroundActor();
    ~BackgroundActor() override;

    void update(int hero_x, int hero_y) override;
    void draw() override;

    // Updated getter for collision behavior
    const CollisionBehavior *collision_behavior() const override;

    void destroy() override;               // Add destroy method
    void take_damage(int damage) override; // Add take_damage method
    void set_x_parallax_speed(int speed) { x_parallax_speed = speed; }


private:
    bn::regular_bg_ptr _clouds_bg;
    bn::regular_bg_ptr _cloud_lonely;
    bn::regular_bg_ptr _glacial_mountains;
    bn::regular_bg_ptr _clouds_mg;
    int x_parallax_speed = 3; // Adjust speed to create parallax effect
    
    CollisionBehavior _collision_behavior; // Collision box for Nerd
};

#endif // BACKGROUND_ACTOR_H
