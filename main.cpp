#include <iostream>
#include <fstream>

#include "./src/bmpHeader.h"

using namespace std;
using namespace Bitmap;

int main(void) {

    cout << "Hello bitmap images" << endl;

    ifstream file;

    BmpFileHeader header;
    BmpInfoHeader infoHeader;

    file.open("./img/sword.bmp", ios::binary);

    file.seekg(0, ios::beg);

    file.read((char *) &header, sizeof(header));
    file.read((char *) &infoHeader, sizeof(infoHeader));

    
    if(header.fileType[0] == 0x42 && header.fileType[1] == 0x4D) {
        cout << "Correct FileType" << endl;
    } else {
        cout << "FileType not correct" << endl;
    }

    cout << std::hex << header.fileType[0] << header.fileType[1] << endl;
    cout << std::dec << (int) header.fileSize << endl;
    cout << std::dec << (int) header.reserved1 << endl;
    cout << std::dec << (int) header.reserved2 << endl;
    cout << std::dec << (int) header.dataOffset << endl << endl;

    cout << std::dec << (int) infoHeader.headerSize << endl;
    cout << std::dec << (int) infoHeader.imageWidth << endl;
    cout << std::dec << (int) infoHeader.imageHeight << endl;
    cout << std::dec << (int) infoHeader.planes << endl;
    cout << std::dec << (int) infoHeader.bitsPerPixel << endl;
    cout << std::dec << (int) infoHeader.compression << endl;
    cout << std::dec << (int) infoHeader.imageSize << endl;
    cout << std::dec << (int) infoHeader.xPixelsPerMeter << endl;
    cout << std::dec << (int) infoHeader.yPixelsPerMeter << endl;
    cout << std::dec << (int) infoHeader.totalColors << endl;
    cout << std::dec << (int) infoHeader.importantColors << endl;
    

    return 0;
}