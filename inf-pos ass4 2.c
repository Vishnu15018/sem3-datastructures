// C program to convert infix expression to postfix
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


// A routine to check if
// the given character is operand
int isOperand(char ch)
{
	return (ch >= 'a' && ch <= 'z') ||
		(ch >= 'A' && ch <= 'Z');
}


int Prec(char ch)     /*this function will help to ckeck the precedence */
{
	switch (ch)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}



// converts given infix expression to postfix expression.
int infixToPostfix(char* exp)
{
	int i, k;

	// Create a stack of capacity
	// equal to expression size
	struct Stack* stack = createStack(strlen(exp));


	for (i = 0, k = -1; exp[i]; ++i)
	{
		
		// If the scanned character is
		// an operand, add it to output.
		if (isOperand(exp[i]))
			exp[++k] = exp[i];
		
		// If the scanned character is an
		// ‘(‘, push it to the stack.
		else if (exp[i] == '(')
			push(stack, exp[i]);
		
		// If the scanned character is an ‘)’,
		// pop and output from the stack
		// until an ‘(‘ is encountered.
		else if (exp[i] == ')')
		{
			while (!isEmpty(stack) && peek(stack) != '(')
				exp[++k] = pop(stack);
			if (!isEmpty(stack) && peek(stack) != '(')
				return -1; // invalid expression			
			else
				pop(stack);
		}
		else // an operator is encountered
		{
			while (!isEmpty(stack) &&
				Prec(exp[i]) <= Prec(peek(stack)))
				exp[++k] = pop(stack);
			push(stack, exp[i]);
		}

	}

	// pop all the operators from the stack
	while (!isEmpty(stack))
		exp[++k] = pop(stack );

	exp[++k] = '\0';
	printf( "postfix expression is : %s", exp );
}

// Driver program to test above functions
int main()
{   printf("Enter a valid infix expression: \n");
    
	char exp[15];
    scanf("%s",&exp);
	infixToPostfix(exp);
	return 0;
}
