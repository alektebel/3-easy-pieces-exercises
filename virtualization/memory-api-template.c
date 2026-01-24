/*
 * Operating Systems: Three Easy Pieces
 * Chapter: Memory Management
 * Exercise: Address Translation - Memory API
 * 
 * OBJECTIVE:
 * Write a program that allocates memory using malloc() and demonstrates
 * proper memory management including allocation, usage, and deallocation.
 * Show what happens when you try to access memory after freeing it.
 *
 * GUIDELINES:
 * 1. Include necessary headers (stdio.h, stdlib.h, string.h)
 * 2. Allocate memory for an array of integers using malloc()
 * 3. Check if allocation was successful
 * 4. Initialize and use the allocated memory
 * 5. Free the memory properly
 * 6. Demonstrate the danger of use-after-free
 *
 * YOUR IMPLEMENTATION BELOW:
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // TODO: Allocate memory for an array of 10 integers using malloc()
    
    // TODO: Check if malloc() returned NULL (allocation failed)
    
    // TODO: Initialize the array with values (e.g., arr[i] = i * 10)
    
    // TODO: Print the values in the array
    
    // TODO: Free the allocated memory
    
    // TODO: Try to access the memory after freeing (demonstrate use-after-free)
    
    return 0;
}

/*
 * ============================================================================
 * SOLUTION (Look here if you're stuck):
 * ============================================================================
 */

#if 0  // Change to #if 1 to compile the solution

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Allocate memory for 10 integers
    int *arr = (int *)malloc(10 * sizeof(int));
    
    // Check if allocation was successful
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    printf("Memory allocated successfully at address: %p\n", (void *)arr);
    
    // Initialize the array
    for (int i = 0; i < 10; i++) {
        arr[i] = i * 10;
    }
    
    // Print the values
    printf("Array values after initialization:\n");
    for (int i = 0; i < 10; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    // Free the memory
    printf("\nFreeing memory...\n");
    free(arr);
    
    // Demonstrate use-after-free (THIS IS A BUG - DON'T DO THIS!)
    printf("\nAttempting to access freed memory (use-after-free bug):\n");
    printf("arr[0] after free: %d (undefined behavior!)\n", arr[0]);
    
    // The correct way: set pointer to NULL after freeing
    arr = NULL;
    
    // Now accessing would cause a segmentation fault (which is better than silent corruption)
    // if (arr != NULL) {
    //     printf("arr[0] = %d\n", arr[0]);
    // } else {
    //     printf("Pointer is NULL, cannot access\n");
    // }
    
    return 0;
}

/*
 * EXPECTED OUTPUT (values may vary for use-after-free):
 * Memory allocated successfully at address: 0x...
 * Array values after initialization:
 * arr[0] = 0
 * arr[1] = 10
 * arr[2] = 20
 * ...
 * arr[9] = 90
 * 
 * Freeing memory...
 * 
 * Attempting to access freed memory (use-after-free bug):
 * arr[0] after free: ??? (undefined behavior!)
 *
 * EXPLANATION:
 * - malloc() allocates memory on the heap and returns a pointer to it
 * - Always check if malloc() returns NULL (allocation failure)
 * - After free(), accessing the memory is undefined behavior
 * - Good practice: set pointers to NULL after freeing to avoid use-after-free bugs
 * - Memory leaks occur when you allocate memory but never free it
 */

#endif
