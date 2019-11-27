#include <stdio.h>
#include <signal.h>

void alarm_handler(int);

int alarm_flag = 0;
int i =0;
main(){
        struct sigaction act;

        act.sa_handler = alarm_handler;
        sigaction(SIGALRM, &act, NULL);
        while(true){
		
        if(alarm_flag)
                printf("passed a5secs. \n");
        printf("sleep for %d sec(s)" , ++i );
        alarm(5);
        pause();
        if(alarm_flag)
                printf("passed a5secs. \n");
        }
}

void alarm_handler(int sig)
{
        printf("Received a alram signal. \n");
        alarm_flag = 1;
}
