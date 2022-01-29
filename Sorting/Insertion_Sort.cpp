#include <bits/stdc++.h>
using namespace std;

//* Insertion Sort iterates through the array and compares the current element to its predecessor and places the element in the correct order from left to right.
//* Time Complexity : O(n^2)

/* Steps:
    1) Start from the second element and compare it with its predecessor.
    2) If the current element is smaller than its predecessor, then push predecessor by 1 and make space for putting the current element.
    3) Then put the smaller element in the created space.
    4) Repeat till array is sorted. 
*/
void InsertionSort(int A[],int n) {
    for (int i=1;i<n;i++) {
        int first = A[i];
        int hole = i;
        while (hole>0 && A[hole-1]>first) {
            A[hole] = A[hole-1];
            hole = hole-1;
        }
        A[hole]=first;
    }
}

int main() {
    int n = 5;
    int A[n] = {5,4,3,2,1};
    // int A[n] = {1,2,3,4,5};

    for(int i=0;i<n;i++) {
        cout<<A[i]<<" ";
    }
    cout<<"\n";

    InsertionSort(A,n);

    for(int i=0;i<n;i++) {
        cout<<A[i]<<" ";
    }
    cout<<"\n";

    return 0;
}