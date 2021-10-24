#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

/* bin_search(A, n, x) =
 *   i,   where A[i] == x and A[j] != x for j<i, if there is such an i
 *        such that 0 <= i < n.
 *   -1,  if there is no such i.
 *
 * Pre-conditions:  A[0] <= ... <= A[n-1] and size of A is n.
 */
int bin_search(int A[], int n, int x) {

    int lo = 0;
    int hi = n;

    while (lo < hi) {
        int m = lo + (hi - lo) / 2 ;
        if (A[m] == x) {
            if (A[m-1] == x) {
                hi = m;
            }
            else {
                return m;
            }
        }
        else if (A[m] > x) {
            hi = m;
        }
        else {
            lo = m + 1;
        }
    }
    return -1;
}
