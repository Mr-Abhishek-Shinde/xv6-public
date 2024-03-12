#include "types.h"
#include "user.h"

#define NPROC 5

void worker(int id) {
    printf(1, "Worker %d (PID: %d) started\n", id, getpid());
    ps();
    int i, j;
    for (i = 0; i < 50000000; i++) {
        for (j = 0; j < 100; j++) {
            asm("nop"); // Some dummy work
        }
    }
    printf(1, "Worker %d (PID: %d) finished\n", id, getpid());
    ps();
    exit();
}

int main() {
    printf(1, "Parent process (PID: %d) started\n", getpid());
	ps();    
    // Create child processes
    int i;
    for (i = 0; i < NPROC; i++) {
        if (fork() == 0) {
            // Child process
            worker(i + 1);
        }
    }

    // Wait for all child processes to finish
    for (i = 0; i < NPROC; i++) {
        wait();
    }

    printf(1, "Parent process finished\n");
    exit();
}

