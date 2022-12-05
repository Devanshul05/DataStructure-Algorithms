#include <bits/stdc++.h>
using namespace std;

//* Bubble Sort sorts the array by comparing each adjacent element and then swapping it
//* Time Complexity : O(n^2)

/* Steps:
    1) We take the first two adjacent pairs and compare them.
    2) If first element is smaller then we swap them.
    3) This way all the greater elements with get pushed to the and in the end the array with be sorted.
    4) We will take a flag and if the array is not sorted we will change the flag, and if already sorted then the flag will be same and we will break out of loop
*/
void BubbleSort(int A[],int n) {
    for (int i=0;i<n;i++) {
        int flag=0;
        for (int j=0;j<n-i-1;j++) {
            if (A[j]>A[j+1]) {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                flag=1;
            }
        }
        if (flag==0) {
            break;
        }
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

    BubbleSort(A,n);

    for(int i=0;i<n;i++) {
        cout<<A[i]<<" ";
    }
    cout<<"\n";

    return 0;
}