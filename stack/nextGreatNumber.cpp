// A Stack based C++ program to find next greater element for all array elements in same order as input.
#include <bits/stdc++.h>
using namespace std;

void printNGE(int arr[], int n){
	
    stack<int> st;
    map<int,int> mp; 
    st.push(arr[0]);
    for(int i=1;i<n;i++){
        while(!st.empty() && st.top() < arr[i]){
            mp[st.top()] = arr[i];
            st.pop();
        }
        st.push(arr[i]);
    }
    while(st.empty()==false){
        mp[st.top()]=-1;
        st.pop();
    }
    
	for (int i = 0; i < n; i++)
		cout<< mp[arr[i]] <<" ";
    cout<<endl;
}

// Driver Code
int main(){
	int arr[] = { 6, 8, 0, 1, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printNGE(arr, n);
	return 0;
}