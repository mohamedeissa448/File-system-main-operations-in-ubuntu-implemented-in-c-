#include <stdio.h>
#include <unistd.h> 
#include <iostream>
#include <string.h>


using namespace std;
int main(int argc, char *argv[])
{
    //(hard linking) link to new location then unlink original file
    cout<< "link status: " << link(argv[1], argv[2]) <<endl;
   cout<< strerror(errno) <<endl;

   cout<< "unlink status: " << unlink(argv[1])<< endl;
   cout<< strerror(errno) <<endl;
    return 0;
}