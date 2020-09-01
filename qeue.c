//
//  @file main.c
//  examCse
//
//  @author TAlimul BAri SHresTho on 8/25/20.
//  Copyright © 2020 SHresTho. All rights reserved.
//

#include <stdio.h>

#include <ctype.h>

#include <stdlib.h>

#include <string.h>

#include <stdbool.h>

//node model of the linkedlist . Every node of the qeue looks like this
struct linkedlist {
    int value;
    struct linkedlist * next;
};

typedef struct linkedlist Queue;

/*
 Prototypes of all functions
 */

/*
 *checks if theres any element or node in the queue
 *@param pointer to the head or the starting node of the queue
 *@returns boll value 1 or 0 . 1 means queue is not empty and 0 means it has no nodes or value
 */
bool empty(Queue * queue);


 /**
  **This function shows the size of the queue or the number of the nodes available in the queue
  **
  *@param queue the  pointer to the head of the queue
  *
  *@return This function returns the int value the number of the the nodes available in the queue
  */
int size(Queue * queue);

/***Prints the top or the value of the starting node of the queue
 *@param queue the  pointer to the head of the queue
 *
 *@see its a void function it prints the frirst node value
 */
void top(Queue * queue); //



/**
  * Enqueues a new value into the given queue
  *
  * @param queueRef Pointer to Pointer to Head of the Queue
  * @param n the value to be enqueued
  *
  * @see returns nothing
  */
void push(Queue ** queueRef, int n);

/*
 *DEqueues a value from the queue and updates the pointyer pointing to the head pf the queue
 *
 *@prama pointer to the head of the queue
 
 *@see returntype is a pointer to struct node
 
 */
Queue * pop(Queue * queue);


/**
  *Prints all values sequentially iof the queue
  *@parma pointer to the head of the queue
 
  *returns void .
 */


void trevarse(Queue * queue);


/*
 *Prints all the command needed
 
 ** void function ,no parameter needed
 */
void printHelp(void);


/**
  *Frees up all memory
  *@param queue Pointer to the Head of the Queue
  * Void return type
 */
void del(Queue *queue) {
    if(queue != NULL) {
    Queue *curr = queue, *next = queue->next;
    while (curr) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    }
}


int main() {
// to store the commands given by the user
    char code;

  

    // Initializing the queue node pointer. It will always point to the head of the queue
    Queue *queue = NULL;
    printHelp();
    for (;;) {

        //Asking users to Enter the command
        printf("Insert the command TO modify the qeue: \n");

        scanf(" %c", & code);
        
        int value, empty_check, size_of_queue;
        
        while (getchar() != '\n') /* skips to end of line */
        ; // Empty Body

        switch (code) { //checks the command . calls suitable function
        case 'e':
            empty_check = empty(queue); //calls empty function

            // checks if the function returns 0 or 1
            if (empty_check == 0) {

                printf("The qeue is empty \n");

            } else {

                printf("The qeue is not empty \n");

            }
            break;
        case 's':
            size_of_queue = size(queue); //calls size function

            if (size_of_queue != 0) {
                printf("The size of the qeue or the number of the nodes in the list is %d \n", size_of_queue);
            }

            break;

        case 'f':
            top(queue); //calls top function

            break;

        case 't':
            trevarse(queue); //calls trevarse function
            break;

        case 'p':
            printf("Enter the value of the new node: \n");
            scanf("%d", & value); //takes input the value you want to add
            push(&queue, value);
            break;

        case 'd':
            queue = pop(queue); //calls pop function
            break;

        case 'q':
            del(queue);
            return 0;
        case 'h':
            printHelp();
                break;
        default:
            printf("Illegal code\n");
        }
        printf("\n");
    }

    return 0;

}


///<======================================= Status Checking functions ========================================>
/*
 ========== This function shows if the function is empty or not ============

  --> 1 means  the function has 1 or more elements
 ---> 0 means the function has no nodes
 */
bool empty(Queue * queue) {
   
    // checks if the starting pointer is null or not if it is null if means there is no element in the qeue
    
    if (queue != NULL) return 1;
    else return 0;
}

/* ====== This function shows the size of the qeue =====
 * returns the number of the nodes there are in the qeue
 ** Takes the pointer to the d=queue element as the parameter
 */
int size(Queue * queue) {
    // checks if the starting pointer is null or not if it is null if means there is no element in the qeue. Shows the warning message
    if (queue == NULL) {
        printf("There is no element in the qeue so the size is 0  \n");
        return 0;
    }
    //variable to store the the number of the nodes there are in the qeue
    int number_of_nodes = 0;

    // loop for counting available nodes. Loops continues until it faces null
    for (; queue != NULL; queue = queue -> next) number_of_nodes++;

    return number_of_nodes; // returns the number of the nodes
}




//=========================================== Modification Functions=======================================
/**
******************** Enqueue Function  *************
*/
void push(Queue ** queue, int n) {
    Queue * newnode, * rear;

    rear = *queue;

    newnode = malloc(sizeof(Queue)); // Allocates memory for the new node to be added
    if (newnode == NULL) {
// Checks if the memory location allocated is valid or not if not shows an error message and exits the program
        printf("The allocated memory is invalid\n");
        exit(EXIT_FAILURE);
    }
    newnode -> value = n;

    // Initially new node does not point anything
    newnode -> next = NULL;
    for (; rear != NULL && rear -> next != NULL; rear = rear -> next);//Empty body

    if (rear != NULL) {
        rear -> next = newnode;
    }

    // Make sure newly created node is at rear
  rear = newnode;

    // Link queue node to front if its NULL
    if (*queue == NULL) {
        *queue = rear;
    }

}


/**
 ******************** DEqueue Function  *************
 */
Queue * pop(Queue * queue) {
    //stores the starting pointer in another pointer
    Queue * temp = queue;
    //checks if the start pointer is null then it shows warning
    if (queue == NULL) printf("The qeue is empty nothing to pop. queue enter some data then try to delete it \n");

    else queue = queue -> next; //modifies the start pointer it makes 2nd node starting point
    free(temp); //clears the deleted node memory
    return queue; // return modified starting pointer
}



//======================================== Accessing Function ============================================
/*
 ===== Prints all values of the qeue =====
 * Takes the pointer pointing to the queue node of the qeue as the parameter
 ** returns nothing
 */
void trevarse(Queue * queue) {
    // checks if the starting pointer is null
    if (queue == NULL) {
        // If the starting pointer is null then shows this warning message
        printf("The qeue is Empty Nothing to print");
        
    }
    else {
        int i = 1;
        //itirates through the qeue to the end. When passing every node  it prints its value
        for (; queue != NULL; queue = queue -> next)
        {
            printf("The value of the %d th node is %d \n", i, queue -> value);
            i++;
        }
    }
}


/*
 ==== Prints the queue node value ====
 *Takes the pointer pointing to the queue node of the qeue as the parameter
 */

void top(Queue * queue) {
    //If the start pionter in null then the program shows a warning this means theres no queue node to show
    if (queue == NULL) printf("Theres no queue element.  The qeue is empty. Frist enter some data.\n");

    else printf("The value stored in the queue node is: %d \n", queue -> value);
}

///<============================== Help Function =====================================>

void printHelp() {
    printf("================= The command List ================ \n \
           --> *Size related commands*\n \
           e = Checks if the qeue is empty or not\n \
           s = Shows the size of the qeue or the number of the nodes\n \
           --> **Accessing Commands** \n \
           f = Shows the value stored in the queue node\n \
           t = traverses through the whole qeue and prints values of the each \n \
           --> ***Modification commands***\n \
           p = Asks you to enter a value and adds the value in the front of the qeue\n \
           d = Deletes the queue element of the qeue\n \
           q = Ending command\n \
           h = help\n");
}
