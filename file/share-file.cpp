#include <unistd.h> // for fork()
#include <iostream>
#include <string.h>
using namespace std;
int main(int argc, char *argv[])
{
    // Hard linking
    cout << "link status: " << link(argv[1], argv[2]) << endl;
    cout << strerror(errno) << endl;
    return 0;
}