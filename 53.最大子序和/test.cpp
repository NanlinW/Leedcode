class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		vector<int> dp(nums.size(), 0);
		int max = nums[0];
		dp[0] = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			if (dp[i - 1] + nums[i] > nums[i])
			{
				dp[i] = dp[i - 1] + nums[i];
			}
			else
			{
				dp[i] = nums[i];
			}
			if (dp[i] > max)
			{
				max = dp[i];
			}
		}
		return max;
	}
};