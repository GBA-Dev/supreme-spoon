#ifndef MAIN_MENU_SCENE_H
#define MAIN_MENU_SCENE_H

#include "scene.h"
#include "background_actor.h"
#include "nerd.h"
#include "bn_sprite_ptr.h"
#include "bn_vector.h"

class MainMenuScene : public Scene {
public:
    MainMenuScene();
    ~MainMenuScene() override;

    void update() override;
    void draw() override;

private:
    bn::vector<bn::sprite_ptr, 32> _text_sprites;
    BackgroundActor _background;
    Nerd _nerd;
};

#endif // MAIN_MENU_SCENE_H
