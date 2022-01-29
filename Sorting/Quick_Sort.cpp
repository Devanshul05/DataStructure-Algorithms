#include <bits/stdc++.h>
using namespace std;

//* Quick Sort
//* Worst Case Time Complexity : O(n^2) // Avoidable using randomized version of QuickSort (This implementation is for randomized version)
//* Best/Average Case Time Complexity : O(n.logn).
//* Quick Sort is not a stable sorting algorithm.
//* Quick Sort is in-place sorting algorithm.
//* Space Complexity => Avg. Case : O(logn).
//* Space Complexity => Worst Case : O(n).
//* Space Complexity is almost constant as logn is very small/discardable.

int Partition(int A[],int start,int end) {
    int pivot = A[end];
    int pIndex = start;
    for (int i=start;i<end;i++) {
        if (A[i]<=pivot) {
            swap(A[i],A[pIndex]);
            pIndex++;
        }
    }
    swap(A[pIndex],A[end]);
    return pIndex;
}

int RandomizedPartition(int A[],int start,int end) {
    int pivotIndex = start + rand()%(end-start);
    swap(A[pivotIndex],A[end]);
    Partition(A,start,end);
}

void QuickSort(int A[],int start,int end) {
    if (start<end) {
        int pIndex = RandomizedPartition(A,start,end);
        QuickSort(A,start,pIndex-1);
        QuickSort(A,pIndex+1,end);
    }
}

int main() {
    int n = 8;
    int A[n] = {2,4,1,6,8,5,3,7};

    for(int i=0;i<n;i++) {
        cout<<A[i]<<" ";
    }
    cout<<"\n";

    QuickSort(A,0,7);

    for(int i=0;i<n;i++) {
        cout<<A[i]<<" ";
    }
    cout<<"\n";    

    return 0;
}