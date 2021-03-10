#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int dex = 0, tmp=0;
        while (dex < nums.size())
        {
            if (nums[dex] != 0)
            {
                swap(nums[dex], nums[tmp]);
                tmp++;
            }
            dex++;
        }
        for (auto e : nums)
        {
            cout << e;
        }
    }
};

int main()
{
    vector<int> nums = { 0,1,0,3,12 };
    Solution s;
    s.moveZeroes(nums);
    return 0;
}