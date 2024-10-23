#ifndef BN_SPRITE_ITEMS_FIXED_32X64_FONT_H
#define BN_SPRITE_ITEMS_FIXED_32X64_FONT_H

#include "bn_sprite_item.h"

//{{BLOCK(fixed_32x64_font_bn_gfx)

//======================================================================
//
//	fixed_32x64_font_bn_gfx, 32x7040@4, 
//	+ palette 16 entries, not compressed
//	+ 3520 tiles not compressed
//	Total size: 32 + 112640 = 112672
//
//	Time-stamp: 2024-10-22, 20:06:40
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_FIXED_32X64_FONT_BN_GFX_H
#define GRIT_FIXED_32X64_FONT_BN_GFX_H

#define fixed_32x64_font_bn_gfxTilesLen 112640
extern const bn::tile fixed_32x64_font_bn_gfxTiles[3520];

#define fixed_32x64_font_bn_gfxPalLen 32
extern const bn::color fixed_32x64_font_bn_gfxPal[16];

#endif // GRIT_FIXED_32X64_FONT_BN_GFX_H

//}}BLOCK(fixed_32x64_font_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item fixed_32x64_font(sprite_shape_size(sprite_shape::TALL, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(fixed_32x64_font_bn_gfxTiles, 3520), bpp_mode::BPP_4, compression_type::NONE, 110), 
            sprite_palette_item(span<const color>(fixed_32x64_font_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

