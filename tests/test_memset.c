/*
** EPITECH PROJECT, 2020
** minilibc
** File description:
** minilibc
*/

#include <criterion/criterion.h>
#include <string.h>
#include <signal.h>
#include <dlfcn.h>
#include <stdio.h>

Test(__memset, __memset_1)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    void *(*fcn)(void *, int, size_t) = dlsym(ptr, "memset");
    char *str = malloc(5);
    int *arr = malloc(sizeof(int) * 12);
    void *nl = malloc(100);

    if (dlerror() != NULL)
        printf("memset 1 error dlsym or open\n");
    cr_assert((*fcn)(str, 0, 5) == memset(str, 0, 5));
    cr_assert((*fcn)(arr, 0, 12) == memset(arr, 0, 12));
    cr_assert((*fcn)(nl, 0, 100) == memset(nl, 0, 100));
    cr_assert(strcmp((*fcn)(str, 0, 5), memset(str, 0, 5)) == 0);
    cr_assert(strcmp((*fcn)(arr, 0, 12), memset(arr, 0, 12)) == 0);
    cr_assert(strcmp((*fcn)(nl, 0, 100), memset(nl, 0, 100)) == 0);
}

Test(__memset, __memset_2)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    void *(*fcn)(void *, int, size_t) = dlsym(ptr, "memset");
    char *str = malloc(5);
    int *arr = malloc(sizeof(int) * 12);
    void *nl = malloc(100);

    if (dlerror() != NULL)
        printf("memset 2 error dlsym or open\n");
    cr_assert((*fcn)(str, 0, 0) == memset(str, 0, 0));
    cr_assert((*fcn)(arr, 0, 0) == memset(arr, 0, 0));
    cr_assert((*fcn)(nl, 0, 0) == memset(nl, 0, 0));
    cr_assert(strcmp((*fcn)(str, 0, 0), memset(str, 0, 0)) == 0);
    cr_assert(strcmp((*fcn)(arr, 0, 0), memset(arr, 0, 0)) == 0);
    cr_assert(strcmp((*fcn)(nl, 0, 0), memset(nl, 0, 0)) == 0);
}

Test(__memset, __memset_3)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    void *(*fcn)(void *, int, size_t) = dlsym(ptr, "memset");
    char *str = malloc(5);
    int *arr = malloc(sizeof(int) * 12);
    void *nl = malloc(100);

    if (dlerror() != NULL)
        printf("memset 3 error dlsym or open\n");
    cr_assert((*fcn)(str, 0, 5) == memset(str, 0, 10));
    cr_assert((*fcn)(arr, 0, 12) == memset(arr, 0, 24));
    cr_assert((*fcn)(nl, 0, 100) == memset(nl, 0, 200));
    cr_assert(strcmp((*fcn)(str, 0, 10), memset(str, 0, 10)) == 0);
    cr_assert(strcmp((*fcn)(arr, 0, 24), memset(arr, 0, 24)) == 0);
    cr_assert(strcmp((*fcn)(nl, 0, 200), memset(nl, 0, 200)) == 0);
}

Test(__memset, __memset_4)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    void *(*fcn)(void *, int, size_t) = dlsym(ptr, "memset");
    char *str = 0;
    int *arr = 0;
    void *nl = 0;

    if (dlerror() != NULL)
        printf("memset 4 error dlsym or open\n");
    cr_assert((*fcn)(str, 0, 0) == memset(str, 0, 0));
    cr_assert((*fcn)(arr, 0, 0) == memset(arr, 0, 0));
    cr_assert((*fcn)(nl, 0, 0) == memset(nl, 0, 0));
}

//test are good