/*  merge3: performs a 3-way merge
 *
 *  A is divided into 3 sub-arrays which are merged in sorted order
 *     -> lo:m1, m1:m2, m2:hi
 * Cost is n
 * Space complexity is n b/c we create one new array the size of the original
 * array (which is of size n).
 */
void merge3(int A[], int lo, int m1, int m2, int hi)
{
    int B[hi-lo];
    int i = m1; // len of left_array
    int j = m2; //len of middle_array
    int k = hi; // len of right_array
    int z = 0;  // indices counter for new B array

    int a = lo;
    int b = m1;
    int c = m2;


    while (i>a && j>b && k>c) {
        if (A[a]<=A[b]  && A[a]<=A[c]) {B[z] = A[a]; a = a + 1; z = z + 1;}
        else if (A[b]<=A[a] && A[b]<=A[c]) {B[z] = A[b]; z = z + 1; b = b + 1;}
        else if (A[c]<=A[a] && A[c]<=A[b]) {B[z] = A[c]; z = z + 1; c = c + 1;}
    }
    // enter new while loop with the arrays remaining but first check which are
    // empty (i.e. their counters = 1)
    if (a>=i) {
        while (j>b && k>c) {

            if (A[b]<=A[c]) {B[z] = A[b]; z = z + 1; b = b + 1;}

            else if (A[c]<=A[b]) {B[z] = A[c]; z = z + 1; c = c + 1;}
        }
    }
    else if(b>=j) {
        while (i>a && k>c) {
            if (A[a]<=A[c]) {B[z] = A[a]; z = z + 1; a = a + 1;}

            else if (A[c]<=A[a]) {B[z] = A[c]; z = z + 1; c = c + 1;}
        }
    }
    else if (c>=k) {
        while (i>a && j>b) {
            if (A[a]<=A[b]) {B[z] = A[a]; a = a + 1; z = z + 1;}

            else if (A[b]<=A[a]) {B[z] = A[b]; b = b + 1; z = z + 1;}
        }
    }
    // enter new while loop b/c one of the sub arrays still remains; check to
    // see which remains
    if (a>=i && b>=j) {
        while (k>c) {
            B[z] = A[c];
            z = z + 1;
            c = c + 1;
        }
    }
    else if (a>=i && c>=k) {
        while (j>b) {
            B[z] = A[b];
            z = z + 1;
            b = b + 1;
        }
    }
    else if (b>=j && c>=k) {
        while (i>a) {
            B[z] = A[a];
            z = z + 1;
            a = a + 1;
        }
    }



    for (int f = 0;f<(hi-lo); f++) {
        A[lo+f] = B[f];
    }

}



/*
 * Implements a recursive 3-way mergesort
 *   -> Divide array into thirds.
 *   -> Recursively sort each third.
 *   -> Merge thirds.
 */
void merge_sort3(int A[], int lo, int hi)
{
    // cost is log3(n) * n
    //
    // Space complexity is 1 (its own) times the space complexity of merge3
    // (which is n). The total space complexity for merge_sort3 is n.
    if (hi-lo <= 1) {return;}

    // calculate where you want to break array into third
    int m1 =lo+(hi-lo)/3;
    int m2 =lo+ 2*(hi-lo)/3;

    merge_sort3(A,lo,m1);
    merge_sort3(A,m1,m2);
    merge_sort3(A,m2,hi);

    // once arrays begin to return we know they are single element arrays so we
    // can begin to merge
    merge3(A,lo,m1,m2,hi);
}
