
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
  char *sp = "a";
  char c = 'a', *cp = &c;
  int i = 1, *ip = &i;
  float f = 1.0, *fp = &f;

  // create nodes with different data types
  cstack_node_t *node_s = cstack_node_new(sp);
  cstack_node_t *node_c = cstack_node_new(cp);
  cstack_node_t *node_i = cstack_node_new(ip);
  cstack_node_t *node_f = cstack_node_new(fp);

  // assert that all nodes were created
  assert(node_s);
  assert(node_c);
  assert(node_i);
  assert(node_f);

  // assert all nodes have correct val's and next pointers
  assert(node_s->next == NULL);
  assert(node_s->val == sp);
  assert(node_c->next == NULL);
  assert(node_c->val == cp);
  assert(node_i->next == NULL);
  assert(node_i->val == ip);
  assert(node_f->next == NULL);
  assert(node_f->val == fp);
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

