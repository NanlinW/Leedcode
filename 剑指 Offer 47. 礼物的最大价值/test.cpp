#include <iostream>
#include <vector>
using namespace std;
//确定状态：假设走了n步，当前走到第n步得到礼物的最大价值为 n-1步的最大礼物价值 + 当前礼物价值
//转移方程： dp[i][j] 代表在棋盘上grid[j][j]处所拿到的最大礼物价值
//          dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
//初始值：dp[0][0] = grid[0][0];
//
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m);
        for (int i = 0; i < m; i++)
        {
            dp[i].resize(n, 0);
        }
        dp[0][0] = grid[0][0];
        for (int i = 1; i < n; i++)
        {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < m; i++)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v = { {1,3,1},{1,5,1},{4,2,1} };
    int res = s.maxValue(v);
    cout << res << endl;
    return 0;
}