#include "types.h"
#include "user.h"

#define NUM_CHILDREN 2

void calculate(int x) {
	int pid;
	if(x == 0){
		pid = 5;
	}
	else{
		pid = 6;
	}
    long i, j;
    int val = 0;
    if(pid == 5){
	    val = 1000;
    }
    else{
	    val = 100000;
    }
    ps();
    for (i = 0; i < 100000; i++) {
        for (j = 0; j < val; j++) {
		ps();
		printf(1, "Running child with pid: %d\n", pid);
            // Some dummy calculations
            int temp = i * j;
            temp++;
        }
    }
    printf(1, "Child %d with PID %d completed.\n", pid, getpid());
}

int main() {
    int pids[NUM_CHILDREN];

    // Create child processes
    for (int i = 0; i < NUM_CHILDREN; i++) {
        pids[i] = fork();
        if (pids[i] < 0) {
            printf(1, "Fork failed.\n");
            exit();
        } else if (pids[i] == 0) {
            // Child process
            calculate(i);
            exit();
        }
    }

    // Wait for all child processes to complete
    for (int i = 0; i < NUM_CHILDREN; i++) {
        wait();
    }

    exit();
}

