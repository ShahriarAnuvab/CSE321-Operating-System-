#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PRODUCTS 5
#define WAREHOUSE_SIZE 5

sem_t available, occupied;
pthread_mutex_t locker;
char available_products[WAREHOUSE_SIZE] = {'A', 'B', 'C', 'D', 'E'};
char storage[WAREHOUSE_SIZE] = {'N'};

void *producer(void *arg) {
    int producer_number = *(int*)arg;
    srand(time(NULL));
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        char product = available_products[rand() % WAREHOUSE_SIZE];
        sem_wait(&available);
        pthread_mutex_lock(&locker);
        storage[i] = product;
        printf("Producer %d: Insert product %c at %d\n", producer_number, product, i);
        for (int j = 0; j < WAREHOUSE_SIZE; j++) printf("%c", storage[j]);
        printf("\n");
        pthread_mutex_unlock(&locker);
        sem_post(&occupied);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int consumer_number = *(int*)arg;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        sem_wait(&occupied);
        pthread_mutex_lock(&locker);
        char product = storage[i];
        storage[i] = 'N';
        printf("Consumer %d: Remove product %c from %d\n", consumer_number, product, i);
        for (int j = 0; j < WAREHOUSE_SIZE; j++) printf("%c", storage[j]);
        printf("\n");
        pthread_mutex_unlock(&locker);
        sem_post(&available);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t producers[5], consumers[5];
    pthread_mutex_init(&locker, NULL);
    sem_init(&available, 0, WAREHOUSE_SIZE);
    sem_init(&occupied, 0, 0);
    int producer_numbers[5] = {1, 2, 3, 4, 5};
    int consumer_numbers[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
        pthread_create(&producers[i], NULL, producer, &producer_numbers[i]);
        pthread_create(&consumers[i], NULL, consumer, &consumer_numbers[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(producers[i], NULL);
        pthread_join(consumers[i], NULL);
    }

    pthread_mutex_destroy(&locker);
    sem_destroy(&available);
    sem_destroy(&occupied);

    return 0;
}
