#pragma once
#include <stdlib.h>
#include <stdbool.h>


#define define_stack(suffix,type) \
\
    bool print_with_ptr_stack_##suffix = false; \
\
    typedef struct s_stack_##suffix { \
        type m_value; \
        struct s_stack_##suffix *ptr_next; \
    } stack_##suffix; \
\
    stack_##suffix *new_stack_##suffix(type val) { \
        stack_##suffix *n = (stack_##suffix*)calloc(1,sizeof(stack_##suffix)); \
        n->m_value = val; \
        n->ptr_next = NULL; \
        return n; \
    } \
\
    bool is_empty_stack_##suffix(stack_##suffix *top) { \
        return top == NULL; \
    } \
\
    void push_stack_##suffix(stack_##suffix **top, type val) { \
        stack_##suffix *n = (stack_##suffix*)calloc(1,sizeof(stack_##suffix)); \
        n->m_value = val; \
        n->ptr_next = NULL; \
        if(is_empty_stack_##suffix(*top)) { \
            *top = n; \
            return; \
        } \
        n->ptr_next = *top; \
        *top = n; \
    } \
\
    void pop_stack_##suffix(stack_##suffix **top) { \
        stack_##suffix *t = (*top)->ptr_next; \
        free(*top); \
        *top = t; \
    } \
\
    void print_stack_##suffix(stack_##suffix *top,char *formatter) { \
        stack_##suffix *c = top; \
        while(c != NULL) { \
            printf(formatter,c->m_value); \
            if(print_with_ptr_stack_##suffix) { \
                printf("self %p\nnext %p\n",c,c->ptr_next); \
            } \
            c = c->ptr_next; \
        } \
    } \
\
    void destroy_stack_##suffix(stack_##suffix *top) { \
        stack_##suffix *c = top; \
        while(c != NULL) { \
            stack_##suffix *t = c->ptr_next; \
            free(c); \
            c = t; \
        } \
    } \
    