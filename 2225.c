#include <stdio.h>

typedef long long ll;
#define MAXNK 210
ll d[MAXNK][MAXNK]; // d[k][n] += d[k - 1][n - l] (0<=l<=n)
int N, K;

void intput()
{
	scanf("%d %d\n", &N, &K);
}

ll max2(ll a, ll b)
{
	return a > b ? a : b;
}

ll max3(ll a, ll b, ll c)
{
	ll m1 = max2(a, b);
	ll m2 = max2(b, c);
	return m1 > m2 ? m1 : m2;
}

ll min2(ll a, ll b)
{
	return a < b ? a : b;
}

ll solve()
{
	d[0][0] = 1LL;
	int k, n, l;
	for (k = 1; k <= K; k++) {
		for (n = 0; n <= N; n++) {
			for (l = 0; l <= n; l++) {
				d[k][n] += d[k - 1][n - l];
				d[k][n] %= 1000000000;
			}
		}
	}

	return d[K][N];
}

int main()
{
	freopen("input.txt", "r", stdin);
	intput();
	printf("%lld\n", solve());
	
	return 0;
}
