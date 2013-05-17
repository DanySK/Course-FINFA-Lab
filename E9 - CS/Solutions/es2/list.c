#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

List *list_cons(int head,List *tail){
    List *l=(List *)malloc(LIST_SIZE);
    l->head=head;
    l->tail=tail;
    return l;
}

List *list_nil(void){
    return NULL;
}

int list_is_empty(List *l){
    return l==NULL;
}

List *list_from_array(int a[],int size){
    List *l=NULL;
    int i=size-1;
    for (;i>=0;i--) l=list_cons(a[i],l);
    return l;
}

int list_length(List *l){
    int sum=0;
    for (;!list_is_empty(l);l=l->tail,sum++);
    return sum;
}

void list_append_to(List *l1,List *l2){
    if (list_is_empty(l1)) return;
    for (;!list_is_empty(l1->tail);l1=l1->tail);
    l1->tail=l2;
}

int list_search(List *l, int i){
    if (list_is_empty(l)){
        return 0;
    }else if (l->head==i){
        return 1;
    }else{
        return list_search(l->tail,i);
    }
}

List *list_get(List *l, int i){
    if (list_is_empty(l)){
        return list_nil();
    }else if (l->head==i){
        return l;
    }else{
        return list_get(l->tail,i);
    }
}

char *list_to_string(List *l){
    char *c=malloc(10*list_length(l));
    sprintf(c,"(");
    if (!list_is_empty(l)) {
        char *d=malloc(20);
        sprintf(d,"%d",l->head);
        strcat(c,d);
        if (!list_is_empty(l->tail)) {
            for (l=l->tail;!list_is_empty(l);l=l->tail) {
                sprintf(d,",%d",l->head);
                strcat(c,d);
            }
        }
        free(d);
    }
    strcat(c,")");
    return c;
}

void free_list(List *l) {
    if(l != NULL) {
        free_list(l->tail);
        free(l);
    }
}

void list_cut_zero(List *l) {
    for(; l != NULL && l->head != 0; l = l->tail);
    if(l != NULL) {
        free_list(l->tail);
    }
    l->tail = list_nil();
}


