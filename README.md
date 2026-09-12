*This project has been created as part of the 42 curriculum by <casampai>.*

# Get Next Line

## Description

**Get Next Line** is a fundamental C programming project at 42. Its goal is to create a function that reads and returns a single line from a file descriptor (`fd`) each time it is called, until the end of the file (EOF) or an error occurs.

The project introduces key concepts in low-level C programming, including:
- **Static variables** to preserve state across multiple function calls.
- **Dynamic memory management** (`malloc`, `free`) without memory leaks.
- Efficient file I/O operations using the `read` system call.
- Buffer size independence (handling any `BUFFER_SIZE` value, from 1 byte to millions of bytes).

---

## Algorithm Explanation & Justification

The core challenge of **Get Next Line** is reading a file in chunks of arbitrary size (`BUFFER_SIZE`) while delivering output line by line (delimited by `\n` or EOF).

### How It Works

1. **Read & Accumulate (`read_to_stash`)**: 
   The program reads `BUFFER_SIZE` bytes from the file descriptor into a temporary buffer and appends them to a persistent **static variable** (`stash`). This process continues in a loop until a newline character (`\n`) is found in the `stash` or the `read` call reaches the end of the file (`bytes_read == 0`).

2. **Extract Line (`extract_line`)**: 
   Once a `\n` is detected (or EOF is reached), the function copies all characters from the beginning of `stash` up to and including the first `\n` into a newly allocated string (`line`).

3. **Clean Stash (`recreate_stash`)**: 
   The remaining characters after the `\n` are extracted into a new string, which becomes the new `stash` for subsequent calls. The previous `stash` memory is freed.

### Algorithm Justification

- **Efficiency & Memory Constraints**: Storing remaining unread data in a static buffer ensures that subsequent function calls resume reading exactly where the previous call stopped, without re-reading bytes from disk.
- **Linear Complexity $O(N)$**: Searching for `\n` directly within the newly read `buffer` (rather than scanning the entire accumulated `stash` at every read step) prevents quadratic slowdowns $O(N^2)$ when dealing with extremely large lines and small `BUFFER_SIZE` values (such as `BUFFER_SIZE = 1`).
- **Memory Safety**: Every dynamic allocation (`malloc`) is guarded by error handling, ensuring that if reading or memory allocation fails, all allocated buffers are safely freed (`free`) to avoid memory leaks.

---

## Instructions

### Prerequisites

You need a C compiler (`gcc` or `clang`) and `make` installed on your UNIX system.

### Compilation

Include `get_next_line.c`, `get_next_line_utils.c`, and `get_next_line.h` in your project compilation. You can set a custom `BUFFER_SIZE` at compile time using the `-D` flag:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl_test