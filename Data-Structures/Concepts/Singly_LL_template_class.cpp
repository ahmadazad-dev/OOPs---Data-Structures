//#include<iostream>
//using namespace std;
//
//template<class T>
//class SLinkedList {
//
//public:
//    class Node {
//
//        Node* next;
//        T data;
//
//    public:
//        Node();
//        Node(T data);
//        T& getData();
//        void setData(T);
//        Node* getNext();
//        const T& getData() const { return data; }
//        void setNext(Node*);
//
//    };
//
//    Node* head;
//    int size;
//
//
//    SLinkedList();
//    SLinkedList(const SLinkedList& rhs);
//    ~SLinkedList();
//    int getSize();
//    void insertHead(const T&);
//    void insertTail(const T&);
//    void insert(const T&, int);
//    void removeHead();
//    void removeTail();
//    void remove(int);
//    T& operator[] (int);
//    SLinkedList<SLinkedList<T>> seperateEquals() const;
//};
//
//template<class T>
//SLinkedList<T>::Node::Node() {
//    next = nullptr;
//}
//template<class T>
//SLinkedList<T>::Node::Node(T data) {
//    this->data = data;
//    next = nullptr;
//}
//template<class T>
//T& SLinkedList<T>::Node::getData() {
//    return data;
//}
//template<class T>
//void SLinkedList<T>::Node::setData(T data) {
//    this->data = data;
//}
//template<class T>
//typename SLinkedList<T>::Node* SLinkedList<T>::Node::getNext() {
//    return next;
//}
//template<class T>
//void SLinkedList<T>::Node::setNext(Node* next) {
//    this->next = next;
//}
//
//
//template<class T>
//SLinkedList<T>::SLinkedList() {
//    head = nullptr;
//    size = 0;
//}
//template<class T>
//SLinkedList<T>::SLinkedList(const SLinkedList& rhs) {
//    head = nullptr;
//    size = 0;
//    Node* current = rhs.head;
//    while (current) {
//        this->insertTail(current->getData());
//        current = current->getNext();
//    }
//}
//template<class T>
//SLinkedList<T>::~SLinkedList() {
//    Node* current = head;
//    while (current) {
//        Node* nextNode = current->getNext();
//        delete current;
//        current = nextNode;
//    }
//    head = nullptr;
//    size = 0;
//}
//template<class T>
//int SLinkedList<T>::getSize() {
//    return size;
//}
//template<class T>
//void SLinkedList<T>::insertHead(const T& data) {
//    Node* newNode = new Node(data);
//    if (head) {
//        newNode->setNext(head);
//        head = newNode;
//    }
//    else {
//        head = newNode;
//    }
//    size++;
//}
//template<class T>
//void SLinkedList<T>::insertTail(const T& data) {
//    Node* newNode = new Node(data);
//    if (head) {
//        Node* current = head;
//        while (current->getNext()) {
//            current = current->getNext();
//        }
//        current->setNext(newNode);
//    }
//    else {
//        head = newNode;
//    }
//    size++;
//}
//template<class T>
//void SLinkedList<T>::insert(const T& data, int index) {
//    if (index < 0 || index > size) {
//        cout << "Invalid index: " << index << endl;
//        return;
//    }
//
//    if (index == 0) {
//        insertHead(data);
//        return;
//    }
//    if (index == size) {
//        insertTail(data);
//        return;
//    }
//
//    Node* newNode = new Node(data);
//    Node* current = head;
//    for (int i = 0; i < index - 1; i++) {
//        current = current->getNext();
//    }
//    newNode->setNext(current->getNext());
//    current->setNext(newNode);
//    size++;
//}
//template<class T>
//void SLinkedList<T>::removeHead() {
//    if (!head) {
//        cout << "LinkedList is empty" << endl;
//        return;
//    }
//
//    Node* temp = head;
//    head = head->getNext();
//    delete temp;
//    size--;
//}
//template<class T>
//void SLinkedList<T>::removeTail() {
//    if (!head) {
//        cout << "LinkedList is empty" << endl;
//        return;
//    }
//
//    if (!head->getNext()) {
//        delete head;
//        head = nullptr;
//        size--;
//        return;
//    }
//
//    Node* current = head;
//    while (current->getNext()->getNext()) {
//        current = current->getNext();
//    }
//    delete current->getNext();
//    current->setNext(nullptr);
//    size--;
//}
//template<class T>
//void SLinkedList<T>::remove(int index) {
//    if (index < 0 || index >= size) {
//        cout << "Invalid index: " << index << endl;
//        return;
//    }
//
//    if (index == 0) {
//        removeHead();
//        return;
//    }
//
//    Node* current = head;
//    for (int i = 0; i < index - 1; i++) {
//        current = current->getNext();
//    }
//
//    Node* temp = current->getNext();
//    current->setNext(temp->getNext());
//    delete temp;
//    size--;
//}
//template<class T>
//T& SLinkedList<T>::operator[](int index) {
//    static T dummy; // Return a dummy value for invalid cases
//
//    if (!head) {
//        cout << "List is empty" << endl;
//        return dummy;
//    }
//
//    if (index < 0 || index >= size) {
//        cout << "Index out of range: " << index << endl;
//        return dummy;
//    }
//
//    Node* current = head;
//    for (int i = 0; i < index; i++) {
//        current = current->getNext();
//    }
//    return current->getData();
//}
//template<class T>
//SLinkedList<SLinkedList<T>> SLinkedList<T>::seperateEquals() const {
//    SLinkedList<SLinkedList<T>> result;
//
//    if (!head) {
//        return result; // Return empty list if original is empty
//    }
//
//    Node* current = head;
//
//    while (current) {
//        T value = current->getData();
//        bool found = false;
//
//        typename SLinkedList<SLinkedList<T>>::Node* groupNode = result.head;
//        while (groupNode) {
//            SLinkedList<T>& innerList = groupNode->getData();
//            // Check if the inner list is not empty before accessing [0]
//            if (innerList.getSize() > 0 && innerList[0] == value) {
//                innerList.insertTail(value);
//                found = true;
//                break;
//            }
//            groupNode = groupNode->getNext();
//        }
//
//        if (!found) {
//            SLinkedList<T> newGroup;
//            newGroup.insertTail(value);
//            result.insertTail(newGroup);
//        }
//
//        current = current->getNext();
//    }
//    return result;
//}
//
//int main() {
//    {
//        SLinkedList<int> list;
//
//        cout << "Inserting at head: 3, 2, 1" << endl;
//        list.insertHead(3);
//        list.insertHead(2);
//        list.insertHead(1);
//
//        cout << "Inserting at tail: 4, 5" << endl;
//        list.insertTail(4);
//        list.insertTail(5);
//
//        cout << "List size after insertions: " << list.getSize() << endl;
//
//        cout << "Elements using operator[]: ";
//        for (int i = 0; i < list.getSize(); i++) {
//            cout << list[i] << " ";
//        }
//        cout << endl;
//
//        cout << "Removing head..." << endl;
//        list.removeHead();
//
//        cout << "Removing tail..." << endl;
//        list.removeTail();
//
//        cout << "Removing element at index 1..." << endl;
//        list.remove(1);
//
//        cout << "List after removals: ";
//        for (int i = 0; i < list.getSize(); i++) {
//            cout << list[i] << " ";
//        }
//        cout << endl;
//
//        cout << "Testing copy constructor..." << endl;
//        SLinkedList<int> copiedList(list);
//        cout << "Copied list: ";
//        for (int i = 0; i < copiedList.getSize(); i++) {
//            cout << copiedList[i] << " ";
//        }
//        cout << endl;
//
//    }
//    {
//        SLinkedList<int> list;
//        list.insertTail(1);
//        list.insertTail(2);
//        list.insertTail(1);
//        list.insertTail(3);
//        list.insertTail(2);
//        list.insertTail(4);
//        list.insertTail(4);
//
//        auto grouped = list.seperateEquals();
//
//        cout << "Grouped lists:" << endl;
//        for (int i = 0; i < grouped.getSize(); i++) {
//            SLinkedList<int>& inner = grouped[i];
//            cout << "[ ";
//            for (int j = 0; j < inner.getSize(); j++) {
//                cout << inner[j] << " ";
//            }
//            cout << "] ";
//        }
//        cout << endl;
//    }
//
//    // Test error cases
//    cout << "\nTesting error cases:" << endl;
//    SLinkedList<int> emptyList;
//    cout << "Accessing empty list: " << emptyList[0] << endl;
//    emptyList.remove(0);
//    emptyList.removeHead();
//    emptyList.removeTail();
//
//    SLinkedList<int> testList;
//    testList.insertHead(10);
//    testList.insert(20, 5); // Invalid index
//    testList.remove(5); // Invalid index
//    cout << "Invalid index access: " << testList[5] << endl;
//
//    return 0;
//}