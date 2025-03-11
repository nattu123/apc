#include "apc.h" 
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 

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

int greater_list(Dlist *head1,Dlist *head2,char *argv1,char *argv2)
{
    if(strlen(argv1) > strlen(argv2))   
    {
        printf("list1 greater\n");
        return LIST1;
    }
    if(strlen(argv2) > strlen(argv1))
    {
        printf("list2 greater\n");
        return LIST2;
    }
    if(strlen(argv1) == strlen(argv2))
    {
        printf("both lists  strlen are equal \n");
        Dlist *temp1 = head1;
        Dlist *temp2 = head2;
        while(temp1 != NULL  & temp2!= NULL)
        {
            if(temp1->data > temp2->data)
            {
                printf("inside while list1 greater\n");
                return LIST1;
            }
            if(temp2->data > temp1->data)
            {
                printf("inside while list2 greater\n");
                return LIST2;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        printf("both no.s are equal\n");
        return EQUAL;
    }
}

Status remove_leading_zeroes(Dlist **head,Dlist **tail)
{
    while((*head)->data == 0)
    {
        Dlist *temp = *head ;
        *head = (*head)->next;
        free(temp);
    }
}