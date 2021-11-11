#include <dlfcn.h>
#include <stddef.h>

#include <stdio.h>
#include <stdlib.h>

//#define ELEMENT_COUNT 10

//size_t strcspn(const char *, const char *);
//char *strpbrk(const char *string1, const char *string2);
//char *strstr(const char *, const char *);
//char *rindex(const char *s, int c);
size_t strlen(const char *);

int main(int ac, char **av)
{
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    int (*fcn)(const char *) = dlsym(ptr, "strlen");

    printf("%d\n", strlen("123456789"));

    //const char *haystack = "TutorialsPbybybypo";
    //char *ret;

    //ret = strstr("truclol", "lol");

    //printf("The substring is: %s\n", ret);

    //ret = rindex(haystack, 'y');

    //printf("The substring is: %s\n", ret);

    //ret = rindex(haystack, '2');

    //printf("The substring is: %s\n", ret);
   
    /*const char s1[] = "Helloworld";
    const char s2[] = "Blank";
    const char s3[] = "2";

    char *result;
    result = strpbrk(s1, s2);
    printf("The matching character : %c\n", *result);
    result = strpbrk(s1, s3);
    if (result == NULL)
        printf("The matching character : null\n");
    else
        printf("The second matching character : %c\n", *result);
    return(0);*/

    //int len;
    //const char str1[] = "ABCDEF4960910";
    //const char str2[] = "013";

    //len = strcspn(str1, str2);

    //printf("First matched character is at %d\n", len + 1);
    //return (*fcn)(av[1]);
    /*const char src[50] = "tes une salope";
    char dest[50];
    strcpy(dest,"Heloooo!!");
    printf("Before memcpy dest = %s\n", dest);
    memcpy(dest, src, strlen(src)+1);
    printf("After memcpy dest = %s\n", dest);*/
    //int data[] = { 20, 30, 40, 50, 60, 70, 80, 90, 100, 0 };

    // On affiche le contenu de la collection
    //for( int i=0; i<ELEMENT_COUNT; i++ ) {
    //    printf( "%d ", data[i] );
    //}
    //puts( "" );  // Un retour à la ligne

    // On décale les éléménts dans la collection ...
    //void * source = (void *) data;
    //void * destination = (void *) ( data + 1 );
    //size_t size = ELEMENT_COUNT * sizeof( int );
    //memmove( destination, source, size );

    // ... pour y insérer une nouvelle valeur en tête
    //data[0] = 10;

    // On affiche le contenu de la collection
    //for( int i=0; i<ELEMENT_COUNT; i++ ) {
    //    printf( "%d ", data[i] );
    //}
    //puts( "" );  // Un retour à la ligne


    return(0);
}

/*
    void *ptr = dlopen("libasm.so", RTLD_LAZY);
    void *(*fcn)(void *, const void *, size_t) = dlsym(ptr, "memmove");

    char *str = calloc(10, '1');
    const char *str2 = "unicorn";

    dprintf(1, "%s\n", str);
    (*fcn)(str, str2, 5);
    dprintf(1, "%s\n", str);
    return 0;
*/
