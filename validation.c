#include "header.h"

int validate(int argc,char*argv[]){
    if(argc!=4){
        return FAILURE;
    }
    if(strlen(argv[2])!=1||(strchr("+-*/",argv[2][0])==NULL)){
        return FAILURE;
    }
    for(int i=1;i<=3;i+=2){
        for(int j=0;argv[i][j]!='\0';j++){
            if(!isdigit(argv[i][j])){
                return FAILURE;
            }
        }
    }
    return SUCCESS;
}
void store_list(Dlist **head,Dlist **tail,char*str){
    int i=0;
    while(str[i]!='\0'){
        if(isdigit(str[i])){
            int num=str[i]-'0';
            insert_at_last(head,tail,num);
        }
        i++;
    }
}
int insert_at_last(Dlist **head,Dlist **tail,int data){
    Dlist*new_node=(Dlist*)malloc(sizeof(Dlist));
    if(!new_node){
        printf("Memory Allocation Failed\n");
        return FAILURE;
    }
    new_node->data=data;
    new_node->next=NULL;
    new_node->prev=NULL;

    if(*head==NULL){
        *head=*tail=new_node;
    }
    else{
        new_node->prev=*tail;
        (*tail)->next=new_node;
        *tail=new_node;
    }
    return SUCCESS;
}
int insert_at_first(Dlist**head,Dlist**tail,int data){
    Dlist*new_node=(Dlist*)malloc(sizeof(Dlist));
    if(!new_node){
        printf("Memory Allocation Failed\n");
        return FAILURE;
    }
    new_node->data=data;
    new_node->prev=NULL;
    new_node->next=NULL;
    if(*head==NULL){
        *head=*tail=new_node;
    }
    else{
        new_node->next=*head;
        (*head)->prev=new_node;
        *head=new_node;
    }
    return SUCCESS;
}
int addition(Dlist*tail1,Dlist*tail2,Dlist**head3,Dlist**tail3){
    int num1,num2,sum,carry=0;
    while(tail1!=NULL || tail2!=NULL){
        num1=(tail1!=NULL) ? tail1->data:0;
        num2=(tail2!=NULL) ? tail2->data:0;
        sum=num1+num2+carry;
        carry=sum/10;
        if(insert_at_first(head3,tail3,sum%10)==FAILURE){
            printf("Failed to insert into result list\n");
            return FAILURE;
        }
        
        if(tail1) tail1=tail1->prev;
        if(tail2) tail2=tail2->prev;
    }
    if(carry!=0){
        if(insert_at_first(head3,tail3,carry)==FAILURE){
            printf("Failed to insert final carry\n");
            return FAILURE;
        }
    }
    return SUCCESS;
}
int check_largest(char*num1,char*num2){
    int len1=strlen(num1);
    int len2=strlen(num2);

    if(len2 > len1){
        return SUCCESS;
    }
    else if(len1 > len2){
        return INVALID_OPERATION;
    }
    else{
        if(strcmp(num1,num2)>0)
            return INVALID_OPERATION;
        else if(strcmp(num1,num2)<0)
            return SUCCESS;
        else
            return FAILURE;
    }
}
void swap(Dlist**head1,Dlist**tail1,Dlist**head2,Dlist**tail2){
    
    Dlist*temp_head=*head1;
    Dlist*temp_tail=*tail1;

    //Swap Head pointers
    *head1=*head2;
    *tail1=*tail2;

    *head2=temp_head;
    *tail2=temp_tail;
}
int subtraction(Dlist*tail1,Dlist*tail2,Dlist**head3,Dlist**tail3){
    int num1,num2,borrow=0;
    while(tail1!=NULL || tail2!=NULL){
        num1=(tail1!=NULL) ? tail1->data:0;
        num2=(tail2!=NULL) ? tail2->data:0;
        
        num1-=borrow;
        
       if(num1<num2){
            num1+=10;
            borrow=1;
        }
        else{
            borrow=0;
        }
        insert_at_first(head3,tail3,num1-num2);

        if(tail1) tail1=tail1->prev;
        if(tail2) tail2=tail2->prev;
    }
    return SUCCESS;
}
int remove_starting_zeros(Dlist**head,Dlist**tail){
    while(*head!=*tail && (*head)->data==0){
        delete_at_first(head,tail);
    }
    return SUCCESS;
}
int delete_at_first(Dlist**head,Dlist**tail){
    if(*head==NULL)
        return FAILURE;
    Dlist*temp=*head;
    if(*head==*tail){
        *head=*tail=NULL;
    }else{
        *head=(*head)->next;
        (*head)->prev=NULL;
    }
    free(temp);
    return SUCCESS;
}
int multiplication(Dlist*tail1,Dlist*tail2,Dlist**head3,Dlist**tail3){
    Dlist*t2=tail2, *t1;
    Dlist*res1h=NULL, *res1t=NULL;
    Dlist*res2h=NULL, *res2t=NULL;
    int carry=0, res, count=0;

    while(t2!=NULL){
        t1=tail1;
        carry=0;
        res1h=res1t=NULL;
        while(t1!=NULL){
            res=t1->data * t2->data + carry;
            carry=res/10;
            insert_at_first(&res1h,&res1t,res % 10);
            t1=t1->prev;
        }
        if(carry!=0){
            insert_at_first(&res1h,&res1t,carry);
        }
        addzeros(&res1h,&res1t,count);

        Dlist*temp_h=NULL, *temp_t=NULL;
        addition(res2t,res1t,&temp_h,&temp_t);

        delete_list(&res2h,&res2t);
        res2h=res2t=NULL;

        copy_list(temp_h,temp_t,&res2h,&res2t);

        delete_list(&temp_h,&temp_t);

        delete_list(&res1h,&res1t);
        res1h=res1t=NULL;

        count++;
        t2=t2->prev;
    }
    copy_list(res2h,res2t,head3,tail3);
    delete_list(&res2h,&res2t);
    return SUCCESS;
}
void addzeros(Dlist**head,Dlist**tail,int count){
    for(int i=0;i<count;i++){
        insert_at_last(head,tail,0);
    }
}
void delete_list(Dlist**head,Dlist**tail){
    Dlist*temp;
    while(*head!=NULL){
        temp=*head;
        *head=(*head)->next;
        free(temp);
    }
    *tail=NULL;
}
void copy_list(Dlist*src_head,Dlist*src_tail,Dlist**dest_head,Dlist**dest_tail){
    *dest_head=*dest_tail=NULL;
    while(src_head!=NULL){
        Dlist*new_node=(Dlist*)malloc(sizeof(Dlist));
        new_node->data=src_head->data;
        new_node->next=NULL;
        new_node->prev=*dest_tail;

        if(*dest_tail!=NULL){
            (*dest_tail)->next=new_node;
        }else{
            *dest_head=new_node;
        }
        *dest_tail=new_node;
        src_head=src_head->next;
    }
}
void print_list(Dlist*head){
    if(head==NULL){
        printf("0");
        return;
    }
    printf("head <-> ");
    while (head!=NULL){
        printf("%d ",head->data);
        printf("<->");
        head=head->next;
    }
    printf("tail");
}
int compare_list(Dlist*tail1,Dlist*tail2){
    int len1=total_nodes(tail1);
    int len2=total_nodes(tail2);

    if(len1<len2)
        return INVALID_OPERATION;
    
    else if (len1>len2)
        return SUCCESS;
    
    else{
        Dlist*temp1=tail1, *temp2=tail2;
        while(temp1 && temp1->prev)
            temp1=temp1->prev;
        while(temp2 && temp2->prev)
            temp2=temp2->prev;

        while(temp1!=NULL && temp2!=NULL){
            if(temp1->data < temp2->data)
                return FAILURE;
            else if(temp1->data > temp2->data)
                return SUCCESS;

            temp1=temp1->next;
            temp2=temp2->next;
        }
        return FAILURE;
    }
}
int total_nodes(Dlist*tail){
    int count=0;

    //Move to head
    while (tail && tail->prev!=NULL)
        tail=tail->prev;
    
    //Count nodes from head to tail
    while(tail!=NULL){
        count++;
        tail=tail->next;
    }
    return count;
}
int division(Dlist**head1,Dlist**tail1,Dlist**head2,Dlist**tail2,Dlist**head3,Dlist**tail3){
    int count=0;
    Dlist*temp_head=NULL,*temp_tail=NULL;
    if(compare_list(*tail1,*tail2)<0){
        insert_at_last(head3,tail3,0);
        return SUCCESS;
    }
    while(compare_list(*tail1,*tail2)>=0){
        temp_head=temp_tail=NULL;
        
        //head1=head1-head2
        subtraction(*tail1,*tail2,&temp_head,&temp_tail);

        //Delete the old dividend
        delete_list(head1,tail1);
        *head1=temp_head;
        *tail1=temp_tail;

        count++;
    }
    if(count==0)
        insert_at_last(head3,tail3,0);
    else{
        //Convert count into digits and store
        char str[20];
        sprintf(str,"%d",count);
        for(int i=0;str[i]!='\0';i++){
            insert_at_last(head3,tail3,str[i]-'0');
        }
    }
    return SUCCESS;
}