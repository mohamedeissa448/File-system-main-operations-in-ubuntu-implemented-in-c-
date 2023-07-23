#include <sys/stat.h>
#include <iostream>

using namespace std;
int main(int argc, char *argv[])

{
    cout<< "status(0 for success): " << remove(argv[1]) <<endl;// Deletes empty directories or single files.

    return 0;
}