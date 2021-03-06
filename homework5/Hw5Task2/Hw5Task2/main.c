#include <stdio.h>
#include <stdlib.h>
#include "../../stack/stack/stackTests.h"
#include "BalanceOfParentheses.h"
#include "testsBalance.h"

int main(int argc, char argv[])
{
    if (!(testsStack() && testsBalance()))
    {
        printf("Tests failed");
        return -1;
    }
    if (argc > 1)
    {
        return 0;
    }
    char sequence[30] = { '\0' };
    printf("Parentheses sequence: ");
    fgets(sequence, (unsigned)sizeof(sequence), stdin);
    if (checkBalance(sequence, 30) == 1)
    {
        printf("Balance is kept");
    }
    else
    {
        printf("There is no balance at all");
    }
}