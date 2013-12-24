# CStack

 C simple stack implementation.

## API

 Below is the public api currently provided by the "cstack" library.

### cstack_t \*cstack_new();

 Allocate and initialize a `stack`.
 
    cstack_t *stack = cstack_new();

### cstack_node_t \*cstack_node_new(void \*val)

 Allocate and initialize a `cstack_node_t` with the given val.

    cstack_node_t *node = cstack_node_new("my value");
    node->val; // "my value"

### void cstack_push(cstack_t \*stack, void \*val)

 Push the new val onto the top of the passed in stack.
 
     cstack_push(stack, "value");
     stack->top->val; // "value"
     stack->size; // 1

### void cstack_pop(cstack_t \*stack)

 Pop the top val off the passed in stack.
 
     cstack_pop(stack);
     stack->top->val; // NULL
     stack->size; // 0

### void cstack_empty(cstack_t \*stack)

 Remove all nodes from the passed in stack.
 
     cstack_push(stack, "value 1");
     cstack_push(stack, "value 2");
     cstack_push(stack, "value 3");
     stack->top->val; // "value 3"
     stack->size; // 3
     cstack_empty(stack);
     stack->top->val; // NULL
     stack->size; // 0

### void cstack_destroy(cstack_t \*stack)

 Completely destroy the passed in list and all nodes.
 
     cstack_destroy(stack);

## Testing

    $ make test

## Contributing

1. Fork it
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create new Pull Request

## License 

(The MIT License)

Copyright (c) 2013 Dominic Giglio &lt;humanshell@gmail.com&gt;

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
'Software'), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

