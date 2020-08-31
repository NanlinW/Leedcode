#include <stdio.h>

void hanoi(int i, char A, char B, char C);
void move(int i, char x, char y);

int main(void)
{
	int n;
	printf("������n��ֵ��");
	scanf("%d", &n);

	hanoi(n, 'A', 'B', 'C');

	return 0;
}

void hanoi(int i, char A, char B, char C)
{
	if (i > 0)
	{
		hanoi(i - 1, A, C, B);   //�����ݹ����
		move(i, A, C);
		hanoi(i - 1, B, A, C);
	}
}

void move(int i, char x, char y)
{
	static int c = 1;   //�ֲ�����i����Ϊ static
	printf("%d: %d from %c ����> %c \n", c++, i, x, y);
}