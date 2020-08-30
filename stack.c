//
//  main.c
//  examCse
//
//  Created by TAlimul BAri SHresTho on 8/25/20.
//  Copyright © 2020 SHresTho. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//node model of the linkedlist . Every node of the stack looks like this
struct linkedlist {
    int value;
    struct linkedlist *next;;
}stacknode;




/*
 Prototypes of all functions
 */
struct linkedlist *push(struct linkedlist *start,int n); //

void traverse(struct linkedlist *start);


int main(){
    
    char code;
//    struct linkedlist *stack; // Initializing the first node pointer
    struct linkedlist *first = NULL; //structure pointer to keep track of the begining of the stack
        for (;;)
        {
           printf("Insert the command TO modify the stack: \n"); //Asking users to Enter the command
            scanf(" %c", &code);     int n;
            switch (code)
            {
//                case 'i': insert();
//                break;
//                case 's': search();
//                break;
                case 't': traverse(first);
                break;
                case 'p':
               
                    printf("Enter the value of the new node: \n");
                       scanf("%d",&n);
                    first = push(first,n);
                    
                break;
                case 'q': return 0;
                default:  printf("Illegal code\n");
            }
            printf("\n");
        }
    

    
}
//the push function. This function adds a new node at the starting of the stack
struct linkedlist *push(struct linkedlist *start,int n){
    struct linkedlist *newnode;
 
    newnode = malloc(sizeof(stacknode));
    if (newnode==NULL){
        printf("The allocated memory is invalid\n");
        exit(EXIT_FAILURE);
    }
    newnode -> next = start;
    newnode -> value = n;
    return newnode;
}


void traverse(struct linkedlist *start){
    if(start==NULL){
        printf("The stack is Empty Nothing to print");
        
    }
    int i = 1;
    for( ; start!=NULL; start = start->next )
    {
        printf("The value of the %d th node is: %d \n", i ,start->value);
        i++;
    }
}