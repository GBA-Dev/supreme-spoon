#include "bn_core.h"
#include "bn_math.h"

int main() {

    bn::core::init();

    while (true) {

        bn::core::update();
    }
}