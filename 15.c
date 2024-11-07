#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define NUM_INCREMENTS 100000

int global_counter = 0;  // Global variable

void *increment_global(void *arg) {
    for (int i = 0; i < NUM_INCREMENTS; i++) {
        global_counter++;
    }
    pthread_exit(NULL);
}

void *increment_local(void *arg) {
    int local_counter = 0;  // Local variable
    for (int i = 0; i < NUM_INCREMENTS; i++) {
        local_counter++;
    }
    printf("Local counter: %d\n", local_counter);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];

    // Create threads to increment the global counter
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, increment_global, NULL) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Global counter: %d\n", global_counter);

    // Create threads to increment the local counter
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, increment_local, NULL) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
