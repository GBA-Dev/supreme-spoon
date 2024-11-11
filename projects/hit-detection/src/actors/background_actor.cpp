#include "background_actor.h"

#include "bn_bg_palettes.h"
#include "bn_log.h"

#include "bn_regular_bg_items_glacial_mountains.h"
#include "bn_regular_bg_items_clouds_bg.h"
#include "bn_regular_bg_items_clouds_mg.h"
#include "bn_regular_bg_items_cloud_lonely.h"

BackgroundActor::BackgroundActor() : _clouds_bg(bn::regular_bg_items::clouds_bg.create_bg(0, -48)),
                                     _cloud_lonely(bn::regular_bg_items::cloud_lonely.create_bg(0, -48)),
                                     _glacial_mountains(bn::regular_bg_items::glacial_mountains.create_bg(0, -48)),
                                     _clouds_mg(bn::regular_bg_items::clouds_mg.create_bg(0, -48)),
                                     _collision_behavior(16, 16) // Assuming the enemy sprite is 16x16
{
    // Set transparent color for background palettes
    bn::bg_palettes::set_transparent_color(bn::color(1, 21, 31));
}

BackgroundActor::~BackgroundActor()
{
    BN_LOG("BackgroundActor deleted");
}

void BackgroundActor::update(int, int)
{
    // Update background positions for parallax effect
    _clouds_bg.set_x(_clouds_bg.x() - x_parallax_speed * 0.2);
    _cloud_lonely.set_x(_cloud_lonely.x() - x_parallax_speed * 0.4);
    _glacial_mountains.set_x(_glacial_mountains.x() - x_parallax_speed * 0.1);
    _clouds_mg.set_x(_clouds_mg.x() - x_parallax_speed * 0.3);

    // // Optional: wrap-around effect if background moves too far to the left/right
    // if (_clouds_bg.x() < -240)
    // {
    //     _clouds_bg.set_x(240); // Assuming screen width is 240; loop background
    // }
    // if (_cloud_lonely.x() < -240)
    // {
    //     _cloud_lonely.set_x(240);
    // }
    // if (_glacial_mountains.x() < -240)
    // {
    //     _glacial_mountains.set_x(240);
    // }
    // if (_clouds_mg.x() < -240)
    // {
    //     _clouds_mg.set_x(240);
    // }
}

void BackgroundActor::draw()
{
    // No drawing logic required; Butano automatically handles rendering of backgrounds
}
// Getter implementation for collision behavior in derived classes
const CollisionBehavior *BackgroundActor::collision_behavior() const
{
    return &_collision_behavior;
}
void BackgroundActor::destroy()
{
    // Add destruction logic
}

void BackgroundActor::take_damage(int damage)
{
    // Add damage handling logic here
}
