#include <iostream>

using namespace std;

struct Node {
	string data;
	Node* next_ptr;
};

class Queue {
private:
	Node* front;
	Node* rear;
	int size;
	int capacity;

public:
	Queue(int cap = 5) {
		front = rear = nullptr;
		size = 0;
		capacity = cap;
	}

	bool isEmpty() {
		return front == nullptr;
	}

	bool isFull() {
		return size >= capacity;
	}

	void enqueue(string value) {
		if (isFull()) {
			cout << "Queue is full! Cannot enqueue '" << value << "'." << endl;
			return;
		}

		Node* newNode = new Node{value, nullptr};

		if (rear == nullptr) {
			front = rear = newNode;
			rear = newNode;
		} else {
			rear->next_ptr = newNode;
			rear = newNode;
		}

		size++;
		cout << "Enqueued: " << value << endl;

	}

	void dequeue() {
		if (isEmpty()) {
			cout << "Queue is empty! Cannot dequeue." << endl;
			return;
		}

		Node* temp = front;
		cout << "Dequeued: " << temp->data << endl;
		front = front->next_ptr;

		if (front == nullptr)
			rear = nullptr;

		delete temp;
		size--;
	}

	void peek() {
		if (isEmpty()) {
			cout << "Queue is empty! Nothing here." << endl;
		} else {
			cout << "Front element: " << front->data << endl;
		}
	}

	void display() {
		if (isEmpty()) {
			cout << "Queue is empty!" << endl;
			return;
		}

		cout << "Queue elements: ";
		Node* current = front;
		while (current!=nullptr) {
			cout << current->data << " ";
			current = current->next_ptr;
		}
		cout << endl;
	}

	~Queue() {
		while (!isEmpty())
			dequeue();
	}
};

int main() {
	Queue q(3);
	q.enqueue("Num1");
	q.enqueue("Num2");
	q.enqueue("Num3");
	q.enqueue("Overflow");

	q.display();
	q.peek();
	q.dequeue();
	q.display();
	q.dequeue();
	q.dequeue();
	q.dequeue();

	return 0;
}

