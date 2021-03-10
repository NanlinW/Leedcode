#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        int dex = 0;
        for (int i = 0; i < n; i++)
        {
            dex = (nums[i] - 1) % n;
            nums[dex] += n;
        }
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= n)
            {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 2,2};
    vector<int> res = s.findDisappearedNumbers(nums);
    for (auto e : res)
    {
        cout << e;
    }
    return 0;
}