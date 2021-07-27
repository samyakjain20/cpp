// A C++ program to print REVERSE level order traversal using stack and queue
// This approach is adopted from following link
// http://tech-queries.blogspot.in/2008/12/level-order-tree-traversal-in-reverse.html
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left and right children */
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

void reverseLevelOrder(struct node *root){
    vector<int> ans;
    
    queue<struct node*> q;
    q.push(root);
    
    stack<struct node*> st;
    while(!q.empty()){
        struct node* temp=q.front();
        q.pop();
        st.push(temp);
        
        //order should be this to get the desired output
        if(temp->right)
            q.push(temp->right);
        if(temp->left)
            q.push(temp->left);
        
    }
    
    while(!st.empty()){
        struct node* temp = st.top();
        st.pop();
        cout<<temp->data<<" ";

    }
}

node* newNode(int data){
	node* temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return (temp);
}

int main(){
	struct node *root = newNode(1);
	root->left	 = newNode(2);
	root->right	 = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	cout << "Level Order traversal of binary tree is \n";
	reverseLevelOrder(root);

	return 0;
}
