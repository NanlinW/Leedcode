//https://leetcode-cn.com/problems/coin-change/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> res(amount + 1);
		res[0] = 0;
		for (int i = 1; i <= amount; i++)
		{
			res[i] = INT_MAX;
			for (int j = 0; j < coins.size(); j++)
			{
				if (i >= coins[j] && res[i - coins[j]] != INT_MAX)
				{
					res[i] = min(res[i - coins[j]] + 1, res[i]);
				}
			}
		}
		if (res[amount] == INT_MAX)
		{
			res[amount] = -1;
		}
		return res[amount];
	}
};

int main()
{
	Solution s;
	vector<int> v = { 2,5,7 };
	int res = s.coinChange(v, 27);
	cout << res << endl;
	return 0;
}

