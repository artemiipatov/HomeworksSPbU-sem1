#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "mergeSort.h"
#include "tests.h"
#define NAME_SIZE 20

bool testOneElementArray(List* testList)
{
    addAtTail(testList, "dgfdggd", 981);
    if (mergeSort(testList, names) == NULL || mergeSort(testList, numbers) == NULL)
    {
        deleteList(&testList);
        return false;
    }
    if (getLength(testList) != 1)
    {
        deleteList(&testList);
        return false;
    }
    return true;
}

bool testSortingByNames(List* testList)
{
    if (!addAtTail(testList, "aaaaaaab", 981)
        || !addAtTail(testList, "zcvzx", 432)
        || !addAtTail(testList, "zcvzx", 789)
        || !addAtTail(testList, "asdsdfsd", 636)
        || !addAtTail(testList, "hfdgsd", 211)
        || !addAtTail(testList, "kdmfg", 211)
        || !addAtTail(testList, "tiewqvc", 129)
        || !addAtTail(testList, "eeeeee", 789)
        || !addAtTail(testList, "eeeeeh", 592)
        || !addAtTail(testList, "aaaaaaaa", 981))
    {
        deleteList(&testList);
        return false;
    }
    if (getLength(testList) != 11)
    {
        deleteList(&testList);
        return false;
    }
    if (mergeSort(testList, names) == NULL)
    {
        deleteList(&testList);
        return false;
    }
    char* correctNameSorting1[11] = { "aaaaaaaa", "aaaaaaab", "asdsdfsd", "dgfdggd", "eeeeee", "eeeeeh", "hfdgsd", "kdmfg", "tiewqvc", "zcvzx", "zcvzx" };
    int correrctNumberSorting1[11] = { 981, 981, 636, 981, 789, 592, 211, 211, 129, 432, 789 };
    for (int index = 0; index < 11; index++)
    {
        char name[NAME_SIZE] = { '\0' };
        int number = 0;
        popHead(testList, name, &number);
        if (!(strcmp(name, correctNameSorting1[index]) == 0 && number == correrctNumberSorting1[index]))
        {
            deleteList(&testList);
            return false;
        }
    }
    return true;
}

bool testSortingByNumbers(List* testList)
{
    if (!addAtTail(testList, "dgfdggd", 981)
        || !addAtTail(testList, "aaaaaaab", 981)
        || !addAtTail(testList, "zcvzx", 432)
        || !addAtTail(testList, "zcvzx", 789)
        || !addAtTail(testList, "asdsdfsd", 636)
        || !addAtTail(testList, "hfdgsd", 211)
        || !addAtTail(testList, "kdmfg", 211)
        || !addAtTail(testList, "tiewqvc", 129)
        || !addAtTail(testList, "eeeeee", 789)
        || !addAtTail(testList, "eeeeeh", 592)
        || !addAtTail(testList, "aaaaaaaa", 981))
    {
        deleteList(&testList);
        return false;
    }
    if (strcmp(getHeadName(testList), "dgfdggd") != 0)
    {
        deleteList(&testList);
        return false;
    }
    if (getHeadNumber(testList) != 981)
    {
        deleteList(&testList);
        return false;
    }
    if (mergeSort(testList, numbers) == NULL)
    {
        deleteList(&testList);
        return false;
    }
    char* correctNameSorting2[11] = { "tiewqvc", "hfdgsd", "kdmfg", "zcvzx", "eeeeeh", "asdsdfsd", "zcvzx", "eeeeee", "dgfdggd", "aaaaaaab", "aaaaaaaa" };
    int correrctNumberSorting2[11] = { 129, 211, 211, 432, 592, 636, 789, 789, 981, 981, 981 };
    for (int index = 0; index < 11; index++)
    {
        char name[NAME_SIZE] = { '\0' };
        int number = 0;
        popHead(testList, name, &number);
        if (!(strcmp(name, correctNameSorting2[index]) == 0 && number == correrctNumberSorting2[index]))
        {
            deleteList(&testList);
            return false;
        }
    }
    return true;
}

bool programPassedTests()
{
    List* testList = createList();
    if (testList == NULL)
    {
        return false;
    }
    bool testsPassed = testOneElementArray(testList) && testSortingByNames(testList) && testSortingByNumbers(testList);
    deleteList(&testList);
    return testsPassed && isEmpty(testList);
}