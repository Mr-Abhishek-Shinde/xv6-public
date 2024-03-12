#include "types.h"
#include "user.h"

#define NPROC 5

void worker(int id) {
    printf(1, "Worker %d (PID: %d) started\n", id, getpid());
    int i, j;
    for (i = 0; i < 50000000; i++) {
        for (j = 0; j < 100; j++) {
            asm("nop"); // Some dummy work
        }
    }
    exit();
}

int main() {
    printf(1, "Parent process (PID: %d) started\n", getpid());
    // Create child processes
    int i;
    uint start_ticks = uptime(); // Record start time
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

    uint end_ticks = uptime(); // Record end time
    printf(1, "Parent process finished\n");

    uint ticks = end_ticks - start_ticks;
    printf(1, "Clock ticks required: %d\n", ticks);
    uint tput = (NPROC * 10000) / ticks;
    printf(1, "Throughput: %d processes/100 sec\n", tput);
    exit();
}

