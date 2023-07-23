#include <iostream>
#include <fstream>

using namespace std;
int main(int argc, char *argv[])
{
    // read original file and write to destination file
    char data[100];

    ifstream originalFile;
    ofstream destinationFile;
    originalFile.open(argv[1], ios::out);
    destinationFile.open(argv[2], ios::out);

    while (true)
    {
        originalFile.getline(data, 1000, EOF);
        destinationFile << data;

        if (originalFile.eof())
            break;
    }
    originalFile.close();
    destinationFile.close();
    return 0;
}