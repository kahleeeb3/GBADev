#include <string.h>
#include <tonc.h>
#include "ch1.h"
#include "brin.h"

#define CBB_0  0
#define SBB_0 28

OBJ_ATTR obj_buffer[128]; // allocate space for 128 sprites
OBJ_ATTR *ch1= &obj_buffer[0]; // define the caleb sprite
//int x= 0, y= 0;

// take some user input
void input(){

	int tile_x = 0; // x-coor of tile
	int tile_y = 0; // y-cool of tile
	int char_x = 104; // x-coor of character
	int char_y = 64; // y-coor of character
	
	while(1)
	{
		vid_vsync();
		key_poll();		
		
		// create boundary
		// map corners at x->{0, 238}, y->{0, 167}
		// screen corners x->{0,208}, y->{0,128}
		
		// if going too far horz
		if( (tile_x == 0 && key_tri_horz() == -1) || (tile_x == 240 && key_tri_horz() == 1) ){
			// move character instead
			if( (char_x == 0 && key_tri_horz() == -1) || (char_x == 208 && key_tri_horz() == 1) )
				continue;
			else
				char_x += 2*key_tri_horz(); // move left/right
			// 
		}
		
		// if going to far vert
		else if( (tile_y == 0 && key_tri_vert() == -1) || (tile_y == 160 && key_tri_vert() == 1) ){
			// move character instead
			if( (char_y == 0 && key_tri_vert() == -1) || (char_y == 128 && key_tri_vert() == 1) )
				continue;
			else
				char_y += 2*key_tri_vert(); // move up/down
		}
		
		// else, move the tile
		else{
			tile_x += key_tri_horz();
			tile_y += key_tri_vert();
			REG_BG0HOFS= tile_x;
			REG_BG0VOFS= tile_y;
		}
		 

		
		//flip left and right when moving
		//if flipped: ch1->attr1 = 0x1XXX
		//Since ATTR1_HFLIP = 0x1000, 
		//attr1 & ATTR1_HFLIP = 0x0000 when ch1 is not flipped
		if(key_hit(KEY_LEFT) && (ch1->attr1 & ATTR1_HFLIP) != 0x1000)
			ch1->attr1 ^= ATTR1_HFLIP;
			
		// same thing here but for the other direction
		if(key_hit(KEY_RIGHT) && (ch1->attr1 & ATTR1_HFLIP) != 0x0000)
			ch1->attr1 ^= ATTR1_HFLIP;
		
		obj_set_pos(ch1, char_x, char_y);
		oam_copy(oam_mem, obj_buffer, 1);	// update 1 sprite in obj_buffer

	}
}

// create the caleb sprite
void caleb(){

	REG_DISPCNT= DCNT_MODE0 | DCNT_BG0 | DCNT_OBJ| DCNT_OBJ_1D;
	
	int x = 104; // starting x pos
	int y = 64; // starting y pos
	
	memcpy(&tile_mem[4][0], ch1Tiles, ch1TilesLen); // copy tiles
	memcpy(pal_obj_mem, ch1Pal, ch1PalLen); // copy the palette
	
	obj_set_attr(ch1, 
		ATTR0_SQUARE,		// Square, regular sprite
		ATTR1_SIZE_32,		// 32x32p, 
		0);					// Not sure this is relevant to me?

	obj_set_pos(ch1, x, y);
	
	oam_copy(oam_mem, obj_buffer, 1);	// update 1 sprite in obj_buffer	
}

// create the background
void map(){

	REG_BG0CNT= BG_CBB(CBB_0) | BG_SBB(SBB_0) | BG_REG_64x64;
	REG_BG0HOFS= 0;
	REG_BG0VOFS= 0;

	// Load palette
	memcpy(pal_bg_mem, brinPal, brinPalLen);
	// Load tiles into CBB 0
	memcpy(&tile_mem[CBB_0][0], brinTiles, brinTilesLen);
	// Load map into SBB 30
	memcpy(&se_mem[SBB_0][0], brinMap, brinMapLen);

}

int main()
{
	map();
	
	//oam_init(obj_buffer, 128); // initialize 128 sprites
	//REG_DISPCNT= DCNT_OBJ | DCNT_OBJ_1D; // Enable Objects & OBJ-VRAM as array.
	
	// create caleb
	//caleb();
	
	// take input
	//input();

	while(1);

	return 0;
}
