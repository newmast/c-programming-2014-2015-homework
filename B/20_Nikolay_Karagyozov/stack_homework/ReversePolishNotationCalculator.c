#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top;

void empty();
bool is_empty();
bool is_full();
void push(int);
char pop();
void subtract();
void divide();
void exit_stack_overflow();
void exit_stack_underflow();
void warn_incomplete_expression();

int main()
{
    int value = 0;
    char input[200];

    printf("Enter an RPN expression: ");

    fgets (input, 200, stdin);

    int i;
    for (i = 0; input[i] != '\0'; i++)
    {
        if ( isspace(input[i]) )
            continue;

        if (input[i] >= '0' && input[i] <= '9')
            push((int) input[i] - '0');
        else if ( input[i] == '+')
            push(pop() + pop());
        else if ( input[i] == '-')
            subtract();
        else if ( input[i] == '*')
            push(pop() * pop());
        else if ( input[i] == '/')
            divide();
    }

    value = pop();

    if ( is_empty() )
    {
        printf("Value: %d\n",  value);
    }
    else
    {
        warn_incomplete_expression();
        empty();
    }

    return 0;
}

void empty()
{
    top = 0;
}

bool is_empty()
{
    return top == 0;
}

bool is_full()
{
    return top == STACK_SIZE;
}

void push(int value)
{
    if (is_full())
        exit_stack_overflow();
    stack[top++] = value;
}

char pop()
{
    if (is_empty())
        exit_stack_underflow();
    return stack[--top];
}

void exit_stack_overflow()
{
    fprintf(stderr, "Expression is too long\n");
    exit(EXIT_FAILURE);
}

void exit_stack_underflow()
{
    fprintf(stderr, "Not enough operands in expression\n");
    exit(EXIT_FAILURE);
}

void warn_incomplete_expression()
{
    fprintf(stderr, "Invalid expression\n");
}

void subtract()
{
    int a = pop();
    int b = pop();

    push(b - a);
}

void divide()
{
    int a = pop();
    int b = pop();

    push(b / a);
}
