// https://www.acmicpc.net/problem/1463
#include <stdio.h>

#define INF 987654321
#define MAXN 1000001
int D[MAXN];

int N;
void intput()
{
	scanf("%d\n", &N);
	int i;
	for (i = 0; i <= N; i++) {
		D[i] = -1;
	}
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int solve(int n)
{
	if (n == 1) 
		return D[n] = 0;
	int minval = INF;

	if (D[n] != -1)
		return D[n];

	// case n-1
	minval = min(solve(n - 1) + 1, minval);
	// case n/3
	if (n % 3 == 0)
		minval = min(solve(n / 3) + 1, minval);
	// case n/2
	if (n % 2 == 0)
		minval = min(solve(n / 2) + 1, minval);

	return D[n] = minval;
}

int main()
{
	intput();
	printf("%d\n", solve(N));
}
