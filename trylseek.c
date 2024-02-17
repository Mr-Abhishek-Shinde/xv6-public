#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

#define SIZE 10

// usage: arg1 --> filename, arg2 --> whence.
int main(int argc, char* argv[]){
	int fd, whence, newOffset;
	char buff[SIZE + 1];
	//char temp[SIZE];

	if((fd = open(argv[1], O_RDWR)) < 0){
		printf(2, "Failed to open the file!\n");
		exit();
	}

	whence = atoi(argv[2]);

	//if(whence == 1){
	//	read(fd, temp, SIZE);
	//}

	newOffset = lseek(fd, 5, whence);

	if(newOffset < 0){
		printf(2, "lseek failed!\n");
		close(fd);
		exit();
	}

	printf(2, "lseek done.\n");
	printf(2, "Printing 10 characters to verify:\n");

	int n = read(fd, buff, SIZE);
	buff[n] = '\0';

	printf(1, "%s\n", buff);

	close(fd);

	exit();
}
