#include <stack.h>
#include <stdio.h>

define_stack(int,int);

int main(void) {
    stack_int *e = new_stack_int(10);
    print_with_ptr_stack_int = true;
    pop_stack_int(&e);
    printf("stack empty? %s\n",is_empty_stack_int(e) ? "Yes" : "No");
    push_stack_int(&e,20);
    printf("stack empty? %s\n",is_empty_stack_int(e) ? "Yes" : "No");
    pop_stack_int(&e);
    push_stack_int(&e,20);
    push_stack_int(&e,30);
    print_stack_int(e,"%d\n");
    destroy_stack_int(e);
}