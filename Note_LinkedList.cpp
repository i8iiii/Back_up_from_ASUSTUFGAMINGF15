#include <iostream> 
using namespace std;

struct Node {
    int data = 0;
    Node* next = nullptr;
};

void addHead(Node* &head, int update) {
    if (head == nullptr) {
        head = new Node {update, nullptr};
        return;
    }

    head = new Node {update, head};
}
void addTail(Node* &head, int update) {
    if (head == nullptr) {
        head = new Node {update, nullptr};
        return;
    }

    Node* tranv = head;
    while (tranv->next) {
        tranv = tranv->next;
    }

    tranv->next = new Node {update, nullptr};
}
void deleteNode(Node* &head, Node* &to_delete) {
    if (head == nullptr) {
        return;
    }

    if (to_delete == head) {
        Node* hold = head;
        head = head->next;

        delete hold;
        return;
    }

    Node* tranv = head;
    while (tranv->next != to_delete) {
        tranv = tranv->next;
    }

    tranv->next = tranv->next->next;
    delete to_delete;
}
void printList (Node* head) {
    if (!head) {
        cout << "empty()\n";
        return;        
    }

    while (head) {
        cout << head->data << ' ';
        head = head->next;
    }

    cout << '\n';
}
void deleteList (Node* &head) {
    while (head) {
        Node* hold = head;
        head = head->next;
        delete hold;
    }

    cout << "Deleted List()\n";
}
void sort (Node* head) {
   for (Node* i = head; i != nullptr; i=i->next) 
   for (Node* j = i; j != nullptr; j=j->next) {
      if (i->data > j->data) {
         int temp = i->data;
         i->data = j->data;
         j->data = temp;
      }
   }
}
int main() {
    cout << "Running";
    cout << '\n';

    Node* li = nullptr;
    addTail(li, 2);
    addTail(li, 4);
    addTail(li, 5);
    addTail(li, 7);
    addTail(li, 7);
    addTail(li, 3);
    addTail(li, 9);

    
    sort(li);
    printList(li);
    deleteList(li);
    return 0;
}