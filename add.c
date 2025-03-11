#include "apc.h" 

Status add(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR)
{
    Dlist *temp1 = *tail1; 
    Dlist *temp2 = *tail2; 

    int carry =0;
    while(temp1!= NULL || temp2!=NULL || carry != 0)
    {
        int num1 , num2;

        if(temp1 == NULL && temp2 == NULL)
        {
            num1 = 0; 
            num2 =0;
        }
        else if(temp1 == NULL)
        {
            num1 = 0;
            num2 = temp2->data;
            temp2 = temp2->prev;
        } 
        else if(temp2 == NULL)
        {
            num2 = 0;
            num1 = temp1->data;
            temp1 = temp1->prev;
        }
        else
        {
            num1 =  temp1->data;
            num2 =  temp2->data;
            temp1 = temp1->prev;
            temp2 = temp2->prev;
        }
        
        int sum = num1 + num2 +carry ;
        int digit = sum%10;
        carry = sum/10;
        if(dl_insert_first(headR,tailR,digit)== FAILURE)
        {
            printf("element not inserted\n");
            return FAILURE;
        }
        
    }

    return SUCCESS;

}