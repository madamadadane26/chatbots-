/*Authors:
Yan Ho[RedID: 826654745]
Yan Ho Edoras: cssc1429
Jenny Nguyen[RedID: 826622622]
Jenny Nguyen Edoras: cssc1451

Course
- CS 480 Summer 2023 Section 01
- Programming Assignment #1 (a1)
*/

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
