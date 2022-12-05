#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 
 * Find the first value that is greater than x in a sorted array.
 * 
 * Naive solution will be to iterative over array and find the first value greater than x.
 * But, its Time Complexity will be O(n).
 * 
 * We can use Binary Search to reduce it to O(logn).
 * 
 * Example: 
 *     v = [1, 3, 4, 5, 5, 5, 7, 8], x = 6
 *      1) We start from the middle element, i.e. 3.
 *      2) Check if middle element is greater than to or less than equal to x.
 *      3) If the middle element is greater than x, then repeat 1st step for the left side of array from middle.
 *      4) Else if the middle element is less than equal to x, then repeat 1st step for the right side of array from middle.
 *      5) In the end, you will have the first element that is greater than or equal to x.
 */

int upper_bound(vector<int> &v, int x) {
    int l=0, r=v.size()-1, idx=-1;

    while (l<r) {
        int mid=l+(r-l)/2;
        if (v[mid]>x) {
            idx=mid;
            r=mid;
        }
        else {
            l=mid+1;
        }
    }

    return idx;
}

int main() {
    int x=6;
    vector<int> v1={3,4,4,5,8,10,10,10};
    vector<int> v2={3,6,6,6,6,6,7,8};

    int index1=upper_bound(v1,x);
    int index2=upper_bound(v2,x);

    cout<<"Upper Bound of "<<x<<" in v1 is at: "<<index1<<endl;
    cout<<"Upper Bound of "<<x<<" in v2 is at: "<<index2<<endl;

    return 0;
}