// There are n people standing in a circle waiting to be executed. The counting out begins at some point in the circle and 
//proceeds around the circle in a fixed direction.

// In each step, a certain number of people are skipped and the next person is executed. The elimination proceeds around the circle 
//(which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom.

//Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle. 
//The task is to choose the place in the initial circle so that you are the last one remaining and so survive.

#include<bits/stdc++.h>
using namespace std;

int joseph(int n,int k){
    if(n==1) return 0;
    else return (joseph(n-1,k)+k)%n;
}
int main(){
    int n=14,k=2;
    // cin>>n>>k;
    
    cout<<joseph(n,k)+1<<endl;
    return 0;
}