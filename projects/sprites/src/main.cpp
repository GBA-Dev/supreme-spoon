#include "bn_core.h"
#include "bn_sprite_actions.h"

#include "bn_sprite_items_nerdy_character_lab_coat_64x64.h"
/*
    The magic here lays with the two files in the graphics folder. Butano and the GBA have limitations
    on the size of the sprites that can be used. The task of adding bitmaps to the GBA is a bit more
    complicated than just adding a bitmap to the screen. To help with this, Butano has a tool that
    converts bitmaps to a format that the GBA can use. The tool is called Grit. The Grit tool converts
    the bitmap to a format that the GBA can use. For now we will not go into the details of how the
    Grit tool works.

    Butano will use the Grit tool and some classes to create this header file at compile time. So if your
    looking for this header file within this codebase, you will not find it. Instead, you will find the
    the two files in the graphics folder a `.bmp` and `.json` file. Butano will take those at compile time
    and create the header file. Following this naming convention: 
        <namespace>_<class_name>_<sprite_name>.h
    
    You can find the json properties that are available here:
        https://gvaliente.github.io/butano/import.html#import_sprite

    You can find the limitations of the BMP size here:
        https://gvaliente.github.io/butano/classbn_1_1sprite__shape__size.html

    You can find a wiki on how to create the BMP and JSON files here:
        https://shadowed-cantaloupe-d33.notion.site/Sprites-12b190019ea380ce8650c920275d635b?pvs=74

    Again we will go more in depth on how to use the Grit tool in a later project.
    For now this is the magic you need to know to get started with sprites in Butano.
*/

int main() {

    bn::core::init();

    /*
        And to add the sprite to the screen, you can see that we create reference("variable")
        named nerd that has a data type of bn::sprite_ptr.

        Then we used that header that was created at compile time. Like we metioned before, the
        the naming convention is <namespace>_<class_name>_<sprite_name>.h. 
        
        So in this case:
            namespace is bn,
            class name is sprite_items, 
            sprite(Object) name is nerdy_character_lab_coat_64x64.

        The method create_sprite() gives us a pointer to the sprite that we can use to manipulate.

        When invoking the create_sprite() method, you can pass in the x and y coordinates of where
        you want the sprite to be placed on the screen. The x and y coordinates are relative to the
        middle of the screen.
    */
    bn::sprite_ptr nerd = bn::sprite_items::nerdy_character_lab_coat_64x64.create_sprite(0, 0);
    
    while (true) {
        bn::core::update();
    }
}