#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;
int main(int argc, char *argv[])

{
    cout << "status: " << rename(argv[1], argv[2]) << endl;
    cout << strerror(errno) << endl;

    return 0;
}