
#include "stdio.h"
#include "stdlib.h"
#include <sched.h>
#include <time.h>
#include <fstream>
#include <string>
#include <iostream>
#include <dirent.h>

using namespace std;

int main(){

    DIR *dir;
    char dir_str[] = "C:\\Users\\UTAT\\Desktop\\UTAT-AeRo\\2017-2018\\TeledyneDalsa\\DecodeImage\\";
    struct dirent *ent;
    if ((dir = opendir (dir_str)) != NULL) {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL) {
            size_t      length = ent->d_namlen;
            const char *filename = ent->d_name;
            const char *pointer;
            char filename_read[100];

            if (!((sscanf(filename, "%s",  filename_read) != 1)))
            {
                //printf("%s\n", filename_read);
                length = strlen(filename);
                if (!(length < 4))
                {
                            pointer = filename + length - 4;
                if (!(strncasecmp(pointer, ".txt", 4) != 0))
                    printf("%s\n", filename);
                }
            }
        }
      closedir (dir);
    } else {
        /* could not open directory */
        perror ("");
        return 1;
    }

    ifstream infile("GenieNano-C5105-full.bmp",ifstream::binary);
    ofstream outfile ("GenieNano-C5105.bmp",ofstream::binary);

    // get size of file
    infile.seekg (0,infile.end);
    long size = 1078; //infile.tellg();
    infile.seekg (0);

    // allocate memory for file content
    unsigned char* buffer = new unsigned char[size];

    // read content of infile
    infile.read (reinterpret_cast<char*>(buffer),size);
    outfile.write(reinterpret_cast<char*>(buffer),size);

    int i=0;
/*
    for (i=0; i<size; i++)
    {
        printf("%i ",buffer[i]);
    }
*/

    printf("%i\n", size);

    return 0;
}
