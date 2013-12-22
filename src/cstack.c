
//
// cstack.c
//
// Copyright (c) 2013 Dominic Giglio <humanshell@gmail.com>
//

#include "cstack.h"

/*
 * Allocate a new cstack_t
 * NULL on failure
 */

cstack_t *
cstack_new() {
  cstack_t *self;
  if (!(self = CSTACK_MALLOC(sizeof(cstack_t)))) return NULL;
  self->size = 0;
  self->top = NULL;
  return self;
}

/*
 * Allocates a new cstack_node_t
 * NULL on failure
 */

cstack_node_t *
cstack_node_new(void *val) {
  cstack_node_t *self;
  if (!(self = CSTACK_MALLOC(sizeof(cstack_node_t)))) return NULL;
  self->next = NULL;
  self->val = val;
  return self;
}

