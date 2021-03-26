//�������ڰѳ���Ϊn�����Ӽ���m�γ˻����
//ȷ��״̬�����һ�γ���Ϊx��ǰm-1��(����n - x))���ӵ����˻� �������һ�����ӳ���x
//ת�Ʒ��̣�dp[i]������Ϊi�����ӵõ�����󳤶�
//          dp[i] = max{max(dp[i - x] * x, x * (i - x)), dp[i]} ��1 <= x < i��
//��ʼ������ dp[2] = 1
//�߽����������һ�����ӳ���x��һ���Ǵ��ڵ���1��С�ڵ�ǰ���ӳ���i��
class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1, 0);
        dp[2] = 1;//�ò���dp[0],dp[1]
        for (int i = 3; i <= n; i++)
        {
            for (int x = 1; x < i; x++)
            {
                dp[i] = max(max(dp[i - x] * x, x * (i - x)), dp[i]);
            }
        }
        return dp[n];
    }
};