class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        vector<int> st;
        prices.push_back(-1);
        for (int i = 0; i < prices.size(); i++)
        {
            while (!st.empty() && prices[i] < st.back())
            {
                ans = max(ans, st.back() - st.front());
                st.pop_back();
            }
            st.push_back(prices[i]);
        }

        return ans;

    }
};