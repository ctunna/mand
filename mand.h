#ifndef MAND_H
#define MAND_H

#define uint16 unsigned short
#define uint32 unsigned int
#define uint8  unsigned char

#define BYTE  unsigned char
#define DWORD  unsigned int
#define LONG  int
#define UINT  unsigned int
#define WORD  unsigned short int
#define LPSTR  char*

#pragma pack(1)
typedef struct
{
	uint16 magic;       /* specifies the file type "BM" 0x424d */
	uint32 bfSize;      /* specifies the size in bytes of the bitmap file */
	uint16 bfReserved1; /* reserved; must be 0 */
	uint16 bfReserved2; /* reserved; must be 0 */
	uint32 bOffBits;
} BITMAPFILEHEADER;

typedef struct{
	uint32 size;
	uint32 width;
	uint32 height;
	uint16 planes;
	uint16 bitcount;
	uint32 compression;
	uint32 sizeimage;
	int xpelspermeter;
	int ypelspermeter;
	uint32 colorsused;
	uint32 colorsimportant;
} BITMAPINFOHEADER;

typedef struct {
	uint8 b;
	uint8 g;
	uint8 r;
	
} color_triplet;
#pragma pack(0)

#endif
