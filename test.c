
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "src/cstack.h"

// Helpers

#define test(fn) \
  puts("... \x1b[33m" # fn "\x1b[0m"); \
  test_##fn();

// Tests

static void
test_cstack_new() {
  cstack_t *stack = cstack_new();
  assert(stack);
  assert(stack->size == 0);
  assert(stack->top == NULL);
}

static void
test_cstack_node_new() {
  cstack_node_t *node = cstack_node_new("a");
  assert(node);
  assert(node->next == NULL);
  assert(node->val == "a");
}

int
main(int argc, const char **argv) {
  printf("\ncstack_t: %ld\n", sizeof(cstack_t));
  printf("cstack_node_t: %ld\n", sizeof(cstack_node_t));
  test(cstack_new);
  test(cstack_node_new);
  puts("... \x1b[32m100%\x1b[0m\n");
  return 0;
}

