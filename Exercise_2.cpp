#include<iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
};

struct List {
    Node* head;
};

Node* createNode(int val) {
    Node* temp = new Node;
    temp->val = val;
    temp->next = NULL;
    return temp;
}

void AddHead(List &l, int val) {
    if (l.head == NULL) {
        l.head = createNode(val);
    } else {
        Node* newNode = createNode(val);
        newNode->next = l.head;
        l.head = newNode;
    }
}

void RemoveDuplicate(List &l) {
    Node* curNode = l.head;
    while (curNode) {
        Node* temp = curNode->next;
        Node* prev = curNode;
        while (temp) {
            if (temp->val == curNode->val) {
                prev->next = temp->next;
            } else {
                prev = prev->next;
            }
            temp = temp->next;
        }
        curNode = curNode->next;
    }
}

void printList(List l) {
    Node* curNode = l.head;
    while (curNode) {
        if (curNode->next)
            cout << curNode->val << " -> ";
        else 
            cout << curNode->val;
        curNode = curNode->next;
    }
}

int main() {
    List l;
    l.head = NULL;
    AddHead(l, 5);
    AddHead(l, 5);
    AddHead(l, 5);
    AddHead(l, 5);
    cout << "Linked List: "; printList(l);
    cout << endl;
    RemoveDuplicate(l);
    cout << "Linked List after removing duplicates: "; printList(l);
    return 0;
}