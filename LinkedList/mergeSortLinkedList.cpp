#include<iostream>
using namespace std;

//Node structure
struct Node{
	int data;
	Node *next;
};

//function to insert in list
void insert(int x,Node **head) {
	if(*head == NULL){
		*head = new Node;
		(*head)->data = x;
		(*head)->next = NULL;
		return;
	}
	Node *temp = new Node;
	temp->data = (*head)->data;
	temp->next = (*head)->next;
	(*head)->data=x;
	(*head)->next=temp;
}

//function to print the list
void print(Node *head) {
	Node *temp=head;
	while(temp!=NULL) {
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

Node* partition(Node* head){
    Node* slow = head;
    Node* fast = head->next;
        
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
    
Node* merge(Node* first, Node* second){
    if(!second)
        return first;
    else if(!first)
        return second;
    else{
        Node* merged;
        if(first->data < second->data){
            merged = first;
            merged->next = merge(first->next, second);
        }
        else{
            merged = second;
            merged->next = merge(first, second->next);
        }
        return merged;
    }
}
    
Node* mergeSort(Node* head) {
    if(!head->next)
        return head;
            
    Node* mid = partition(head);
    Node* head2 = mid->next;
    mid->next = NULL;
        
    head = merge(mergeSort(head), mergeSort(head2));
    return head;
}

int main(void) {
	Node *head = NULL;
	int n[]={7,10,5,20,3,2};
	for(int i=0;i<6;i++) 
		insert(n[i],&head); //inserting in the list
	
    cout<<"\nSorted Linked List is: \n";
	print(mergeSort(head));	 //printing the sorted list returned by sort()
	return 0;
}
