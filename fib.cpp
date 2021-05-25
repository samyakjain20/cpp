// Printing fibonacci series
// Can use recursion for calculating fibonacci number 
#include<iostream>
using namespace std;

void fib(int x){
	int n1=0,n2=1,n3=0;
    while((x--)>0){
        n3=n1+n2;
        n1=n2;
        n2=n3;
        cout<<n3<<" ";
    }
}
int main(){
    int T;
    cin>>T;
    while((T--)>0){
        int n;
        cin>>n;
        cout<<"0 1 ";
        fib(n-2);
        cout<<"\n";
    }
    return 0;
}
