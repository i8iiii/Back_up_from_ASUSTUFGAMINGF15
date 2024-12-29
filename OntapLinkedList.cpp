#include<iostream>
#include<fstream>

using namespace std;

struct Node {
    int val;
    Node* next;
};

struct List {
    Node* head;
};

Node* makeNode (int val) {
    Node* temp = new Node;
    temp->val = val;
    temp->next = NULL;
    return temp;
}

void printlist(const List &l) {
    Node* curNode = l.head;
    while (curNode) {
        std::cout << curNode->val << " ";
        curNode = curNode->next;
    }
    std::cout << "\n";
}

void AddHead(List &l, int val) {
    Node* newNode = makeNode(val);
    newNode->next = l.head;
    l.head = newNode;
}

void AddTail(List &l, int val) {
    if (l.head == NULL) {
        l.head = makeNode(val);
    } else {
        Node* curNode = l.head;
        while (curNode->next) {
            curNode = curNode->next;
        }
        curNode->next = makeNode(val);
    }
}

void removeVal(List &l, int val) {
    while (l.head->val == val && l.head) {
        Node* temp = l.head;
        l.head = l.head->next;
        delete temp;
    }

    if (l.head == NULL) return;

    Node* curNode = l.head;
    while (curNode->next) {
        if (curNode->next->val == val) {
            Node* trash = curNode->next;
            curNode->next = curNode->next->next;
            delete trash;
        } else {
            curNode = curNode->next;
        }
    } 
}

void reverseLinkedList(List &l) {
    if (l.head == NULL) return;
    if (l.head->next == NULL) return;

    Node* curNode = l.head;
    while (curNode->next) {
        Node* temp = curNode->next;
        curNode->next = curNode->next->next;
        temp->next = l.head;
        l.head = temp;
    }
}

void addEven(List &l1) {
    if (l1.head == NULL)
        return;
    Node* l1node = l1.head;
    int sochan = 2;

    while (l1node->next) {
        sochan += 2;
        Node* temp = new Node{sochan, nullptr};
        
        Node* hold = l1node;
        l1node = l1node->next;
        hold->next = temp;
        temp->next = l1node;
    }
    
    Node* temp = new Node{2, l1.head};
    l1.head = temp;
    
}

void addInOrder(List &l, int val) {
    Node* add = new Node{val, NULL};

    if (add->val < l.head->val) {
        add->next = l.head;
        l.head = add;
    }
    
    Node* prev = l.head;
    while (prev) {
        Node* temp = prev->next;
        if (temp == NULL && prev->val < add->val) {
            prev->next = add;
            return;
        }
        if (add->val < temp->val) {
            prev->next = add;
            add->next = temp;
            return;
        }
        prev = prev->next;
    }
}

List sum(List l) {
    List newList;
    newList.head = NULL;
    Node* curNode = l.head;
    int sum = 0;

    while (curNode) {
        sum += curNode->val;
        AddTail(newList, sum);
        curNode = curNode->next;
    }

    return newList;
}

void split(List &l) {
    Node* curNode = l.head;

    List evens; List odds;
    odds.head = curNode;
    evens.head = curNode->next;

    Node* even = evens.head;
    Node* odd = odds.head;

    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = NULL;
    even->next = NULL;

    Node* node = odds.head;
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }

    cout << endl;

    Node* node1 = evens.head;
    while (node1) {
        cout << node1->val << " ";
        node1 = node1->next;
    }
}

int main() {
    List l1; int val, n, value;
    l1.head = NULL;
    ifstream fin("new.txt");
    ofstream fout("output.txt");

    if (!fin.is_open() || !fout.is_open())
        cout << "Can't open this file";

    fin >> n; fin >> value;

    for (int i = 0; i < n; i++) {
        fin >> val;
        AddTail(l1, val);
    }
    
    printlist(l1);
    split(l1);
   

    fin.close();
    fout.close();
    return 0;
}