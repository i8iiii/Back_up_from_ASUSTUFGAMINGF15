//Problem 11
//URL: https://leetcode.com/problems/two-sum/
//Level: Easy
//Last updated: 2024/11/17
//Description: According to this problem, we have to calculate the sum of two elemnts that equal to target which is an input number.
/*Example:

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [1,2,4], target = 3
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 3, we return [0, 1].

Example 3:
Input: nums = [4,3], target = 4
Output: [0]
Explanation: Because nums[0] == 4, we return [0].

*/   
//Solution in C++ language
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                return {i,j};
                }
            }
        }
    return {};
    }
};
