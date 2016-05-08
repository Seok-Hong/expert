#include <stdio.h>

typedef long long ll;
#define MAXN 1010
ll d[MAXN][MAXN]; // d[i][j] = (1,1)에서 (i,j)로 올때 최대 사탕값
int map[MAXN][MAXN];
int N, M;

ll max2(ll a, ll b)
{
	return a > b ? a : b;
}

void intput()
{
	scanf("%d %d\n", &N, &M);
	int i, j;
	for (i = 0; i <= N; i++) {
		d[i][0] = 0;
		d[0][i] = 0;
		d[N + 1][0] = 0;
		d[0][N + 1] = 0;
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			scanf(" %d", &map[i][j]);
			d[i][j] = 0;
		}
	}
}

ll solve()
{
	int i, j;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			d[i][j] = max2(d[i - 1][j], d[i][j - 1]) + map[i][j];
		}
	}

	return d[N][M];
}

int main()
{
	freopen("input.txt", "r", stdin);
	intput();
	printf("%lld\n", solve());

	return 0;
}
