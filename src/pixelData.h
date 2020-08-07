#pragma pack(push,1)
#include <cstdint>


namespace Bitmap
{
    struct PixelData
    {
        uint8_t blue;
        uint8_t green;
        uint8_t red;
    };

    struct Padding
    {
        uint8_t padding;
    };
    
} // namespace Bitmap

#pragma pack(pop)
