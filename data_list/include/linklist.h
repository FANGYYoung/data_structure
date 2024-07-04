#ifndef _LINKLIST_H_
#define _LINKLIST_H_

typedef int data_t;

typedef struct node
{
    data_t data;
    struct node *next;
}listnode, *linklist;

linklist  linklist_create();
int linklist_tail_insert(linklist H, data_t data);
int linklist_show(linklist H);
linklist linklist_locate(linklist H, int pos);
int linklist_insert(linklist H, data_t data, int pos);
int linklist_delete(linklist H, int pos);
int linklist_free(linklist H);
int linklist_reverse(linklist H);
linklist list_adjmax(linklist H, data_t *sum);
int linklist_merge(linklist H1, linklist H2);


#endif