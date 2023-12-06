#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_ITEMS 10
#define BUFFER_SIZE 6
#define NUM_THREADS 2

char shared_buffer[BUFFER_SIZE];
char data_source[] = "abcdef";
int producer_counter = 0, consumer_counter = 0, data_source_length;
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t nonEmpty = PTHREAD_COND_INITIALIZER, full = PTHREAD_COND_INITIALIZER;

void *producer(void *id) {
    int thread_id = *(int *)id;
    while (producer_counter < MAX_ITEMS) {
        pthread_mutex_lock(&count_mutex);
        while (strlen(shared_buffer) == BUFFER_SIZE) {
            pthread_cond_wait(&full, &count_mutex);
        }
        shared_buffer[strlen(shared_buffer)] = data_source[producer_counter % data_source_length];
        printf("%d produced %c by Thread %d\n", producer_counter, data_source[producer_counter % data_source_length], thread_id);
        producer_counter++;
        pthread_cond_signal(&nonEmpty);
        pthread_mutex_unlock(&count_mutex);
        usleep(500);
    }
    pthread_exit(NULL);
}

void *consumer(void *id) {
    int thread_id = *(int *)id;
    while (consumer_counter < MAX_ITEMS) {
        pthread_mutex_lock(&count_mutex);
        while (strlen(shared_buffer) == 0) {
            pthread_cond_wait(&nonEmpty, &count_mutex);
        }
        char c = shared_buffer[strlen(shared_buffer) - 1];
        shared_buffer[strlen(shared_buffer) - 1] = '\0';
        printf("%d consumed %c by Thread %d\n", consumer_counter, c, thread_id);
        consumer_counter++;
        pthread_cond_signal(&full);
        pthread_mutex_unlock(&count_mutex);
        usleep(500);
    }
    pthread_exit(NULL);
}

int main() {
    int i, thread_ids[NUM_THREADS] = {0, 1};
    pthread_t threads[NUM_THREADS];
    data_source_length = strlen(data_source);
    pthread_create(&threads[0], NULL, producer, &thread_ids[0]);
    pthread_create(&threads[1], NULL, consumer, &thread_ids[1]);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    return 0;
}
