// C++ program for implementation of Heap Sort
#include <iostream>
using namespace std;

// To heapify a subtree rooted with node i which is  an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    
    if(arr[largest]<arr[l] && l<n)
        largest=l;
    if(arr[largest]<arr[r] && r<n)
        largest=r;
    
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
    
}
        // int temp=arr[largest];
        // arr[largest]=arr[i];
        // arr[i]=temp;

// Main function to do heap sort
void heapSort(int arr[], int n) {
    // Build max heap
    for(int i=(n/2)-1;i>=0;i--)
        heapify(arr,n,i);
    
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        
        heapify(arr,i,0);
    }
}
void printArray(int arr[], int n){
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int main(){
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, n);

	cout << "Sorted array is \n";
	printArray(arr, n);
}
