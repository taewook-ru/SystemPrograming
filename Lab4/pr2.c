#include <stdio.h>
#include <pthread.h>


void* producer(void* arg);
void* consumer(void* arg);


//버퍼 설정 값
int buffer[1];
int count = 0;
int out = -1;
int in = -1;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t buffer_has_space = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t buffer_has_data = PTHREAD_MUTEX_INITIALIZER;


void* producer(void* arg) {

	int i;

	for (i = 0; i < 10; i++) {
		printf("producer data  %d \n", i);

		pthread_mutex_lock(&mutex);
		if (count == 1)
			pthread_cond_wait(&buffer_has_space, &mutex);

		in++;
		in %= 1;
		buffer[in] = i;
		count++;

		pthread_cond_signal(&buffer_has_data);
		pthread_mutex_unlock(&mutex);

	}
}

void* consumer(void *arg) {

	int i, data;

	for (i = 0; i < 10; i++) {
		pthread_mutex_lock(&mutex);

		if (count == 0) 

			pthread_cond_wait(&buffer_has_data, &mutex);

			out++;
			out %= 1;
			data = buffer[out];
			count--;

			pthread_cond_signal(&buffer_has_space);
			pthread_mutex_unlock(&mutex);

			printf("                consumer data = %d \n", data);
		
	}

}

int main(void) {
	int i;

	pthread_t thread[2];
	pthread_create(&thread[0], NULL, producer, NULL);
	pthread_create(&thread[1], NULL, consumer, NULL);

	for (i = 0; i < 2; i++)
		pthread_join(thread[i], NULL);

	pthread_cond_destroy(&buffer_has_space);
	pthread_cond_destroy(&buffer_has_data);

	pthread_exit(NULL);
	return 0;
}

