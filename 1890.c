#include <stdio.h>

typedef long long ll;
#define MAXN 110
ll d[MAXN][MAXN];		// i,j에서 갈 수 있는 경우의 수. map[i][j] == 0이라면 갈 수 없으니 예외처리한다.
int map[MAXN][MAXN];
int N;

ll max2(ll a, ll b)
{
	return a > b ? a : b;
}

void intput()
{
	scanf("%d\n", &N);
	int i, j;
	for (i = 0; i <= N; i++) {
		d[i][0] = 0;
		d[0][i] = 0;
		d[N + 1][0] = 0;
		d[0][N + 1] = 0;
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf(" %d", &map[i][j]);
			d[i][j] = 0;
		}
	}
}

ll solve()
{
	d[1][1] = 1;
	int i, j;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (map[i][j] == 0) continue;
			d[i][j + map[i][j]] += d[i][j];
			d[i + map[i][j]][j] += d[i][j];
		}
	}

	return d[N][N];
}

int main()
{
	freopen("input.txt", "r", stdin);
	intput();
	printf("%lld\n", solve());

	return 0;
}
