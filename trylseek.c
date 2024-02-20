#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

#define SIZE 5

//  arg1 --> filename
int main(int argc, char* argv[]){
	int fd, n;
	char buff[SIZE + 1];

	if((fd = open(argv[1], O_RDWR)) < 0){
		printf(2, "Failed to open the file!\n");
		exit();
	}

	printf(1, "Moving to offset 5 and printing 5 characters:\n");
	lseek(fd, 5, 0);
	n = read(fd, buff, SIZE);
	buff[n] = '\0';
	printf(1, "%s\n", buff);

	printf(1, "Moving to offset 5 from current and printing 5 characters:\n");
        lseek(fd, 5, 1);
        n = read(fd, buff, SIZE);
        buff[n] = '\0';
        printf(1, "%s\n", buff);

	printf(1, "Moving to offset -5 from end and printing 5 characters:\n");
        lseek(fd, -5, 2);
        n = read(fd, buff, SIZE);
        buff[n] = '\0';
        printf(1, "%s\n", buff);

	close(fd);

	exit();
}
