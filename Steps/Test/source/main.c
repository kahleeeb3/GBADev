#include <string.h>
#include <tonc.h>
#include "bgr.h"

// move the map
void move(){
	
	int tile_x = 0; // x-coor of tile
	int tile_y = 0; // y-cool of tile
	
	while(1)
	{
		vid_vsync();
		key_poll();
		tile_x += key_tri_horz();
		tile_y += key_tri_vert();
		REG_BG0HOFS= tile_x;
		REG_BG0VOFS= tile_y;
		
	}
}


// create the background
void map(){

	// Load palette
    memcpy(pal_bg_mem, bgrPal, bgrPalLen);
    // Load tiles into CBB 0
    memcpy(&tile_mem[0][0], bgrTiles, bgrTilesLen);
    // Load map into SBB 30
    memcpy(&se_mem[30][0], bgrMap, bgrMapLen);

    // set up BG0 for a 4bpp 64x32t map, using charblock 0 and screenblock 31
	// BG_CBB - Character Base Block - Sets the charblock that serves as the base for character/tile indexing. (Values: 0-3)
	// REG_BGxCNT - The primary control register (1 of 3). x indicates the background 0 -3
	// BG_SBB - Screen Base Block - Sets the screen block that serves as the base for screen-entry/map indexing. (Values: 0-31)
	// BG_4BPP (GB_8BPP) - Color Mode - 16 colors (4bpp) if cleared; 256 colors (8bpp) if set
	// BG_REG_64x64 - Regular background (not affine) - Tiles: 64x64 Pixels: 512x512
	REG_BG0CNT= BG_CBB(0) | BG_SBB(30) | BG_4BPP | BG_REG_64x64;
    REG_DISPCNT= DCNT_MODE0 | DCNT_BG0;	

}


// main function
int main()
{
	// draw the map
	map();
	// take input
	move();

	while(1);

	return 0;
}
