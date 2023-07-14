
README.txt

Files:
    - README.txt
    - bots.cpp
    - Makefile
    - bots.h
    
Code Summary:
Our program, named "bots", creates multiple threads using POSIX threads (pthreads) and handles synchronization between them using semaphores. Each thread writes messages to a file "QUOTE.txt". Depending on their thread ID, threads write different quotes and sleep for different intervals.

Compile Instructions:
    - The command to run and make an executable on terminal: 
        - g++ bots.cpp -o bots -std=c++11 -pthread -lrt
            - This command will create an executable named `bots`
        - Alternatively, you can use the provided Makefile for compilation. Run 'make' in the terminal.
        - The g++ command includes the -lrt option and -pthread to ensure our program is linked with the correct libraries required for multi-threading and semaphore handling.

Operating Instructions:
    - After compiling, you can run the program by typing `./bots`.
    - The program will write messages from multiple threads to a file named "QUOTE.txt".
    - Each message includes the ID of the thread that wrote it along with a distinct quote.
    - After finishing, the terminal will output "All threads have completed their work. Exiting gracefully."

Code Details:
    - We chose to use pthreads and semaphores to handle multi-threading and synchronization in C++.
    - We created a struct `thread_data` to pass relevant data to the threads. The data includes the thread id, semaphore for synchronization, and the ofstream object for file writing.
    - A semaphore named FLAG is used to ensure that only one thread writes to the file at a time, thus preventing data corruption.
    - Threads write different quotes based on their thread ID. Even numbered threads write one quote, odd numbered threads write another.
    - Threads sleep for different intervals based on their thread ID, introducing a level of non-determinism in the quote sequence in the file.

Known Issues:
    - As of now, we believe there are no known bugs in the program. If there are issues, we apologize in advance! 

Lessons Learned:
    - We learned how to debug, run, execute, and compile on Edoras(a remote server) for the first time as we are required to make sure our program executes cleanly when using the gcc, or g++ compiler(g++ compiler for us)
    - Multithreading in C++: This project gave us experience with multi-threading using pthreads in C++, which is great for improving program performance.
    - Semaphore synchronization: We learned the value of semaphores for ensuring synchronization between threads and preventing data corruption.
    - How to create a program that is managing the creation, execution, and termination of threads. 
    - We made sure that our program correctly blocks and waits for all threads to complete using the pthread_join function.
    - Makefile usage: We learned about the creation and usage of Makefiles for efficient and flexible compilation. It saves a lot of time when we have to deal with larger, more complex projects. Fortunately, in this case, our program isn't very large or complex.
    - Different sleeping times for threads introduced us to the non-deterministic nature of multi-threaded applications.
    - The pthread_create function creates a new thread, and in our program, it's creating NUM_THREADS threads, with each thread executing the PrintHello function.
    - We learned how to use POSIX semaphore functions(sem_init(), sem_wait(), sem_post(), and sem_destroy()), which are used for synchronization between threads to ensure that shared resources are accessed in a thread-safe manner.
    - How to correctly write the process ID (PID) into the shared file "QUOTE.txt" by using the getpid() function, which is a POSIX system call that returns the PID of the current process, and this is being written directly to the file using the << operator.
    - We learned to use the semaphore FLAG, which is being used to synchronize access to the output file and the console output, ensuring that threads don't interfere with each other's output. 
