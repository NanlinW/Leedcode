class Solution {
public:
	/**
	 * 进制转换
	 * @param M int整型 给定整数
	 * @param N int整型 转换到的进制
	 * @return string字符串
	 */
	string solve(int M, int N) {
		// write code here
		string t = "0123456789ABCDEF";
		string s;
		if (M == 0)
		{
			return "0";
		}
		int flag = 1;
		if (M < 0)
		{
			flag = -1;
			M = -M;
		}
		while (M != 0)
		{
			s.push_back(t[M % N]);
			M = M / N;
		}
		if (flag < 0)
		{
			s.push_back('-');
		}
		reverse(s.begin(), s.end());
		return s;
	}
};