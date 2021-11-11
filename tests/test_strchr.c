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

Test(__strchr, __strchr_1)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    char *(*fcn)(const char *, int) = dlsym(ptr, "strchr");
    cr_assert((*fcn)("unicorn", 'u') == strchr("unicorn", 'u'));
    cr_assert((*fcn)("unicorn", 'n') == strchr("unicorn", 'n'));
    cr_assert((*fcn)("bruh", 'h') == strchr("bruh", 'h'));
    cr_assert((*fcn)("bruh", 'r') == strchr("bruh", 'r'));
}

Test(__strchr, __strchr_2)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    char *(*fcn)(const char *, int) = dlsym(ptr, "strchr");
    cr_assert((*fcn)("unicorn", '\0') == strchr("unicorn", '\0'));
    cr_assert((*fcn)("unicorn", 0) == strchr("unicorn", 0));
    cr_assert((*fcn)("    ", '\0') == strchr("    ", '\0'));
    cr_assert((*fcn)("    ", 0) == strchr("    ", 0));
}

Test(__strchr, __strchr_3)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    char *(*fcn)(const char *, int) = dlsym(ptr, "strchr");
    cr_assert((*fcn)("unicorn", 'b') == strchr("unicorn", 'b'));
    cr_assert((*fcn)("unicorn", 98) == strchr("unicorn", 98));
    cr_assert((*fcn)("bruh", 'c') == strchr("bruh", 'c'));
    cr_assert((*fcn)("bruh", 99) == strchr("bruh", 99));
}

Test(__strchr, __strchr_4, .signal = SIGSEGV)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    char *(*fcn)(const char *, int) = dlsym(ptr, "strchr");
    cr_assert((*fcn)(NULL, 0));
}
