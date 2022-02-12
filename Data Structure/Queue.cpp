#include <iostream>
#include <exception>
using namespace std;

/**
 * Queue is a linear data structure that works on the principle of FIFO (first-in first-out)
 *  
 * Best example for Queue is a Queue :P
 *      _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
 *     |_5_|_2_|_7_|_1_|_9_|_4_|_ _|_ _
 */

//* This implementation uses dynamic array
// Declaration
template <class T> class Queue {
    private:
        // Throw exception for empty queue 
        class EmptyQueueException : public std::exception {
            virtual const char * what() const throw() {
                return "Queue is empty";
            }
        } empty_queue_exception;

        int head;
        int tail;
        T* a;
        int sizeArr;
        int cap = 20;
    public:
        Queue() {
            a = new T[cap];
            head = tail = -1;
            sizeArr = 0;
        }
        bool empty();
        bool full();
        void pop();
        void push(T x);
        T front();
        T back();
        int size();
};

// Returns number of elements queue
template <class T> int Queue<T>::size() {
    return sizeArr;
}

// Check if Queue is empty
template <class T> bool Queue<T>::empty() {
    return (head==-1 && tail==-1);
}

// Check if Queue is full
template <class T> bool Queue<T>::full() {
    return (sizeArr==cap);
}

// Return first element of Queue
template <class T> T Queue<T>::front() {
    if (empty()) throw empty_queue_exception;
    return a[head];
}

// Return last element of Queue
template <class T> T Queue<T>::back() {
    if (empty()) throw empty_queue_exception;
    return a[tail];
}

// Push element into Queue
template <class T> void Queue<T>::push(T x) {
    if (full()) {
        cap *= 2;
        T* tmp = new T[cap];

        for (int i=0;i<sizeArr;i++) {
            tmp[i]==a[i];
        }

        delete[] a;
        a = tmp;
        delete[] tmp;
    }

    if (empty()) {
        head = tail = 0;
        a[tail] = x;
        sizeArr++;
        return;
    }

    tail = (tail+1)%cap;
    a[tail] = x;
    sizeArr++;
    return;
}

// Delete first element from Queue
template <class T> void Queue<T>::pop() {
    if (empty()) throw empty_queue_exception;
    
    if (head==tail) {
        head = tail = -1;
        sizeArr--;
        return;
    }

    head = (head+1)%cap;
    sizeArr--;
    return;
}

// Print Queue
template <class T> void printQueue(Queue<T> q) {
    while (!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }cout<<endl;
}

int main() {
    
    return 0;
}