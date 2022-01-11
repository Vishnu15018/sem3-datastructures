#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
 
struct Stack
{
    int top;
    unsigned size;
    int* array;
};
 
struct Stack* createStack( unsigned capacity )
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
 
    if (!stack) return NULL;
 
    stack->top = -1;
    stack->size = capacity;
    stack->array = (int*) malloc (stack->size * sizeof(int));
 
    if (!stack->array) return NULL;
    return stack;
}
 int isFull(struct Stack* s){
     if(s->top==s->size-1)
        return 1;
      else 
        return 0;
 }
 void push(struct Stack* s, char op)
{
    s->top++;
    s->array[s->top] = op;
}
int isEmpty(struct Stack* s)
{
    return s->top == -1 ;
}
 
char peek(struct Stack* s)
{
    return s->array[s->top];
}
 
char pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}
 

int evaluatePostfix(char* postfix)
{
    struct Stack* stack = createStack(strlen(postfix));
    
 
    if (!stack) return -1;
    for (int i = 0; postfix[i]; ++i)
    {
        if (isdigit(postfix[i]))
            push(stack, postfix[i] - '0');
 
        else
        {
            int op1 = pop(stack);
            int op2 = pop(stack);
            switch (postfix[i])
            {
            case '%':
                push(stack,op2%op1);
                break;
            case '^':
                push(stack,op2^op1);
                break;
            case '+': 
                   push(stack, op2 + op1); 
                   break;
            case '-': 
                   push(stack, op2 - op1); 
                   break;
            case '*':
                   push(stack, op2 * op1); 
                   break;
            case '/': 
                   push(stack, op2/op1); 
                   break;
            }
        }
    }
    return pop(stack);
}
 
int main()
{
    char postfix[] = "988/+4%";
    printf ("postfix evaluation: %d", evaluatePostfix(postfix));
    return 0;
}