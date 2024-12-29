#include<iostream>
#include<vector>

using namespace std;

void findDiff(vector<int> &a) {
    for (int i = 0; i < a.size() - 1; i++) {
        for (int j = i + 1; j < a.size(); j++) {
            if (a[i] == a[j]) {
                a.erase(a.begin() + j);
                j--;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; 
    vector<int> input(n);
    vector<int> input1(m);

    for (int i = 0; i < n; i++) {               
        cin >> input[i];                                  
    }

    for (int i = 0; i < m; i++) {
        cin >> input1[i];
    }

    findDiff(input);
    findDiff(input1);
    int i = 0; j = 0;
    while (i < n && j < m) {
        if (input[i] == input1[j]) {
            
        }
    }
    return 0;
}