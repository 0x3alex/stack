#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <assert.h>


#define define_stack(suffix,type) \
\
    static bool print_with_ptr_stack_##suffix = false; \
\
    typedef struct s_stack_##suffix { \
        type m_value; \
        struct s_stack_##suffix *ptr_next; \
    } stack_##suffix; \
\
    static stack_##suffix *new_stack_##suffix(const unsigned int amount_of_values,...) { \
        if(amount_of_values < 1) return NULL;  \
        stack_##suffix *n = NULL, *t = NULL;\
        va_list argp; \
        va_start(argp,amount_of_values); \
        if(amount_of_values >= 1) { \
            for(int i = 0; i < amount_of_values; i++) { \
                n = (stack_##suffix*)calloc(1,sizeof(stack_##suffix)); \
                assert(n != NULL); \
                n->m_value = va_arg(argp,type); \
                n->ptr_next = t; \
                t = n; \
            } \
        }  \
        va_end(argp); \
        return n; \
    } \
\
    static bool is_empty_stack_##suffix(stack_##suffix *top) { \
        return top == NULL; \
    } \
\
    static void push_stack_##suffix(stack_##suffix **top, type val) { \
        stack_##suffix *n = (stack_##suffix*)calloc(1,sizeof(stack_##suffix)); \
        assert(n != NULL); \
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
    static void pop_stack_##suffix(stack_##suffix **top) { \
        stack_##suffix *t = (*top)->ptr_next; \
        free(*top); \
        *top = t; \
    } \
\
    static void print_stack_##suffix(stack_##suffix *top,char *formatter) { \
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
    static void destroy_stack_##suffix(stack_##suffix *top) { \
        stack_##suffix *c = top, *t = NULL; \
        while(c != NULL) { \
            t = c->ptr_next; \
            free(c); \
            c = t; \
        } \
    } \
    
