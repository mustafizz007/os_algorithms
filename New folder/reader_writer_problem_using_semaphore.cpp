#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include<bits/stdc++.h>

// Semaphore declarations
sem_t rw_mutex, mutex;
int read_count = 0; // Keeps track of the number of readers
int data = 0;       // Shared resource

// Reader function
void* reader(void* arg) {
    int id = (int)(long)arg; // Convert thread argument back to integer
    sem_wait(&mutex);
    read_count++;
    if (read_count == 1) sem_wait(&rw_mutex); // First reader locks the resource
    sem_post(&mutex);

    // Critical section for reading
    printf("Reader %d read data: %d\n", id, data);

    sem_wait(&mutex);
    read_count--;
    if (read_count == 0) sem_post(&rw_mutex); // Last reader unlocks the resource
    sem_post(&mutex);
    return NULL;
}

// Writer function
void* writer(void* arg) {
    int id = (int)(long)arg; // Convert thread argument back to integer
    sem_wait(&rw_mutex);

    // Critical section for writing
    data += 10; // Modify shared data
    printf("Writer %d wrote data: %d\n", id, data);

    sem_post(&rw_mutex);
    return NULL;
}

int main() {
    pthread_t r1, r2, w1, w2;

    // Initialize semaphores
    sem_init(&rw_mutex, 0, 1);
    sem_init(&mutex, 0, 1);

    // Create threads
    pthread_create(&r1, NULL, reader, (void*)(long)1);
    pthread_create(&r2, NULL, reader, (void*)(long)2);
    pthread_create(&w1, NULL, writer, (void*)(long)1);
    pthread_create(&w2, NULL, writer, (void*)(long)2);

    // Wait for threads to finish
    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w1, NULL);
    pthread_join(w2, NULL);

    // Destroy semaphores
    sem_destroy(&rw_mutex);
    sem_destroy(&mutex);

    return 0;
}
