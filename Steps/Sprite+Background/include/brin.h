
//{{BLOCK(brin)

//======================================================================
//
//	brin, 512x512@4, 
//	+ palette 16 entries, not compressed
//	+ 7 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x64 
//	Total size: 32 + 224 + 8192 = 8448
//
//	Time-stamp: 2022-10-05, 05:16:11
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BRIN_H
#define GRIT_BRIN_H

#define brinTilesLen 224
extern const unsigned short brinTiles[112];

#define brinMapLen 8192
extern const unsigned short brinMap[4096];

#define brinPalLen 32
extern const unsigned short brinPal[16];

#endif // GRIT_BRIN_H

//}}BLOCK(brin)
