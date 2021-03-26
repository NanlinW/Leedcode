//假设现在把长度为n的绳子剪成m段乘积最大
//确定状态：最后一段长度为x，前m-1段(长度n - x))绳子的最大乘积 乘上最后一段绳子长度x
//转移方程：dp[i]代表长度为i的绳子得到的最大长度
//          dp[i] = max{max(dp[i - x] * x, x * (i - x)), dp[i]} （1 <= x < i）
//初始条件： dp[2] = 1
//边界条件：最后一段绳子长度x，一定是大于等于1，小于当前绳子长度i的
class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1, 0);
        dp[2] = 1;//用不到dp[0],dp[1]
        for (int i = 3; i <= n; i++)
        {
            for (int x = 1; x < i; x++)
            {
                dp[i] = max(max(dp[i - x] * x, x * (i - x)), dp[i]);
            }
        }
        return dp[n];
    }
};