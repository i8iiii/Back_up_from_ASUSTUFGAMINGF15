//Problem 20
//URL: https://leetcode.com/problems/sum-in-a-matrix/
//Level: Medium
//Last updated: 2024/11/25
/*Description: According to this problem, we sort the row of the matrix in desending order, then we find the sum of the max numbers of each column.
/*Example:    

Example 1:
Input: nums = [[7,2,1],[6,4,2],[6,5,3],[3,2,1]]
Output: 15
Explanation: In the first operation, we remove 7, 6, 6, and 3. We then add 7 to our score. 
Next, we remove 2, 4, 5, and 2. We add 5 to our score. Lastly, we remove 1, 2, 3, and 1.
We add 3 to our score. Thus, our final score is 7 + 5 + 3 = 15.

Example 2:
Input: nums = [[7,5,1],[6,12,2],[6,5,1],[3,2,12],[22,16,77]]
Output: 115
Explanation: In the first operation, we remove 7, 6, 6, 3 and 22. We then add 22 to our score. 
Next, we remove 5, 12, 5, 2 and 16. We add 16 to our score. 
Lastly, we remove 1, 2, 1, 12 and 77.
We add 7 to our score. Thus, our final score is 22 + 16 + 77 = 115.

Example 3:
Input: nums = []
Output: 0
Explanation: Because the matrix is empty, so we return 0.
*/
//Solution in C++ language
class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int col = nums.size();
        int row = nums[0].size();
        int score = 0;
        if (col == 0) return 0;
        for (int i = 0; i < col; i++) {
            sort(nums[i].begin(), nums[i].end());
        }
        for (int i = 0; i < row; i++) {
            int max = nums[0][i];
            for (int j = 1; j < col; j++) {
                if (max < nums[j][i]) {
                    max = nums[j][i];
                }
            }
            score += max;
        }
    return score;
    }
};