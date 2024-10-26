#include "bn_core.h"
#include "bn_sprite_actions.h"

#include "bn_sprite_items_nerdy_character_lab_coat_64x64.h"

int main() {

    bn::core::init();
    bn::sprite_ptr nerd = bn::sprite_items::nerdy_character_lab_coat_64x64.create_sprite(0, 0);
    
    while (true) {
        bn::core::update();
    }
}