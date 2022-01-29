#include <bits/stdc++.h>
using namespace std;

//* Merge Sort keeps dividing the array in two sub-arrays until only 2 elements are left in the sub-array, then we sort these two arrays first and then merge them with the parent array.
//* Time Complexity : O(n.logn).
//* Merge Sort is stable sorting algorithm.
//* Merge Sort is not in-place sorting algorithm.
//* Space Complexity : O(n).
void Merge(int L[],int R[],int A[],int n) {
    int nL = (n+1)/2;
    int nR = n-nL;
    int i{0},j{0},k{0};
    while (i<nL && j<nR) {
        if (L[i]<=R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i<nL) {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j<nR) {
        A[k] = R[j];
        j++;
        k++;
    }
}
void MergeSort(int A[],int n) {
    if (n<2){
        return;
    }
    int mid = (n+1)/2;
    int L[mid];
    int R[n-mid];
    for (int i=0;i<mid;i++) {
        L[i] = A[i];
    }
    for (int i=mid;i<n;i++) {
        R[i-mid] = A[i];
    }
    MergeSort(L,mid);
    MergeSort(R,n-mid);
    Merge(L,R,A,n);
}

int main() {
    int n = 8;
    int A[n] = {2,4,1,6,8,5,3,7};

    for(int i=0;i<n;i++) {
        cout<<A[i]<<" ";
    }
    cout<<"\n";

    MergeSort(A,n);

    for(int i=0;i<n;i++) {
        cout<<A[i]<<" ";
    }
    cout<<"\n";
    
    return 0;
}