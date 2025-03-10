#ifndef APC_H
#define APC_H

typedef enum
{
    SUCCESS,
    FAILURE
}Status;

typedef struct dlist
{
    int data;
    struct dlist *next;
    struct dlist *prev;
}Dlist;

void print_list(Dlist *head);
Status create_list(Dlist **head,Dlist **tail,char *op);

#endif