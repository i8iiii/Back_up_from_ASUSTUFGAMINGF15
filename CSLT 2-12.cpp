#include<iostream>
#include<cmath>

struct Node {
    int val;
    Node *next;
};

struct List {
    Node *head;
};

void init(List &l) {
    l.head = NULL;
}

Node* createNode(int val) {
    Node* temp = new Node;
    temp->val = val;
    temp->next = NULL;
    return temp;
}

void deleteAll(List &l) {
    Node* curNode = l.head;
    while (curNode != NULL) {
        delete l.head;
        curNode = curNode->next;
        l.head = curNode;
    }
}

void addHead(List &l, int val) {
    if (l.head == NULL) {
        Node* curNode = createNode(val);
        l.head = curNode;
    } else {
        Node* curNode = createNode(val);
        curNode->next = l.head;
        l.head = curNode;
    }
}

void AddTail(List &l, int val) {
    if (l.head == NULL)
        addHead(l, val);
    else {
        Node* curNode = l.head;
        while (curNode->next) {
            curNode = curNode->next;
        }
        curNode->next = createNode(val);
    }
}

void printlist(const List &l) {
    Node* curNode = l.head;
    while (curNode != NULL) {
        std::cout << curNode->val << " ";
        curNode = curNode->next;
    }
    std::cout << "\n";
}

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n == 2) return true;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void delHead(List &l) {
    if (l.head == NULL) {
        return;
    } else {
        l.head = l.head->next;
    }
}

// void deletePrimes(List &l) {
//     Node *node = l.head;
//     while (node) {
//         Node *curNode = l.head;
//         if (l.head == NULL) 
//             return;

//         if (l.head->next == NULL && isPrime(l.head->val)) {
//             delHead(l);
//             return;
//         }

//         if (isPrime(l.head->val)) {
//             delHead(l);
//         } 
        
//         if (isPrime((curNode->next->val))) {
//             Node *tmp = curNode->next;
//             curNode->next = curNode->next->next;
//             delete tmp;
//         } else {
//             curNode = curNode->next;
//         }

//         node = node->next;
//     }
// }

List noPrimes(List &l) {
    List res;
    res.head = NULL;
    Node* curNode = l.head;
    while (curNode) {
        if (!isPrime(curNode->val))
            AddTail(res, curNode->val);
        curNode = curNode->next;
    }
    deleteAll(l);
    return res;
}

int main() {
    List l;
    init(l);
    addHead(l, 5);
    addHead(l, 7);
    addHead(l, 4);
    addHead(l, 13);
    printlist(l);
    printlist(noPrimes(l));
    deleteAll(l);
    return 0;
}