#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "struct.h"
#include "my_test.h"

static void print_mem (void *p, int n)
{
    printf ("addr: %x, size: %d\n", (uintptr_t)p, n);
    /*for (int i=0; i<n; i++) {
        if (i%8 == 0)
            printf ("\n0x");
        printf ("%x", *(((char*)p)+i)&0xff);
    }*/
    puts (" ");
}

List *list_init ()
{
    List *l;
    l = my_malloc (sizeof (List));
    l->head = NULL;
    return l;
}

static Node *init_node (void *p, int n)
{
    Node *no;
//    write (1, "init_node\n", sizeof ("init_node\n"));
    no = my_malloc (sizeof (Node));
//    write (1, "init_node\n", sizeof ("init_node\n"));
    no->ptr = p;
    no->len = n;
    no->next = NULL;
    return no;
}

void insert_head (List *l, void *p, int n)
{
    //printf ("insert_head addr: %x, len: %d\n", p, n);
//    write (1, "insert_head\n", sizeof ("insert_head\n"));
    Node *buf, *nn;
    buf = l->head;
//    write (1, "insert_head\n", sizeof ("insert_head\n"));
    nn = init_node (p, n);
//    write (1, "insert_head\n", sizeof ("insert_head\n"));
    l->head = nn;
//    write (1, "insert_head\n", sizeof ("insert_head\n"));
    nn->next = buf;
    //print_mem (p, n);
}


int remove_ptr (List *l, void *p)
{
    chk_list (l);
    Node **ptr,*buf;
    ptr = &(l->head);
    while (*ptr) {
        if ((*ptr)->ptr == p) {
            printf ("\nfree called, addr: %x, size: %d\n\n", (*ptr)->ptr, (*ptr)->len);
           // print_mem (p, (*ptr)->len);
           // buf = *ptr;
            *ptr = (*ptr)->next;
            //my_free (buf->ptr);
            //buf->ptr = NULL;
            //p = NULL;
           // my_free (buf);
           // buf = NULL;
            //chk_list (l);
            return 1;
        }
        ptr = &((*ptr)->next);
    }
    return 0;
}

void chk_list (List *l)
{
    printf ("==== start check ====\n");
    Node *ptr;
    ptr = l->head;
    while (ptr) {
        printf ("Unfree memory: \n");
        print_mem (ptr->ptr, ptr->len);
        ptr = ptr->next;
    }
}
