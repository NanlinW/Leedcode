//ȷ��״̬�� �����x����������ô���һ����ǰx-1���������� + prices[i] - prices[i-1]
//          �����⣺��ֻ��Ʊ��ǰx-1�����������������
//ת�Ʒ��̣� dp[i] ��ʾ��i���ܵõ����������
//          dp[i] = max{dp[i-1] + prices[i] - prices[i-1], dp[i]}
//��ʼֵ�ͱ߽�������dp[0] = 0 ��һ����Ȼ��ֱ����������Ϊ0

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