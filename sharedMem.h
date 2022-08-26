#ifndef SHAREDMEM_H
#define SHAREDMEM_H
#define _GNU_SOURCE

//for the struct stat type
#include <sys/stat.h>
#include <stdbool.h>
#include <fcntl.h>
#include <semaphore.h>
char *attachMemBlock(char *filename, int size);
//shmdt(char *block)  - removes block from the address space
bool destMemBlock(char *filename);


#define SIZE 5
#define FILENAME "sender.c"

#define SEMR "sem_receive"
#define SEMS "sem_send"
#endif
