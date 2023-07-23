#include <sys/stat.h>
#include <iostream>
#include <filesystem>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

using namespace std;
int main(int argc, char *argv[])

{
    //1)-First solution: using (Rename)
    /* 
    cout << "Rename status: " << rename(argv[1], argv[2]);
    cout << strerror(errno) << endl;
    */
// 1)-Second solution: Move all files inside original directory to new location

    DIR *dir; // pointer to directory

    dir = opendir(argv[1]);
    if (!dir)
    {
        cout << "Couldn't open directory!";
        return 1;
    }

    // create destination directory
    const int dir_err = mkdir(argv[2], S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    if (-1 == dir_err)
    {
        printf("Error creating destination directory!n");
        exit(1);
    }
    struct dirent *entry; // all stuff in the directory
    struct stat info;     // info about each entry

    while ((entry = readdir(dir)) != NULL)
    {
        cout << "d_name: " << entry->d_name << endl;
        if (entry->d_name[0] != '.')
        {
            char source[20];
            strcpy(source, argv[1]);

            char destination[20];
            strcpy(destination, argv[2]);

            char *from = strcat(source, "/");
            from = strcat(from, entry->d_name);
            cout << "from: " << from << endl;

            char *to = strcat(destination, "/");
            to = strcat(to, entry->d_name);
            cout << "to: " << to << endl;

            cout << "link status: " << link(from, to) << endl;

            cout << "unlink status: " << unlink(from) << endl;

            *source = *argv[1];
            *destination = *argv[2];
        }
    }

    cout << "---------------------------------" << endl;
    cout << "remove status: " << remove(argv[1]) << endl;
    cout << "close directory status: " << closedir(dir) << endl;
    cout<< strerror(errno) <<endl;

    return 0;
}