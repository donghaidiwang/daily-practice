#define _CRT_SECURE_NO_WARNINGS 1
#define N 1000010
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int judge(int a)
{
	while (a)
	{
		int tmp = a % 16;
		if (tmp >= 10)
		{
			return 0;
		}
		a = a / 16;
	}
	return 1;
}
int main()
{
	int f[N] = { 0 };
	int sum, start, end, i, j;
	for (i = 1; i < N; i++)
	{
		f[i] = f[i - 1];
		f[i] += judge(i);
	}
	scanf("%d", &sum);
	for (i = 0; i < sum; i++)
	{
		scanf("%d %d", &start, &end);
		if (f[start] == f[start - 1])
		{
			printf("%d\n", f[end] - f[start]);
		}
		else
		{
			printf("%d\n", f[end] - f[start] + 1);
		}
	}
	return 0;
}