#ifndef GAMEPLAY_SCENE_H
#define GAMEPLAY_SCENE_H

#include <vector>
#include "scene.h"
#include "hero.h"


class GameplayScene : public Scene
{
public:
    GameplayScene();
    ~GameplayScene() override;

    void update() override;
    void draw() override;

    bool should_transition(std::unique_ptr<Scene>& next_scene) override;

private:
    Hero _hero;
    std::vector<Actor *> _actors;
};

#endif // GAMEPLAY_SCENE_H
