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

Test(__strncmp, __strncmp_1)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    int (*fcn)(const char *, const char *, size_t) = dlsym(ptr, "strncmp");
    cr_assert((*fcn)("unicorn", "unicorn", 7) == 0);
    cr_assert((*fcn)("bruh", "bruh", 4) == 0);
    cr_assert((*fcn)("test", "test", 4) == 0);
    cr_assert((*fcn)("hello world", "hello world", 11) == 0);
    cr_assert((*fcn)("i am a unicorn", "i am a unicorn", 14) == 0);
}

Test(__strncmp, __strncmp_2)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    int (*fcn)(const char *, const char *, size_t) = dlsym(ptr, "strncmp");
    cr_assert((*fcn)("", "", 0) == 0);
    cr_assert((*fcn)("", "", 1) == 0);
    cr_assert((*fcn)("\t", "\t", 1) == 0);
    cr_assert((*fcn)("\n", "\n", 1) == 0);
    cr_assert((*fcn)("\0", "\0", 1) == 0);
}

Test(__strncmp, __strncmp_3)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    int (*fcn)(const char *, const char *, size_t) = dlsym(ptr, "strncmp");
    cr_assert((*fcn)("this is a bruh", "this is a", 14) > 0 &&
        (int)strncmp("this is a bruh", "this is a", 14) > 0);
    cr_assert((*fcn)("this is a", "this is a bruh", 9) == 0 &&
        (int)strncmp("this is a", "this is a bruh", 9) == 0);
    cr_assert((*fcn)("this is a bruh", "this is a", 9) == 0 &&
        (int)strncmp("this is a bruh", "this is a", 9) == 0);
    cr_assert((*fcn)("this is a", "this is a bruh", 14) < 0 &&
        (int)strncmp("this is a", "this is a bruh", 14) < 0);
}

Test(__strncmp, __strncmp_4, .signal = SIGSEGV)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    int (*fcn)(const char *, const char *, size_t) = dlsym(ptr, "strncmp");
    cr_assert((*fcn)(NULL, NULL, 1));
}
