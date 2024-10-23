#include "bn_core.h" // Butano core functions
#include "bn_math.h" // Butano math functions
#include "bn_log.h" // Import logging helper from Butano
#include "bn_sprite_ptr.h" // Import sprite pointer from Butano
#include "bn_sprite_text_generator.h" // Import sprite text generator from Butano

#include "fixed_32x64_sprite_font.h" // Import fixed 32x64 sprite font (We make this)

#include "common_variable_8x16_sprite_font.h" // Like Importing from a "shared" module

int main() {
    // This must be called before using Butano
    bn::core::init();

    // How to log using Butano
    BN_LOG("GAME INITIALIZED :)");

    /* 
    Explanation
        1) Namespace (bn::):
            - In C++, bn:: indicates that vector and sprite_ptr are part of the bn namespace.
              Namespaces are used to organize code and prevent name conflicts.
            - In JavaScript, this is somewhat similar to using objects or modules to group
              related functions and variables.
        2) Template (vector<bn::sprite_ptr, 32>):
            - vector is a template class in C++ that represents a dynamic array. The template 
              parameters here are bn::sprite_ptr and 32.
            - bn::sprite_ptr is the type of elements stored in the vector. In JavaScript, 
              this would be like specifying the type of elements in an array, though 
              JavaScript arrays are more flexible with types.
            - 32 is the maximum size of the vector. This is a fixed-size constraint, unlike 
              JavaScript arrays which can grow dynamically.
        3) Type (bn::sprite_ptr):
            - bn::sprite_ptr is likely a pointer to a sprite object. In JavaScript, you might 
              think of this as a reference to an object, like a reference to a DOM element 
              or a custom object.
        4) Variable Declaration (text_sprites):
             text_sprites is the name of the variable. It holds a vector of bn::sprite_ptr
              objects with a maximum size of 32.
            - In JavaScript, this would be similar to declaring an array that can 
              hold up to 32 sprite references.

    JavaScript Equivalent

    While JavaScript doesn't have direct equivalents for all these concepts, you 
    can think of it like this:

    class Sprite {  }
    let textSprites = new Array(32).fill(null).map(() => new Sprite());

    In this JavaScript example:
        - We create an array textSprites with a fixed size of 32.
        - Each element in the array is initialized to a new Sprite object.
    
    Summary
        - Namespace (bn::): 
            Similar to modules or objects in JavaScript.
        - Template (vector<bn::sprite_ptr, 32>):
            Similar to an array with type constraints and fixed size.
        - Type (bn::sprite_ptr):
            Similar to object references in JavaScript.
        - Variable (text_sprites):
            Similar to an array variable in JavaScript.
    */
    bn::vector<bn::sprite_ptr, 16> text_sprites;



    /*
    Explanation
        1) Namespace (bn::):
            - In C++, bn:: indicates that sprite_text_generator is part of the bn namespace.
              Namespaces are used to organize code and prevent name conflicts.
            - In JavaScript, this is somewhat similar to using objects or modules to group
              related functions and variables.
        2) Class (sprite_text_generator):
            - sprite_text_generator is a class within the bn namespace. Classes in C++ are 
              similar to classes in JavaScript introduced with ES6.
            - In JavaScript, you might define a class like this:

                class SpriteTextGenerator {
                    constructor(font) {
                        this.font = font;
                    }
                }

        3) Object (text_generator):
            - text_generator is an instance of the sprite_text_generator class.
            - In JavaScript, this would be similar to creating an object from a class:

                const textGenerator = new SpriteTextGenerator(fixed_32x64_sprite_font);

        4) Argument (fixed_32x64_sprite_font):
            - fixed_32x64_sprite_font is passed as an argument to the constructor 
              of sprite_text_generator. This is likely a bitmap or font object.
            - In JavaScript, this would be similar to passing an argument to a class constructor.

        JavaScript Equivalent

        Here's how you might write the equivalent code in JavaScript:

        const bn = {
            SpriteTextGenerator: class {
                constructor(font) {
                    this.font = font;
                }
            }
        };

        const fixed32x64SpriteFont = {}; // Assuming this is your font object
        const textGenerator = new bn.SpriteTextGenerator(fixed32x64SpriteFont);

        Summary
            Namespace (bn::):
                Similar to modules or objects in JavaScript.
            Class (sprite_text_generator):
                Similar to ES6 classes in JavaScript.
            Object (text_generator):
                Similar to creating an instance of a class in JavaScript.
            Argument (fixed_32x64_sprite_font):
                Similar to passing an argument to a class constructor in JavaScript.

    */
    bn::sprite_text_generator text_generator(fixed_32x64_sprite_font);



    /*
    Explanation
        1) Object Method Call (text_generator.generate):
            - text_generator is an object of the class sprite_text_generator.
            - generate is a method of the sprite_text_generator class.
            - In JavaScript, this is similar to calling a method on an object.
        2) Method Arguments (0, 0, "OPTIONS", text_sprites):
            - 0: x-coordinate for text placement.
            - 0: y-coordinate for text placement.
            - "Hello World": A string to be rendered as text.
            - text_sprites: A vector (array) to store the generated sprite objects.
            - In JavaScript, you would pass arguments to a method in a similar way.
    */
    text_generator.generate(0, -48, "foo bar baz", text_sprites);
    text_generator.set_center_alignment(); // Can be used to center the alignment of the text


    // Same as above, but with a different font from our common library
    // This font can be shared across multiple projects 
    bn::vector<bn::sprite_ptr, 32> text_sprites_import;
    bn::sprite_text_generator text_generator_import(common::variable_8x16_sprite_font);
    text_generator_import.set_center_alignment(); // Can be used to center the alignment of the text
    text_generator_import.generate(0, 16, "Hello World Common (Shared) Font", text_sprites_import);

    // Will explain this in the future it's for amimation :)
    bn::fixed angle;
    bn::fixed angle_inc = 6;

    /*
    Main loop
        Explanation
        
        Gameboy Advance needs a loop!
        In the Gameboy Advance (GBA) and other similar systems, the main loop is 
        essential for game development. Unlike modern systems with operating systems 
        that handle tasks like rendering, input, and updating in the background,
        the GBA requires developers to manage these tasks manually. The main loop is 
        where the game logic, rendering, and input processing are handled.
        
        Developers need to update the game state, handle user input, and render graphics 
        within this loop to create a playable game.

        The main loop typically consists of three main parts:
            1) Handle Input: Check for user input and update the game state accordingly.
            2) Update Game State: Update the positions of game objects, handle collisions, 
               and perform other game-related calculations.
            3) Render: Draw the game world, characters, and other elements on the screen.
    */
    while (true) {

        // Will explain this in the future it's for amimation :)
        angle += angle_inc;
        if(angle >= 360)
        {
            angle -= 360;
        }

        bn::fixed local_angle = angle;
        for(bn::sprite_ptr& character_sprite : text_sprites_import)
        {
            local_angle += angle_inc;

            if(local_angle >= 360)
            {
                local_angle -= 360;
            }

            character_sprite.set_y(bn::degrees_lut_sin(local_angle) * 16);
        }

        // move the text_sprites to the left
        for(bn::sprite_ptr& character_sprite : text_sprites)
        {
            character_sprite.set_x(character_sprite.x() - 1);

            // If the sprite is out of the screen, move it to the right at 240 pixels
            if(character_sprite.x() < -240)
            {
                character_sprite.set_x(240);
            }
        }

        // It must be called in order to update Butano's internal state
        // This is necessary to keep the game running
        bn::core::update();
    }
}