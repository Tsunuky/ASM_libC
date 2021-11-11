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

Test(__memmove, __memmove_1)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    void *(*fcn)(void *, const void *, size_t) = dlsym(ptr, "memmove");
    void *str = malloc(15);
    const void *str2 = "i am a unicorn";

    if (dlerror() != NULL)
        printf("memmove 1 error dlsym or open\n");
    cr_assert((*fcn)(str, str2, 15) == memmove(str, str2, 15));
    cr_assert(strcmp((*fcn)(str, str2, 15), memmove(str, str2, 15)) == 0);
}

Test(__memmove, __memcpy_2)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    void *(*fcn)(void *, const void *, size_t) = dlsym(ptr, "memmove");
    void *str = malloc(15);
    const void *str2 = "i am a unicorn";

    if (dlerror() != NULL)
        printf("memmove 2 error dlsym or open\n");
    cr_assert((*fcn)(str, str2, 0) == memmove(str, str2, 0));
    cr_assert(strcmp((*fcn)(str, str2, 0), memmove(str, str2, 0)) == 0);
}

Test(__memmove, __memmove_3)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    void *(*fcn)(void *, const void *, size_t) = dlsym(ptr, "memmove");
    void *str = malloc(15);
    const void *str2 = "i am a unicorn";

    if (dlerror() != NULL)
        printf("memmove 3 error dlsym or open\n");
    cr_assert((*fcn)(str, str2, 30) == memmove(str, str2, 30));
    cr_assert(strcmp((*fcn)(str, str2, 30), memmove(str, str2, 30)) == 0);
}

Test(__memmove, __memmove_4)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    void *(*fcn)(void *, const void *, size_t) = dlsym(ptr, "memmove");
    void *str = malloc(15);
    const void *str2 = "i am a unicorn";

    if (dlerror() != NULL)
        printf("memmove 4 error dlsym or open\n");
    cr_assert((*fcn)(str, str2, 10) == memmove(str, str2, 10));
    cr_assert(strcmp((*fcn)(str, str2, 10), memmove(str, str2, 10)) == 0);
}

//test are good