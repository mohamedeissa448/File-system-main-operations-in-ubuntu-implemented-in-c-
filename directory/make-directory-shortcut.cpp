#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;
int main(int argc, char *argv[])

{
    // Note: shortcut in linux is implemented via symbolic linking
    cout << "symlink status: " << symlink(argv[1], argv[2]) << endl;
    cout << strerror(errno) << endl;

    return 0;
}