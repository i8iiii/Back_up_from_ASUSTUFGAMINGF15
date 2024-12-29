#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

bool isPrime(int val) {
    if (val <= 1) 
        return false;
    if (val == 2)
        return true;
    for (int i = 2; i <= sqrt(val); i++) {
        if (val % i == 0)
            return false;
    }
    return true;
}

struct Node {
    int val;
    Node* next;
};

struct List {
    Node* head;
};

Node* makeNode(int val) {
    Node* temp = new Node;
    temp->val = val;
    temp->next = NULL;
    return temp;
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

void printList(List l) {
    Node* curr = l.head;
    ofstream fout("output.txt");
    while (curr) {
        if (curr->next == NULL) {
            cout << curr->val;
            fout << curr->val;
        }
        else {
            cout << curr->val << " ";
            fout << curr->val << " ";
        }
        curr = curr->next;
    }
    fout.close();
}

List combine(List &l) {
    if (l.head == NULL)
        return l;
    List res;
    res.head = NULL;
    Node* curr = l.head;
    Node* sum = new Node{0, NULL};

    while (curr) {
        if (isPrime(curr->val)) {
            sum->val += curr->val;
        } else {
            if (sum->val != 0) 
                AddTail(res, sum->val);
            AddTail(res, curr->val);
            sum->val = 0;
        }
        curr = curr->next;
    }

    if (sum->val != 0) 
        AddTail(res, sum->val);

    delete sum;
    return res;
}

List numToList(long long number) {
    List res;
    res.head = NULL;
    long long temp = number, count = 0;
    while (temp) { 
        temp /= 10;
        count++;
    }
    int n = count;
    for (int i = 0; i < n; i++) {
        int tmp = number / pow(10, count - 1);
        AddTail(res, tmp);
        number -= (pow(10, count - 1) * tmp);
        count--;
    }
    return res;
}

List merge2SortedLists(List l1, List l2) {
    List res;
    res.head = NULL;
    Node* n1 = l1.head;
    Node* n2 = l2.head;

    while (n1 && n2) {
        if (n1->val < n2->val) {
            AddTail(res, n1->val);
            n1 = n1->next;
        } else {
            AddTail(res, n2->val);
            n2 = n2->next;
        }
    }
    Node* temp = res.head;
    while (temp->next) {
        temp = temp->next;
    } 
    if (n1 == NULL) 
        temp->next = n2;
    else 
        temp->next = n1;
    return res;
}

int listToNum(List l) {
    Node* curNode = l.head;
    int number = 0;
    while (curNode) {
        number = 10 * number + curNode->val;
        curNode = curNode->next;
    }
    return number;
}

void sortList(List &l) {
    Node* curr = l.head;
    while (curr) {
        Node* temp = curr;
        while (temp) {
            if (curr->val > temp->val) {
                int tmp = curr->val;
                curr->val = temp->val;
                temp->val = tmp;
            }
            temp = temp->next;
        }
        curr = curr->next;
    }
}

int main() {
    List l;
    int val, n;
    l.head = NULL;

    ifstream fin("new.txt");
    ofstream fout("output.txt");

    if (!fin.is_open() || !fout.is_open())
        cout << "Can't open this file";

    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> val;
        AddTail(l, val);
    }

    printList(l);
    cout << endl;
    sortList(l);
    printList(l);

    fin.close();
    fout.close();
    return 0;
}