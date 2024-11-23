#include "enemy_small.h"
#include "bn_log.h"
#include "bn_sprite_items_enemy_small.h"
#include "bn_math.h"
#include "bn_sprites_mosaic.h"


// Constructor
EnemySmall::EnemySmall(int start_x, int start_y) : _enemy_small(bn::sprite_items::enemy_small.create_sprite(start_x, start_y)),
                                                   _collision_behavior(16, 16), // Initialize collision box with appropriate size
                                                   _is_approaching(true),
                                                   _flee_phase(0),
                                                   _enemy_small_action(bn::create_sprite_animate_action_forever(
                                                       _enemy_small, 16, bn::sprite_items::enemy_small.tiles_item(), 0, 1))
{
    _collision_behavior.set_position(start_x, start_y);
    bn::sprites_mosaic::set_stretch(0.2);
}

// Destructor
EnemySmall::~EnemySmall()
{
}

// Update Function
void EnemySmall::update(int hero_x, int hero_y)
{
    int current_x = _enemy_small.x().right_shift_integer();
    int current_y = _enemy_small.y().right_shift_integer();

    int delta_x = hero_x - current_x;
    int delta_y = hero_y - current_y;

    int distance = bn::abs(delta_x) + bn::abs(delta_y);

    // if (_is_approaching && distance <= 30)
    // {
    //     _is_approaching = false;
    // }

    if (_is_approaching)
    {
        // Move towards the hero
        if (delta_x > 0)
        {
            _enemy_small.set_x(_enemy_small.x() + 0.5);
        }
        else if (delta_x < 0)
        {
            _enemy_small.set_x(_enemy_small.x() - 0.5);
        }

        if (delta_y > 0)
        {
            _enemy_small.set_y(_enemy_small.y() + 0.5);
        }
        else if (delta_y < 0)
        {
            _enemy_small.set_y(_enemy_small.y() - 0.5);
        }
    }
    else
    {
        // Flee from the hero with mosaic effect enabled
        _enemy_small.set_mosaic_enabled(true);

        if (delta_x > 0)
        {
            _enemy_small.set_x(_enemy_small.x() - 1);
        }
        else if (delta_x < 0)
        {
            _enemy_small.set_x(_enemy_small.x() + 1);
        }

        int sine_offset = static_cast<int>(bn::sin(_flee_phase) / 16);
        _flee_phase = (_flee_phase + 5) % 360;

        _enemy_small.set_y(_enemy_small.y() + sine_offset);
    }

    // Update the collision box position to match the enemy's position
    _collision_behavior.set_position(_enemy_small.x().right_shift_integer(), _enemy_small.y().right_shift_integer());
    _enemy_small_action.update();
}

// Draw Function
void EnemySmall::draw()
{
    // Drawing logic; typically managed by Butano automatically
}

// Getter implementation for collision behavior in derived classes
const CollisionBehavior *EnemySmall::collision_behavior() const
{
    return &_collision_behavior;
}

void EnemySmall::destroy()
{
    // Add destruction logic
    _enemy_small.set_visible(false);
}

void EnemySmall::take_damage(int damage)
{
    // Add damage handling logic here
}
