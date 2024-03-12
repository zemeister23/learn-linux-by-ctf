#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define WANTED_PATH "/home/challenge07/you/can/.achieve/this/Trust/Yourself.py"

int main() {
    const char *filename = WANTED_PATH;
    struct stat file_stat;

    if (stat(filename, &file_stat) == 0) {        
        if ((file_stat.st_mode & S_IRWXU) == S_IRUSR|S_IWUSR|S_IXUSR && (file_stat.st_mode & S_IRGRP) && (file_stat.st_mode & S_IROTH)) {
            printf("Flag: {{flag}}\n");
        } else {
            printf("File permissions are not set to 744\n");
        }
    } else {
        printf("Try Harder Neo, Never Give Up!\n");
        perror("stat");
        return 1;
    }

    return 0;
}
