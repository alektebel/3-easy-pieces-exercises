# Operating Systems: Three Easy Pieces - Exercise Templates

This repository contains exercise templates for learning Operating Systems concepts from the book ["Operating Systems: Three Easy Pieces"](https://pages.cs.wisc.edu/~remzi/OSTEP/) by Remzi H. Arpaci-Dusseau and Andrea C. Arpaci-Dusseau.

## 📚 About

Each template provides:
- **Clear objectives** explaining what you'll learn
- **Step-by-step guidelines** to help you implement the solution
- **TODO comments** marking where you need to write code
- **Complete solutions** that you can reveal when stuck
- **Detailed explanations** of the concepts and expected behavior

## 🗂️ Repository Structure

```
3-easy-pieces-exercises/
├── virtualization/          # CPU and Memory virtualization exercises
│   ├── cpu-intro-template.c      # Process API and fork()
│   └── memory-api-template.c     # Memory allocation with malloc()
├── concurrency/             # Threading and synchronization exercises
│   ├── threads-intro-template.c  # Basic threading and race conditions
│   └── locks-mutex-template.c    # Mutex locks and synchronization
├── persistence/             # File systems and I/O exercises
│   └── file-io-template.c        # Basic file I/O operations
├── Makefile                 # Build system for all exercises
└── README.md               # This file
```

## 🚀 Getting Started

### Prerequisites

You need a C compiler and pthread library:

```bash
# Ubuntu/Debian
sudo apt-get install build-essential

# macOS (install Xcode Command Line Tools)
xcode-select --install

# Fedora/RHEL
sudo dnf install gcc make
```

### Building Exercises

Use the provided Makefile to compile exercises:

```bash
# Compile all exercises
make

# Compile exercises by category
make virtualization
make concurrency
make persistence

# Compile a specific exercise
make virtualization/cpu-intro-template
make concurrency/threads-intro-template

# Clean compiled binaries
make clean

# Show help
make help
```

## 📖 How to Use the Templates

### Step 1: Choose an Exercise

Pick an exercise template from one of the three main categories:
- **Virtualization**: Process creation, memory management
- **Concurrency**: Threads, locks, synchronization
- **Persistence**: File I/O, file systems

### Step 2: Read the Objective

Each template starts with:
- The chapter it relates to
- A clear objective of what you'll learn
- Guidelines to help you implement it

### Step 3: Implement Your Solution

Look for `TODO` comments in the code and implement your solution following the guidelines.

Example from `cpu-intro-template.c`:
```c
// TODO: Declare and initialize a variable x to 100

// TODO: Call fork() and store the return value

// TODO: If in child process (return value == 0):
//       - Print that we're in the child
//       - Print current value of x
```

### Step 4: Compile and Test

```bash
# Compile your exercise
make virtualization/cpu-intro-template

# Run it
./virtualization/cpu-intro-template
```

### Step 5: Check the Solution (If Stuck)

Each template has a complete solution at the bottom wrapped in `#if 0 ... #endif`.

To view and compile the solution:
1. Change `#if 0` to `#if 1` at the solution section
2. Recompile and run

The solution includes:
- Complete working code
- Expected output
- Detailed explanation of concepts
- Common pitfalls and best practices

## 📋 Exercise List

### Virtualization

1. **cpu-intro-template.c** - Process API
   - Learn about `fork()` and process creation
   - Understand address space separation
   - Use `wait()` for process synchronization

2. **memory-api-template.c** - Memory Management
   - Allocate memory with `malloc()`
   - Understand memory leaks and use-after-free bugs
   - Practice proper memory deallocation with `free()`

### Concurrency

3. **threads-intro-template.c** - Basic Threading
   - Create threads with `pthread_create()`
   - Observe race conditions with shared data
   - Understand why synchronization is needed

4. **locks-mutex-template.c** - Mutex Synchronization
   - Fix race conditions using mutexes
   - Use `pthread_mutex_lock()` and `pthread_mutex_unlock()`
   - Learn the trade-offs between correctness and performance

### Persistence

5. **file-io-template.c** - File I/O Operations
   - Open, read, and write files with `fopen()`, `fprintf()`, `fgets()`
   - Handle file operation errors
   - Understand file modes and proper resource cleanup

## 💡 Learning Tips

1. **Try it yourself first**: Don't look at the solution immediately. Struggling with the problem helps you learn.

2. **Compile frequently**: Compile after each small change to catch errors early.

3. **Read error messages carefully**: Compiler errors are your friends. They tell you exactly what's wrong.

4. **Experiment**: Modify the code to see what happens. Break things intentionally to understand how they work.

5. **Read the explanations**: The solution sections include detailed explanations that are crucial for understanding.

6. **Use debugging tools**: Learn to use `gdb` for debugging and `valgrind` for memory errors.

## 🔧 Troubleshooting

### Compilation Errors

```bash
# If you get "pthread" errors on Linux
gcc -pthread your-file.c -o your-program

# On macOS, threading is included by default
gcc your-file.c -o your-program
```

### Runtime Issues

- **Segmentation fault**: Check array bounds, null pointers, use-after-free
- **Race condition**: Use proper synchronization with mutexes
- **Memory leaks**: Always `free()` what you `malloc()`

## 📚 Additional Resources

- [Operating Systems: Three Easy Pieces (free online)](https://pages.cs.wisc.edu/~remzi/OSTEP/)
- [POSIX Threads Programming](https://computing.llnl.gov/tutorials/pthreads/)
- [GNU C Library Documentation](https://www.gnu.org/software/libc/manual/)

## 📝 Contributing

Feel free to add more exercise templates! Follow the existing format:
- Clear objective and guidelines
- TODO markers for student implementation
- Complete solution with explanations
- Expected output examples

## 📄 License

These templates are educational materials for learning Operating Systems concepts from the "Three Easy Pieces" book.

## 🙏 Acknowledgments

Based on the excellent book "Operating Systems: Three Easy Pieces" by Remzi H. Arpaci-Dusseau and Andrea C. Arpaci-Dusseau.