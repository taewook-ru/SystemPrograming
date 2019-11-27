#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 512

main()
{
	char buffer[BUFSIZE];
	int filedes;
	ssize_t nread;
	long total = 0;

	if((filedes = open("test1.txt", O_RDONLY)) == -1)
	{
		printf("error in opening anotherfile \n");
		exit(1);
	}

	while((nread = read (filedes, buffer, BUFSIZE)) >0)
		total += nread;

	printf("total chars in test.txt: %ld \n", total);
	exit(0);
}

