
@{{BLOCK(variable_8x16_font_red_bn_gfx)

@=======================================================================
@
@	variable_8x16_font_red_bn_gfx, 8x16@4, 
@	+ palette 16 entries, not compressed
@	+ 2 tiles not compressed
@	Total size: 32 + 64 = 96
@
@	Time-stamp: 2024-10-22, 20:06:40
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global variable_8x16_font_red_bn_gfxTiles		@ 64 unsigned chars
	.hidden variable_8x16_font_red_bn_gfxTiles
variable_8x16_font_red_bn_gfxTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000CEE,0x00000CEE,0x00000CEE
	.word 0x00000CEE,0x00000CEE,0x00000CCC,0x00000CEE,0x00000CCC,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global variable_8x16_font_red_bn_gfxPal		@ 32 unsigned chars
	.hidden variable_8x16_font_red_bn_gfxPal
variable_8x16_font_red_bn_gfxPal:
	.hword 0x03E0,0x2D06,0x2CED,0x20D6,0x1CFC,0x318C,0x4189,0x219E
	.hword 0x5E0C,0x5E2C,0x2A5F,0x52F0,0x0000,0x6317,0x001F,0x0001

@}}BLOCK(variable_8x16_font_red_bn_gfx)
