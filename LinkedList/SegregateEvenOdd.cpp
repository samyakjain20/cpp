// CPP program to segregate even and odd nodes in a Linked List
#include <stdio.h>
#include <stdlib.h>

/* a node of the singly linked list */
struct Node{
	int data;
	struct Node *next;
};

// Function to segregate even and odd nodes.
void segregateEvenOdd(struct Node **head_ref){
    if(*head_ref==NULL)
        return;
    Node *evenStart = NULL, *evenEnd = NULL;
    Node *oddStart = NULL, *oddEnd = NULL;
    Node *currNode = *head_ref;
         
    while(currNode != NULL){
        int val = currNode -> data;
             
        if(val % 2 == 0) {
            if(evenStart == NULL){
                evenStart = currNode;
                evenEnd = evenStart;
                }
            else{
                evenEnd -> next = currNode;
                evenEnd = evenEnd -> next;
            }
        }
            
        else{
            if(oddStart == NULL){
                oddStart = currNode;
                oddEnd = oddStart;
            }
            else{
                oddEnd -> next = currNode;
                oddEnd = oddEnd -> next;
            }
        }
                         
        currNode = currNode -> next;   
    }
    if(oddStart == NULL || evenStart == NULL){
        return;
    }
        
    evenEnd -> next = oddStart;
    oddEnd -> next = NULL;
         
    *head_ref = evenStart;
}

void push(struct Node** head_ref, int new_data){
	struct Node* new_node =	(struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

void printList(struct Node *node){
	while (node!=NULL){
		printf("%d ", node->data);
		node = node->next;
	}
}

int main(){
	/* Start with the empty list */
	struct Node* head = NULL;
	/* Let us create a sample linked list as following 0->1->4->6->9->10->11 */

	push(&head, 11);
	push(&head, 10);
	push(&head, 9);
	push(&head, 6);
	push(&head, 4);
	push(&head, 1);
	push(&head, 0);

	printf("\nOriginal Linked list \n");
	printList(head);

	segregateEvenOdd(&head);

	printf("\nModified Linked list \n");
	printList(head);

	return 0;
}