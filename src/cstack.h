
//
// cstack.h
//
// Copyright (c) 2013 Dominic Giglio <humanshell@gmail.com>
//

#ifndef __CSTACK_H__
#define __CSTACK_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

// Library version
#define CSTACK_VERSION "0.0.1"

// Memory management macros
#ifndef CSTACK_MALLOC
#define CSTACK_MALLOC malloc
#endif

#ifndef CSTACK_FREE
#define CSTACK_FREE free
#endif

/**
 * cstack_t node struct
 */

typedef struct cstack_node {
  struct cstack_node *next;
  void *val;
} cstack_node_t;


/**
 * cstack_t struct
 */

typedef struct {
  unsigned int size;
  cstack_node_t *top;
  void (*push)(cstack_node_t *node);
  void (*pop)(void);
  void (*empty)(void);
} cstack_t;


/**
 * cstack_t node prototypes
 */ 

cstack_node_t *
cstack_node_new(void *val);


/**
 * cstack_t prototypes
 */

cstack_t *
cstack_new();

void
cstack_destroy(cstack_t *self);

#ifdef __cplusplus
}
#endif

#endif /* __CSTACK_H__ */

