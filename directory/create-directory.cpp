#include <sys/stat.h>
#include <iostream>

using namespace std;
int main(int argc, char *argv[])

{
    const int dir_err = mkdir(argv[1], S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    if (-1 == dir_err)
    {
        printf("Error creating directory!n");
        exit(1);
    }
    return 0;
}