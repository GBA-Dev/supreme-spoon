#ifndef MAIN_MENU_SCENE_H
#define MAIN_MENU_SCENE_H

#include "scene.h"

class GameplayScene : public Scene {
public:
    GameplayScene();
    ~GameplayScene() override;

    void update() override;
    void draw() override;
};

#endif // GAMEPLAY_SCENE_H
