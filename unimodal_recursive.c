#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

int uni(int A[], int a, int b) {

    int hi = b; // upper bound
    int lo = a; // lower bound
    int m = lo + (hi-lo)/2;

    if (lo == hi -1) {return 0;}

    else if (A[0]>A[1]) {return 0;}

    else if ((m!=0 && A[m-1]<A[m]) && A[m]>A[m+1]) {return m;}

    else if (A[m]<A[m+1]) {return uni(A,m,hi);}

    else if((m!=0 && A[m]<A[m-1])) {return uni(A,lo,m);}

    else {return -1;}
}
