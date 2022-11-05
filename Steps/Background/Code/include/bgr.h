
//{{BLOCK(bgr)

//======================================================================
//
//	bgr, 512x512@4, 
//	+ palette 8 entries, not compressed
//	+ 404 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x64 
//	Total size: 16 + 12928 + 8192 = 21136
//
//	Time-stamp: 2022-11-04, 23:53:33
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BGR_H
#define GRIT_BGR_H

#define bgrTilesLen 12928
extern const unsigned char bgrTiles[12928];

#define bgrMapLen 8192
extern const unsigned char bgrMap[8192];

#define bgrPalLen 16
extern const unsigned char bgrPal[16];

#endif // GRIT_BGR_H

//}}BLOCK(bgr)
