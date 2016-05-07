// https://www.acmicpc.net/problem/9095
// D[n] = n을 1, 2, 3의 합으로 나타낼 수 있는 경우의 수
// D[0] = 0
// D[1] = 1 (1)
// D[2] = 2 (11, 2)
// D[3] = 4 (111,12,21,3)
// D[n] = D[n - 1] + D[n - 2] + D[n - 3];
// n을 1을 빼보고, 2를 빼보고, 3을 빼보는 경우의 수가 반환되면 된다.

#include <stdio.h>

#define MAXN 12
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
	if (n == 2) return D[n] = 2;
	if (n == 3) return D[n] = 4;
	if (D[n] != -1)
		return D[n];
	return D[n] = solve(n - 1) + solve(n - 2) + solve(n - 3);
}

int main()
{
	freopen("input.txt", "r", stdin);

	int T;
	scanf("%d\n", &T);
	while (T--) {
		intput();
		printf("%d\n", solve(N));
	}

	return 0;
}
