class Solution {
public:
	/**
	 * ����ת��
	 * @param M int���� ��������
	 * @param N int���� ת�����Ľ���
	 * @return string�ַ���
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