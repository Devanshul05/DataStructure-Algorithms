#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct minHeap {
    vector<T> pq;
    
    void heapify_down(int i) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        int smallest = i;

        if (l < size() && pq[l] < pq[smallest]) {
            smallest = l;
        }

        if (r < size() && pq[r] < pq[smallest]) {
            smallest = r;
        }

        if (smallest != i) {
            swap(pq[i], pq[smallest]);
            heapify_down(smallest);
        }
    }

    void heapify_up(int i) {
        if (i && pq[(i - 1) / 2] > pq[i]) {
            swap(pq[i], pq[(i - 1) / 2]);
            heapify_up((i - 1) / 2);
        }
    }
public:
    unsigned int size() {
        return pq.size();
    }

    bool empty() {
        return pq.empty();
    }

    void push(T val) {
        pq.push_back(val);
        heapify_up((int)size() - 1);
    }

    void pop() {
        try {
            if (empty()) {
                throw out_of_range("Vector<X>::at() : index is out of range(Heap underflow)");
            }
            pq[0] = pq.back();
            pq.pop_back();
            heapify_down(0);
        }
        catch (const out_of_range &e) {
            cout << e.what() << endl;
        }
    }

    T top() {
        try {
            if (empty()) {
                throw out_of_range("Vector<X>::at() : index is out of range(Heap underflow)");
            }
            return pq[0];

        }
        catch (const out_of_range &e) {
            cout << e.what() << endl;
        }
        return -1;
    }
};

int main() {
    minHeap<int> pq;
 
    pq.push(3);
    pq.push(2);
    pq.push(15);
 
    cout << "Size is " << pq.size() << endl;
 
    cout << pq.top() << " ";
    pq.pop();

    cout << pq.top() << " ";
    pq.pop();

    return 0;
}