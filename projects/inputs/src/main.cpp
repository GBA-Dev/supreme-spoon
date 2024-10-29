#include "bn_core.h"
#include "bn_color.h"
#include "bn_math.h"
#include "bn_keypad.h"
#include "bn_display.h"
#include "bn_blending.h"
#include "bn_bg_palettes.h"
#include "bn_sprite_actions.h"
#include "bn_sprite_animate_actions.h"
#include "bn_sprites_mosaic.h"
#include "bn_regular_bg_actions.h"
#include "bn_sprite_position_hbe_ptr.h"

// Same as before in the sprites project. This is created at compile time.
#include "bn_regular_bg_items_glacial_mountains.h"
#include "bn_regular_bg_items_clouds_bg.h"
#include "bn_regular_bg_items_clouds_mg.h"
#include "bn_regular_bg_items_cloud_lonely.h"

#include "bn_sprite_items_nerd_tile.h"
#include "bn_sprite_items_hero_tile.h"

int main() {

    bn::core::init();

    // Setting the transparent color for the background palettes
    bn::bg_palettes::set_transparent_color(bn::color(1, 21, 31));
    
    // Creating background layers
    bn::regular_bg_ptr clouds_bg = bn::regular_bg_items::clouds_bg.create_bg(0, -48);
    bn::regular_bg_ptr cloud_lonely = bn::regular_bg_items::cloud_lonely.create_bg(0, -48);
    bn::regular_bg_ptr glacial_mountains = bn::regular_bg_items::glacial_mountains.create_bg(0, -48);
    bn::regular_bg_ptr clouds_mg = bn::regular_bg_items::clouds_mg.create_bg(0, -48);

    // Creating multiple instances of the "nerd" sprite to create shadow effects
    bn::sprite_ptr shadow_four = bn::sprite_items::nerd_tile.create_sprite(0, 0);
    bn::sprite_ptr shadow_three = bn::sprite_items::nerd_tile.create_sprite(0, 0);
    bn::sprite_ptr shadow_two = bn::sprite_items::nerd_tile.create_sprite(0, 0);
    bn::sprite_ptr shadow_one = bn::sprite_items::nerd_tile.create_sprite(0, 0);
    bn::array<bn::fixed, bn::display::height()> horizontal_deltas;

    bn::sprite_ptr nerd = bn::sprite_items::nerd_tile.create_sprite(0, 0);

    bn::sprite_ptr hero = bn::sprite_items::hero_tile.create_sprite(-100, 0);
    bn::sprite_animate_action<2> action = bn::create_sprite_animate_action_forever(
            hero, 16, bn::sprite_items::hero_tile.tiles_item(), 0, 1);

    // Setting the priority of the middle ground clouds
    clouds_mg.set_priority(0);  // Lower priority means it will appear closer to the viewer
    cloud_lonely.set_priority(0);  // Lower priority means it will appear closer to the viewer

    // Setting blending and mosaic effects for visual impact
    bn::blending::set_transparency_alpha(0.5);  // Adjusts transparency for blending enabled objects
    bn::sprites_mosaic::set_stretch(0.1);  // Mosaic effect stretch factor

    // Enable blending for each of the shadow sprites to create a "shadow" effect
    shadow_one.set_blending_enabled(true);
    shadow_two.set_blending_enabled(true);
    shadow_three.set_blending_enabled(true);
    shadow_four.set_blending_enabled(true);

    // Initial time values for animating the movement
    bn::fixed time = 0;
    bn::fixed wave_speed = 0.006;
    bn::fixed time_shadow_one = time - 0.08;
    bn::fixed time_shadow_two = time_shadow_one - 0.1;
    bn::fixed time_shadow_three = time_shadow_two - 0.1;
    bn::fixed time_shadow_four = time_shadow_three - 0.1;

    // Amplitude values for sprite oscillation
    bn::fixed amplitude_x = 60;
    bn::fixed amplitude_y = 36;

    // Parallax speed for backgrounds
    double x_parallax_speed = 1.5;
    
    // Initial value for sprite mosaic effect
    bn::fixed sprites_mosaic = 0.1;
    bool increasing_mosaic = true;
    
    while (true) {
        // Moving the background layers at different speeds to create a parallax effect
        cloud_lonely.set_x(cloud_lonely.x() - x_parallax_speed * 0.2);
        clouds_bg.set_x(clouds_bg.x() - x_parallax_speed * 0.5);
        glacial_mountains.set_x(glacial_mountains.x() - x_parallax_speed * 0.75);
        clouds_mg.set_x(clouds_mg.x() - x_parallax_speed * 1);

        // Update the main "nerd" sprite's position using sine and cosine for oscillation
        nerd.set_position(bn::fixed_point(bn::sin(time / 2) * amplitude_x, bn::cos(time) * amplitude_y));

        // Updating shadow sprites' positions to trail the main sprite, creating a shadow effect
        shadow_one.set_position(bn::fixed_point(bn::sin(time_shadow_one / 2) * amplitude_x, bn::cos(time_shadow_one) * amplitude_y));
        shadow_two.set_position(bn::fixed_point(bn::sin(time_shadow_two / 2) * amplitude_x, bn::cos(time_shadow_two) * amplitude_y));
        shadow_three.set_position(bn::fixed_point(bn::sin(time_shadow_three / 2) * amplitude_x, bn::cos(time_shadow_three) * amplitude_y));
        shadow_four.set_position(bn::fixed_point(bn::sin(time_shadow_four / 2) * amplitude_x, bn::cos(time_shadow_four) * amplitude_y));

        // Incrementing time values for continuous animation
        time += wave_speed;
        time_shadow_one += wave_speed;
        time_shadow_two += wave_speed;
        time_shadow_three += wave_speed;
        time_shadow_four += wave_speed;


        bn::fixed hero_speed = 1;  // Speed for the hero sprite

        // Handle directional input for hero movement
        if(bn::keypad::left_held()) {
            hero.set_x(hero.x() - hero_speed);
            action = bn::create_sprite_animate_action_forever(
                        hero, 16, bn::sprite_items::hero_tile.tiles_item(), 0, 1);
        }
        if(bn::keypad::right_held()) {
            hero.set_x(hero.x() + hero_speed);
            action = bn::create_sprite_animate_action_forever(
                        hero, 16, bn::sprite_items::hero_tile.tiles_item(), 2, 3);
        }
        if(bn::keypad::up_held()) {
            hero.set_y(hero.y() - hero_speed);
            action = bn::create_sprite_animate_action_forever(
                        hero, 16, bn::sprite_items::hero_tile.tiles_item(), 4, 5);
        }
        if(bn::keypad::down_held()) {
            hero.set_y(hero.y() + hero_speed);
            action = bn::create_sprite_animate_action_forever(
                        hero, 16, bn::sprite_items::hero_tile.tiles_item(), 6, 7);
        }

        // If the button B is pressed, the background should speed up
        if(bn::keypad::b_held()) {
            if(x_parallax_speed < 6) {
                x_parallax_speed += 0.2;
            }
        }

        if(x_parallax_speed > 6) {
            // Change background color to dark red
            bn::bg_palettes::set_transparent_color(bn::color(5, 0, 0));

            shadow_four.set_tiles(bn::sprite_items::nerd_tile.tiles_item().create_tiles(1));
            shadow_three.set_tiles(bn::sprite_items::nerd_tile.tiles_item().create_tiles(1));
            shadow_two.set_tiles(bn::sprite_items::nerd_tile.tiles_item().create_tiles(1));
            shadow_one.set_tiles(bn::sprite_items::nerd_tile.tiles_item().create_tiles(1));

            // Enable the mosaic on shadow sprites
            shadow_one.set_mosaic_enabled(true);
            shadow_two.set_mosaic_enabled(true);
            shadow_three.set_mosaic_enabled(true);
            shadow_four.set_mosaic_enabled(true);

            if(increasing_mosaic) {
                sprites_mosaic += 0.005;
                if(sprites_mosaic >= 0.4) {
                    sprites_mosaic = 0.4;
                    increasing_mosaic = false;
                }
            } else {
                sprites_mosaic -= 0.005;
                if(sprites_mosaic <= 0) {
                    sprites_mosaic = 0;
                    increasing_mosaic = true;
                }
            }

            bn::sprites_mosaic::set_stretch(sprites_mosaic);
            
            nerd.set_tiles(bn::sprite_items::nerd_tile.tiles_item().create_tiles(1));
        }

        // Ensure the hero stays within screen boundaries
        hero.set_x(bn::clamp(hero.x(), bn::fixed(-120), bn::fixed(120)));
        hero.set_y(bn::clamp(hero.y(), bn::fixed(-80), bn::fixed(80)));

        // Update the animation action
        action.update();

        // Updating the core to apply all changes per frame
        bn::core::update();
    }
}
