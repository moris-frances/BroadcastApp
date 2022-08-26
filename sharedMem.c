#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include"sharedMem.h"

#define IPC_RESULT_ERROR (-1)

//returns the id of the shared block
static int get_shared_block(char*filename, int size){
    key_t key;
    // Request a key
    // The key is linked to a filename,so that other programs can access it.
    //get a numeric key for the ffilename (we want 0)
    key=ftok(filename,0);
    if(key == IPC_RESULT_ERROR)
        return IPC_RESULT_ERROR;
    // get shared block --- create it if it doesn't exist
    return shmget(key, size, 0644 | IPC_CREAT);
}

char *attachMemBlock(char *filename, int size){

    int shared_block_id=get_shared_block(filename,size);
    char*result;
    if(shared_block_id==IPC_RESULT_ERROR){
        return NULL;      
    }
    // map the shared block into this process's memory
    // and give meapointer to it                  
    result=shmat(shared_block_id,NULL,0);
    if(result ==(char*)IPC_RESULT_ERROR){
        return NULL;
    

    }
    return result;
}

bool destMemBlock(char *filename){
    int shared_block_id=get_shared_block(filename,0);

    if(shared_block_id  == IPC_RESULT_ERROR){
        return NULL;
                     
    }
    
    return(shmctl(shared_block_id,IPC_RMID,NULL)!=IPC_RESULT_ERROR);
}