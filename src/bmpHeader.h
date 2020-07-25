
namespace Bitmap
{
    struct BmpHeader
    {
        unsigned char fileType[2];
        unsigned int fileSize;
        unsigned short reserved1;
        unsigned short reserved2;
        unsigned int dataOffset;
    };
    
} // namespace Bitmap
