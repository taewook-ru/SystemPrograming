#include <unistd.h>

main()
{
	printf("Executing execl. \n");

	execl("/bin/ls", "ls", "-l", (char *)0);

	perror("execl failed to run is");
	exit(1);
}

