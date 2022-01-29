#include <bits/stdc++.h>
using namespace std;

//* Heap Sort is similar to Selection Sort where we find the minimum element and place it in the beginning, repeat the same for rest elements.
//* Time Complexity : O(n.logn).
//* Heap Sort is not a stable sorting algorithm.
//* Heap Sort is an in-place sorting algorithm.

//* Heapify is the process of reshaping an Array/Binary tree into a Heap data structure.

//* Note:
//*    1) If an element is at say i,
//*         => its left-child is at : 2*i
//*         => its right-child is at : 2*i+1
//*         => its parent is at : floor(i/2)
void heapify(int A[], int n, int i) {
    int mx = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l<n && A[l]>A[mx]) {
        mx = l;
    }

    if (r<n && A[r]>A[mx]) {
        mx = r;
    }

    if (mx != i) {
        swap(A[i], A[mx]);
        heapify(A, n, mx);
    }
}

void HeapSort(int A[], int n) {
    for (int i=n/2-1;i>=0;i--) {
        heapify(A, n, i);
    }

    for (int i=n-1;i>0;i--) {
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }
}

int main() {
    int n = 8;
    int A[n] = {2,4,1,6,8,5,3,7};

    for(int i=0;i<n;i++) {
        cout<<A[i]<<" ";
    }
    cout<<"\n";

    HeapSort(A,n);

    for(int i=0;i<n;i++) {
        cout<<A[i]<<" ";
    }
    cout<<"\n";

    return 0;
}