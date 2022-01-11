#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Stack
{
    int top;
    unsigned size;
    int array[size][];
};
 
struct Stack* createStack( unsigned capacity )
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
 
    if (!stack) return NULL;
 
    stack->top = -1;
    stack->size = capacity;
     
 
    if (!stack->array) return NULL;
    return stack;
}
 int isFull(struct Stack* s){
     if(s->top==s->size-1)
        return 1;
      else 
        return 0;
 }
 void push(struct Stack* s, char op[80])
{
    s->top++;
    s->array[s->top][] = op[80];
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
int prefixinfix(char* prefix){
    int length=strlen(prefix);
    struct Stack *stack=createStack(length);
    for(int i=length-1;i>=0;i++){
        if(!(isOperator(prefix[i]))){
            push(stack,prefix[i]);
        }
        else{
            char op1[]=pop(stack);
            char op2[]=pop(stack);
            char conc[]=strcat("(",op1);
            char conc1[]=strcat(conc,prefix[i]);
            char conc2[]=strcat(conc1,op2);
            char conc3[]=strcat(conc2,")");

            push(stack,conc3);
        }
    }
     printf("The final infinix expression is : %s",pop(stack));
}
int main(){
 
  char a[]= "+*A%BC+-AKL";
  prefixinfix(a);

}