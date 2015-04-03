#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 256

struct stack_t {
    int top_, size_;
    int *data_;
};
void init(struct stack_t*);
void release(struct stack_t*);
void push(struct stack_t*, int);
int pop(struct stack_t*);
int is_full(struct stack_t);
int is_empty(struct stack_t);
int peek(struct stack_t);

int main()
{
    char brackets[MAX_INPUT_SIZE];

    struct stack_t stack;
    init(&stack);

    printf("Enter brackets: ");
    scanf("%s", brackets);

    int i;
    for (i = 0; brackets[i] != '\0'; i++)
    {
        if (brackets[i] == '{' ||
            brackets[i] == '(' ||
            brackets[i] == '[')
        {
            push(&stack, (int)brackets[i]);
        }
        else if (brackets[i] == '}' ||
                 brackets[i] == ')' ||
                 brackets[i] == ']')
        {
            char last_pushed = (char) peek(stack);

            if ((last_pushed == '{' && brackets[i] == '}') ||
                (last_pushed == '(' && brackets[i] == ')') ||
                (last_pushed == '[' && brackets[i] == ']'))
            {
                pop(&stack);
            }
        }
    }

    if (is_empty(stack) == 0)
         printf("YES");
    else printf("NO");

    return 0;
}

void init(struct stack_t* st)
{
    st->top_ = 0;
    st->size_ = 5;
    st->data_ = (int*) malloc(st->size_ * sizeof(int));
}

void release(struct stack_t* st)
{
    free(st->data_);
    st->top_ = 0;
    st->size_ = 0;
}

int is_full(struct stack_t st)
{
    return st.top_ == st.size_;
}

int is_empty(struct stack_t st)
{
    return st.top_ == 0 ? 0 : -1;
}

void push(struct stack_t* st, int value)
{
    st->data_[st->top_++] = value;
}

int pop(struct stack_t* st)
{
    return st->data_[--st->top_];
}

int peek(struct stack_t st)
{
    return st.data_[st.top_ - 1];
}
