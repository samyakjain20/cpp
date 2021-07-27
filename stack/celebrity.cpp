// C++ program to find celebrity
#include <bits/stdc++.h>
using namespace std;
#define N 8


int celebrity(vector<vector<int> >& M, int n) {
        stack<int> st;
        for(int i=0;i<n;i++)
            st.push(i);
            
        while(st.size()>=2){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if(M[a][b]==1) st.push(b);
            else st.push(a);
        }
        
        int temp=st.top(); //only potenial element will remain
        for(int i=0;i<n;i++){
            if(i==temp && M[i][i]==0) continue;
            else if(M[i][temp]==1 && M[temp][i]==0) continue;
            else return -1;
        }
        return temp;
    }

// Driver code
int main(){
    int n = 4;
    vector<vector<int> > M(n, vector<int> (n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>M[i][j];
        }
    }
    int id = celebrity(M,n);
    id == -1 ? cout << "No celebrity" :
               cout << "Celebrity ID " << id;
    return 0;
}

