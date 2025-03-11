#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "apc.h"

Status check_if_number(char *argv)
{
    for(int i=0 ; argv[i]!='\0'; i++)
    {
        if(!isdigit(argv[i])) return FAILURE;
    }
    return SUCCESS;
}


int main(int argc,char **argv)
{
    if(argc != 4)
    {
        fprintf(stderr,"please enter 4 arguments \n");
        return FAILURE;
    }
    else if((argv[2][0]=='x'|| argv[2][0]=='+'||argv[2][0]=='-'||argv[2][0]=='/') && strlen(argv[2])==1 )
    {
        if(check_if_number(argv[1])== SUCCESS && check_if_number(argv[3]) == SUCCESS)
        {
            printf("Number verified\n");
        } 
        else
        {
            fprintf(stderr,"Enter a valid number\n");
            
        }
    }
    else
    {
        fprintf(stderr,"choose a valid operand \n");
        return FAILURE;
    }
    
    // head and tail intitialsed to NULL 
    Dlist *head1,*tail1,*head2,*tail2,*headR,*tailR; 
    head1 = tail1 = head2 = tail2 = tailR = headR = NULL;
    
    if(create_list(&head1,&tail1,argv[1])==FAILURE)
    {
        printf("list not created \n");
        return FAILURE ;
    }
    if(create_list(&head2,&tail2,argv[3])==FAILURE)
    {
        printf("list not created \n");
        return FAILURE;
    }
    print_list(head1);
    print_list(head2);

    switch(argv[2][0])  
    {
        case '+':
                printf("add\n");
                add(&head1,&tail1,&head2,&tail2,&headR,&tailR);
                print_list(headR);
                break;
        case '-':
                printf("sub\n");
                int greater = greater_list(head1,head2,argv[1],argv[3]);
                if(greater == EQUAL)
                {
                    dl_insert_first(&headR,&tailR,0);
                }
                if(greater == LIST1)
                {
                    substract(&head1,&tail1,&head2,&tail2,&headR,&tailR);
                    remove_leading_zeroes(&headR,&tailR);
                }
                if(greater == LIST2)
                {
                    substract(&head2,&tail2,&head1,&tail1,&headR,&tailR);
                    remove_leading_zeroes(&headR,&tailR);
                    headR->data *= -1;
                }
                print_list(headR);
                break;
        default : 
            break;
    }

}   