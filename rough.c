#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
 
struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};
 
struct Stack* createStack( unsigned capacity )
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
 
    if (!stack) return NULL;
 
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
 
    if (!stack->array) return NULL;
 
    return stack;
}
 
int isEmpty(struct Stack* stack)
{
    return stack->top == -1 ;
}
 
char peek(struct Stack* stack)
{
    return stack->array[stack->top];
}
 
char pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}
 
void push(struct Stack* stack, char op)
{
    stack->array[++stack->top] = op;
}

int isOperator(char x) {
switch (x) {
case '+':
case '-':
case '/':
case '*':
	return 1;
}
    return 0;
}

// Convert prefix to Infix expression
/*string preToInfix(string pre_exp) {
stack<string> s;

// length of expression
int length = pre_exp.size();

// reading from right to left
for (int i = length - 1; i >= 0; i--) {

	// check if symbol is operator
	if (isOperator(pre_exp[i])) {

	// pop two operands from stack
	string op1 = s.top(); s.pop();
	string op2 = s.top(); s.pop();

	// concat the operands and operator
	string temp = "(" + op1 + pre_exp[i] + op2 + ")";

	// Push string temp back to stack
	s.push(temp);
	}

	// if symbol is an operand
	else {

	// push the operand to the stack
	s.push(string(1, pre_exp[i]));
	}
}

// Stack now contains the Infix expression
return s.top();
}
*/
int main(){
//string pre_exp = "*-A/BC-/AKL";
//cout << "Infix : " << preToInfix(pre_exp);
   //char *str1=(char*)malloc(20*sizeof(char));
   //scanf("%s",str1);
   //printf("%s",str1); 
   struct Stack *s=createStack(10);
   push(s,'a');
   push(s,'b');
   //pop(s);
   printf("%c",peek(s));

}