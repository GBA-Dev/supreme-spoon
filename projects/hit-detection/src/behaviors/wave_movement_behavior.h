#ifndef WAVE_MOVEMENT_BEHAVIOR_H
#define WAVE_MOVEMENT_BEHAVIOR_H

#include "behavior.h"
#include "bn_fixed_point.h"
#include "bn_sprite_ptr.h"
#include "bn_math.h"
#include "bn_log.h"

class WaveMovementBehavior : public Behavior
{
public:
    WaveMovementBehavior(
        bn::sprite_ptr &sprite, bn::fixed wave_speed, bn::array<bn::fixed, 2> amplitudes) : _sprite(sprite), _wave_speed(wave_speed), _amplitudes(amplitudes) {}

    void update() override
    {
        _sprite.set_position(bn::fixed_point(bn::sin(_time / 2) * _amplitudes[0], bn::cos(_time) * _amplitudes[1]));
        _time += _wave_speed;
    }

private:
    bn::sprite_ptr &_sprite;
    bn::fixed _wave_speed;
    bn::array<bn::fixed, 2> _amplitudes;
    bn::fixed _time = 0;
};

#endif // WAVE_MOVEMENT_BEHAVIOR_H
