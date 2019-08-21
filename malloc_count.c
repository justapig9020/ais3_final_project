#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <dlfcn.h>
#include "struct.h"

List *l;


void* my_malloc (size_t size)
{
    char buf[32];
    static void* (*real_malloc)(size_t) = NULL;

    if (real_malloc == NULL) {
        *(void**)(&real_malloc) = dlsym(RTLD_NEXT, "malloc");
    }

    //sprintf(buf, "my_malloc called, size = %zu\n", size);
    //write(2, buf, strlen(buf));
    return real_malloc(size);

}

void* malloc(size_t size)
{
    //printf ("malloc\n");
    //printf ("l addr: %x\n", l);
    char buf[50];
    void *ptr;
    static void* (*real_malloc)(size_t) = NULL;

    if (real_malloc == NULL) {
        *(void**)(&real_malloc) = dlsym(RTLD_NEXT, "malloc");
    }

    //printf ("hi!\n");
    //printf("malloc called, size = %zu\n", size);
    ptr = real_malloc(size);
    sprintf(buf, "malloc called, addr: %x ,size: %zu\n", ptr, size);
    write(1, buf, strlen(buf));
    if (l)
        insert_head (l, ptr, size);
    else
        write (1, "Null!\n", sizeof ("Null!\n"));
    return ptr;
}

void my_free (void *ptr)
{
    static void* (*real_free)(void* ptr) = NULL;
//    printf ("my_free\n");

    if (real_free == NULL) {
        *(void**)(&real_free) = dlsym(RTLD_NEXT, "free");
    }
    real_free(ptr);
}

void free(void* ptr)
{
    char buf[32];
    static void* (*real_free)(void* ptr) = NULL;

    if (real_free == NULL) {
        *(void**)(&real_free) = dlsym(RTLD_NEXT, "free");
    }
    
    //printf("free called, ptr address = %p\n", ptr);
    //sprintf(buf, "free called, ptr address = %p\n", ptr);
    //write(2, buf, strlen(buf));
    real_free(ptr);
    remove_ptr (l, ptr);
}

/*
void exit(int status)
{

}
*/

__attribute__ ((constructor)) void init_test () 
{
    l = list_init ();
    write (1, "==== test_start ====\n", 21);
}

__attribute__ ((destructor)) void final_chk () 
{
    chk_list (l);
    //puts ("==== test_end ====");
}








/*void test_init ()
{
    l = list_init ();
    printf ("test_start\n");
    printf ("l addr: %x\n", l);
}

List *test_end ()
{
    printf ("test_end\n");
    //return NULL;
    chk_list (l);
    return l;
}*/

