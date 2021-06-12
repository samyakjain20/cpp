//Chef has two numbers N and M. Help Chef to find number of integer N-tuples (A1,A2,…,AN) such that 0≤A1,A2,…,AN≤2M−1 and A1&A2&…&AN=0, where & denotes the bitwise AND operator.
//Since the number of tuples can be large, output it modulo 109+7.
// Sample Input
// 4
// 1 2
// 2 2
// 4 2
// 8 4
// Sample Output
// 1
// 9
// 225
// 228250597

#include <bits/stdc++.h>
using namespace std;
#define M 1000000007

// Normal Method Complexity - O(n)
// Complexity - O(logn)
// Modular Exponention
long long int calculatepower(long long int A, long long int B){
    if (B == 0) return 1;
    else if (B % 2 == 0)
        return calculatepower((A*A) % M, B >> 1) % M;
    else
        return (A * calculatepower((A*A) % M, B >> 1) % M );
}

int main() {
    int T;
    cin>>T;
    while(T-->0){
        int n,m,c=1;
        cin>>n>>m;        
        c=calculatepower(2,n);
        c=c-1; // for n numbers of 1-digit if we do the AND of these than we can get 0 in these many ways
        cout<<calculatepower(c,m)<<endl;  //if we hvae M digits
    }
	return 0;
}
