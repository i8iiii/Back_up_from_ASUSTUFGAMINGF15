#include<iostream>
#include<conio.h>

using namespace std;

struct Node {
    int val;
    Node* next;
};

struct List {
    Node* head;
};

void Traversalnodes(List l) {
    Node* curNode = l.head;
    while (curNode) {
        cout << curNode->val << " ";
        curNode = curNode->next;
    }
}

void SearchNodes(List l, int val) {
    Node* curNode = l.head;
    int count = 0;
    while (curNode) { 
        if (curNode->val == val) {
            cout << "The node with value " << val << " is found in this list." << endl;
            count++;
            break;
        } 
        curNode = curNode->next;
    }
    if (count == 0)
        cout << "There is no node with the value " << val << " in this list." << endl;
}

void CheckForEmpiness(List l) {
    if (l.head == NULL) {
        cout << "This list is empty!" << endl;
    } else {
        cout << "This list is not empty!" << endl;
    }
}

int CountNodes(List l) {
    Node* curNode = l.head;
    int count = 0;
    while (curNode) {
        count++;
        curNode = curNode->next;
    }
    return count;
}

Node* makeNode(int val) {
    Node* temp = new Node;
    temp->val = val;
    temp->next = NULL;
    return temp;
}

void AddHead(List &l, int val) {
    if (l.head == NULL) {
        l.head = makeNode(val);
    } else {
        Node* temp = makeNode(val);
        temp->next = l.head;
        l.head = temp;
    }

}

void AddTail(List &l, int val) {
    if (l.head == NULL)
        AddHead(l, val);
    Node* curNode = l.head;
    Node* temp = makeNode(val);
    while (curNode->next) {
        curNode = curNode->next;
    } 
    curNode->next = temp;
}

void DeleteHead(List &l) {
    l.head = l.head->next;
}

void DeleteTail(List &l) {
    Node* curNode = l.head;
    while (curNode->next->next) {
        curNode = curNode->next;
    }
    curNode->next = curNode->next->next;
}

void RemoveDuplicate(List &l) {
    Node* curNode = l.head;
    int count = 0;
    while (curNode) {
        Node* temp = curNode->next;
        Node* prev = curNode;
        while (temp) {
            Node* save = temp;
            if (save->val == curNode->val) {
                prev->next = save->next;
                count++;
            } else {
                prev = prev->next;
            }
            temp = temp->next;
        }
        curNode = curNode->next;
    }
    if (count == 0)
        cout << "There are no duplicates!" << endl;
    else 
        cout << "Duplicates have been removed!" << endl;
}

int main() {
    int choice = 1;
    List l;
    l.head = NULL;
    int val;
    do
    {
        system("cls");

        cout << ((choice == 1) ? ">> " : "   ") << "1. Traversal nodes" << endl;
        cout << ((choice == 2) ? ">> " : "   ") << "2. Search nodes" << endl;
        cout << ((choice == 3) ? ">> " : "   ") << "3. Check for emptiness" << endl;
        cout << ((choice == 4) ? ">> " : "   ") << "4. Count nodes" << endl;
        cout << ((choice == 5) ? ">> " : "   ") << "5. Add head" << endl;
        cout << ((choice == 6) ? ">> " : "   ") << "6. Add tail" << endl;
        cout << ((choice == 7) ? ">> " : "   ") << "7. Remove head" << endl;
        cout << ((choice == 8) ? ">> " : "   ") << "8. Remove tail" << endl;
        cout << ((choice == 9) ? ">> " : "   ") << "9. Remove duplicate" << endl;
        cout << ((choice == 0) ? ">> " : "   ") << "0. Exit" << endl;

        char key;
        key = getch();

        switch (key)
        {
        // Up
        case 72:
            choice--;
            if (choice == -1)
                choice = 9;
            break;

        // Down
        case 80:
            choice++;
            if (choice == 10)
                choice = 9 / choice;
            break;

        // Enter
        case 13:
            switch (choice)
            {
            case 1:
                if (l.head == NULL) {
                    cout << "This list is empty!" << endl;
                } else {
                    cout << "Showing list: ";
                    Traversalnodes(l);
                    cout << endl;
                }
                break;
            case 2:
                cout << "Type the value of node: ";
                cin >> val;
                if (l.head == NULL) {
                    cout << "We can't find the node you want cause this list is empty!" << endl;
                } else {
                    SearchNodes(l, val);
                }
                break;
            case 3:
                CheckForEmpiness(l);
                break;
            case 4:
                cout << "The number of nodes is: " << CountNodes(l) << endl;
                break;
            case 5:
                cout << "Please type the node: ";
                cin >> val;
                AddHead(l, val);
                break;
            case 6:
                cout << "Please type the node: ";
                cin >> val;
                AddTail(l, val);
                break;
            case 7:
                if (l.head == NULL) {
                    cout << "We can't remove head cause this list is empty!" << endl;
                } else {
                    DeleteHead(l);
                    cout << "Removed!" << endl;
                }
                break;
            case 8:
                if (l.head == NULL) {
                    cout << "We can't remove tail cause this list is empty!" << endl;
                } else {
                    DeleteTail(l);
                    cout << "Removed!" << endl;
                }
                break;
            case 9:
                if (l.head == NULL || l.head->next == NULL) {
                    cout << "Can't find duplicates!" << endl;
                } else {
                    RemoveDuplicate(l);
                }
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