//Problem 19
//URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/?envType=problem-list-v2&envId=dynamic-programming
//Level: Easy
//Last updated: 2024/11/24
/*Description: According to this problem, we find the max profit we make when buy and sell a given stock.
/*Example:    

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:
Input: prices = [3,2,6,5,0,3]
Output: 4
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.

Example 2:
Input: prices = [3,3,3,3,3,3]
Output: 0
Explanation: Because the price is still the same within 6 days, so the profit will be 0.
*/
//Solution in C++ language
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int min = prices[0];
        int max = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (min > prices[i])
                min = prices[i];

            int profit = prices[i] - min;

            if (max < profit)
                max = profit;

        }
    return max;
    }
};
