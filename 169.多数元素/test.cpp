//≈≈–Ú∑®
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int len = nums.size();
		sort(nums.begin(), nums.end());
		return nums[len / 2];
	}
};

//Boyer-MooreÕ∂∆±À„∑®
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int candidate = -1;
		int count = 0;
		for (int num : nums) {
			if (num == candidate)
				++count;
			else if (--count < 0) {
				candidate = num;
				count = 1;
			}
		}
		return candidate;
	}
};
