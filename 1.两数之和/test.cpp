#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int right = 0, left, temp = 0;
        while (right < nums.size())
        {
            left = right + 1;
            while (left < nums.size()-1 && nums[right] + nums[left] != target)
            {
                left++;
            }
            if (nums[right] + nums[left] == target)
            {
                break;
            }
            right++;
        }
        vector<int> res;
        res.push_back(right);
        res.push_back(left);

        return res;

    }
};

int main()
{
    Solution s;
    vector<int> sum = { 2,5,5,11 };
    vector<int> res = s.twoSum(sum, 10);
    for (auto e : res)
    {
        cout << e;
    }
    return 0;
}