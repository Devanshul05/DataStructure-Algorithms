#include <iostream>
#include <climits>
using namespace std;
#define SIZE 500 // Stack capacity

/**
 * Stack is a linear data structure that works on the principle of LIFO (last-in first-out)
 * 
 * In simple words,you stack one element on top of the other elements,just like a stack of books
 * 
 *      |__ __|
 *      |__8__|
 *      |__6__|
 *      |__3__|
 *      |__9__|
 *      |__1__|
 */

// Declaration
template <class T> class Stack {
    private:
        T st[SIZE];
        int n;
    public:
        Stack() {
            n = -1;
        }
        bool empty();
        bool full();
        T pop();
        T top();
        int size();
        void push(T x);
};

// Return number of elements in stack
template <class T> int Stack<T>::size() {
    return n+1;
}

// Check if stack is empty
template <class T> bool Stack<T>::empty() {
    return (n==-1);
}

// Return top element of stack
template <class T> T Stack<T>::top() {
    T peak = st[n];
    return peak;
}

// Check if stack is full
// ? Can this be put in private class because its primary use-case is just before pushing an element
template <class T> bool Stack<T>::full() {
    return (n==(SIZE-1));
}

// Push element into Stack
template <class T> void Stack<T>::push(T x) {
    if (full())
        cout<<"Stack is full\n";
    n++;
    st[n]=x;
}

// Delete top element from stack
template <class T> T Stack<T>::pop() {
    if (empty()) 
        cout<<"Stack is empty\n";
    T del = st[n];
    n--;
    return del;
}

// Print stack
template <class T> void printStack(Stack<T> st) {
    while (!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
}

int main() {

    return 0;
}