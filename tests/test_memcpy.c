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

Test(__memcpy, __memcpy_1)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    void *(*fcn)(void *, const void *, size_t) = dlsym(ptr, "memcpy");
    void *str = malloc(15);
    const void *str2 = "i am a unicorn";

    if (dlerror() != NULL)
        printf("memcpy 1 error dlsym or open\n");
    cr_assert((*fcn)(str, str2, 15) == memcpy(str, str2, 15));
    cr_assert(strcmp((*fcn)(str, str2, 15), memcpy(str, str2, 15)) == 0);
}

Test(__memcpy, __memcpy_2)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    void *(*fcn)(void *, const void *, size_t) = dlsym(ptr, "memcpy");
    void *str = malloc(15);
    const void *str2 = "i am a unicorn";

    if (dlerror() != NULL)
        printf("memcpy 2 error dlsym or open\n");
    cr_assert((*fcn)(str, str2, 0) == memcpy(str, str2, 0));
    cr_assert(strcmp((*fcn)(str, str2, 0), memcpy(str, str2, 0)) == 0);
}

Test(__memcpy, __memcpy_3)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    void *(*fcn)(void *, const void *, size_t) = dlsym(ptr, "memcpy");
    void *str = malloc(15);
    const void *str2 = "i am a unicorn";

    if (dlerror() != NULL)
        printf("memcpy 3 error dlsym or open\n");
    cr_assert((*fcn)(str, str2, 30) == memcpy(str, str2, 30));
    cr_assert(strcmp((*fcn)(str, str2, 30), memcpy(str, str2, 30)) == 0);
}

Test(__memcpy, __memcpy_4)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    void *(*fcn)(void *, const void *, size_t) = dlsym(ptr, "memcpy");
    void *str = malloc(15);
    const void *str2 = "i am a unicorn";

    if (dlerror() != NULL)
        printf("memcpy 4 error dlsym or open\n");
    cr_assert((*fcn)(str, str2, 10) == memcpy(str, str2, 10));
    cr_assert(strcmp((*fcn)(str, str2, 10), memcpy(str, str2, 10)) == 0);
}

//test are good