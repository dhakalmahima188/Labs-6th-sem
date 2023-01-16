#include <dirent.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    DIR* dir;
    struct dirent* ent;
    if (argc < 2) {
        printf("Usage: %s directory\n", argv[0]);
        return 1;
    }
    if ((dir = opendir(argv[1])) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            printf("%s\n", ent->d_name);
        }
        closedir(dir);
    } else {
        printf("Could not open directory\n");
        return 1;
    }
    return 0;
}
