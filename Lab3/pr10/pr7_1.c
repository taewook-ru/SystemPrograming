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

	fp2=fopen("22.txt", "w");

if ((shmid = shmget(SHMKEY, SHMSIZE,IPC_CREAT|0666)) == -1) 
{
       	perror ("shmget failed"); exit (1); 

}

if ((shmaddr=shmat(shmid, NULL, 0)) == (void *)-1)
{
       	perror ("shmat failed"); exit (1);

}


pid_t pid;

        pid = fork();

        if(pid == 0)
               fputs((char *)shmaddr, fp2);

        else if(pid > 0)

if (shmdt(shmaddr) == -1) 
{
       	perror ("shmdt failed"); exit (1); 
}
if (shmctl(shmid, IPC_RMID, 0) == -1) 
{
       	perror ("shmctl failed"); exit (1); 
}
fclose(fp2);
}



