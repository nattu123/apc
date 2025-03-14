#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIST1 1
#define LIST2 2
#define EQUAL 3

typedef enum
{
    SUCCESS,
    FAILURE,
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
Status substract(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);
int greater_list(Dlist *head1,Dlist *head2,char *argv1,char *argv2);
Status remove_leading_zeroes(Dlist **head,Dlist **tail);
int delete_list(Dlist**head,Dlist**tail);
Status multiply(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

#endif