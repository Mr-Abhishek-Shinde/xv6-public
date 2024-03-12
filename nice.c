#include "types.h"
#include "stat.h"
#include "user.h"
//#include "fs.h"

int main(int argc, char *argv[]){
	int pid, prior;

	if(argc < 3){
		printf(2, "Please provide pid and priority as CLA\n");
	}
	pid = atoi(argv[1]);
	prior = atoi(argv[2]);

	if(prior < 0 || prior > 10){
		printf(2, "Invalid input! Enter priority between 0-10!\n");
		exit();
	}

	nice(pid, prior);
	exit();
}
