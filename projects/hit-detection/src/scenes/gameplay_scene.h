#ifndef GAMEPLAY_SCENE_H
#define GAMEPLAY_SCENE_H

#include <vector>
#include "scene.h"
#include "hero.h"
#include "background_actor.h"
#include "bn_vector.h"

class GameplayScene : public Scene
{
public:
    GameplayScene();
    ~GameplayScene() override;

    void update() override;
    void draw() override;

    bool should_transition(SceneManagerNamespace::SceneType &next_scene_type) override;
    void handle_collisions() override;

private:
    Hero _hero; // Use Hero correctly
    BackgroundActor _background;
    bn::vector<Actor*, 32> _actors;
    bn::vector<Actor*, 32> _enemies;
    int _spawn_timer; // Timer for spawning enemies

    // Declare on_hit method`
    void on_hit(const bn::sprite_ptr& projectile, Actor& enemy);
};

#endif // GAMEPLAY_SCENE_H
