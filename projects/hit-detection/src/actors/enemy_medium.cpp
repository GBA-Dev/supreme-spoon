#include "enemy_medium.h"
#include "bn_log.h"
#include "bn_sprite_items_enemy_medium.h"
#include "bn_math.h"
#include "bn_sprites_mosaic.h"

EnemyMedium::EnemyMedium(int start_x, int start_y) : _enemy_medium(bn::sprite_items::enemy_medium.create_sprite(start_x, start_y)),
                                                     _collision_behavior(16, 16), // Assuming the enemy sprite is 16x16
                                                     _is_approaching(true),
                                                     _flee_phase(0),
                                                     _enemy_medium_action(bn::create_sprite_animate_action_forever(
                                                         _enemy_medium, 16, bn::sprite_items::enemy_medium.tiles_item(), 0, 1))
{
    // Initialize the collision box position
    _collision_behavior.set_position(start_x, start_y);
    bn::sprites_mosaic::set_stretch(0.2);
}

EnemyMedium::~EnemyMedium()
{
}

void EnemyMedium::update(int hero_x, int hero_y)
{
    int current_x = _enemy_medium.x().right_shift_integer();
    int current_y = _enemy_medium.y().right_shift_integer();

    int delta_x = hero_x - current_x;
    int delta_y = hero_y - current_y;

    int distance = bn::abs(delta_x) + bn::abs(delta_y);

    // Determine if the enemy should approach or flee from the hero
    if (_is_approaching && distance <= 30)
    {
        _is_approaching = false;
    }

    if (_is_approaching)
    {
        // Move towards the hero
        if (delta_x > 0)
        {
            _enemy_medium.set_x(_enemy_medium.x() + 0.5);
        }
        else if (delta_x < 0)
        {
            _enemy_medium.set_x(_enemy_medium.x() - 0.5);
        }

        if (delta_y > 0)
        {
            _enemy_medium.set_y(_enemy_medium.y() + 0.5);
        }
        else if (delta_y < 0)
        {
            _enemy_medium.set_y(_enemy_medium.y() - 0.5);
        }
    }
    else
    {
        // Flee from the hero with mosaic effect enabled
        _enemy_medium.set_mosaic_enabled(true);

        if (delta_x > 0)
        {
            _enemy_medium.set_x(_enemy_medium.x() - 1);
        }
        else if (delta_x < 0)
        {
            _enemy_medium.set_x(_enemy_medium.x() + 1);
        }

        int sine_offset = static_cast<int>(bn::sin(_flee_phase) / 16);
        _flee_phase = (_flee_phase + 5) % 360;

        _enemy_medium.set_y(_enemy_medium.y() + sine_offset);
    }

    // Update the collision box position to match the enemy's position
    _collision_behavior.set_position(_enemy_medium.x().right_shift_integer(), _enemy_medium.y().right_shift_integer());
    _enemy_medium_action.update();
}

void EnemyMedium::draw()
{
    // Drawing logic, if needed. Butano handles the automatic rendering of sprites.
}

// Getter implementation for collision behavior in derived classes
const CollisionBehavior *EnemyMedium::collision_behavior() const
{
    return &_collision_behavior;
}
void EnemyMedium::destroy()
{
    // Add destruction logic
    _enemy_medium.set_visible(false);
}

void EnemyMedium::take_damage(int damage)
{
    // Add damage handling logic here
}
