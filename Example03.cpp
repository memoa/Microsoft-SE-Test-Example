// MinPeriod

#include <iostream>
using namespace std;

int MinPeriod(int* a, int n) {
    if (n < 1)
        return 0;
        
    int T = 1; // length of repeating array (minimal period)
    
    for (int i = 1; i < n; ++i)
        // If repeating array is not repeated, new length of repeating array is assigned
        if (a[i % T] != a[i])
            T = i;

    // If last elements of array does not match to last element of repeating array, break
    if (a[T-1] != a[n-1])
        return n;
    // Repeating array sequence confirmed, return period
    else
        return T;
}

int main()
{
    // int a[] = { 2, 5, 3, 4, 2, 5, 3, 4 };
    int a[] = { 2, 5, 3, 2, 5, 3, 2, 5 };
    int n = 8;
    
    cout << MinPeriod(a, n) << endl;

    return 0;
}


