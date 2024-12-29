//Problem 13
//URL: https://leetcode.com/problems/median-of-two-sorted-arrays/
//Level: Hard
//Last updated: 2024/11/17
//Description: According to this problem, we have to calculate the median number of two arrays
//Example:    

//Example 1:
// Sample Input: nums1 = [1,3], nums2 = [2]
// Sample Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.

// Example 2:
// Input: nums1 = [1,5], nums2 = [3,4]
// Output: 3.50000
// Explanation: merged array = [1,3,4,5] and median is (3 + 4) / 2 = 3.5. 

// Example 2:
// Input: nums1 = [1,2,12,7], nums2 = [6,4]
// Output: 2.50000
// Explanation: merged array = [1,2,4,6,7,12] and median is (4 + 6) / 2 = 5. 

//Solution in C++ language
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        for (int i = 0; i < n; i++) {
            nums1.push_back(nums2[i]);
        }
        int z = nums1.size();
        for (int i = 0; i < z; i++) {
            for (int j = i + 1; j < z; j++) {
                if (nums1[i] > nums1[j])
                    swap(nums1[i], nums1[j]);
            }
        }
        double res;
        if (z % 2 == 0)
            res = (nums1[(z - 1) / 2] + nums1[(z - 1)/ 2 + 1]) / 2.0;
        else 
            res = nums1[(z - 1)/ 2];
        return res;
    }
};