#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include <pthread.h>
#include "sharedMem.h"


int main(int argc, char **argv)
{
    destMemBlock(FILENAME);
    //ftok - gives us a key
    //key -shmget - block of mem
    //shmat returns a poiter to the block
    
    sem_unlink(SEMS);
    sem_unlink(SEMR);

    sem_t *semSender = sem_open(SEMS, O_CREAT, 0660, 0);
    if(semSender == SEM_FAILED){
        perror("semSender failed");
        exit(0);
    }

    sem_t *semReciever = sem_open(SEMR, O_CREAT, 0660, 1);
    if(semReciever == SEM_FAILED){
        perror("semSender failed");
        exit(0);
    }

    char *block = attachMemBlock(FILENAME, SIZE*sizeof(char));
    if (block==NULL){
        printf("Couldnt get the block");


    }
    int memCount = 0;
    int semFlag = 1;
    while(true){
        if(semFlag==1){
            semFlag = 0;
            sem_wait(semReciever);
        }
        
        //char *temp= malloc(SIZE*sizeof(char));
        printf("sending:");
        scanf(" %c", (block+memCount));
        //strncpy(block, temp, SIZE);
        memCount++;
        if(memCount==SIZE){
            //printf("Received: %s\n", block);
            memCount = 0;
            semFlag = 1;
            sem_post(semSender);
        }
    }

    // sem_close(semSender);
    // sem_close(semReciever);
    // shmdt(block);
    
    return 0;
    
}
