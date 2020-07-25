#include <iostream>
#include <fstream>

using namespace std;

int main(void) {

    // struct BmpSignature
    // {
    //     unsigned char data[2];
    // };

    struct BmpHeader
    {
        unsigned char fileType[2];
        unsigned int fileSize;
        unsigned short reserved1;
        unsigned short reserved2;
        unsigned int dataOffset;
    };

    cout << "Hello bitmap images" << endl;

    unsigned char fileType[2];
    unsigned int fileSize;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int dataOffset;

    ifstream file;

    file.open("./img/sword.bmp", ios::binary);

    file.seekg(0, ios::beg);

    file.read((char *) fileType, sizeof(fileType));
    
    if(fileType[0] == (char) 0x42 && fileType[1] == (char) 0x4D) {
        cout << "FileType : Bitmap" << endl;
    } else {
        cout << "FileType not correct" << endl;
    }

    



    return 0;
}