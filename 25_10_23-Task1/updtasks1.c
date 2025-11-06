#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

struct Node {
    string data;
    Node* next_ptr;
};

class Stack {
private:
    Node* top_ptr; 

public:
    Stack() : top_ptr(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop(); 
        }
    }

    bool isEmpty() const {
        return top_ptr == nullptr;
    }

    void push(const string& value) {
        Node* new_node = new Node;
        new_node->data = value;
        new_node->next_ptr = top_ptr; 
        top_ptr = new_node; 
        cout << "Pushed: " << value << endl;
    }

    string pop() {
        if (isEmpty()) {
            throw runtime_error("Stack underflow: Cannot pop from an empty stack.");
        }
        Node* temp = top_ptr; 
        string popped_data = temp->data;
        top_ptr = top_ptr->next_ptr;
        delete temp; 
        return popped_data;
    }

    const string& top() const {
        if (isEmpty()) {
            throw runtime_error("Stack is empty: Cannot get top element.");
        }
        return top_ptr->data;
    }
};

int main() {
    Stack myStack;

    cout << "Is the stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << endl;
    cout << "---------------------------------" << endl;

    myStack.push("Data 1");
    myStack.push("Data 2");
    myStack.push("Data 3 (TOP)");
    cout << "---------------------------------" << endl;

    try {
        cout << "Top element is: " << myStack.top() << endl;
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }
    cout << "---------------------------------" << endl;

    try {
        cout << "Popped: " << myStack.pop() << endl; 
        cout << "New top element is: " << myStack.top() << endl;
        cout << "Popped: " << myStack.pop() << endl; 
        cout << "Popped: " << myStack.pop() << endl; 
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }
    cout << "---------------------------------" << endl;

    cout << "Is the stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}

