#include<iostream>
#include<conio.h>

using namespace std;

struct Node {
    int val;
    Node* next;
};

struct Queue {
    Node* head;
    Node* tail;
};

Node* makeNode(int val) {
    Node* temp = new Node;
    temp->val = val;
    temp->next = NULL;
    return temp;
}

void enqueue(Queue &l, int val) {
    Node* curNode = makeNode(val);
    if (l.head == NULL) {
        l.head = l.tail = curNode;
    } else {
        l.tail->next = curNode;
        l.tail = curNode;
    }
}

void dequeue(Queue &l) {
    if (l.head == NULL) {
        cout << "can't dequeue cause this queue is empty!" << endl;
    } else {
        Node* temp = l.head;
        l.head = l.head->next;
        delete temp;
        if (l.head == NULL)
            l.tail = NULL;
    }
} 

int front(Queue l) {
    if (l.head == NULL) 
        return -1;
    return l.head->val;
}

int main() {
int choice = 1;
    Queue l;
    l.head = NULL;
    l.tail = NULL;
    int val;
    do
    {
        system("cls");

        cout << ((choice == 1) ? ">> " : "   ") << "1. enqueue" << endl;
        cout << ((choice == 2) ? ">> " : "   ") << "2. dequeue" << endl;
        cout << ((choice == 3) ? ">> " : "   ") << "3. front" << endl;
        cout << ((choice == 0) ? ">> " : "   ") << "0. Exit" << endl;

        char key;
        key = getch();

        switch (key)
        {
        // Up
        case 72:
            choice--;
            if (choice == -1)
                choice = 3;
            break;

        // Down
        case 80:
            choice++;
            if (choice == 4)
                choice = 3 / choice;
            break;

        // Enter
        case 13:
            switch (choice)
            {
            case 1:
                cin >> val;
                enqueue(l, val);
                break;
            case 2:
                dequeue(l);
                break;
            case 3:
                if (front(l) == -1)
                    cout << "No front!" << endl;
                else
                    cout << front(l) << endl;
                break;
            case 0:
                return 0;
                break;
            default:
                break;
            }
            system("pause");
            break;

        default:
            break;
        }
    } while (true);
    return 0;
}