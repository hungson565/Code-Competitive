// https://www.geeksforgeeks.org/median-of-sliding-window-in-an-array-set-2/?ref=rp

// C++ Program to implement the
// above approach
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
// Policy based data structure
typedef tree<int, null_type,
             less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    Ordered_set;
 
// Function to find and return the
// median of every window of size k
void findMedian(int arr[], int n,
                int k)
{
 
    Ordered_set s;
 
    for (int i = 0; i < k; i++)
        s.insert(arr[i]);
 
    if (k & 1) {
 
        // Value at index k/2
        // in sorted list.
        int ans = *s.find_by_order(k / 2);
 
        cout << ans << " ";
 
        for (int i = 0; i < n - k; i++) {
 
            // Erasing Element out of window.
            s.erase(s.find_by_order(
                s.order_of_key(
                    arr[i])));
 
            // Inserting newer element
            // to the window
            s.insert(arr[i + k]);
 
            // Value at index k/2 in
            // sorted list.
            ans = *s.find_by_order(k / 2);
 
            cout << ans << " ";
        }
        cout << endl;
    }
    else {
 
        // Getting the two middle
        // median of sorted list.
        float ans = ((float)*s.find_by_order(
                         (k + 1) / 2 - 1)
                     + (float)*s.find_by_order(k
                                               / 2))
                    / 2;
 
        printf("%.2f ", ans);
 
        for (int i = 0; i < n - k; i++) {
            s.erase(s.find_by_order(
                s.order_of_key(arr[i])));
 
            s.insert(arr[i + k]);
 
            ans = ((float)*s.find_by_order(
                       (k + 1) / 2 - 1)
                   + (float)*s.find_by_order(k
                                             / 2))
                  / 2;
 
            printf("%.2f ", ans);
        }
        cout << endl;
    }
}
 
// Driver Code
int main()
{
    int arr[] = { -1, 5, 13, 8, 2,
                  3, 3, 1 };
    int k = 3;
 
    int n = sizeof(arr)
            / sizeof(arr[0]);
    findMedian(arr, n, k);
 
    return 0;
}
