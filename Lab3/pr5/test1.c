#include <sys/types.h>
#include <unistd.h>

main()
{
	pid_t pid;
	printf("Calling fork \n");
	pid = fork();

	if(pid == 0)
		printf("i'm the child process \n");
	else if (pid > 0)
		printf("i'm the parent process \n");
	else
		printf("fork failed \n");
}

