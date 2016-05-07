//https://www.acmicpc.net/problem/11727
#include <stdio.h>

#define MAXN 1001
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

int solve(int n)
{
	if (n == 0) return D[n] = 0;
	if (n == 1) return D[n] = 1;
	if (n == 2) return D[n] = 3;
	if (D[n] != -1)
		return D[n];
	return D[n] = ((solve(n - 1) + 2*solve(n - 2)) % 10007);
}

int main()
{
	freopen("input.txt", "r", stdin);
	intput();
	printf("%d\n", solve(N));
}
