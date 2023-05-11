#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

#define ERROR  -1
#define OK      0

int main(int argc,char *argv[])
{
    int i = 1;
    int pid = fork();
    if(pid < 0){
        perror("Create process failed!\n");
        return ERROR;
    }
    else if(pid > 0){    //father
        while(i<11){
            if(i%2){
                printf("father: %d\n",i);
            }
            sleep(1);
            i++;
        }
        exit(0);
    }
    else if(pid == 0){   //son
        while(i<11){
            if(i%2 == 0){
                printf("son: %d\n",i);
            }
            i++;
            sleep(1);
        }
        wait(NULL);
    }


    return 0;
}
