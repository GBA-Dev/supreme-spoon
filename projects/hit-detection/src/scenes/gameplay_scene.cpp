#include "gameplay_scene.h"

#include "bn_bg_palettes.h"
#include "bn_color.h"
#include "bn_log.h"
#include "bn_keypad.h"
#include "bn_random.h"

#include "main_menu_scene.h"
#include "enemy_medium.h"
#include "enemy_small.h"
#include "hero.h"

GameplayScene::GameplayScene() : _hero(), _background(), _spawn_timer(0)
{

    bn::bg_palettes::set_transparent_color(bn::color(0, 0, 0));

    // Add hero to actors
    _actors.push_back(&_hero);
}

GameplayScene::~GameplayScene()
{
    // Clean up dynamically allocated enemies
    for (Actor *actor : _actors)
    {
        if (actor != &_hero)
        {
            delete actor;
        }
    }
}

void GameplayScene::update()
{
    int hero_x = _hero.get_x();
    int hero_y = _hero.get_y();

    // Update all actors, including enemies and the hero
    for (Actor *actor : _actors)
    {
        actor->update(hero_x, hero_y);
    }

    // Handle collisions after all actors are updated
    handle_collisions();

    // Update the spawn timer and spawn new enemies every 5 seconds
    _spawn_timer++;
    if (_spawn_timer >= 300) // Assuming 60 FPS, 300 frames = 5 seconds
    {
        _spawn_timer = 0;
        bn::random random_generator;
        for (int i = 0; i < 3; ++i)
        {
            int x = 150 + (i * 20);                        // Fixed x position
            int y = random_generator.get_int() % 161 - 80; // Random y between -80 and 80
            EnemySmall *enemy = new EnemySmall(x, y);
            _actors.push_back(enemy);
            _enemies.push_back(enemy);
        }
    }

    _background.update(0, 0);
}

void GameplayScene::draw()
{
    // Draw all actors
    for (Actor *actor : _actors)
    {
        actor->draw();
    }
}

bool GameplayScene::should_transition(std::unique_ptr<Scene> &next_scene)
{
    if (bn::keypad::start_pressed())
    {
        next_scene = std::make_unique<MainMenuScene>();
        return true;
    }
    return false;
}

void GameplayScene::handle_collisions()
{
    // Iterate over laser bolts and enemies for collision detection
    const auto &laser_bolts = _hero.laser_bolts();
    for (int i = 0; i < laser_bolts.get_active_bolts().size(); ++i)
    {
        const bn::sprite_ptr &projectile = laser_bolts.get_active_bolts()[i];
        const CollisionBehavior &projectile_collision = laser_bolts.collision_behaviors()[i];

        for (auto &enemy : _enemies)
        {
            const CollisionBehavior *enemy_collision = enemy->collision_behavior();

            if (enemy_collision && projectile_collision.intersects(*enemy_collision))
            {
                on_hit(projectile, *enemy);
            }
        }
    }
}

void GameplayScene::on_hit(const bn::sprite_ptr &projectile, Actor &enemy)
{
    BN_LOG("Projectile hit enemy.");
    // Example logic: destroy both the projectile and reduce enemy health
    // projectile.destroy();
    enemy.destroy();
    // enemy.take_damage(1);
    _enemies.erase(std::remove(_enemies.begin(), _enemies.end(), &enemy), _enemies.end());
    _actors.erase(std::remove(_actors.begin(), _actors.end(), &enemy), _actors.end());
}
