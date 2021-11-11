/*
** EPITECH PROJECT, 2020
** minilibc
** File description:
** minilibc
*/

#include <criterion/criterion.h>
#include <string.h>
#include <strings.h>
#include <signal.h>
#include <dlfcn.h>

Test(__strcasecmp, __strcasecmp_1)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    int (*fcn)(const char *, const char *) = dlsym(ptr, "strcasecmp");
    cr_assert((*fcn)("unicorn", "unicorn") == 0);
    cr_assert((*fcn)("bruh", "bruh") == 0);
    cr_assert((*fcn)("test", "test") == 0);
    cr_assert((*fcn)("hello world", "hello world") == 0);
    cr_assert((*fcn)("i am a unicorn", "i am a unicorn") == 0);
    cr_assert((*fcn)("UNICORN", "UNICORN") == 0);
    cr_assert((*fcn)("BRUH", "BRUH") == 0);
    cr_assert((*fcn)("TEST", "TEST") == 0);
    cr_assert((*fcn)("HELLO WORLD", "HELLO WORLD") == 0);
    cr_assert((*fcn)("I AM A UNICORN", "I AM A UNICORN") == 0);
    cr_assert((*fcn)("unicorn", "UNICORN") == 0);
    cr_assert((*fcn)("bruh", "BRUH") == 0);
    cr_assert((*fcn)("test", "TEST") == 0);
    cr_assert((*fcn)("hello world", "HELLO WORLD") == 0);
    cr_assert((*fcn)("i am a unicorn", "I AM A UNICORN") == 0);
    cr_assert((*fcn)("UNICORN", "unicorn") == 0);
    cr_assert((*fcn)("BRUH", "bruh") == 0);
    cr_assert((*fcn)("TEST", "test") == 0);
    cr_assert((*fcn)("HELLO WORLD", "hello world") == 0);
    cr_assert((*fcn)("I AM A UNICORN", "i am a unicorn") == 0);
}

Test(__strcasecmp, __strcasecmp_2)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    int (*fcn)(const char *, const char *) = dlsym(ptr, "strcasecmp");
    cr_assert((*fcn)("", "") == 0);
    cr_assert((*fcn)("\t", "\t") == 0);
    cr_assert((*fcn)("\n", "\n") == 0);
    cr_assert((*fcn)("\0", "\0") == 0);
}

Test(__strcasecmp, __strcasecmp_3)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    int (*fcn)(const char *, const char *) = dlsym(ptr, "strcasecmp");
    cr_assert((*fcn)("this is a bruh", "this is a") > 0 &&
        (int)strcasecmp("this is a bruh", "this is a") > 0);
    cr_assert((*fcn)("this is a", "this is a bruh") < 0 &&
        (int)strcasecmp("this is a", "this is a bruh") < 0);
    cr_assert((*fcn)("THIS IS A BRUH", "THIS IS A") > 0 &&
        (int)strcasecmp("THIS IS A BRUH", "THIS IS A") > 0);
    cr_assert((*fcn)("THIS IS A", "THIS IS A BRUH") < 0 &&
        (int)strcasecmp("THIS IS A", "THIS IS A BRUH") < 0);
}

Test(__strcasecmp, __strcasecmp_4, .signal = SIGSEGV)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    int (*fcn)(const char *, const char *) = dlsym(ptr, "strcasecmp");
    cr_assert((*fcn)(NULL, NULL));
}
