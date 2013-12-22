
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "src/stack.h"

// Helpers

#define test(fn) \
  puts("... \x1b[33m" # fn "\x1b[0m"); \
  test_##fn();

// Tests

static void
test_() {}

int
main(int argc, const char **argv){
  test();
  puts("... \x1b[32m100%\x1b[0m\n");
  return 0;
}

