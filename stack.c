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

//node model of the linkdlist . Every node of the stack looks like this
struct linkdlist {
    int value;
    struct linkdlist *next;;
}stacknode;




/*
 Prototypes of all functions
 */
struct linkdlist *push(struct linkdlist *start); //



int main(){
    
    char code;
//    struct linkdlist *stack; // Initializing the first node pointer
    struct linkdlist *first = NULL; //structure pointer to keep track of the begining of the stack
        for (;;)
        {
           printf("Insert the command TO modify the stack: \n"); //Asking users to Enter the command
            scanf("%c", &code);
            while (getchar() != '\n')   /* skips to end of line */
                ;
            switch (code)
            {
//                case 'i': insert();
//                break;
//                case 's': search();
//                break;
                case 't': ;
                break;
                case 'p': first = push(first);
                break;
                case 'q': return 0;
                default:  printf("Illegal code\n");
            }
            printf("\n");
        }
    

    
}
//the push function. This function adds a new node at the starting of the stack
struct linkdlist *push(struct linkdlist *start){
    struct linkdlist *newnode;
    int n;
    newnode = malloc(sizeof(stacknode));
    if ( {
        <#statements#>
    }
    newnode -> next = start;
    printf("Enter the value of the new node: /n");
    scanf("%d",&n);
    newnode -> value = n;
    return newnode;
}
