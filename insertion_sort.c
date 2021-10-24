/*  Insertion sort
 *
 *  The for loop continues until n-1. Notice that the while loop is nested in
 *  the for loop, b/c of this the cost of each of the loops will be multiplied
 *  together when calculating the total cost of the algorithm. The while loop
 *  continues at most n-1 times as well (specifically in the situation where
 *  the smallest element in the array is at the end of the original array --
 *  this will cause the while loop to shift all precceding values by one). Thus
 *  the cost is n-1*n-1 = Big Oh (n^2).
 *
 *  Space complexity is constant; no new array created.
 */
void insertion_sort(int A[], int n)
{
    int i = 1;
    int hole, value;
    for(i=1; i<n; i++) {
        value = A[i];
        hole = i;
        while(hole>0 && A[hole-1]>value) {
            A[hole] = A[hole-1];
            hole = hole-1;
        }
        A[hole] = value;
    }
}
