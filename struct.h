#ifndef _STRUCT_H_
#define _STRUCT_H_

typedef struct __Node {
    struct __Node *next;
    int len;
    void *ptr;
} Node;

typedef struct {
    Node *head;
        //, *tail;
} List;

List *list_init ();
void insert_head (List*,void*,int);
int remove_ptr (List*, void*);
void chk_list (List*);

#endif

