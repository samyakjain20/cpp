//There are N stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does matter).
#include<bits/stdc++.h>
using namespace std;

struct Solution {
  int Ways[10000000];
  int max_steps(int A) {
      /* write your solution here */
      if(A==1) return 1;
      if(A==2) return 2;
      
      int m=1000000007;
      if(Ways[A]==0) Ways[A]=(max_steps(A-1)+max_steps(A-2))%m;
      
      return Ways[A];
  }
};

int main(){
    int Stairs=4;
    // cin>>Stairs;

    Solution obj;
    cout<<"No of Ways to reach: "<<obj.max_steps(Stairs)<<endl;

    return 0;
}