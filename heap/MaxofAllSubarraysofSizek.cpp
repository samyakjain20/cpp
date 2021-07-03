// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int returnMax(int arr[],int n){
        int res=arr[0];
        for(int i=1;i<n;i++) res=max(res,arr[i]);
        return res;
    }
    
    vector<int> max_of_subarrays(int *arr, int n, int k){
        // sliding window protcol
        vector<int> ans;

        int temp=returnMax(arr,k);
        ans.push_back(temp);
        for(int i=k;i<n;i++){
            if(arr[i-k]==temp) temp=returnMax(arr+i-k+1,k);
            else if(temp<arr[i]) temp=arr[i];
            ans.push_back(temp);
        }
        return ans;
    }
};


int main(){
	int arr[] = { 1,2,3,1,4,5,2,3,6 };
	int n = sizeof(arr) / sizeof(arr[0]);
    int k=3;
	Solution obj;
    vector<int> ans=obj.max_of_subarrays(arr, n,k);

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0; 
}
