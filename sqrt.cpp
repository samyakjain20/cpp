// A Better (than Naive) Solution to find all divisiors
#include <bits/stdc++.h>
 
// Function to print the divisors
void printDivisors(int n)
{
    // Note that this loop runs till square root
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                printf("%d ", i);
 
            else // Otherwise print both
                printf("%d %d ", i, n/i);
        }
    }
}
 
/* Driver program to test above function */
int main()
{
    printf("The divisors of 100 are: \n");
    printDivisors(100);
    return 0;
}
//Output:
//The divisors of 100 are: 
//1 100 2 50 4 25 5 20 10
