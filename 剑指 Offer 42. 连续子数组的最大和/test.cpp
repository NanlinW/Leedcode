#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len + 1);
        dp[0] = nums[0];
        int max = dp[0];
        //×ªÒÆ·½³Ìdp[i] = max{dp[i - 1] + nums[i], nums[i]}
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
            if (dp[i] > max)
            {
                max = dp[i];
            }
        }

        return max;
    }
};