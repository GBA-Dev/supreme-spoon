#ifndef COLLISION_BEHAVIOR_H
#define COLLISION_BEHAVIOR_H

#include "bn_fixed_rect.h"

class CollisionBehavior {
public:
    CollisionBehavior(int width, int height, int offset_x = 0, int offset_y = 0);

    void set_position(int x, int y); // Update the position of the collision box
    bool intersects(const CollisionBehavior& other) const; // Check if this box intersects another

    const bn::fixed_rect& collision_box() const; // Getter for accessing the collision box

private:
    bn::fixed_rect _collision_box; // The collision rectangle for the actor
    int _offset_x; // Optional x offset from the actor's origin to the collision box
    int _offset_y; // Optional y offset from the actor's origin to the collision box
};

#endif
