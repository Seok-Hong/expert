// simillar with 10844
#include <stdio.h>

#define MODVAL  10007
#define MAXN 1010
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
	for (j = 0; j <= 9; j++)	D[1][j] = 1;
	for (i = 2; i <= N; i++) {
		for (j = 0; j <= 9; j++) {
			D[i][j] = 0;
			int k;
			for (k = 0; k <= j; k++)
				D[i][j] += D[i - 1][k];
			D[i][j] %= MODVAL;
		}
	}

	long long ans = 0;
	for (j = 0; j <= 9; j++) {
		ans += D[N][j];	// 길이 N이고, 끝이 0~9로 끝나는 모든 오름수의 합
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
