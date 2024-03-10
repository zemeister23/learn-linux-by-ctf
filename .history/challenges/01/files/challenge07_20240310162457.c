#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    const char *filename = "example.txt";
    struct stat file_stat;

    // Use stat to retrieve file information
    if (stat(filename, &file_stat) == 0) {
        // Check if file permissions are 744
        if ((file_stat.st_mode & S_IRWXU) == S_IRUSR|S_IWUSR|S_IXUSR && (file_stat.st_mode & S_IRGRP) && (file_stat.st_mode & S_IROTH)) {
            printf("Flag: FLAG_PERMISSIONS_744\n");
        } else {
            printf("File permissions are not set to 744\n");
        }
    } else {
        perror("stat");
        return 1;
    }

    return 0;
}
