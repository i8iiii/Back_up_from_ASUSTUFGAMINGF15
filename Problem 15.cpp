//Problem 15
//URL: https://leetcode.com/problems/search-insert-position/
//Level: Easy
//Last updated: 2024/11/19
/*Description: According to this problem, we have to find the index of the target in given array, if we can't find the target number, 
we have to find where it should be put.*/
/*Example:    

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2
Explanation: the index of 5 in array is 2, so print out 2.

Example 2:
Input: nums = [1,6,7,12], target = 5
Output: 1
Explanation: 1 < target < 6 --> 5 should be put at index 2, so print out 1.

Example 3:
Input: nums = [1,6,7,12,20], target = 30
Output: 5
Explanation: 20 < target--> 30 should be put at index 5, so print out 5.
*/

//Solution in C++ language
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        nums.push_back(target);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] >= nums[j])
                    swap(nums[i], nums[j]);    
            } 
        }
        for (int i = 0 ; i < n; i++) {
            if (nums[i] == target)
                return i;
        }
    return 0;
    }
};