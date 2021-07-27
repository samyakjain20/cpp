#include <bits/stdc++.h>
using namespace std;

int minCost(int arr[], int n){
    // Create a priority queue
    // By default 'less' is used which is for decreasing order and 'greater' is used for increasing order
    priority_queue<int, vector<int>, greater<int> > pq(arr, arr + n);

    int res = 0;
    while (pq.size() > 1) {
        // Extract shortest two ropes from pq
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        res += first + second;
        pq.push(first + second);
    }

    return res;
}

int main(){
    int len[] = { 4, 3, 2, 6 };
    int size = sizeof(len) / sizeof(len[0]);
    cout << "Total cost for connecting ropes is " << minCost(len, size);
    return 0;
}
