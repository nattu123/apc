#include "apc.h" 
#include <stdlib.h> 
#include <stdio.h> 

void print_list(Dlist *head)
{
    if(head == NULL)
    {
        printf("list is empty \n"); 
    }
    else 
    {
        while(head)
        {
            printf("%d",head->data);
            head = head->next ;
        }
        printf("\n");
    }
}


Status dl_insert_first(Dlist **head,Dlist **tail,int data)
{
    //Alllocate memory for new node 
    Dlist *new_node = malloc(sizeof(Dlist));

    //check if memory is allocated or not 
    if(new_node == NULL)
    {
        fprintf(stderr,"Node not created \n");
        return FAILURE ;
    }
    new_node->data = data;
    new_node->prev = NULL; 
    new_node->next = NULL; 
    
    // if empty insert first node 
    if(*head == NULL && *tail == NULL)
    {
        *head = *tail =new_node ;
        return SUCCESS;
    }
    
    new_node->next = *head; 
    (*head)->prev = new_node;
    *head = new_node;
    return SUCCESS; 
    
}


Status dl_insert_last(Dlist **head, Dlist **tail , int data)
{
    //allocate memory  
    Dlist *new_node = malloc(sizeof(Dlist));
    
    // check if noode is created 
    if(new_node == NULL)
    {
        fprintf(stderr,"Node not created \n");
        return FAILURE ;
    }
    new_node->data = data;
    new_node->prev = NULL; 
    new_node->next = NULL; 
    
    //if list empty 
    if(*head == NULL && *tail ==NULL )
    {
        *head = *tail = new_node; 
        return SUCCESS;
    }
    new_node->prev = *tail;
    (*tail)->next = new_node; 
    *tail = new_node ;
    return SUCCESS;

}

Status create_list(Dlist **head,Dlist **tail,char *operand)
{            
    while(*operand)
    {
        // printf(" fafasfas\n");    
        if(dl_insert_last(head,tail,*operand++-'0')== FAILURE)
        {
            fprintf(stderr,"insertionn failed \n");
            return FAILURE;
        }

    }
    return SUCCESS;
}