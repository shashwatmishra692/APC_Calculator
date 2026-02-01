#ifndef HEADER_H
#define HEADER_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define SUCCESS 1
#define FAILURE 0
#define INVALID_OPERATION -1

typedef struct node{
    int data;
    struct node*prev;
    struct node*next;
}Dlist;

int validate(int argc,char*argv[]);
int insert_at_last(Dlist **head,Dlist **tail,int data);
int insert_at_first(Dlist**head,Dlist**tail,int data);
int delete_at_first(Dlist**head,Dlist**tail);
void store_list(Dlist **head,Dlist **tail,char*str);
void print_list(Dlist*head);
int addition(Dlist*tail1,Dlist*tail2,Dlist**head3,Dlist**tail3);
int check_largest(char*num1,char*num2);
void swap(Dlist**head1,Dlist**tail1,Dlist**head2,Dlist**tail2);
int subtraction(Dlist*tail1,Dlist*tail2,Dlist**head3,Dlist**tail3);
int remove_starting_zeros(Dlist**head3,Dlist**tail3);
int multiplication(Dlist*tail1,Dlist*tail2,Dlist**head3,Dlist**tail3);
void addzeros(Dlist**head,Dlist**tail,int count);
void delete_list(Dlist**head,Dlist**tail);
void copy_list(Dlist*src_head,Dlist*src_tail,Dlist**dest_head,Dlist**dest_tail);
int compare_list(Dlist*tail1,Dlist*tail2);
int total_nodes(Dlist*tail);
int division(Dlist**head1,Dlist**tail1,Dlist**head2,Dlist**tail2,Dlist**head3,Dlist**tail3);

#endif