#include <stdio.h>

int system(const char *command);

int my_system(char *command)
{
	int status;

	switch(fork()){
		case 0:
			execl("/bin/bash", "bin/bash", "-c", command, NULL);
			break;

		case -1:
			perror("fork");
			exit(0);

		default:
			wait(&status);
			break;
	}
	return status;
}

main(int argc, char *argv[])
{
/*	if(argv[2] != NULL){
	strcat(argv[1], " ");
	strcat(argv[1], argv[2]);
	}
*/	
	my_system(argv[1]);

}

