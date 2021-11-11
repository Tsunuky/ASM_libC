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

Test(__strcmp, __strcmp_1)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    int (*fcn)(const char *, const char *) = dlsym(ptr, "strcmp");
    cr_assert((*fcn)("unicorn", "unicorn") == 0);
    cr_assert((*fcn)("bruh", "bruh") == 0);
    cr_assert((*fcn)("test", "test") == 0);
    cr_assert((*fcn)("hello world", "hello world") == 0);
    cr_assert((*fcn)("i am a unicorn", "i am a unicorn") == 0);
}

Test(__strcmp, __strcmp_2)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    int (*fcn)(const char *, const char *) = dlsym(ptr, "strcmp");
    cr_assert((*fcn)("", "") == 0);
    cr_assert((*fcn)("\t", "\t") == 0);
    cr_assert((*fcn)("\n", "\n") == 0);
    cr_assert((*fcn)("\0", "\0") == 0);
}

Test(__strcmp, __strcmp_3)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    int (*fcn)(const char *, const char *) = dlsym(ptr, "strcmp");
    cr_assert((*fcn)("this is a bruh", "this is a") > 0 &&
        (int)strcmp("this is a bruh", "this is a") > 0);
    cr_assert((*fcn)("this is a", "this is a bruh") < 0 &&
        (int)strcmp("this is a", "this is a bruh") < 0);
}

Test(__strcmp, __strcmp_4, .signal = SIGSEGV)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    int (*fcn)(const char *, const char *) = dlsym(ptr, "strcmp");
    cr_assert((*fcn)(NULL, NULL));
}
