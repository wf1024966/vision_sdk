#include <examples/tda2xx/include/draw2d.h>
/*
* 16-bit RGB565 font data
 */

static const unsigned int gDraw2D_Bmp_BytesPerPixel = 2;
static const unsigned int gDraw2D_Bmp_Width         = 25;
static const unsigned int gDraw2D_Bmp_Height        = 25;

static const unsigned char gDraw2D_Bmp[] =
{


0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x03,0x50,0x05,0x78,0x06,0x90,0x07,0x90,0x07,0x88,0x05,0x80,0x03,0x48,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x05,0x78,0x06,0xb0,0x07,0xd8,0x07,0xc8,0x07,0xb0,0x07,0xa0,0x07,0x98,0x07,0xa0,
0x07,0xc0,0x07,0xb0,0x05,0x80,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x07,0x98,0x07,0xb8,0x07,0xb8,0x06,0xc0,0x08,0xd8,0x29,0xf8,0x07,0xe8,0x08,0xe0,0x07,0xe0,0x07,0xc8,0x06,0xc8,0x07,0xb0,0x07,0xa0,0x01,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x07,0xa8,0x07,0xd8,0x06,0xe0,0x07,0xd8,0x49,0xf0,
0x09,0xf8,0x6a,0xf8,0x09,0xf8,0x69,0xf8,0xaa,0xf8,0x4a,0xe8,0x08,0xd0,0x07,0xc8,0x07,0xb8,0x08,0xb8,0x01,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x98,0x06,0xd0,0x07,0xc0,0x07,0xe8,0x08,0xf8,0xaa,0xf8,0x49,0xf8,0x09,0xf8,0x07,0xf8,0x08,0xf8,0x6a,0xf8,0x29,0xf8,0xcc,0xf8,0x49,0xf8,0x08,0xe8,0x07,0xd0,0x07,0xb8,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x80,0x07,0xd0,
0x06,0xc8,0x07,0xc8,0x07,0xf0,0x08,0xf8,0x07,0xf8,0x49,0xf8,0xeb,0xf8,0x0c,0xf9,0xec,0xf8,0xab,0xf8,0xca,0xf8,0x69,0xf8,0x08,0xf8,0x08,0xe8,0x08,0xc8,0x08,0xd0,0x05,0x88,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x07,0xa8,0x06,0xb8,0x07,0xd0,0x08,0xf8,0x49,0xf8,0x08,0xf8,0x6a,0xf8,0x09,0xf8,0x49,0xf8,0xeb,0xf8,0xea,0xf8,0x8a,0xf8,0x08,0xf8,0x08,0xf8,0x29,0xf8,0x08,0xf8,0x07,0xe0,0x07,0xc8,0x07,0xd8,0x00,0x28,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x03,0x50,0x06,0x98,0x06,0xb0,0x07,0xe8,0x28,0xf8,0x6a,0xf8,0x8a,0xf8,0xca,0xf8,0x09,0xf8,0x07,0xf8,0x07,0xf8,0x08,0xf8,0x07,0xf8,0x07,0xf8,0xcb,0xf8,0x6a,0xf8,0xaa,0xf8,0x07,0xf8,0x07,0xd0,0x07,0xc0,0x03,0x68,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x88,0x06,0xc8,0x07,0xd0,0x07,0xe8,0x07,0xf8,0x07,0xf8,0x08,0xf8,0xea,0xf8,0x6c,0xf9,0xed,0xf9,0xc9,0xf8,0xeb,0xf8,0x4b,0xf9,0xca,0xf8,0x69,0xf8,0x09,0xf8,0x29,0xf8,0xaa,0xf8,
0x08,0xd8,0x07,0xa8,0x05,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0xa0,0x07,0xd0,0x08,0xd8,0x08,0xf0,0x07,0xf8,0x08,0xf8,0x2b,0xf9,0x0b,0xf9,0xaf,0xfa,0x74,0xfc,0x33,0xfc,0xf6,0xfc,0xf0,0xfa,0xca,0xf8,0x49,0xf8,0x08,0xf8,0x07,0xf8,0x08,0xe8,0x08,0xe0,0x07,0xc0,0x06,0xa0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x78,0x06,0xa8,0x07,0xc8,0x08,0xf8,0x08,0xf8,0x07,0xf8,0x2a,0xf9,0x4d,0xfa,0x74,0xfc,0xbb,0xfe,0x9e,0xff,0xfc,0xfe,0x16,0xfd,
0x0d,0xfa,0x6b,0xf9,0x89,0xf8,0x08,0xf8,0x08,0xf0,0x07,0xe8,0x07,0xd8,0x06,0xc8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x88,0x07,0xb8,0x07,0xe0,0x07,0xf0,0x07,0xf0,0x06,0xf8,0x07,0xf8,0xcc,0xf9,0xb5,0xfc,0xbe,0xff,0xff,0xff,0xbe,0xff,0xd5,0xfc,0x2e,0xfa,0xea,0xf8,0x69,0xf8,0x69,0xf8,0x08,0xf8,0x07,0xc0,0x08,0xb8,0x06,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x90,0x07,0xb8,0x07,0xd8,0x07,0xe0,0x07,0xf0,0x07,0xf8,0x07,0xf8,0x28,0xf8,
0x0d,0xfa,0xf3,0xfb,0xf6,0xfc,0x31,0xfb,0x6c,0xf9,0x48,0xf8,0x07,0xf8,0x09,0xf8,0x07,0xe8,0x49,0xf0,0x08,0xd8,0x08,0xc0,0x04,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x58,0x08,0xb0,0x07,0xd0,0x07,0xe8,0x08,0xf8,0x06,0xf8,0x06,0xf8,0x69,0xf8,0xca,0xf8,0x06,0xf8,0x08,0xf8,0x08,0xf8,0x4a,0xf8,0x28,0xf8,0x08,0xf8,0x07,0xf8,0x07,0xf8,0x07,0xe0,0x07,0xd8,0x07,0xc8,0x03,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x07,0xb0,0x07,0xc0,
0x08,0xe8,0x08,0xf8,0x07,0xf8,0x06,0xf8,0xca,0xf8,0x4b,0xf9,0xaa,0xf8,0x06,0xf8,0x89,0xf8,0x8a,0xf8,0x89,0xf8,0x27,0xf8,0x08,0xf8,0x08,0xf8,0x07,0xe8,0x08,0xd0,0x08,0xb0,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x98,0x08,0xd8,0x07,0xd0,0x08,0xf0,0x08,0xf8,0x08,0xf8,0x07,0xf8,0x0b,0xf9,0x0b,0xe9,0x28,0xf0,0x2c,0xf9,0x2b,0xf9,0x69,0xf8,0x08,0xf8,0x08,0xf8,0x08,0xf8,0x07,0xd8,0x08,0xd0,0x05,0x88,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x07,0xc8,0x08,0xe0,0x07,0xf0,0x07,0xf8,0x07,0xf8,0x07,0xf8,0x2b,0xf9,0xeb,0xf0,0x6d,0xf9,0x8d,0xf9,0x2c,0xf9,0x07,0xf8,0x07,0xf8,0x07,0xf8,0x08,0xe0,0x07,0xd8,0x08,0xd8,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x48,0x08,0xf8,0x08,0xe8,0x08,0xf0,0x07,0xf8,0x07,0xf8,0x49,0xf0,0x09,0xf8,0x08,0xf8,0x89,0xf8,0xea,0xf0,0x07,0xf8,0x07,0xf8,0x07,0xe0,0x08,0xe8,0x09,0xf0,
0x01,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x50,0x08,0xf0,0x08,0xf8,0x07,0xf8,0x07,0xf8,0x06,0xf0,0x06,0xf8,0x06,0xf8,0x05,0xf8,0x06,0xf8,0x07,0xf8,0x08,0xf8,0x08,0xf8,0x08,0xf8,0x02,0x58,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x06,0xc0,0x08,0xf8,0x08,0xf8,0x07,0xf0,0x07,0xf8,0x07,0xf8,0x07,0xf8,0x28,0xf8,
0x2a,0xf8,0x09,0xf8,0x06,0xc8,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x38,0x03,0x88,0x07,0xd8,0x48,0xf0,0xa9,0xf8,0x08,0xf8,0x07,0xd0,0x04,0x98,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 // 1250 bytes

};

Int32 Draw2D_getBmpProperty15(Draw2D_BmpProperty *pProp)
{
    pProp->width  = gDraw2D_Bmp_Width;
    pProp->height = gDraw2D_Bmp_Height;
    pProp->addr   = (UInt32)gDraw2D_Bmp;
    pProp->bpp    = gDraw2D_Bmp_BytesPerPixel;
    pProp->lineOffset = pProp->width*pProp->bpp;

    return 0;
}