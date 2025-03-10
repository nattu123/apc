#ifndef APC_H
#define APC_H

#include<stdio.h>

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
Status dl_insert_last(Dlist **head, Dlist **tail , int data);
Status dl_insert_first(Dlist **head,Dlist **tail,int data);
Status add(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

#endif