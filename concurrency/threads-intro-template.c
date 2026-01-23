/*
 * Operating Systems: Three Easy Pieces
 * Chapter: Concurrency
 * Exercise: Threads - Basic Threading
 * 
 * OBJECTIVE:
 * Write a multi-threaded program that creates multiple threads to increment
 * a shared counter. Observe the race condition when threads access shared data
 * without synchronization.
 *
 * GUIDELINES:
 * 1. Include necessary headers (stdio.h, pthread.h)
 * 2. Create a global counter variable
 * 3. Create a function that will be executed by threads
 * 4. In the function, increment the counter many times
 * 5. Create multiple threads and join them
 * 6. Print the final counter value and observe if it matches expected value
 *
 * YOUR IMPLEMENTATION BELOW:
 * ============================================================================
 */

#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 2
#define NUM_ITERATIONS 1000000

// TODO: Declare a global counter variable

// TODO: Implement the thread function that increments the counter
// The function should:
// - Take a void* argument (required for pthread)
// - Loop NUM_ITERATIONS times
// - Increment the counter in each iteration
// - Return NULL

int main() {
    // TODO: Declare an array of pthread_t to hold thread IDs
    
    // printf("Initial counter value: %d\n", /* TODO: print counter */);
    
    // TODO: Create NUM_THREADS threads using pthread_create()
    // Each thread should execute the thread function
    
    // TODO: Join all threads using pthread_join()
    
    // printf("Final counter value: %d\n", /* TODO: print counter */);
    printf("Expected value: %d\n", NUM_THREADS * NUM_ITERATIONS);
    
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

// Global shared counter
int counter = 0;

// Thread function
void *increment_counter(void *arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        counter++;  // This is NOT thread-safe!
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    
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
    
    if (counter != NUM_THREADS * NUM_ITERATIONS) {
        printf("\nRACE CONDITION DETECTED!\n");
        printf("The counter value is incorrect due to concurrent access.\n");
    }
    
    return 0;
}

/*
 * EXPECTED OUTPUT (values will vary each run):
 * Initial counter value: 0
 * Final counter value: 1823471 (or some other value less than 2000000)
 * Expected value: 2000000
 * 
 * RACE CONDITION DETECTED!
 * The counter value is incorrect due to concurrent access.
 *
 * EXPLANATION:
 * The increment operation (counter++) is NOT atomic. It actually consists of:
 * 1. Load counter value from memory into a register
 * 2. Increment the value in the register
 * 3. Store the value back to memory
 *
 * When multiple threads execute this simultaneously, they can interleave:
 * Thread 1: Load counter (value = 100)
 * Thread 2: Load counter (value = 100)
 * Thread 1: Increment (value = 101)
 * Thread 2: Increment (value = 101)
 * Thread 1: Store (counter = 101)
 * Thread 2: Store (counter = 101)
 * 
 * Result: Two increments, but counter only increased by 1!
 *
 * TO FIX: Use pthread_mutex_t to protect the critical section.
 */

#endif
