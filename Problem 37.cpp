//Problem 37
//URL: https://leetcode.com/problems/transpose-matrix/
//Level: Easy
//Last updated: 2024/12/18
/*Description: According to this problem, we have to transpose the given matrix by swap the columns and the rows.
Example:    

Example 1:
Input: matrix = [[1,2,3],
                 [4,5,6],
                 [7,8,9]]
Output: [[1,4,7],
         [2,5,8],
         [3,6,9]]

Example 2:
Input: matrix = [[1,2],
                 [5,1],
                 [9,5]]
Output: [[1,5,9],
         [2,1,5]]

Example 3:
Input: matrix = [[3,0,1,4],
                 [5,6,2,7],
                 [1,3,7,2]]
Output: [[3,5,1],
         [0,6,3],
         [1,2,7],
         [4,7,2]]

Solution in C++ language
 */
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> res(n, vector<int> (m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = matrix[j][i];
            }
        }
    return res;
    }
};