#include <stdio.h>
#include <pthread.h>

 
void *thread(void *);
pthread_t    tid[4];
pthread_mutex_t    mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t    cond = PTHREAD_COND_INITIALIZER;
 char message[100];
int main() {
    int i;
    int id[4];

	printf("input the message \n");
	scanf("%s", &message);
    for(i = 0; i < 4; i++){
        id[i] = i;
        pthread_create(&tid[i],NULL,thread,(void*)&id[i]);
    }
 
    sleep(2);
    pthread_cond_broadcast(&cond);
 
    for(i = 0; i < 4 ; i++){
        pthread_join(tid[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
 
    return 0;
}
 
void *thread(void *arg){

	
    //pthread_mutex_lock(&mutex);
    pthread_cond_wait(&cond, &mutex);
    //cout << "hello, world! from " <<  *((int*)arg) << endl;
	printf("%s from %d \n", message,*((int*)arg));
    pthread_mutex_unlock(&mutex);
}


