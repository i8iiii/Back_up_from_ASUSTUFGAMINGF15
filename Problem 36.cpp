//Problem 36
//URL: https://leetcode.com/problems/toeplitz-matrix/
//Level: Easy
//Last updated: 2024/12/18
/*Description: According to this problem, we have to check if the given matrix is toeplitz matrix. 
If all elements in them same diagonal have the same value, we return true, if not, we return false.
Example:    

Example 1:
Input: matrix = [[1,2,3,4],
                 [5,1,2,3],
                 [9,5,1,2]]
Output: true
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.

Example 2:
Input: matrix = [[1,2],
                 [5,1],
                 [9,5]]
Output: true
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1]", "[2]".
In each diagonal all elements are the same, so the answer is True.

Example 3:
Input: matrix = [[3,4],
                 [5,3],
                 [1,2]]
Output: true
Explanation:
In the above grid, the elements of the diagonal start from matrix[1][0] don't equal to each other. So the answer is False.

Solution in C++ language
 */
class Solution {
public:
    bool isDiagonal(vector<vector<int>>& matrix, int i, int j) {
        int m = matrix[0].size();
        int n = matrix.size();
        int res = matrix[i][j];
        while (++i < n && ++j < m) { //check all the elements on the same diagonal
            if (matrix[i][j] != res)
                return false;
        }
    return true;
    }
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix[0].size();
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            if (!isDiagonal(matrix, i, 0)) //check the first row
                return false;
        }

        for (int i = 1; i < m; i++) {
            if (!isDiagonal(matrix, 0, i)) //check the first column
                return false;
        }
    return true;
    }
};