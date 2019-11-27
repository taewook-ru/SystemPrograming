#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>

#define SHMSIZE 1024
#define SHMKEY (key_t)0111

main()
{
	int shmid, len;
	void *shmaddr;
	char a[SHMSIZE];
	FILE *fp1, *fp2;

	fp1=fopen("11.txt", "r");
	


	if((shmid = shmget(SHMKEY, SHMSIZE, IPC_CREAT|0666)) == -1){
		perror("shmget failed");
		exit(1);
	}

	if((shmaddr = shmat(shmid, NULL, 0)) == (void *)-1){
		perror("shmat failed");
		exit(1);
		}

	pid_t pid;

	pid = fork();

	if(pid >0)
	strcpy((char *)shmaddr, fgets(a, SHMSIZE, fp1));

	if(shmdt(shmaddr) == -1) {
		perror("shmdt failed");
		exit(1);
	}

	fclose(fp1);

}

