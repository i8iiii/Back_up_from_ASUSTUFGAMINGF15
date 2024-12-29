#include<iostream>
#include<cmath>

//Excercise 1
void swap1(int *a, int *b) { 
    int temp = *(a);
    *(a) = *(b);
    *(b) = temp;
}

//Excersice 2
int* sum(int *a, int *b) { 
    int temp = *a + *b;
    int *TEMP = &temp;
    return TEMP;
}

//Exercise 3
void inputArray(int *&a, int &n) {
    std::cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i]; 
    }
}

//Exercise 4
void printArray(int *a, int n) { 
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
}

//Excercise 5
int* findMax(int *arr, int n) { 
    int temp = arr[0];
    int *max = NULL;

    for (int i = 0; i < n; i++) {
        if (temp < arr[i]) {
            temp = arr[i];
        }
    }
    max = &temp;

    return max;
}

//Exercise 6
int* copyArray(int *arr, int n) { 
    int *arr1 = new int[n];
    for (int i = 0; i < n; i++) {
        arr1[i] = arr[i];
    }
    return arr1;
}

 //Exercise 7
int* countEvens(int *arr, int n, int *evens) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) 
            count++;
    }
    evens = &count;

    return evens;                                                                   
}

int* genEvenSubarray(int *arr, int n, int *count) {
    int j = 0;

    int *arr2 = new int [*count];
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            arr2[j] = arr[i];
            j++;
        }
    }

    return arr2;
}

//Exercise 8
int* findLargestTotalSubarray(int *a, int n, int &total, int &length) { 
    int max = INT_MIN;
    int start, end;

    for (int i = 0; i < n; i++) {
        total = a[i];
        for (int j = i + 1; j < n; j++) {
            total += a[j];
            if (max < total) {
                max = total;
                end = j;
                start = i;
            }
        }
    }

    total = max;
    length = end - start + 1;
    int j = 0;

    int *newArr = new int[length];
    for (int i = start; i <= end; i++) {
        newArr[j] = a[i]; 
        j++;
    }

    return newArr;
}

 //Exercise 9
int* findTheLongestAscendingArray(int *a, int n, int &length) {
    int start = 0, curLength = 1, curStart = 0;
    length = 0; 

    for (int i = 0; i < n - 1; i++) {
        if (a[i] < a[i + 1]) {
            curLength++;
            if (length < curLength) {
                length = curLength;
                start = curStart;
            }
        } else {
            curStart = i + 1;
            curLength = 1;
        }
    }

    int *a1 = new int[length];
    int k = 0;
    for (int i = start; i < start + length; i++) {
        a1[k] = a[i];
        k++;
    }

    return a1;
}

 //Exercise 10
void swapArrays (int *&a , int *&b , int &na , int &nb ) {
    int *a1 = new int[na];
    for (int i = 0; i < na; i++) {
        a1[i] = a[i];
    }
    
    int temp = na; 
    na = nb;
    nb = temp;

    for (int i = 0; i < na; i++)
        a[i] = b[i];
    for (int i = 0; i < nb; i++)
        b[i] = a1[i];

    delete []a1;
}

//Exercise 11
int* concatenate2Array(int *a, int *b, int na, int nb) {
    int *array = new int[na + nb];
    int i = 0, j = 0, k = 0; 

    while(i < na) { 
        array[k] = a[i]; 
        k++; i++;
    } 

    while(j < nb) { 
        array[k] = b[j]; 
        k++; j++;
    } 

    return array; 
}

 //Exercise 12
int* merge2Arrays (int* a , int* b , int na , int nb , int &nc) {
    nc = na + nb;
    
    int *c = concatenate2Array(a, b, na, nb);
    for (int i = 0; i < nc; i++) {
        for (int j = i + 1; j < nc; j++) {
            if (c[i] > c[j]) {
                std::swap(c[i], c[j]);
            }
        }
    }

    return c;
}

//Exercise 13
void generateMatrix1 (int **&a, int length, int width) { 
    a = new int* [length];

    for (int i = 0; i < length; i++) {
        a[i] = new int[width];
    }

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            std::cin >> a[i][j];
        }
    }
}

//Exersice 14
int ** generateMatrix2 (int* a, int* b, int na, int nb) { 
    int nc = na * nb;

    int **c = new int* [nc];
    for (int i = 0; i < na; i++) {
        c[i] = new int[nb];
    }

    for (int i = 0; i < na; i++) {
        for (int j = 0; j < nb; j++) {
           c[i][j] = a[i] * b[j];
        }
    }
    return c;
}

//Exercise 15
void swapRows (int ** a, int width , int row1 , int row2) { 
    for (int j = 0; j < width; j++) {
        int temp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = temp;
    }
}

void swapColumns (int ** a , int length, int col1 , int col2 ) {
    for (int j = 0; j < length; j++) {
        int temp = a[j][col1];
        a[j][col1] = a[j][col2];
        a[j][col2] = temp;
    }
}

//Exercise 16
int** transposeMatrix(int** a, int &row, int &col) {
    int temp = row;
    row = col;
    col = temp;

    int** b = new int*[row];
    for (int i = 0; i < row; i++) {
        b[i] = new int[col];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            b[i][j] = a[j][i];
        }
    }
    return b;
}

//Exercise 17
int** concatenate2MatricesH (int ** a , int ** b , int &length , int &width) {
    width *= 2;

    int **c = new int *[length];
    for (int i = 0; i < length; i++) {
        c[i] = new int [width];
    }

    for (int i = 0; i < length; i ++) {
        for (int j = 0; j < width / 2; j++) {
            c[i][j] = a[i][j];
        }
        for (int j = width / 2; j < width; j++) {
            c[i][j] = b[i][j - width / 2];
        }
    }
    return c;
}

int** concatenate2MatricesV (int ** a , int ** b , int &length , int &width) {
    length *= 2;

    int **c = new int *[length];
    for (int i = 0; i < length; i++) {
        c[i] = new int [width];
    }

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < length / 2; j++) {
            c[j][i] = a[j][i];
        }
        for (int j = length / 2; j < length; j++) {
            c[j][i] = b[j - length / 2][i];
        }
    }

    return c;
}

//Execise 18
// bool multiply2Matrices (int ** a, int ** b, int lengtha, int widtha, int lengthb, int widthb, int ** &result) {
    
// }
//Exercise 20
int ** rotateMatrix90Clockwise (int **a , int &length , int &width) {
    int **rotatedMatrix = transposeMatrix(a, length, width);

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width/ 2; j++) {
            int temp = rotatedMatrix[i][j];
            rotatedMatrix[i][j] = rotatedMatrix[i][width - j - 1];
            rotatedMatrix[i][width - j - 1] = temp;
        }
    }

    delete[]transposeMatrix(a, length, width);
    return rotatedMatrix;
}
//Bonus
void printMatrix(int** a, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void deleteMatrix (int **&a, int row) {
    for (int i = 0; i < row; i++) {
        delete a[i];
    }
    delete[] a;
    a = NULL;
}

int main() { 
    int n, length = 0;
    int *a = NULL;
    inputArray(a, n);
    int *p = findTheLongestAscendingArray(a, n, length);
    printArray(p, length);
    return 0;
}