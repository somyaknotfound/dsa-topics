#include <bits/stdc++.h>

using namespace std;

class ArrayStack {
    
    private:
        int* arr;
        int topIndex;
        int capacity;
    
    public:
    //constructor
    
    ArrayStack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
        
    }
    
    void push(int x) {
        if (topIndex == capacity -1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++topIndex] = x;
        
    }
    
    int pop() {
        if (isEmpty()) {
            cout << "stack underflow" << endl;
            return -1;
        }
        
        return arr[topIndex--];
    }
    
    int top() {
        
        if (isEmpty()) {
            cout << "Stack is empty" <<endl;
            return -1;
        }
        
        return arr[topIndex];
    }
    
    bool isEmpty() {
        return topIndex == -1;
    }
    
    ~ArrayStack() {
        delete[] arr;
    }
    
};

int main() {
    ArrayStack st(5);
    
    
    cout <<"pushing elements to it" << endl;
    
    st.push(10);
    st.push(20);
    st.push(30);
    
    cout << "Top element is "<< st.top() << endl;
    
    cout << "Popped" << st.pop() << endl;
    
    cout << "Top after pop: " << st.top() << endl;
    
    st.push(40);
    st.push(50);
    st.push(60);

    cout << "Trying to push beyond capacity...\n";
    st.push(70); // Overflow

    cout << "\nPopping all elements:\n";
    while (!st.isEmpty()) {
        cout << st.pop() << " ";
    }
    cout << endl;

    cout << "\nTrying to pop from empty stack...\n";
    st.pop(); // Underflow

    return 0;
}
