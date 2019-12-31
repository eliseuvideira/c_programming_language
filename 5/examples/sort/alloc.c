#define ALLOC_SIZE 10000

static char alloc_buffer[ALLOC_SIZE];
static char *alloc_pointer = alloc_buffer;

char *alloc(int n) {
  // check if available space is sufficient
  if (alloc_buffer + ALLOC_SIZE - alloc_pointer >= n) {
    alloc_pointer += n;
    return alloc_pointer - n;
  } else {
    return 0; // NULL
  }
}

void afree(char *pointer) {
  // check if pointer is inside range
  if (pointer >= alloc_buffer && pointer < alloc_buffer + ALLOC_SIZE) {
    alloc_pointer = pointer;
  }
}

