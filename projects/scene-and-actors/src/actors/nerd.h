#ifndef NERD_H
#define NERD_H

#include "actor.h"
#include "wave_movement_behavior.h"

#include "bn_sprite_ptr.h"

class Nerd : public Actor {
public:
    Nerd();
    ~Nerd() override;

    void update() override;
    void draw() override;

private:
    bn::sprite_ptr _nerd_sprite;
    WaveMovementBehavior _wave_behavior; // Composition: Use wave movement behavior
};

#endif // NERD_H