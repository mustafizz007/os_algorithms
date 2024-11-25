#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define BUFFER_SIZE 5
#include<bits/stdc++.h>

#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];  // Shared buffer
int count = 0;             // Keeps track of how many items are in the buffer
sem_t empty, full;         // Semaphores for managing empty and full slots
pthread_mutex_t mutex;     // Mutex for mutual exclusion on buffer access

void* producer(void* arg) {
    while (1) {
        int item = rand() % 100;   // Generate a random item to produce
        sem_wait(&empty);           // Wait if the buffer is full
        pthread_mutex_lock(&mutex); // Lock mutex for exclusive buffer access

        buffer[count] = item;      // Place the item in the buffer
        count++;                   // Increment the count of items
        printf("Produced: %d\n", item);

        pthread_mutex_unlock(&mutex); // Release mutex
        sem_post(&full);            // Signal that the buffer has a new item
        sleep(1);                   // Simulate work being done
    }
}

void* consumer(void* arg) {
    while (1) {
        sem_wait(&full);            // Wait if the buffer is empty
        pthread_mutex_lock(&mutex); // Lock mutex for exclusive buffer access

        int item = buffer[--count]; // Consume an item from the buffer
        printf("Consumed: %d\n", item);

        pthread_mutex_unlock(&mutex); // Release mutex
        sem_post(&empty);            // Signal that a new empty slot is available
        sleep(1);                    // Simulate work being done
    }
}



int main() {
    pthread_t prod, cons;
    sem_init(&empty, 0, BUFFER_SIZE);  // Initialize 'empty' semaphore to buffer size
    sem_init(&full, 0, 0);              // Initialize 'full' semaphore to 0
    pthread_mutex_init(&mutex, NULL);   // Initialize mutex

    pthread_create(&prod, NULL, producer, NULL);  // Create producer thread
    pthread_create(&cons, NULL, consumer, NULL);  // Create consumer thread

    pthread_join(prod, NULL);  // Wait for producer thread to finish
    pthread_join(cons, NULL);  // Wait for consumer thread to finish

    sem_destroy(&empty);  // Destroy the 'empty' semaphore
    sem_destroy(&full);   // Destroy the 'full' semaphore
    pthread_mutex_destroy(&mutex);  // Destroy the mutex

    return 0;
}


