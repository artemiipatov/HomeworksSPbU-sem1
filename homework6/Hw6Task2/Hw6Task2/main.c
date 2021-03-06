#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "countingOut.h"
#include "countingOutTests.h"
#include "../../cyclicList/cyclicList/cyclicListTests.h"

int main(int argc, char argv[])
{
    if (!(cyclicListPassedTests() && rhymePassedTests()))
    {
        printf("Tests failed");
        return -1;
    }
    if (argc > 1)
    {
        return 0;
    }
    int numberOfWarriors = 0;
    printf("Number of warriors: ");
    scanf("%d", &numberOfWarriors);
    int period = 0;
    printf("Period: ");
    scanf("%d", &period);
    printf("%d", countPosition(numberOfWarriors, period));
}