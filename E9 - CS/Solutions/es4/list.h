#ifndef LIST_H_
#define LIST_H_

#define LIST_SIZE sizeof(List)

struct list {
    int head;
    struct list *tail;
};

typedef struct list List;

List *list_cons(int head,List *tail);

List *list_nil(void);

int list_is_empty(List *l);

List *list_from_array(int a[],int size);

int list_length(List *l);

void list_append_to(List *l1,List *l2);

int list_search(List *l, int i);

List *list_get(List *l, int i);

char *list_to_string(List *l);

void apply_to_all(List *l, void f(int *));

#endif
