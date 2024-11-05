// main.cpp ---------------------------------------------------------------------
#include "bn_core.h"
#include "scene_manager.h"
#include "main_menu_scene.h"
#include <climits> // Include this for INT_MAX

int main()
{
    bn::core::init();

    SceneManager scene_manager;
    scene_manager.set_scene(std::make_unique<MainMenuScene>()); // Set initial scene to Main Menu

    // Add a frame counter variable
    int frameCounter = 0;

    while (true)
    {
        scene_manager.draw();

        if (frameCounter % 2 == 0)
        {
            scene_manager.update();
        }

        frameCounter++;

        // Reset frameCounter to avoid overflow
        if (frameCounter >= INT_MAX)
        {
            frameCounter = 0;
        }

        bn::core::update();
    }
}
