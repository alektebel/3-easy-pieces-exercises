/*
 * Operating Systems: Three Easy Pieces
 * Chapter: Persistence
 * Exercise: I/O Devices and Files - File I/O
 * 
 * OBJECTIVE:
 * Write a program that demonstrates basic file operations: creating, writing,
 * reading, and closing files. Show proper error handling for file operations.
 *
 * GUIDELINES:
 * 1. Include necessary headers (stdio.h, stdlib.h, string.h)
 * 2. Open a file for writing using fopen()
 * 3. Check if file was opened successfully
 * 4. Write data to the file using fprintf() or fwrite()
 * 5. Close the file using fclose()
 * 6. Open the file for reading
 * 7. Read and display the contents
 * 8. Close the file
 *
 * YOUR IMPLEMENTATION BELOW:
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // TODO: Define a filename (e.g., "test_file.txt")
    
    // TODO: Open the file for writing ("w" mode)
    // Store the FILE* pointer
    
    // TODO: Check if file opened successfully (pointer != NULL)
    
    // TODO: Write some text to the file using fprintf()
    
    // TODO: Close the file
    
    // TODO: Open the file for reading ("r" mode)
    
    // TODO: Check if file opened successfully
    
    // TODO: Read and print the contents of the file
    // Use fgets() to read line by line or fread() for binary data
    
    // TODO: Close the file
    
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
    const char *filename = "test_file.txt";
    FILE *fp;
    char buffer[256];
    
    // ===== WRITING TO FILE =====
    printf("Opening file '%s' for writing...\n", filename);
    fp = fopen(filename, "w");
    
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file for writing\n");
        return 1;
    }
    
    printf("Writing to file...\n");
    fprintf(fp, "Operating Systems: Three Easy Pieces\n");
    fprintf(fp, "This is a test file.\n");
    fprintf(fp, "Line 1: Virtualization\n");
    fprintf(fp, "Line 2: Concurrency\n");
    fprintf(fp, "Line 3: Persistence\n");
    
    fclose(fp);
    printf("File written and closed successfully.\n\n");
    
    // ===== READING FROM FILE =====
    printf("Opening file '%s' for reading...\n", filename);
    fp = fopen(filename, "r");
    
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file for reading\n");
        return 1;
    }
    
    printf("Reading from file:\n");
    printf("-------------------\n");
    
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    
    printf("-------------------\n");
    fclose(fp);
    printf("File read and closed successfully.\n");
    
    return 0;
}

/*
 * EXPECTED OUTPUT:
 * Opening file 'test_file.txt' for writing...
 * Writing to file...
 * File written and closed successfully.
 * 
 * Opening file 'test_file.txt' for reading...
 * Reading from file:
 * -------------------
 * Operating Systems: Three Easy Pieces
 * This is a test file.
 * Line 1: Virtualization
 * Line 2: Concurrency
 * Line 3: Persistence
 * -------------------
 * File read and closed successfully.
 *
 * EXPLANATION:
 * File I/O in C uses the FILE* type and several standard library functions:
 *
 * fopen(filename, mode):
 * - "r"  : Open for reading (file must exist)
 * - "w"  : Open for writing (creates new or truncates existing)
 * - "a"  : Open for appending (creates if doesn't exist)
 * - "r+" : Open for reading and writing (file must exist)
 * - "w+" : Open for reading and writing (creates new or truncates)
 * 
 * fprintf(fp, format, ...):
 * - Writes formatted output to a file
 *
 * fgets(buffer, size, fp):
 * - Reads a line from the file into buffer
 * - Returns NULL when end of file is reached
 *
 * fclose(fp):
 * - Closes the file and flushes any buffered data
 * - Important: Always close files when done!
 *
 * ERROR HANDLING:
 * - Always check if fopen() returns NULL (file couldn't be opened)
 * - Common reasons: file doesn't exist, no permissions, disk full
 *
 * GOOD PRACTICES:
 * - Always close files after use to free resources
 * - Check return values of file operations
 * - Use binary mode ("rb", "wb") for binary data
 */

#endif
