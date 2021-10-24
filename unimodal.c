#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

/* unimodal_search(A, n) = j, where A[j] = max{A[0],...,A[n-1]}.
 *
 * Pre-conditions:
 * - A has size n.
 * - There is j such that
 *     A[0] < A[1] < ... < A[j-1] < A[j] > A[j+1] > ... A[n-1].
 *   It is possible that j=0 or j=n-1.
 */

int unimodal_search(int A[], int x) {

    int lo = 0;
    int hi = x-1;

    while (lo < hi) {

        int ft = lo + (hi-lo+1)/3;
        int st = lo + (hi-lo+1)*2/3;

        if (A[ft] > A[ft+1] && (ft == 0 || A[ft] > A[ft-1])) {
                return ft;
            }
        else if (A[st] > A[st-1] && (st == x-1 || A[st] > A[st+1])) {
            return st;
            }
        else if (A[st]<A[st+1] && A[st] > A[st-1]) {
            lo = st+1;
        }
        else if (A[ft]>A[ft+1] && A[ft] < A[ft-1]){
            hi = ft-1;
        }
        else {
            lo = ft+1;
            hi = st-1;

        }}
return lo;
}
