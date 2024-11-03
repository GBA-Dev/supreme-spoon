#include "background_actor.h"

#include "bn_bg_palettes.h"
#include "bn_log.h"

#include "bn_regular_bg_items_glacial_mountains.h"
#include "bn_regular_bg_items_clouds_bg.h"
#include "bn_regular_bg_items_clouds_mg.h"
#include "bn_regular_bg_items_cloud_lonely.h"

BackgroundActor::BackgroundActor() :
    _clouds_bg(bn::regular_bg_items::clouds_bg.create_bg(0, -48)),
    _cloud_lonely(bn::regular_bg_items::cloud_lonely.create_bg(0, -48)),
    _glacial_mountains(bn::regular_bg_items::glacial_mountains.create_bg(0, -48)),
    _clouds_mg(bn::regular_bg_items::clouds_mg.create_bg(0, -48)) {

    bn::bg_palettes::set_transparent_color(bn::color(1, 21, 31));
}

BackgroundActor::~BackgroundActor() {
    BN_LOG("BackgroundActor destroyed.");
}

void BackgroundActor::update() {
    _clouds_bg.set_x(_clouds_bg.x() - x_parallax_speed * 0.2);
    _cloud_lonely.set_x(_cloud_lonely.x() - x_parallax_speed * 0.4);
    _glacial_mountains.set_x(_glacial_mountains.x() - x_parallax_speed * 0.1);
    _clouds_mg.set_x(_clouds_mg.x() - x_parallax_speed * 0.3);
}

void BackgroundActor::draw() {
}
