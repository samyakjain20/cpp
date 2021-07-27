// C++ program to find maximum rectangular area in linear time
#include<bits/stdc++.h>
using namespace std;

int getMaxArea(int hist[], int n){
	    stack<int> s;
     
        long long max_area = 0,tp,area_with_top;
        hist[n]=0; // to pop the remaining bars in the end from stack and calculate
        // area with every popped bar as the smallest bar
        
        
        // Run through all bars of given histogram
        int i = 0;
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

// Driver program to test above function
int main(){
	int hist[] = {2, 1, 2, 3, 1};
	int n = sizeof(hist)/sizeof(hist[0]);
	cout << "Maximum area is " << getMaxArea(hist, n);
	return 0;
}
