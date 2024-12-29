#include<iostream>
#include<conio.h>

using namespace std;

struct Node {
    int val;
    Node* next;
};

struct Stack {
    Node* head;
};

Node* makeNode(int val) {
    Node* temp = new Node;
    temp->val = val;
    temp->next = NULL;
    return temp;
}

void push(Stack &st, int val) {
    if (st.head == NULL) {
        st.head = makeNode(val);
    } else {
        Node* curNode = makeNode(val);
        curNode->next = st.head;
        st.head = curNode;
    }
}

void pop(Stack &st) {
    if (st.head == NULL) {
        cout << "can't pop cause this stack is empty!" << endl;
    } else {
        st.head = st.head->next;
    }
} 

int top(Stack st) {
    if (st.head == NULL) 
        return 1;
    return st.head->val;
}

int main() {
int choice = 1;
    Stack st;
    st.head = NULL;
    int val;
    do
    {
        system("cls");

        cout << ((choice == 1) ? ">> " : "   ") << "1. push" << endl;
        cout << ((choice == 2) ? ">> " : "   ") << "2. pop" << endl;
        cout << ((choice == 3) ? ">> " : "   ") << "3. top" << endl;
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
                push(st, val);
                break;
            case 2:
                pop(st);
                break;
            case 3:
                if (top(st) == 1)
                    cout << "No top!" << endl;
                else
                    cout << top(st) << endl;
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