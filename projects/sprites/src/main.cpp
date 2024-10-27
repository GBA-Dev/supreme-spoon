#include "bn_core.h"
#include "bn_math.h"
#include "bn_sprite_actions.h"

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
#include "bn_sprite_items_nerdy_character_lab_coat_64x64.h"

int main() {

    bn::core::init();

    // We will explain this later
    bn::fixed time = 0;
    bn::fixed amplitude_x = 60;
    bn::fixed amplitude_y = 36;
    bn::fixed speed = 0.003;

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

        /*
            We can take all kind of actions(Move, Scale, Rotate, etc) to manipulate the sprite. 
            GBA's hardware has registers that can be manipulated to move the sprite around the 
            screen.

            Butano abstracts GBA hardware registers through a higher-level API, allowing you to 
            manipulate sprites without directly accessing hardware registers. However, underneath 
            Butano's abstractions, the GBA does use hardware registers to move sprites. Butano’s 
            software handles most details, like sprite movement and animation, by interfacing with 
            the GBA’s hardware.

            If you need ultra-precise control, you can access GBA hardware registers directly to 
            manipulate sprites, but it requires a good understanding of GBA memory mapping. Using GBA 
            hardware registers directly (OAM memory for sprites) allows for fine-grained control 
            over properties like position, rotation, scaling, and priority.
        */

       /*
            The Game Boy Advance screen has a resolution of 240x160 pixels, giving it a total of 38,400 pixels.

            In Butano, the screen coordinates are set up with the center of the screen as (0, 0). 
            This setup differs from the more common origin-at-top-left approach in many graphics systems. 
            Here’s how the coordinate system works on the GBA screen in Butano:
            
            X-Axis:
                Ranges from -120 to +119 horizontally.
                -120 is the far left, and +119 is the far right.

            Y-Axis:
                Ranges from -80 to +79 vertically.
                -80 is the top, and +79 is the bottom.

            Top-left corner: (-120, -80)
            Bottom-right corner: (119, 79)
            Center: (0, 0)

            `nerd` is a sprite_ptr object that has "action" methods like set_position(), set_x(), etc.
            This puts the sprite at the bottom-right corner:
       */
        // nerd.set_x(-120);
        // nerd.set_y(79);

        /*
            The key to making the sprite move in a smooth, oscillating motion lies in the trigonometry
            functions `bn::cos()` and `bn::sin()`. These functions return values that "wave" or oscillate 
            between -1 and 1, creating a natural back-and-forth pattern as `time` progresses. 

            Here's how it works step-by-step:

            1. Periodic Nature of Cosine and Sine: The `cos()` and `sin()` functions are based on 
               the unit circle. As `time` increases, `cos(time)` and `sin(time)` cycle through a smooth 
               oscillation from -1 to 1 and back, creating a repeated pattern that perfectly suits 
               animations with no abrupt starts or stops.

            2. Mapping the Output to Screen Movement: By multiplying `cos(time)` and `sin(time)` 
               by an amplitude (like `amplitude_x` and `amplitude_y`), we scale the oscillation, which 
               controls the maximum distance the sprite can move horizontally (x-axis) and vertically 
               (y-axis). Larger amplitudes mean a wider movement, while smaller amplitudes create a 
               tighter motion.

            3. Why Time Matters: `time` is the input to both `cos()` and `sin()`, and it 
               increases gradually with each frame, effectively "driving" the oscillation. By adding 
               `speed` to `time`, we control how fast the sprite moves back and forth. Higher speeds 
               make the animation faster, while lower speeds slow it down.

            4. Why Oscillations Can Appear Jerky: It's important to choose values for `amplitude_x`, 
               `amplitude_y`, and `speed` carefully. If these values are too large or too small, they 
               can lead to jerky or unnatural movement. For example, very high values of `speed` might 
               make the animation appear choppy because the sprite will jump over pixels too quickly. 
               Similarly, extremely high or low values for `amplitude_x` or `amplitude_y` might cause 
               the sprite to exceed the screen boundaries or barely move at all. We will talk more about
               creating smooth animations with a concept called Tweening with easing functions.

            By using `bn::cos(time) * amplitude_x` and `bn::sin(time) * amplitude_y` to set the sprite's 
            x and y coordinates, we create a fluid, natural back-and-forth motion. With the right values, 
            this approach provides smooth, wave-like animation that's perfect for adding life to game 
            elements or UI components!

            Here's the code that makes the sprite move in a smooth, oscillating motion:
            nerd.set_x(bn::cos(time) * amplitude_x);
            nerd.set_y(bn::sin(time) * amplitude_y);

            or another way to write it:
        */
        nerd.set_position(bn::fixed_point(bn::cos(time) * amplitude_x, bn::sin(time) * amplitude_y));

        // Increment the time variable
        time += speed;

        bn::core::update();
    }
}