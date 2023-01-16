#include <stdio.h>
#include <stdlib.h>

#include<sys/types.h>
#include<sys/stat.h>

int main(){
    int id;
    // create return 0 on success and -1 on error
    if(id = creat("z.txt", 0) == -1){
        printf("cannot create the file\n");
        exit(1);
    }
    else{
        printf("file is created");
        exit(1);
    }
}

