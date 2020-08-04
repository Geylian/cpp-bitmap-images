#pragma pack(push,1)

#include <cstdint>


namespace Bitmap
{
    struct BmpFileHeader
    {
        unsigned char fileType[2]; //2byte per char
        int32_t fileSize;  //4byte
        int16_t reserved1; //2byte
        int16_t reserved2; //2byte
        int32_t dataOffset; //4byte
    };

    struct BmpInfoHeader
    {
        int32_t headerSize;
        int32_t imageWidth;
        int32_t imageHeight;
        int16_t planes;
        int16_t bitsPerPixel;
        int32_t compression;
        int32_t imageSize;
        int32_t xPixelsPerMeter;
        int32_t yPixelsPerMeter;
        int32_t totalColors;
        int32_t importantColors;
    };
    
} // namespace Bitmap

#pragma pack(pop)
