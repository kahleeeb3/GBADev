
//{{BLOCK(brin)

//======================================================================
//
//	brin, 512x512@4, 
//	+ palette 256 entries, not compressed
//	+ 6 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x64 
//	Total size: 512 + 192 + 8192 = 8896
//
//	Time-stamp: 2022-10-03, 21:41:09
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BRIN_H
#define GRIT_BRIN_H

#define brinTilesLen 192
extern const unsigned char brinTiles[192];

#define brinMapLen 8192
extern const unsigned char brinMap[8192];

#define brinPalLen 512
extern const unsigned char brinPal[512];

#endif // GRIT_BRIN_H

//}}BLOCK(brin)
