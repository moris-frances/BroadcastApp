#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include "sharedMem.h"

int main(int argc, char **argv)
{

    sem_t *semSender = sem_open(SEMS, 0);
    if(semSender == SEM_FAILED){
        perror("semSender doesnt exist");
        exit(0);
    }
    sem_t *semReciever = sem_open(SEMR, 1);
    if(semReciever == SEM_FAILED){
        perror("semSender doesnt exist");
        exit(0);
    }
    //ftok - gives us a key
    //key -shmget - block of mem
    //shmat returns a poiter to the block
    
    char *block = attachMemBlock(FILENAME, SIZE*sizeof(char));
    if (block==NULL){
        printf("Couldnt get the block; sender not started");


    }
    while(true){
        sem_wait(semSender);

        printf("Received: %s\n", block);

        sem_post(semReciever);
    }

    // sem_close(semSender);
    // sem_close(semReciever);

    // shmdt(block);
    return 0;
}
