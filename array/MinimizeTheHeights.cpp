#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//function to find the minimum possible difference between maximum and minimum elements when we have to add/subtract every number by k
	int getMinDiff(int a[], int n, int k) {
        sort(a,a+n);
        int diff=a[n-1]-a[0];
        int max_temp=INT_MIN,min_temp=INT_MAX;
        
        for(int i=1;i<n;i++){
            max_temp=max(a[n-1]-k,a[i-1]+k);
            min_temp=min(a[0]+k,a[i]-k);
            if(min_temp<0) continue;
            diff=min(diff,(max_temp-min_temp));
        }
        return diff;
    }
};

// Driver Code
int main()
{
	int t=1;
	
	while (t--) {
		int k = 5;
	int n=10;
		int arr[n]={8,1,5,4,7,5,7,9,4,6};
		
		Solution ob;
		int ans = ob.getMinDiff(arr, n, k);
		cout << ans << "\n";
	}
	return 0;
}