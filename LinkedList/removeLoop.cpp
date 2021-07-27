#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void removeNode(struct Node* head,struct Node* itr){
    struct Node *ptr1=head,*ptr2=itr;
    
    if(ptr1 == ptr2) 
        while(ptr2->next != ptr1) ptr2 = ptr2->next;
    else {
        while (ptr1->next != ptr2->next) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    ptr2->next=NULL;
}
int detectAndRemoveLoop(struct Node* head){
    struct Node *itr1=head,*itr2=head;
    while(itr2!=NULL && itr2->next!=NULL){
        itr1=itr1->next;
        itr2=itr2->next->next;
        
        if(itr1==itr2){
            removeNode(head,itr1);
            return 1;
        }
    }
    return 0;
}

void printList(struct Node* node){
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

struct Node* newNode(int key){
    struct Node* temp = new Node();
    temp->data = key;
    temp->next = NULL;
    return temp;
}

int main(){
    struct Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    detectAndRemoveLoop(head);

    cout << "Linked List after removing loop \n";
    printList(head);
    return 0;
}