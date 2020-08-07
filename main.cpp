#include <iostream>
#include <fstream>

#include "./src/bmpHeader.h"
#include "./src/pixelData.h"

using namespace std;
using namespace Bitmap;

int main(void) {

    cout << "Hello bitmap images" << endl;

    ifstream file;

    BmpFileHeader header;
    BmpInfoHeader infoHeader;
    BmpColorTable colorTable;
    PixelData pixelData;
    Padding padding;

    string filePath;

    cout << "Enter FilePath = ";
    cin >> filePath;

    file.open(filePath, ios::binary);

    file.seekg(0, ios::beg);

    file.read((char *) &header, sizeof(header));
    file.read((char *) &infoHeader, sizeof(infoHeader));
    file.read((char *) &colorTable, sizeof(colorTable));
    
    if(header.fileType[0] == 0x42 && header.fileType[1] == 0x4D) {
        cout << "Correct FileType" << endl;
    } else {
        cout << "FileType not correct" << endl;
    }

    cout << std::hex << "FileType : 0x" << (int) header.fileType[0] << (int) header.fileType[1] << endl;
    cout << std::dec << "FileSize : " << (int) header.fileSize << endl;
    cout << std::dec << "reserved 1 : " << (int) header.reserved1 << endl;
    cout << std::dec << "reserved 2 : " << (int) header.reserved2 << endl;
    cout << std::dec << "dataOffset : " << (int) header.dataOffset << endl;
    cout << "--------------------" << endl;
    cout << std::dec << "headerSize : " << (int) infoHeader.headerSize << endl;
    cout << std::dec << "Width : " << (int) infoHeader.imageWidth << endl;
    cout << std::dec << "Height : " << (int) infoHeader.imageHeight << endl;
    cout << std::dec << "planes : " << (int) infoHeader.planes << endl;
    cout << std::dec << "bits Per Pixel : " << (int) infoHeader.bitsPerPixel << endl;
    cout << std::dec << "compression : " << (int) infoHeader.compression << endl;
    cout << std::dec << "imageSize : " << (int) infoHeader.imageSize << endl;
    cout << std::dec << "x pixels Per Meter : " << (int) infoHeader.xPixelsPerMeter << endl;
    cout << std::dec << "y pixels Per Meter : " << (int) infoHeader.yPixelsPerMeter << endl;
    cout << std::dec << "total Colors : " << (int) infoHeader.totalColors << endl;
    cout << std::dec << "important Colors : " << (int) infoHeader.importantColors << endl;
    cout << "--------------------" << endl;

    int paddingNumber = 0;
    paddingNumber = (infoHeader.imageWidth * 3) % 4;


    if(!(((infoHeader.imageWidth * 3) % 4) == 0)) {
        paddingNumber = 4 - ((infoHeader.imageWidth * 3) % 4);
    } else {
        paddingNumber = 0;
    }

    cout << "padding number: " << paddingNumber << endl;
    cout << "--------------------" << endl;

    file.seekg(54, ios::beg);

    // while (!file.eof())
    // {
    //     file.read((char *) &padding, sizeof(padding));
    //     cout << std::hex << (int) padding.padding << " ";
    // }
    
    for (int height = 0; height < infoHeader.imageHeight; height++)
    {

        for (int width = 0; width < infoHeader.imageWidth; width++)
        {

            
            file.read((char *) &pixelData, sizeof(pixelData));

            cout << std::dec << (int) pixelData.red << " " << (int) pixelData.green << " " << (int) pixelData.blue << "   ";
        }

        for (int paddingCounter = 0; paddingCounter < paddingNumber; paddingCounter++)
        {
            file.read((char *) &padding, sizeof(padding));
        }

        cout << endl;
        
    }
    
    return 0;
}