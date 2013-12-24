
//
// cstack.c
//
// Copyright (c) 2013 Dominic Giglio <humanshell@gmail.com>
//

#include "cstack.h"

/**
 * Allocate a new cstack_t (NULL on failure)
 */

cstack_t *
cstack_new() {
  cstack_t *self;
  if (!(self = CSTACK_MALLOC(sizeof(cstack_t)))) return NULL;
  self->size = 0;
  self->top = NULL;
  return self;
}

/**
 * Allocate a new cstack_node_t (NULL on failure)
 */

cstack_node_t *
cstack_node_new(void *val) {
  cstack_node_t *self;
  if (!(self = CSTACK_MALLOC(sizeof(cstack_node_t)))) return NULL;
  self->next = NULL;
  self->val = val;
  return self;
}

/**
 * Push a new node onto the stack
 */

void
cstack_push(cstack_t *stack, void *val) {
  cstack_node_t *node = cstack_node_new(val);
  node->next = stack->top;
  stack->top = node;
  stack->size++;
}

/**
 * Pop a node off the stack
 */

void
cstack_pop(cstack_t *stack) {
  if (stack->size) {
    cstack_node_t *popped = stack->top;
    stack->top = stack->top->next;
    stack->size--;
    CSTACK_FREE(popped);
  }
}

/**
 * Destroy the entire stack
 */

void
cstack_destroy(cstack_t *self) {
  unsigned int size = self->size;
  cstack_node_t *next, *top = self->top;

  while (size--) {
    next = top->next;
    CSTACK_FREE(top);
    top = next;
  }

  CSTACK_FREE(self);
}

