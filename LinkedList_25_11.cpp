#include<iostream>
#include<cmath>
#include<cstring>

struct Node {
    int val;
    Node *next;
};

struct List {
    Node *pHead;
};

void init(List &l) {
    l.pHead = NULL;
}

Node* createNode(int val) {
    Node* temp = new Node;
    temp->val = val;
    temp->next = NULL;
    return temp;
}

void addHead(List &l, int val) {
    if (l.pHead == NULL) {
        Node* curNode = createNode(val);
        l.pHead = curNode;
    } else {
        Node* curNode = createNode(val);
        curNode->next = l.pHead;
        l.pHead = curNode;
    }
}

void addTail(List &l, int val) {
     if (l.pHead == NULL) {
        l.pHead = createNode(val);
    } else {
        Node* curNode = l.pHead;
        while (curNode->next != NULL) {
            curNode = curNode->next;
        }
        curNode->next = createNode(val);
    }
}

void insert(List &l, int pos, int val) {
    Node* newNode = createNode(val);
    Node* curNode = l.pHead;
    int count = 1;
    if (pos < 0) {
        std::cout << "Invalid Position!";
        curNode = NULL;
    }
    if (l.pHead == NULL) {
        l.pHead = newNode;
    } else {
        while (count < pos) {
            curNode = curNode->next;
            count++;
        }
        newNode->next = curNode->next;
        curNode->next = newNode;
    }  
}

void printlist(const List &l) {
    Node* curNode = l.pHead;
    while (curNode != NULL) {
        std::cout << curNode->val << " ";
        curNode = curNode->next;
    }
    std::cout << "\n";
}

void deleteAll(List &l) {
    Node* curNode = l.pHead;
    while (curNode != NULL) {
        delete l.pHead;
        curNode = curNode->next;
        l.pHead = curNode;
    }
}

void delHead(List &l) {
    if (l.pHead == NULL) {
        std::cout << "Can't delete this node";
    } else {
        l.pHead = l.pHead->next;
    }
}

void delTail(List &l) {
    Node* curNode = l.pHead;
    if (curNode->next == NULL) {
        delHead(l);
    } else {
        while (curNode->next->next) {
            curNode = curNode->next;
        }
        Node* temp = curNode->next;
        curNode->next = curNode->next->next;
        delete temp;
    }
}

void delPos(List &l, int pos) {
    Node* curNode = l.pHead;
    int count = 1;
    if (pos == 0) {
        delHead(l);
    }
    if (l.pHead == NULL) {
        return;
    } else {
        while (count < pos) {
            curNode = curNode->next;
            count++;
        }
        Node* temp = curNode->next;
        curNode->next = temp->next;
        delete temp;
    }
}

void sort(List &l) {
    for (Node* i = l.pHead; i != NULL; i = i->next) {
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (j->val < i->val) {
                int temp = i->val;
                i->val = j->val;
                j->val = temp;
            }
        }
    }
}

void RemoveDuplicate(List &l) {
    Node* curNode = l.pHead;
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

int main() {    
    List l;
    l.pHead = NULL;
    addHead(l, 3);
    addHead(l, 3);
    addHead(l, 3);
    addTail(l, 3);
    insert(l, 2, 5);
    printlist(l);
    delTail(l);
    RemoveDuplicate(l);
    delPos(l, 1);
    printlist(l);
    deleteAll(l);
    return 0;
}