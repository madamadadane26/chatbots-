
// Function to be run by each thread
void* PrintHello(void* threadarg) {
    struct thread_data* my_data = (struct thread_data*) threadarg;

    int tid = my_data->thread_id;  // Thread ID
    string message;

    // Loop for writing messages
    for (int i = 0; i < LOOP_ITERATIONS; i++) {
        if(sem_wait(my_data->FLAG) == -1) {  // Error checking: If semaphore wait fails, exit. POSIX system call
            cerr << "Semaphore wait failed\n";
            pthread_exit(NULL);
        }

        if (tid % 2 == 0) // For even numbered threads
            message = "Controlling complexity is the essence of computer programming --Brian Kernigan";
            
        else // For odd numbered threads
            message = "Computer science is no more about computers than astronomy is about telescopes --Edsger Dijkstra";

        *(my_data->of) << "Thread ID " << tid << ": " << message << endl;

        cout << "Thread " << tid << " is running" << endl; // Writes the thread’s tid (thread id) followed by “The Quote”

        if(sem_post(my_data->FLAG) == -1) {  // Error checking: If semaphore post fails, exit. POSIX system call. The semaphore FLAG is released
            cerr << "Semaphore post failed\n";
            pthread_exit(NULL);
        }

        if (tid % 2 == 0)
            sleep(2);
        else
            sleep(3);
    }

    pthread_exit(NULL);
}

int main() {
    cout << "bots" << endl;

    ofstream quoteFile;
    quoteFile.open("QUOTE.txt"); // Opens the file QUOTE.txt 

    if (!quoteFile) {
        cerr << "File could not be opened\n"; // Error checking
        exit(-1);
    }

    quoteFile << "Process ID: " << getpid() << "\n";

    sem_t FLAG;
    if(sem_init(&FLAG, 0, 1) == -1) {  // Error checking: If semaphore initialization fails, exit. POSIX system call
        cerr << "Semaphore initialization failed\n";
        exit(-1);
    }

    pthread_t threads[NUM_THREADS];
    struct thread_data td[NUM_THREADS];

    // Creating threads
    for (int i = 0; i < NUM_THREADS; i++) {
        td[i].thread_id = i + 1;
        td[i].FLAG = &FLAG;
        td[i].of = &quoteFile;

        cout << "Creating thread in main(): " << i + 1 << endl;

        int rc = pthread_create(&threads[i], NULL, PrintHello, (void*)&td[i]);

        if (rc) {
            cerr << "Error: Unable to create thread " << rc << endl;
            exit(-1); //Error checking: 
        }
    }

    // Waiting for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        int rc = pthread_join(threads[i], NULL);
        if (rc) {
            cerr << "Error: Unable to join thread " << rc << endl; //Error checking: if unable to join the thread, exit
            exit(-1);
        }
    }

    // Destroying the semaphore, POSIX system call
    if(sem_destroy(&FLAG) == -1) {
        cerr << "Semaphore destruction failed\n"; // More error checking
        exit(-1);
    }

    // Closes the file QUOTE.txt
    quoteFile.close();
        cout << "All threads have completed their work. Exiting gracefully." << endl;

    return 0;
}


   
