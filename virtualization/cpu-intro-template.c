/*
 * Operating Systems: Three Easy Pieces
 * Chapter: CPU Introduction
 * Exercise: CPU Virtualization - Process API
 * 
 * OBJECTIVE:
 * Write a program that calls fork(). Before calling fork(), have the main process
 * access a variable (e.g., x) and set its value to something (e.g., 100).
 * What is the value of the variable in the child process? What happens to the
 * variable when the child and parent both change the value of x?
 *
 * GUIDELINES:
 * 1. Include necessary headers (stdio.h, unistd.h, sys/wait.h)
 * 2. Create a variable and initialize it
 * 3. Use fork() to create a child process
 * 4. In both parent and child, modify the variable and print its value
 * 5. Use wait() in the parent to wait for the child to complete
 *
 * YOUR IMPLEMENTATION BELOW:
 * ============================================================================
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // TODO: Declare and initialize a variable x to 100
    
    // TODO: Print the initial value of x
    
    // TODO: Call fork() and store the return value
    
    // TODO: Check if fork() failed (return value < 0)
    
    // TODO: If in child process (return value == 0):
    //       - Print that we're in the child
    //       - Print current value of x
    //       - Modify x (e.g., set to 200)
    //       - Print new value of x
    
    // TODO: If in parent process (return value > 0):
    //       - Print that we're in the parent
    //       - Print current value of x
    //       - Modify x (e.g., set to 300)
    //       - Print new value of x
    //       - Wait for child to complete using wait()
    
    return 0;
}

/*
 * ============================================================================
 * SOLUTION (Look here if you're stuck):
 * ============================================================================
 */

#if 0  // Change to #if 1 to compile the solution

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int x = 100;
    printf("Initial value of x: %d\n", x);
    
    pid_t pid = fork();
    
    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process - x before modification: %d\n", x);
        x = 200;
        printf("Child process - x after modification: %d\n", x);
    } else {
        // Parent process
        printf("Parent process - x before modification: %d\n", x);
        x = 300;
        printf("Parent process - x after modification: %d\n", x);
        wait(NULL);  // Wait for child to complete
    }
    
    printf("Final value of x in %s: %d\n", 
           (pid == 0) ? "child" : "parent", x);
    
    return 0;
}

/*
 * EXPECTED OUTPUT (may vary due to scheduling):
 * Initial value of x: 100
 * Parent process - x before modification: 100
 * Parent process - x after modification: 300
 * Child process - x before modification: 100
 * Child process - x after modification: 200
 * Final value of x in parent: 300
 * Final value of x in child: 200
 *
 * EXPLANATION:
 * When fork() is called, the child process gets a COPY of the parent's address
 * space. This means both processes have their own independent copy of variable x.
 * Changes made in one process do NOT affect the other process's copy.
 */

#endif
