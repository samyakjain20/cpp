// C++ program to find largest rectangle with all 1s in a binary matrix
#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int maxHist(int hist[], int n){
    stack<int> s;     
    long long max_area = 0,tp,area_with_top;
        
    // Run through all bars of given histogram
    int i = 0;
    hist[n]=0; // to pop the remaining bars in the end from stack and calculate
    // area with every popped bar as the smallest bar
    while (i <=n){
        // If this bar is higher than the bar on top stack, push it to stack
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
        else{
            tp = s.top();  // store the top index
            s.pop();  // pop the top
     
            // Calculate the area with hist[tp] stack as smallest bar
            area_with_top = hist[tp] * (s.empty() ? i : i-s.top()-1);
     
            max_area = max(max_area,area_with_top);
        }
    }
    return max_area;
}
    
int maxRectangle(int M[MAX][MAX], int n, int m) {
    int area=maxHist(M[0],m);
            
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(M[i][j]) M[i][j]+=M[i-1][j];
        }
        area=max(area,maxHist(M[i],m));
    }
        
    return area;
}

int main(){
    int r=3,c=3;
    int A[MAX][MAX] = {
        { 0, 1, 0 },
        { 1, 0, 1 },
        { 0, 1, 0 },
    };

    cout << "Area of maximum rectangle is " << maxRectangle(A,r,c);
    return 0;
}