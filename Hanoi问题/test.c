#include <stdio.h>

void hanoi(int i, char A, char B, char C);
void move(int i, char x, char y);

int main(void)
{
	int n;
	printf("请输入n的值：");
	scanf("%d", &n);

	hanoi(n, 'A', 'B', 'C');

	return 0;
}

void hanoi(int i, char A, char B, char C)
{
	if (i > 0)
	{
		hanoi(i - 1, A, C, B);   //函数递归调用
		move(i, A, C);
		hanoi(i - 1, B, A, C);
	}
}

void move(int i, char x, char y)
{
	static int c = 1;   //局部变量i申明为 static
	printf("%d: %d from %c ——> %c \n", c++, i, x, y);
}