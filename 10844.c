#include <stdio.h>

#define MODVAL  1000000000
#define MAXN 111
int D[MAXN][11];
int N;

void intput()
{
	scanf("%d\n", &N);
}

int max(int a, int b)
{
	return a > b ? a : b;
}

long long solve()
{
	int i, j;
	// N == 1 모두 계단수
	D[1][0] = 0;
	for (j = 1; j <= 9; j++)
		D[1][j] = 1;
	for (i = 2; i <= N; i++) {
		for (j = 0; j <= 9; j++) {
			D[i][j] = 0;
			if (j - 1 >= 0) D[i][j] += D[i - 1][j - 1];
			if (j + 1 <= 9) D[i][j] += D[i - 1][j + 1];
			D[i][j] %= MODVAL;
		}
	}

	long long ans = 0;
	for (j = 0; j <= 9; j++) {
		ans += D[N][j];	// 길이 N이고, 끝이 0~9로 끝나는 모든 계산수의 합
	}
	return ans % MODVAL;
}

int main()
{
	freopen("input.txt", "r", stdin);
	intput();
	printf("%lld\n", solve());
	
	return 0;
}
