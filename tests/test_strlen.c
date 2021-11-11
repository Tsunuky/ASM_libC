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

Test(__strlen, __strlen_1)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    int (*fcn)(const char *) = dlsym(ptr, "strlen");
    cr_assert((*fcn)("unicorn") == (int)strlen("unicorn"));
    cr_assert((*fcn)("bruh") == (int)strlen("bruh"));
    cr_assert((*fcn)("test") == (int)strlen("test"));
}

Test(__strlen, __strlen_2)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    int (*fcn)(const char *) = dlsym(ptr, "strlen");
    cr_assert((*fcn)("") == (int)strlen(""));
    cr_assert((*fcn)("\t") ==  (int)strlen("\t"));
    cr_assert((*fcn)("\n") ==  (int)strlen("\n"));
    cr_assert((*fcn)("\0") == (int)strlen("\0"));
}

Test(__strlen, __strlen_3)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    int (*fcn)(const char *) = dlsym(ptr, "strlen");
    cr_assert((*fcn)("hello world") ==  (int)strlen("hello world"));
    cr_assert((*fcn)("i am a unicorn") ==  (int)strlen("i am a unicorn"));
}

Test(__strlen, __strlen_4, .signal = SIGSEGV)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    int (*fcn)(const char *) = dlsym(ptr, "strlen");
    cr_assert((*fcn)(NULL));
}
