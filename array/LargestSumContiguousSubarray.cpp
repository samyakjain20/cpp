//find Largest sum contiguous Subarray [V. IMP]
//Kadane's Algo V. IMP

#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(int arr[], int n){
    int temp_max=arr[0],max=arr[0];
    if(temp_max<0) temp_max=0;
    for(int i=1;i<n;i++){
        temp_max+=arr[i];
        if(temp_max> max) max=temp_max;        
        if(temp_max<0) temp_max=0;
    }
    return max;    
}

int main(){
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}
