# Makefile for Operating Systems: Three Easy Pieces Exercises
# This Makefile helps compile individual exercises or all exercises at once

CC = gcc
CFLAGS = -Wall -Wextra -pthread -g
RM = rm -f

# Directories
VIRT_DIR = virtualization
CONC_DIR = concurrency
PERS_DIR = persistence

# Virtualization exercises
VIRT_SOURCES = $(wildcard $(VIRT_DIR)/*-template.c)
VIRT_BINS = $(VIRT_SOURCES:.c=)

# Concurrency exercises
CONC_SOURCES = $(wildcard $(CONC_DIR)/*-template.c)
CONC_BINS = $(CONC_SOURCES:.c=)

# Persistence exercises
PERS_SOURCES = $(wildcard $(PERS_DIR)/*-template.c)
PERS_BINS = $(PERS_SOURCES:.c=)

# All binaries
ALL_BINS = $(VIRT_BINS) $(CONC_BINS) $(PERS_BINS)

.PHONY: all virtualization concurrency persistence clean help

# Default target
all: virtualization concurrency persistence
	@echo "All exercises compiled successfully!"

# Compile all virtualization exercises
virtualization: $(VIRT_BINS)
	@echo "Virtualization exercises compiled!"

# Compile all concurrency exercises
concurrency: $(CONC_BINS)
	@echo "Concurrency exercises compiled!"

# Compile all persistence exercises
persistence: $(PERS_BINS)
	@echo "Persistence exercises compiled!"

# Generic rule for compiling C files
%: %.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -o $@ $<

# Clean all compiled binaries
clean:
	@echo "Cleaning compiled files..."
	$(RM) $(ALL_BINS)
	$(RM) test_file.txt  # Remove test files created by exercises
	@echo "Clean complete!"

# Help message
help:
	@echo "Operating Systems: Three Easy Pieces - Exercise Compilation"
	@echo ""
	@echo "Usage:"
	@echo "  make                    - Compile all exercises"
	@echo "  make virtualization     - Compile only virtualization exercises"
	@echo "  make concurrency        - Compile only concurrency exercises"
	@echo "  make persistence        - Compile only persistence exercises"
	@echo "  make clean              - Remove all compiled binaries"
	@echo ""
	@echo "To compile a specific exercise:"
	@echo "  make virtualization/cpu-intro-template"
	@echo "  make concurrency/threads-intro-template"
	@echo "  make persistence/file-io-template"
	@echo ""
	@echo "To run an exercise:"
	@echo "  ./virtualization/cpu-intro-template"
	@echo "  ./concurrency/threads-intro-template"
	@echo "  ./persistence/file-io-template"
