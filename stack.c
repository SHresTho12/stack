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
#include<stdbool.h>

//node model of the linkedlist . Every node of the stack looks like this
struct linkedlist {
    int value;
    struct linkedlist *next;;
}stacknode;




/*
 Prototypes of all functions
 */

// checks if the stack is empty or not . Returns boo 0 or 1
bool empty(struct linkedlist *start);

// shows  how many nodes the stack has. returns the number of the nodes the stack has . Takes the pointer to the head or the first element odf the stack as parameter
int size(struct linkedlist *start);

//takes the starting node pointer as parameter and prints the value stored in the first node. Returns nothing.
void top(struct linkedlist *start); //

//takes two parameters one is the starting pointer of the stack and the new value you want to add. Adds a new node at the start of the stack and returns new starting pointer.
struct linkedlist *push(struct linkedlist *start,int n);

//Takes the starting node pointer as  parameter and deletes the first node. Then returns the new starting pointer
struct linkedlist *pop(struct linkedlist *start);

//Takes the starting node pointer as  parameter and goes throuh every node printing evry value of every node.
void trevarse(struct linkedlist *start);







int main(){
    
    char code; // to store the commands given by the user
    
    // First it shows the list of the commands and what they do to the user
    
    printf("================= The command List ================ \n \
           --> *Size related commands*\n \
           e = Checks if the stack is empty or not\n \
           s = Shows the size of the stack or the number of the nodes\n \
           --> **Accessing Commands** \n \
           f = Shows the value stored in the first node\n \
           t = traverses through the whole stack and prints values of the each \n \
           --> ***Modification commands***\n \
           p = Asks you to enter a value and adds the value in the front of the stack\n \
           d = Deletes the first element of the stack\n \
           q = Ending command\n");

    // Initializing the first node pointer. It will always point to the head of the stack
    struct linkedlist *first = NULL; //structure pointer to keep track of the begining of the stack
        for (;;)
        {
           
            
            printf("Insert the command TO modify the stack: \n"); //Asking users to Enter the command
            
            
            scanf(" %c", &code);     int value, empty_check, size_of_stack ;
            while (getchar() != '\n')   /* skips to end of line */
                ;
           
            
            switch (code) //checks the command . calls suitabble function
            {
                case 'e':
                    empty_check = empty(first); //calls empty function
                    
                    // checks if the functio returns 0 or 1
                    if(empty_check == 0) {
                        
                        printf("The stack is empty \n");
                        
                    }
                    else {
                        
                        printf("The stack is not empty \n");
                        
                    }
                    break;
                case 's':
                    size_of_stack = size(first); //calls size function
                    
                    if(size_of_stack != 0)
                    {
                        printf("The size of the stack or the number of the nodes in the list is %d \n",size_of_stack);
                    }
                    
                    break;
                  
                case 'f':
                    top(first); //calls top function
                    
                    break;
                    
                case 't': trevarse(first); //calls trevarse function
                    break;
                    
                case 'p':
                    printf("Enter the value of the new node: \n");
                    scanf("%d",&value); //takes input the value you want to add
                    first = push(first,value);
                    break;
                    
                case 'd':
                   first = pop(first); //calls pop function
                    break;
                    
                case 'q': return 0;
                
                default:  printf("Illegal code\n");
            }
            printf("\n");
        }
    
return 0;
    
}
/*
 ========== This function shows if the function is empty or not ============
 * The function takes the ponter to the first element as the parameter
 * If the first element is null then the function has no node
 * If the starting pointer is nuyll funtion returns 0
 * If the starting pointer is not null then the function retuns 1
---> 1 means  the funtion has 1 or more elements
 ---> 0 means the funtion has no nodes
 */
bool empty(struct linkedlist *start){
    if(start != NULL) return  1; // checks if the starting pointer is null or not if it is null if means there is no element in the stack
    else return 0;
}


/* ====== This function shows the size of the stack =====
 * returns the number of the nodes there are in the stack
 ** Takes the pointer to the d=first element as the parameter
 */
int size(struct linkedlist *start){
    // checks if the starting pointer is null or not if it is null if means there is no element in the stack. Shows the warning message
    if(start == NULL){
        printf("There is no element in the stack so the size is 0  \n");
        return 0;
    }
    //variable to store the the number of the nodes there are in the stack
    int number_of_nodes = 0;
    
    // loop for counting available nodes. Loops countinue untill it faces null
    for( ; start != NULL ;start = start->next) number_of_nodes++;
    
    return number_of_nodes; // returns the number of the nodes
        }


/*
 ==== Prints the first node value ====
 *Takes the pointer pointing to the first node of the stack as the parameter
 */
void top(struct linkedlist *start){
    //If the start pionter in null then the programm shows a warning this means theres no first node to show
    if(start == NULL) printf("Theres no first element the stack is empty. First enter some data.\n");
    
    else printf("The value stored in the first node is: %d \n",start -> value);
}

/*The push function. This function adds a new node at the starting of the stack
 *It has two parameters
 **--> one is the starting node pointer and
 **--> second is the value is to be added in the added node
 
 *function return type is a struct pointer
 * It actually updates the pointer holding the location for the head or the starting pointer of the linked list
 */
struct linkedlist *push(struct linkedlist *start,int n){
    struct linkedlist *newnode;
 
    newnode = malloc(sizeof(stacknode)); // Allocates memory for the new node to be added
    if (newnode==NULL){
                                  // Checks if the memory location allocated is valid or not if not shows an error message and exits the program
        printf("The allocated memory is invalid\n");
        exit(EXIT_FAILURE);
    }
    newnode -> next = start; // stores the start pointer as the new nodes next pointing pointer and makes previous first pointer 2nd
    newnode -> value = n;//stores the value in new node
    
    return newnode; //returns the new starting node pointer and modifies first or the head pointer
}

/*
 ======= DEletes the first node ====
 *Takes the pointer pointing to the first node of the stack as the parameter
 *return new  starting pointer
 */

struct linkedlist *pop(struct linkedlist *start)
{
    struct linkedlist *temp = start; //stores the starting pointer in another pointer
    //checks if the start pointer is null then it shows warning
    if(start == NULL) printf("The stack is empty nothing to pop. First enter some data then try to delete it \n");
    
    else start = start->next; //modifies the start pointer it makes 2nd node starting point
    free(temp);  //clears the deleted node memory
    return start; // return modified starting pointer
}


/*
 ===== Prints all values of the stack =====
 * Takes the pointer pointing to the first node of the stack as the parameter
 ** returns nothing
 */
void trevarse(struct linkedlist *start){
    // checks if the starting pointer is null
    if(start==NULL){
        printf("The stack is Empty Nothing to print"); // If the starting pointer is null then shows this warning message
        exit(EXIT_FAILURE);
    }
    int i = 1;
    for( ; start!=NULL; start = start->next ) //itirates through the stack to the end. When passing every node  it prints its value
    {
        printf("The value of the %d th node is %d \n", i ,start->value);
        i++;
    }
}
