#ifndef PLAYER_H
#define PLAYER_H

#include "actor.h"

class Player : public Actor {
public:
    Player();
    ~Player() override;

    void update() override;
    void draw() override;
};

#endif // PLAYER_H
