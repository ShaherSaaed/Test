#include<iostream>

using namespace std;

template<class T>
class Node {
public:
    T data;
    Node<T> *next;

    Node(const T &value);
};

template<class T>
class CircularLinkedList {
private:
    Node<T> *head;
    Node<T> *tail;
public:

    CircularLinkedList();

    void insertAtHead(const T &value);

    void insertAtTail(const T &value);

    void insertAt(const T &value, int index);

    void removeAtHead();

    void removeAtTail();

    void removeAt(const int &index);

    T retrieveAt(const int &index);

    void replaceAt(const T &value, int index);

    bool isExist(const T &value);

    bool isItemAtEqual(const T &value, int index);

    void swap(const int &index1, const int &index2);

    bool isEmpty();

    int circularLinkedListSize();

    void clear();

    void print();
};

int main() {
    CircularLinkedList<int> list;
    list.insertAtTail(0);
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.swap(0, 3);
/*  list.replaceAt(-1, 0);
    list.replaceAt(-1, 1);
    list.replaceAt(-1, 2);
    list.replaceAt(-1, 3);
*/
/*   cout << list.isItemAtEqual(0, 0) << endl;
    cout << list.isItemAtEqual(1, 1) << endl;
    cout << list.isItemAtEqual(2, 2) << endl;
    cout << list.isItemAtEqual(40, 3) << endl;
*/
//    cout << list.circularLinkedListSize() << '\t';
//    list.insertAtHead(0);
//    list.insertAt(44, 4);
//    cout << list.circularLinkedListSize() << '\t';
//    cout << list.isEmpty() << '\t';
//    list.insertAtHead(2);
//    list.insertAtHead(3);
    list.print();
}

//==================================================Constructors==================================================
template<class T>
Node<T>::Node(const T &value): data(value), next(nullptr) {}

template<class T>
CircularLinkedList<T>::CircularLinkedList(): head(nullptr) {}

//==================================================Insertion=====================================================
template<class T>
void CircularLinkedList<T>::insertAtHead(const T &value) {
    Node<T> *new_node = new Node(value);
    if (head == nullptr) {
        head = new_node;
        tail = new_node;
        new_node->next = head;
        return;
    }
    new_node->next = tail->next;
    tail->next = new_node;
    head = new_node;
}

template<class T>
void CircularLinkedList<T>::insertAtTail(const T &value) {
    Node<T> *new_node = new Node(value);
    if (head == nullptr) {
        head = new_node;
        tail = new_node;
        new_node->next = head;
        return;
    } else {
        new_node->next = tail->next;
        tail->next = new_node;
        tail = new_node;
    }
}

template<class T>
void CircularLinkedList<T>::insertAt(const T &value, int index) {
    Node<T> *new_node = new Node(value);
    Node<T> *current;
    if (index == 0) {
        insertAtHead(value);
        return;
    } else if (index < 0 || index > circularLinkedListSize()) {
        throw runtime_error("Invalid index");
    }
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;

}

//==================================================Deletion=======================================================
template<class T>
void CircularLinkedList<T>::removeAtHead() {
    if (head == nullptr)
        throw runtime_error("List is empty");
    Node<T> *temp = head;
    if (head->next == nullptr) {
        head = nullptr;
        tail = nullptr;
        delete temp;
        return;
    }
    tail->next = head->next;
    head = head->next;
    delete temp;
}

template<class T>
void CircularLinkedList<T>::removeAtTail() {
    if (head == nullptr) {
        throw runtime_error("List is empty");
    }
    Node<T> *current = head, *temp;
    if (head->next == head) {
        head = nullptr;
        tail = nullptr;
        delete current;
        return;
    }
    while (current->next->next != head) {
        current = current->next;
    }
    temp = current->next;
    current->next = temp->next;
    tail = current;
    delete temp;

}

template<class T>
void CircularLinkedList<T>::removeAt(const int &index) {
    Node<T> *current = head, *temp;
    if (index > circularLinkedListSize() || index < 0)
        throw runtime_error("Invalid index");
    if (index == 0 && head->next == head) {
        head = nullptr;
        tail = nullptr;
        delete current;
        return;
    }
    if (index == 0) {
        head = head->next;
        tail->next = head;
        delete current;
        return;
    }
    for (int i = 0; i < index - 1; ++i) {
        current = current->next;
    }
    temp = current->next;
    current->next = temp->next;
    delete temp;
}

//==================================================Retrieval=====================================================
template<class T>
T CircularLinkedList<T>::retrieveAt(const int &index) {
    Node<T> *current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

//==================================================Replace=======================================================
template<class T>
void CircularLinkedList<T>::replaceAt(const T &value, int index) {
    Node<T> *current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->data = value;
}

//==================================================isExist=======================================================
template<class T>
bool CircularLinkedList<T>::isExist(const T &value) {
    Node<T> *current = head;
    do {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    } while (current != head);
    return false;
}

//==================================================isItemAtEqual=================================================
template<class T>
bool CircularLinkedList<T>::isItemAtEqual(const T &value, int index) {
    Node<T> *current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    if (current->data == value)
        return true;
    return false;
}

//==================================================Swap==========================================================
template<class T>
void CircularLinkedList<T>::swap(const int &index1, const int &index2) {
    Node<T> *current = head, *item, *temp;
    for (int i = 0; i < index1; i++) {
        current = current->next;
    }
    for (int i = 0; i < index2; i++) {
        item = item->next;
    }
    temp = current;
    current = item;
    item = temp;
    temp->data = current->data;
    current->data = item->data;
    item->data = temp->data;
}

//==================================================isEmpty=======================================================
template<class T>
bool CircularLinkedList<T>::isEmpty() {
    return !(circularLinkedListSize());
}

//==================================================Size==========================================================
template<class T>
int CircularLinkedList<T>::circularLinkedListSize() {
    int size = 0;
    if (head == nullptr)
        return size;
    Node<T> *current = head;
    do {
        size++;
        current = current->next;
    } while (current != head);
    return size;
}

//==================================================Clear==================================================
template<class T>
void CircularLinkedList<T>::clear() {
    head = tail = nullptr;
}

//==================================================Print==================================================
template<class T>
void CircularLinkedList<T>::print() {
    if (head == nullptr) {
        throw runtime_error("List is Empty");
    }
    Node<T> *current = head;
    do {
        cout << current->data << ' ';
        current = current->next;
    } while (current != head);
}