#include<iostream>
#include<math.h>
using namespace std;

bool sumFactors(long n){
    long sum=1;
    for(int i=2;(i*i)<=n;i++){
        if(n%i==0){
            sum+=i;
            if(i!=(n/i)) sum+=(n/i);
        }
    }
    if(sum==n && n!=1) return true;
    else return false;
}

int main(){
    int T;
    cin>>T;
    while((T--)>0){
        long n;
        cin>>n;
        bool t=sumFactors(n);
        if(t==true) cout<<"YES\n";
        else cout<<"NO\n";
    }
    
    return 0;
}