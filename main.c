#include "header.h"
int main(int argc,char*argv[]){
    Dlist*head1=NULL, *tail1=NULL;
    Dlist*head2=NULL, *tail2=NULL;
    Dlist*head3=NULL, *tail3=NULL;
    int retvalue,sign=0;
    int ret=validate(argc,argv);
    if(ret==FAILURE){
        printf("Invalid arguments. Usage ./a.out <num1> <operator> <num2>\n");
        return FAILURE;
    }
    store_list(&head1,&tail1,argv[1]);
    store_list(&head2,&tail2,argv[3]);
    switch(argv[2][0]){
        case '+':
            addition(tail1,tail2,&head3,&tail3);
            print_list(head3);
            break;

        case '-':
            retvalue=check_largest(argv[1],argv[3]);
                if(retvalue>0){
                    swap(&head1,&tail1,&head2,&tail2);
                    sign=1;
                }
                subtraction(tail1,tail2,&head3,&tail3);
                remove_starting_zeros(&head3,&tail3);
                if(sign==1){
                    printf("-");
                }
                print_list(head3);
            break;

        case 'X':
                multiplication(tail1,tail2,&head3,&tail3);
                print_list(head3);
                break;

        case '/': 
            int num_zero=0;
            int num_one=1;
            if(check_largest(argv[1],argv[3])<0){
                printf("%d",num_zero);
            }
            else if(check_largest(argv[1],argv[3])==0){
                printf("%d",num_one);
            }
            else{
                division(&head1,&tail1,&head2,&tail2,&head3,&tail3);
                print_list(head3);
                break;
            }
        default:
            printf("Invalid Operator: Use + - X /");
            return SUCCESS;
        }
        return FAILURE;
}