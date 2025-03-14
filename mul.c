#include "apc.h"

Status multiply(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR)
{
    Dlist *res1h = NULL;
    Dlist *res1t = NULL;
    Dlist *res2h = NULL;
    Dlist *res2t = NULL;
    Dlist *res3h = NULL;
    Dlist *res3t = NULL;
    
    dl_insert_first(&res2h,&res2t,0);
    int count = 0;
    
    Dlist *temp2 = *tail2;  
    while(temp2 != NULL)
    {
        Dlist *temp1 = *tail1;
        int carry = 0 ;
        while(temp1 != NULL)
        {
            int num = (temp2->data*temp1->data) + carry;
            carry = num/10;
            num = num % 10 ;
            dl_insert_first(&res1h,&res1t,num);
            temp1 = temp1->prev;
        }
        if(carry)
        {
            dl_insert_first(&res1h,&res1t,carry);
            carry = 0;
        }

        add(&res1h,&res1t,&res2h,&res2t,&res3h,&res3t);
        temp2 = temp2->prev;
        count++;
        temp1 = *tail1;
        
        if(temp2 == NULL)
        {
            *headR = res3h;
            *tailR = res3t;
            break;
        }
        else
        {
            res2h = res3h;
            res2t = res3t;
            res3t = res3h = NULL;
            delete_list(&res1h,&res1t);
            for(int i=0;i<count;i++)
            {
                dl_insert_first(&res1h,&res1t,0);
            }
        }

    }
}