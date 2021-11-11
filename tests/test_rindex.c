/*
** EPITECH PROJECT, 2020
** minilibc
** File description:
** minilibc
*/

#include <criterion/criterion.h>
#include <strings.h>
#include <signal.h>
#include <dlfcn.h>
#include <stdio.h>

Test(__rindex, __rindex_1)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    char *(*fcn)(const char *, int) = dlsym(ptr, "rindex");

    if (dlerror() != NULL)
        printf("rindex 1 error dlopen\n");
    if (dlsym(ptr, "rindex") == NULL)
        printf("rindex 1 error dlsym\n");
    cr_assert((*fcn)("unicorn", 'u') == rindex("unicorn", 'u'));
    cr_assert((*fcn)("unicorn", 'n') == rindex("unicorn", 'n'));
    cr_assert((*fcn)("bruh", 'h') == rindex("bruh", 'h'));
    cr_assert((*fcn)("unicornunicorn", 'o') == rindex("unicornunicorn", 'o'));
    cr_assert((*fcn)("bruhbruh", 'r') == rindex("bruhbruh", 'r'));
}

Test(__rindex, __rindex_2)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    char *(*fcn)(const char *, int) = dlsym(ptr, "rindex");
    cr_assert((*fcn)("unicorn", '\0') == rindex("unicorn", '\0'));
    cr_assert((*fcn)("unicorn", 0) == rindex("unicorn", 0));
    cr_assert((*fcn)("    ", '\0') == rindex("    ", '\0'));
    cr_assert((*fcn)("    ", 0) == rindex("    ", 0));
}

Test(__rindex, __rindex_3)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    char *(*fcn)(const char *, int) = dlsym(ptr, "rindex");
    cr_assert((*fcn)("unicorn", 'b') == rindex("unicorn", 'b'));
    cr_assert((*fcn)("unicorn", 98) == rindex("unicorn", 98));
    cr_assert((*fcn)("bruh", 'c') == rindex("bruh", 'c'));
    cr_assert((*fcn)("bruh", 99) == rindex("bruh", 99));
}

Test(__rindex, __rindex_4, .signal = SIGSEGV)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    char *(*fcn)(const char *, int) = dlsym(ptr, "rindex");
    cr_assert((*fcn)(NULL, 0));
}
