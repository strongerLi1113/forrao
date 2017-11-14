#ifndef CONVERSION_H
#define CONVERSION_H
#include <stdint.h>


class conversion
{
public:
    conversion();
    int YUV2RGB(unsigned char *pYUV, unsigned char *pBGR24, int width, int height);
};
#endif // CONVERSION_H

