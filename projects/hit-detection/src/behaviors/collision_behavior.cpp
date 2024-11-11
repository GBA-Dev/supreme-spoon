#include "collision_behavior.h"

CollisionBehavior::CollisionBehavior(int width, int height, int offset_x, int offset_y) :
    _collision_box(0, 0, width, height), _offset_x(offset_x), _offset_y(offset_y) {}

void CollisionBehavior::set_position(int x, int y) {
    _collision_box.set_position(x + _offset_x, y + _offset_y);
}

bool CollisionBehavior::intersects(const CollisionBehavior& other) const {
    return _collision_box.intersects(other.collision_box());
}

const bn::fixed_rect& CollisionBehavior::collision_box() const {
    return _collision_box;
}
