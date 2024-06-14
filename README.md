# Get_Next_Line

## Overview

The "Get Next Line" involves creating a function that reads and returns a line from a file descriptor. This function should handle multiple calls efficiently, reading the file one line at a time.

## Project Objectives

- Implement a function that reads a line from a file descriptor.
- Utilize static variables to maintain state across multiple function calls.
- Manage memory allocation and ensure there are no memory leaks.

## Project Structure

### Mandatory Part

- Implement the `get_next_line` function:

```c
char *get_next_line(int fd);
```

- Handle repeated calls to `get_next_line` to read a file line by line.
- Ensure the function works for both file input and standard input.
- Include the terminating newline character in the returned line, if present.
- Return `NULL` if there is nothing more to read or an error occurs.

### Bonus Part

- Implement `get_next_line` to handle multiple file descriptors simultaneously.
- Ensure the function can read from different file descriptors in successive calls without losing track.

## Getting Started

1. **Clone the repository**:

```bash
git clone https://github.com/stanislavmg/get-next-line.git
```

1. **Compile the project**:

```bash
cd gnl && make
```

1. Include the header file and compile your project with `gnl.a`**:**

```c
#include "/path/to/get_next_line_bonus.h"
gcc main.c get_next_line_bonus.a -o your_program
```