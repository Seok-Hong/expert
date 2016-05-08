#include <stdio.h>

typedef long long ll;
#define MAXN 10010
ll d[MAXN][3]; // d[i][j] = i번째 포도주를 마실때 최대 포도주양, j=0, i번 안마심, j=1, 1번마심, j=2 2번연속마심
ll a[MAXN];
int N;

void intput()
{
	scanf("%d\n", &N);
	int i;
	for (i = 1; i <= N; i++) {
		scanf("%d\n", &a[i]);
	}
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

ll solve()
{
	d[0][0] = 0;
	d[0][1] = 0;
	d[0][2] = 0;
	d[1][0] = 0;
	d[1][1] = a[1];
	d[1][2] = a[1];
	int i;
	for (i = 2; i <= N; i++) {
		d[i][0] = max3(d[i - 1][0], d[i - 1][1], d[i - 1][2]);
		d[i][1] = d[i - 1][0] + a[i]; // 1번연속마심. 이전에는 안마셔야 함.
		d[i][2] = d[i - 1][1] + a[i]; // 2번연속마심. 이전에는 마셨어야 함.
	}

	return max3(d[N][0], d[N][1], d[N][2]);
}

int main()
{
	freopen("input.txt", "r", stdin);
	intput();
	printf("%lld\n", solve());
	
	return 0;
}
