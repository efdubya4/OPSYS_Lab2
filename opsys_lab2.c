#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create two child processes
    for (int i = 0; i < 2; i++) {
        pid_t child_pid = fork();

        if (child_pid == 0) { // Child process
            int iterations = (rand() % 30) + 1; // Random number of iterations (1 to 30)
            pid_t child_id = getpid();
            pid_t parent_id = getppid();

            for (int j = 0; j < iterations; j++) {
                printf("Child Pid: %d is going to sleep!\n", child_id);

                int sleep_duration = (rand() % 10) + 1; // Random sleep duration (1 to 10 seconds)
                sleep(sleep_duration);

                printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n", child_id, parent_id);
            }

            exit(0); // Terminate child process
        }
    }

    // Parent process
    int status;
    pid_t child_pid;

    for (int i = 0; i < 2; i++) {
        child_pid = wait(&status);
        printf("Child Pid: %d has completed\n", child_pid);
    }

    return 0;
}
