#include <stdio.h>

struct EV
{
	int result;
	int n;
};

struct EV evaluate(char* x)
{
	struct EV ev = { 0,0 };
	struct EV v1;
	struct EV v2;

	if (*x == 0) return ev;

	if (x[0] >= '0' && x[0] <= '9')
	{
		ev.result = x[0] - '0';
		ev.n = 1;
		return ev;
	}

	v1 = evaluate(x + 1);
	v2 = evaluate(x + 1 + v1.n);

	if (x[0] == '+')
	{
		ev.result = v1.result + v2.result;
	}
	if (x[0] == '-')
	{
		ev.result = v1.result - v2.result;
	}
	if (x[0] == '*')
	{
		ev.result = v1.result * v2.result;
	}
	ev.n = 1 + v1.n + v2.n;

	return ev;
}

int main()
{
	char s[] = {"-+3*5+261"};
	EV res = evaluate(s);
	printf("%d %d", res.result, res.n);
	return 0;
}
