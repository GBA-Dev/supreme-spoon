#ifndef BACKGROUND_ACTOR_H
#define BACKGROUND_ACTOR_H

#include "actor.h"
#include "bn_regular_bg_ptr.h"

class BackgroundActor : public Actor {
public:
    BackgroundActor();
    ~BackgroundActor() override;

    void update() override;
    void draw() override;

private:
    bn::regular_bg_ptr _clouds_bg;
    bn::regular_bg_ptr _cloud_lonely;
    bn::regular_bg_ptr _glacial_mountains;
    bn::regular_bg_ptr _clouds_mg;
    int x_parallax_speed = 3; // Adjust speed to create parallax effect
};

#endif // BACKGROUND_ACTOR_H
