#include <stdio.h>

#define INPUT_LENGTH 256

int main()
{
    char brackets_input[INPUT_LENGTH];

    printf("Enter brackets: ");
    scanf("%s", brackets_input);
    if (check_balance(brackets_input) == 0)
         printf("The brackets ARE balanced.");
    else printf("The brackets ARE NOT balanced.");

    return 0;
}

int check_balance(char brackets[])
{
    if (brackets[0] == '}') return -1;

    int balancer = 0;

    int i;
    for (i = 0; brackets[i] != '\0'; i++)
    {
        if (brackets[i] == '{') balancer++;
        if (brackets[i] == '}') balancer--;
        if (balancer < 0) return -1;
    }

    return balancer==0 ? 0 : -1;
}
