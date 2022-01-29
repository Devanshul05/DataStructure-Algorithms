#include <bits/stdc++.h>
using namespace std;

//* Selection Sort finds minimum element and swaps it with the element in the beginning
//* Time Complexity : O(n^2)

/* Steps:
    1) Take iMin(variable) as first element of the array.
    2) Now iterate again through the rest of the array and compare iMin to all elements to find the minimum element and set it to iMin.
    3) Now make temp(variable) and using it swap the first element of array with iMin.
    4) Repeat till array is sorted.
*/
void SelectionSort(int a[],int n) {
    for (int i=0;i<n-1;i++) {
        int iMin = i;
        for (int j=i+1;j<n;j++) {
            if (a[j]<a[iMin]) {
                iMin = j;
            }
        }
        int temp = a[i];
        a[i] = a[iMin];
        a[iMin] = temp;
    }
}

int main() {
    int n;
    cin>>n;
    
    int a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }

    SelectionSort(a,n);
    
    for (int i=0;i<n;i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}