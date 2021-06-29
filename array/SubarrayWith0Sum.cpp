//Subarray with 0 sum V.V.V IMP
//Kadane's Algo

// A C++ program to find if
// there is a zero sum subarray
#include <bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[], int n){
    set<int> s;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==0 ||  s.find(sum)!=s.end()) return true;
            
        s.insert(sum);
    }
    return false;
}

int main(){
	int arr[] = { -3, 2, 3, 1, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	if (subArrayExists(arr, n))
		cout << "Found a subarray with 0 sum";
	else
		cout << "No Such Sub Array Exists!";
	return 0;
}