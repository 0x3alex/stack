# stack
 generic stack implementation in c

The pointer, which is set when calling
```c
new_stack_...
```
will always be the top element of the stack,  except when set to another address manually

# Config options
```c
bool print_with_ptr_stack_##suffix = false;
```
