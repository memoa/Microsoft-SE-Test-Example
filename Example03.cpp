// MinPeriod

#include <iostream>
using namespace std;

int MinPeriod(int* a, int n) {
    int T = 0; // length of repeating array (minimal period)
    bool T_stop = false; // stop defining repeating array
    
    for (int i = 0; i < n; ++i) {
        // If repeating array is not repeated, break
        if (T_stop && a[i % T] != a[i])
            return n;
        // If first element repeated, stop increasing repeating array length
        else if (i != 0 && a[i] == a[0])
            T_stop = true;
        // If repeating array is not stopped, increase repeating array length
        else if (!T_stop)
            ++T;
    }
    
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

