
// bots.h
#ifndef bots_H
#define bots_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

#define NUM_THREADS 7
#define LOOP_ITERATIONS 8

struct thread_data {
    int thread_id;  
    sem_t *FLAG;    
    ofstream *of;  
};

void* PrintHello(void* threadarg);

#endif 
