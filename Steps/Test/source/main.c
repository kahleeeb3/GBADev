#include <string.h>
#include <tonc.h>
#include "ch1.h"

OBJ_ATTR obj_buffer[128]; // allocate space for 128 sprites
OBJ_ATTR *ch1= &obj_buffer[0]; // define the caleb sprite


void input()
{
	//u32 tid= 0, pb= 0;		// tile id, pal-bank

	while(1)
	{
		vid_vsync();
		key_poll();
			
		
		// flip left and right when moving
		// if flipped: ch1->attr1 = 0x1XXX
		// Since ATTR1_HFLIP = 0x1000, 
		// attr1 & ATTR1_HFLIP = 0x0000 when ch1 is not flipped
		
		if(key_hit(KEY_LEFT) && (ch1->attr1 & ATTR1_HFLIP) != 0x1000)
			ch1->attr1 ^= ATTR1_HFLIP;
			
		// same thing here but for the other direction
		if(key_hit(KEY_RIGHT) && (ch1->attr1 & ATTR1_HFLIP) != 0x0000)
			ch1->attr1 ^= ATTR1_HFLIP;
		
		oam_copy(oam_mem, obj_buffer, 1);	// update 1 sprite in obj_buffer

	}
}

// create the caleb sprite
void caleb(){
	
	int x = 96; // starting x pos
	int y = 32; // starting y pos
	
	memcpy(&tile_mem[4][0], ch1Tiles, ch1TilesLen); // copy tiles
	memcpy(pal_obj_mem, ch1Pal, ch1PalLen); // copy the palette
	
	obj_set_attr(ch1, 
		ATTR0_SQUARE,		// Square, regular sprite
		ATTR1_SIZE_32,		// 32x32p, 
		0);					// Not sure this is relevant to me?

	obj_set_pos(ch1, x, y);
	
}
int main()
{
	
	oam_init(obj_buffer, 128); // initialize 128 sprites
	REG_DISPCNT= DCNT_OBJ | DCNT_OBJ_1D; // Enable Objects & OBJ-VRAM as array.
	
	// create caleb
	caleb();
	
	// take input
	input();

	while(1);

	return 0;
}		