#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void addToHead(Node*& head, float value);
void addToTail(Node*& head, float value);
void deleteNode(Node*& head, int position);
void insertNode(Node*& head, int position, float value);
void deleteList(Node*& head);
void output(Node *);


int main() {
    Node *head = nullptr;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        addToHead(head, tmp_val);
    }
    output(head);

    // deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    
    deleteNode(head, entry);
    output(head);

    // insert a node
    cout << "After which node to insert 10000? " << endl;
    int count = 1;
    Node* current = head;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    insertNode(head, entry, 10000);
    output(head);

    // deleting the linked list
    deleteList(head);
    output(head);

    return 0;
}

void addToHead(Node*& head, float value) {  // adds new node to the head
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = head;
    head = newNode;
}

void addToTail(Node*& head, float value) { // add node to tail
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;
     
    if (!head) {           // check for empty list
        head = newNode;
        return;
    }
    
    Node* current = head;  // go to end of list
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

void deleteNode(Node*& head, int position) {  // delete node at current position
    if (!head || position < 1) {
        cout << "Empty list.\n";
        return;
    }
    
    // Delete the head here
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    
    // Go to node before the one to delete
    Node* current = head;
    for (int i = 1; i < position - 1 && current->next; i++) {
        current = current->next;
    }

    if (!current->next) {   // position is out of range
        cout << "Position out of range.\n";
        return;
    }
    Node* nodeToDelete = current->next; // node to delete
    current->next = nodeToDelete->next;
    delete nodeToDelete; 
    }

void insertNode(Node*& head, int position, float value) {
    if (position < 1) {
        cout << "Invalid position.\n";
        return;
    }

    if (position == 1) { // insert at head
        addToHead(head, value);
        return;
    }

    // here we go to the node before the insertion point
    Node* current = head;
    for (int i = 1; i < position && current; i++) {
        current = current->next;
    }


    if (!current) { // if list is empty and position > 1
        cout << "Not in range.\n";
        return;
    }

    // Insert the new node after current
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = current->next;
    current->next = newNode;
}
    
// Delete the entire linked list
void deleteList(Node*& head) {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}




void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

