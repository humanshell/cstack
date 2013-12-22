
//
// stack.h
//
// Copyright (c) 2013 Dominic Giglio <humanshell@gmail.com>
//

#ifndef __STACK_H__
#define __STACK_H__

#ifdef __cplusplus
extern "C" {
#endif

// Library version
#define STACK_VERSION "0.0.1"

// Memory management macros
#ifndef STACK_MALLOC
#define STACK_MALLOC malloc
#endif

#ifndef STACK_FREE
#define STACK_FREE free
#endif

#ifdef __cplusplus
}
#endif

#endif /* __STACK_H__ */

