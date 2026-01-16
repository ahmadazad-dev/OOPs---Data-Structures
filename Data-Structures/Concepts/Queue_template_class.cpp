//#include<iostream>
//#include<string>
//using namespace std;
//
//template<class T>
//class SLinkedList {
//	class Node {
//	public:
//		T data;
//		Node* next;
//		Node();
//		Node(const T);
//		void print();
//	};
//	Node* top;
//	int size;
//public:
//	SLinkedList();
//	~SLinkedList();
//	void pop();
//	void push(const T&);
//	int get_size() const;
//	bool isEmpty();
//	bool isFull();
//	T peek();
//	void printList();
//	bool Top(T&);
//	void display();
//};
//
//
//template<class Q>
//class QLinkedList {
//	class Node {
//	public:
//		Q data;
//		Node* next;
//		Node();
//		Node(const Q);
//		void print();
//	};
//	Node* rear;
//	Node* front;
//	int size;
//public:
//	QLinkedList();
//	QLinkedList(const QLinkedList&);
//	~QLinkedList();
//	void dequeue();
//	void enqueue(const Q);
//	int get_size() const;
//	bool isEmpty();
//	bool isFull();
//	Q peak();
//	Q Rear();
//	void printList();
//	void reverseQueue();
//};
//template<class Q>
//QLinkedList<Q>::Node::Node() {
//	next = nullptr;
//	data = 0;
//}
//template<class Q>
//QLinkedList<Q>::Node::Node(const Q data) {
//	next = nullptr;
//	this->data = data;
//}
//template<class Q>
//void QLinkedList<Q>::Node::print() {
//	cout << data << " ";
//}
//
//template<class Q>
//QLinkedList<Q>::QLinkedList() {
//	rear = nullptr;
//	front = nullptr;
//	size = 0;
//}
//template<class Q>
//QLinkedList<Q>::QLinkedList(const QLinkedList& rhs) {
//	front = nullptr;
//	rear = nullptr;
//	size = 0;
//	if (rhs.front == nullptr) {return;}
//	Node* current = rhs.front;
//	while (current != nullptr) {
//		Node* newNode = new Node(current->data);
//		if (front == nullptr) {
//			front = newNode;
//			rear = newNode;
//		}
//		else {
//			rear->next = newNode;
//			rear = newNode;
//		}
//		current = current->next;
//		size++;
//	}
//}
//template<class Q>
//QLinkedList<Q>::~QLinkedList() {
//
//}
//template<class Q>
//void QLinkedList<Q>::enqueue(const Q data) {
//	Node* newNode = new Node(data);
//	if (!front) { front = rear = newNode; size++; return; }
//	if (isEmpty()) { rear->next = newNode; rear = newNode; size++; return; }
//	if (isFull()) { cout << "\nQueue is full\n"; size++; return; }
//
//	return;
//}
//template<class Q>
//void QLinkedList<Q>::dequeue() {
//	if (front) {
//		Node* temp = front->next;
//		delete front;
//		front = temp;
//		size--;
//	}
//	else { cout << "\nQueue is Empty\n"; }
//}
//template<class Q>
//int QLinkedList<Q>::get_size() const {
//	return size;
//}
//template<class Q>
//bool QLinkedList<Q>::isEmpty() {
//	return size < 5;
//}
//template<class Q>
//bool QLinkedList<Q>::isFull() {
//	return size == 5;
//}
//template<class Q>
//Q QLinkedList<Q>::peak() {
//	return front->data;
//}
//template<class Q>
//Q QLinkedList<Q>::Rear() {
//	return rear->data;
//}
//template<class Q>
//void QLinkedList<Q>::printList() {
//	Node* current = front;
//	while (current) {
//		current->print();
//		current = current->next;
//	}
//}
//template<class Q>
//void QLinkedList<Q>::reverseQueue() {
//	SLinkedList<Q> stack;
//	Node* current = this->front;
//	while (current) {
//		stack.push(current->data);
//		current = current->next;
//		dequeue();
//	}
//	while (stack.get_size() != 0) {
//		enqueue(stack.peek());
//		stack.pop();
//	}
//}
//
//
//
//template<class T>
//SLinkedList<T>::Node::Node() {
//	next = nullptr;
//	data = 0;
//}
//template<class T>
//SLinkedList<T>::Node::Node(const T data) {
//	next = nullptr;
//	this->data = data;
//}
//template<class T>
//void SLinkedList<T>::Node::print() {
//	cout << data << " ";
//}
//
//
//template<class T>
//SLinkedList<T>::SLinkedList() {
//	top = nullptr;
//	size = 0;
//}
//template<class T>
//SLinkedList<T>::~SLinkedList() {
//
//}
//template<class T>
//void SLinkedList<T>::push(const T& data) {
//	Node* newNode = new Node(data);
//	if (!top) { top = newNode; size++; return; }
//	if (isEmpty()) { newNode->next = top; top = newNode; size++; return; }
//	if (isFull()) { cout << "\nStack is full\n"; return; }
//	return;
//}
//template<class T>
//void SLinkedList<T>::pop() {
//	if (top) {
//		Node* temp = top->next;
//		delete top;
//		top = temp;
//		size--;
//	}
//	else { cout << "\nStack is Empty\n"; }
//}
//template<class T>
//int SLinkedList<T>::get_size() const {
//	return size;
//}
//template<class T>
//bool SLinkedList<T>::isEmpty() {
//	return size < 20;
//}
//template<class T>
//bool SLinkedList<T>::isFull() {
//	return size == 20;
//}
//template<class T>
//T SLinkedList<T>::peek() {
//	return top->data;
//}
//template<class T>
//void SLinkedList<T>::printList() {
//	Node* current = top;
//	while (current) {
//		current->print();
//		current = current->next;
//	}
//}
//template<class T>
//bool SLinkedList<T>::Top(T& data) {
//	if (!top) return false;
//	this->push(data);
//	return true;
//}
//template<class T>
//void SLinkedList<T>::display() {
//	SLinkedList<T> newStack;
//	while (top) {
//		newStack.push(top->data);
//		pop();
//	}
//	newStack.printList();
//	while (newStack.top) {
//		push(newStack.top->data);
//		newStack.pop();
//	}
//}
//
//int prec(char c) {
//	if (c == '^')
//		return 3;
//	else if (c == '/' || c == '*')
//		return 2;
//	else if (c == '+' || c == '-')
//		return 1;
//	else
//		return -1;
//}
//bool isRightAssociative(char c) {
//	return c == '^';
//}
//string infixToPostfix(string& s) {
//	SLinkedList<char> st;
//	string res;
//	for (int i = 0; i < s.length(); i++) {
//		char c = s[i];
//		if ((c >= 'a' && c <= 'z') ||
//			(c >= 'A' && c <= 'Z') ||
//			(c >= '0' && c <= '9'))
//			res += c;
//		else if (c == '(')
//			st.push('(');
//		else if (c == ')') {
//			while (!st.isEmpty() && st.peek() != '(') {
//				res += st.peek();
//				st.pop();
//			}
//			st.pop();
//		}
//		else {
//			while (!st.isEmpty() && st.peek() != '(' &&
//				(prec(st.peek()) > prec(c) ||
//					(prec(st.peek()) == prec(c) && !isRightAssociative(c)))) {
//				res += st.peek();
//				st.pop();
//			}
//			st.push(c);
//		}
//	}
//	while (!st.isEmpty()) {
//		res += st.peek();
//		st.pop();
//	}
//	return res;
//}
//
//bool isPalindrome(string myString) {
//	SLinkedList<char> Palindrome;
//	for (int i = 0; i < myString.length(); i++) {
//		Palindrome.push(myString[i]);
//	}
//	SLinkedList<char> newStack1;
//	SLinkedList<char> newStack2;
//	for (int i = 0, j = myString.length() - 1; i < myString.length(), j >= 0; i++, j--) {
//		newStack1.push(myString[i]);
//		newStack2.push(myString[j]);
//	}
//	while (newStack1.get_size() != 0) {
//		if (newStack1.peek() != newStack2.peek()) { return false; }
//		newStack1.pop(); newStack2.pop();
//	}
//	return true;
//}
//template<class Q>
//bool isQPalindrome(QLinkedList<Q> queue) {
//	QLinkedList<Q> newQueue(queue);
//	newQueue.reverseQueue();
//	for (int i = 0;i < queue.get_size();i++) {
//		if (newQueue.peak() != queue.peak()) return false;
//		newQueue.dequeue();
//		queue.dequeue();
//	}
//	return true;
//}
//
//
//int main() {
//	{
//		SLinkedList<int> stack;
//		cout << "Stack after Pushing elements: ";
//		stack.push(4);
//		stack.push(6);
//		stack.push(8);
//		stack.push(11);
//		stack.push(2);
//		stack.printList(); cout << endl;
//		cout << "Stack after Popping 1 element: ";
//		stack.pop();
//		stack.printList(); cout << endl;
//		cout << "Stack after Popping 1 element: ";
//		stack.pop();
//		stack.printList(); cout << endl;
//		cout << "Size of Stack: " << stack.get_size() << endl;
//		int top = 7;
//		bool flag = stack.Top(top);
//		cout << "Using top function: " << flag << endl;
//		cout << "Stack after Pushing elements: ";
//		stack.push(13);
//		stack.push(4);
//		stack.push(21);
//		stack.push(20);
//		stack.printList(); cout << endl;
//		cout << "Stack Display: ";
//		stack.display();cout << endl;
//	}
//	{
//		if (isPalindrome("ggg")) cout << "Is Palindrome" << endl;
//		else { cout << "It is not palindrome" << endl; }
//	}
//	{
//		string str = "A+B*C+D";
//		string strr = infixToPostfix(str);
//		cout << "PostFix: ABC*+D+" << endl;
//	}
//	{
//		QLinkedList<int> queue;
//		queue.enqueue(4);
//		queue.enqueue(6);
//		queue.enqueue(8);
//		queue.enqueue(11);
//		queue.enqueue(2);
//		cout << "EnQueue: ";
//		queue.printList(); cout << endl;
//		cout << "DeQueue: ";
//		queue.dequeue();
//		queue.dequeue();
//		queue.printList(); cout << endl;
//		bool flag = isQPalindrome(queue);
//		cout << "The Palindorme Queue: 0 for not 1 for yes:" << flag << endl;
//		cout << "Reversed List: ";
//		queue.reverseQueue();
//		queue.printList();
//	}
//}