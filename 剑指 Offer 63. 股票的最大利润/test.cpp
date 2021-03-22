//确定状态： 假设第x天卖出，那么最后一步是前x-1天的最大利润 + prices[i] - prices[i-1]
//          子问题：这只股票在前x-1天能卖出的最大利润
//转移方程： dp[i] 表示第i天能得到的最大利润
//          dp[i] = max{dp[i-1] + prices[i] - prices[i-1], dp[i]}
//初始值和边界条件：dp[0] = 0 第一天买然后直接卖，利润为0

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size() + 1);
        dp[0] = 0;
        int MAX = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i] = max(dp[i - 1] + prices[i] - prices[i - 1], dp[i]);
            if (dp[i] > MAX)
            {
                MAX = dp[i];
            }
        }
        return MAX;

    }
};