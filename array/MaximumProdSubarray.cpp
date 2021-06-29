
// C++ program to find maximum product subarray
#include <bits/stdc++.h>
using namespace std;

long long maxProduct(int *a, int n) {
	    // code here
	    long long maxProd=a[0],ans=a[0],minProd=a[0];
	    for(int i=1;i<n;i++){
	        long long t=a[i];
	        if(a[i]<0) swap(maxProd,minProd);
	        maxProd=max(maxProd*a[i],t);
	        minProd=min(minProd*a[i],t);
	        
	        ans=max(ans,maxProd);
	    }
	    
	    return ans;
	}

int main(){
    int arr[] = { -1, -3, -10, 0, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum Subarray product is " << maxProduct(arr, n) << endl;
    return 0;
}
