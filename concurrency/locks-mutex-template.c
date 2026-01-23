/*
 * Operating Systems: Three Easy Pieces
 * Chapter: Concurrency
 * Exercise: Locks - Mutex Synchronization
 * 
 * OBJECTIVE:
 * Fix the race condition from the previous exercise by using a mutex lock
 * to protect the shared counter. This demonstrates proper thread synchronization.
 *
 * GUIDELINES:
 * 1. Include necessary headers (stdio.h, pthread.h)
 * 2. Declare a global mutex variable
 * 3. Initialize the mutex using pthread_mutex_init()
 * 4. Use pthread_mutex_lock() before accessing shared data
 * 5. Use pthread_mutex_unlock() after accessing shared data
 * 6. Destroy the mutex when done using pthread_mutex_destroy()
 *
 * YOUR IMPLEMENTATION BELOW:
 * ============================================================================
 */

#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 2
#define NUM_ITERATIONS 1000000

// TODO: Declare a global counter variable
// TODO: Declare a global mutex variable (pthread_mutex_t)

// TODO: Implement the thread function that safely increments the counter
// The function should:
// - Lock the mutex before accessing the counter
// - Increment the counter
// - Unlock the mutex after accessing the counter

int main() {
    // TODO: Declare an array of pthread_t to hold thread IDs
    
    // TODO: Initialize the mutex using pthread_mutex_init()
    
    // printf("Initial counter value: %d\n", /* TODO: print counter */);
    
    // TODO: Create NUM_THREADS threads
    
    // TODO: Join all threads
    
    // printf("Final counter value: %d\n", /* TODO: print counter */);
    printf("Expected value: %d\n", NUM_THREADS * NUM_ITERATIONS);
    
    // TODO: Destroy the mutex using pthread_mutex_destroy()
    
    return 0;
}

/*
 * ============================================================================
 * SOLUTION (Look here if you're stuck):
 * ============================================================================
 */

#if 0  // Change to #if 1 to compile the solution

#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 2
#define NUM_ITERATIONS 1000000

// Global shared counter and mutex
int counter = 0;
pthread_mutex_t lock;

// Thread function with proper synchronization
void *increment_counter(void *arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        pthread_mutex_lock(&lock);    // Acquire lock
        counter++;                     // Critical section
        pthread_mutex_unlock(&lock);  // Release lock
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    
    // Initialize the mutex
    if (pthread_mutex_init(&lock, NULL) != 0) {
        fprintf(stderr, "Mutex initialization failed\n");
        return 1;
    }
    
    printf("Initial counter value: %d\n", counter);
    
    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, increment_counter, NULL) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return 1;
        }
    }
    
    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Error joining thread %d\n", i);
            return 1;
        }
    }
    
    printf("Final counter value: %d\n", counter);
    printf("Expected value: %d\n", NUM_THREADS * NUM_ITERATIONS);
    
    if (counter == NUM_THREADS * NUM_ITERATIONS) {
        printf("\nSUCCESS! Counter value is correct.\n");
        printf("The mutex properly synchronized access to the shared counter.\n");
    }
    
    // Destroy the mutex
    pthread_mutex_destroy(&lock);
    
    return 0;
}

/*
 * EXPECTED OUTPUT:
 * Initial counter value: 0
 * Final counter value: 2000000
 * Expected value: 2000000
 * 
 * SUCCESS! Counter value is correct.
 * The mutex properly synchronized access to the shared counter.
 *
 * EXPLANATION:
 * A mutex (mutual exclusion lock) ensures that only one thread at a time
 * can execute the critical section (the code between lock and unlock).
 *
 * When a thread calls pthread_mutex_lock():
 * - If the mutex is available, the thread acquires it and continues
 * - If another thread holds the mutex, the calling thread blocks (waits)
 *
 * When a thread calls pthread_mutex_unlock():
 * - The mutex becomes available for other waiting threads
 *
 * This prevents the race condition by serializing access to the counter.
 *
 * NOTE: This version is slower than the unsynchronized version because:
 * - Locking/unlocking has overhead
 * - Threads must wait for each other
 * But correctness is more important than speed!
 *
 * OPTIMIZATION TIP: For better performance, you could increment a local
 * variable inside the loop and only lock once to add it to the global counter.
 */

#endif
