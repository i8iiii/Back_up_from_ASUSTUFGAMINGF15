//Problem 17
//URL: https://leetcode.com/problems/remove-element/
//Level: Easy
//Last updated: 2024/11/20
/*Description: According to this problem, we have to erase the elements that equal to given value in given array, 
then we find the k number which presents for the rest elements and return k when function is done.

Custom Judge:
The judge will test your solution with the following code:
int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.
int k = removeElement(nums, val); // Calls your implementation                       //explain how function is used
assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted..*/

/*Example:    

Example 1:
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:
Input: nums = [3,2,1,0,12,2,3], val = 2
Output: 5, nums = [3,1,0,12,3]
Explanation: Your function should return k = 5, with the rest elements of nums being 3, 1, 0, 12, 3.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 3:
Input: nums = [4,2,4,4,2,0,6], val = 4
Output: 4, nums = [2,2,0,6]
Explanation: Your function should return k = 4, with the rest elements of nums being 2, 2, 0, 6.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/

//Solution in C++ language
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == val)
                count++; 
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == val)
                    swap(nums[i], nums[j]);
            }
        }
    return n - count;
    }
};