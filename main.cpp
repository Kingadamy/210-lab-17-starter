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
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!head) { // if this is the first node, it's the new head
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else { // its a second or subsequent node; place at the head
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
    output(head);

    // deleting a node
    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    current = head;
    Node *prev = head;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
    output(head);

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
    output(head);

    // deleting the linked list
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
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

