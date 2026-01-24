# Exercise Template Structure Guide

## How the Templates Work

Each exercise template has two sections:

1. **Student Implementation Section** - Where you write your code
2. **Solution Section** - Complete working solution (initially disabled)

## Using the Templates

### Step 1: Work on Your Implementation
Write your code in the main body of the file, following the TODO comments.

### Step 2: When You Get Stuck
If you want to see the solution:
1. **Comment out your implementation** in the main section (optional but recommended)
2. **Enable the solution**: Change `#if 0` to `#if 1` in the solution section
3. **Recompile and run** to see the working solution

### Example Workflow

#### Initial state (working on your code):
```c
int main() {
    // TODO: Your implementation here
    int x = 100;
    // ... your code ...
    return 0;
}

#if 0  // Solution is DISABLED
// Solution code here
#endif
```

#### When checking the solution:
```c
#if 0  // Comment out your implementation (optional)
int main() {
    // TODO: Your implementation here  
    int x = 100;
    // ... your code ...
    return 0;
}
#endif

#if 1  // Solution is ENABLED (changed from 0 to 1)
// Solution code here
int main() {
    // Complete working solution
    return 0;
}
#endif
```

## Notes

- The template files compile without errors in their initial state (student section)
- To compile the solution, you must change `#if 0` to `#if 1` in the solution block
- You can switch back and forth between your code and the solution
- Both sections cannot be active at the same time (would cause "redefinition of main" error)
