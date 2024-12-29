#include <iostream> 
using namespace std;

void innit(int** &ma, int row, int col) {
    ma = new int*[row];
    for (int i = 0; i < row; ++i) {
        ma[i] = new int[col];
        for (int j = 0; j < col; ++j) {
            cin >> ma[i][j];
        }
    }
}
void printMatrix(int** ma, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; ++j) {
            cout << ma[i][j] << ' ';
        }
        cout << '\n';
    }
}
void deleteMatrix(int** ma, int row) {
    for (int i = 0; i < row; ++i)
        delete[] ma[i];
}

struct SubArray {
   int* src = nullptr;
   int start = 0;
   int end = 0;
   int sum = 0;

   void display() {
      for (int i = start; i <= end; ++i)
      cout << src[i] << ' ';
   }
};
SubArray maximumSubArray(int* arr, int size) {
   int local_sum = 0, max = -10000;
   int start = 0, end = 0;

   for (int i = 0; i < size; i++) {
      for (int j = i; j < size; j++) {
         local_sum += arr[j];
         if (local_sum > max) {
            max = local_sum;
            start = i;
            end = j;
         }
      }
      local_sum = 0;
   }
   return {arr, start, end, max};
}
void addArray (int* des, int* src, int size) {
   for (int i = 0; i < size; ++i)
      des[i] += src[i];
}

void maximumSubmatrix(int** ma, int row, int col) {
/*
2 −4 −5 2 −5
7 −7 3 2 −4
3 −6 −4 5 −3
5 5 3 7 1
*/  
    int max = -10000;
    int up = 0, down = 0, left = 0, right = 0;
    for (int i = 0; i < row; ++i) {
        int* arr = new int[col];
        for (int i = 0; i < col; ++i)
            arr[i] = 0;

        
        for (int j = i; j < row; ++j) {
            addArray(arr, ma[j], col);
            SubArray MSA = maximumSubArray(arr, col);
            if (MSA.sum > max) {
                max = MSA.sum;
                up = i, down = j;
                left = MSA.start; right = MSA.end;
            }
        }
    }
    for (int i = up; i <= down; ++i) {
        for (int j = left; j <= right; ++j) {
            cout << ma[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    int row, col;
    cout << "Row = " ; cin >> row;
    cout << "Col = " ; cin >> col;
    int** ma = nullptr;
    innit(ma,row,col);
    cout << "Matrix with maximum sum: \n";
    maximumSubmatrix(ma, row, col);
    deleteMatrix(ma,row);
}