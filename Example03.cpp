// MinPeriod

#include <iostream>
using namespace std;

int MinPeriod(int* a, int n) {
    int T = 0; // length of repeating array
    bool T_stop = false; // stop creating repeating array
    
    int T_arr[n]; // repeating array
    
    for (int i = 0; i < n; ++i) {
        // If repeating array is not repeated, break
        if (T_stop && T_arr[i % T] != a[i])
            return n;
        // If first element repeated, stop creating repeating array
        else if (i != 0 && a[i] == a[0])
            T_stop = true;
        // If creating repeating array is not stopped, continue creating
        else if (!T_stop) {
            T_arr[i] = a[i];
            ++T;
        }
    }
    
    // If last elements of arrays does not match, break
    if (T_arr[T-1] != a[n-1])
        return n;
    // Repeating array sequence completed, return period
    else
        return T;
}

int main()
{
    //int a[] = { 2, 5, 3, 4, 2, 5, 3, 4 };
    int a[] = { 2, 5, 3, 2, 5, 3, 2, 5 };
    int n = 8;
    
    int T = MinPeriod(a, n);
    cout << T << endl;

    return 0;
}

