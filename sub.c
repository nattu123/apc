#include "apc.h"

Status substract(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR)
{
    int b = 0 ;
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    while(temp1 != NULL)
    {
        int num1 = temp1->data ,num2; 
        temp1 = temp1->prev ; 

        if(temp2 == NULL)
        {
            num2 = 0; 
        }
        else
        {
            num2 = temp2->data;
            temp2 = temp2->prev;
        }

        int sub = num1 - num2- b; 
        b = 0; 

        if(sub < 0)
        {
            sub = 10 + sub ; 
            b = 1 ;
        }
        if(dl_insert_first(headR,tailR,sub) == FAILURE)return FAILURE;
    }

    return SUCCESS;
}