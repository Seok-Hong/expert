// 실수한것. 최대합이 음수일 수 있는데, dp[0]을 0으로 했더니 음수가 계산이 안되었다. -INF로 충분히 큰수를 넣었다.
// 제대로 하려면 n개중 최소값보다 더 작은 값을 넣으면 될 것 같다.

#include <stdio.h>

#define INF 987654321
typedef long long ll;
#define MAXN 100010
ll d[MAXN]; // d[i] = a[1],a[2],...,a[i]인 수열 중 a[i]를 마지막으로 포함하는 최대 연속합
ll a[MAXN];
int N;

void intput()
{
	scanf("%d\n", &N);
	int i;
	for (i = 1; i <= N; i++) {
		scanf(" %lld", &a[i]);
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
	int i;
	d[0] = -INF;
	for (i = 1; i <= N; i++) {
		d[i] = a[i];
		if (d[i - 1] + a[i] > d[i])
			d[i] = d[i - 1] + a[i];
	}

	ll maxlen = d[1];
	for (i = 2; i <= N; i++)
		maxlen = max2(d[i], maxlen);

	return maxlen;
}

int main()
{
	freopen("input.txt", "r", stdin);
	intput();
	printf("%lld\n", solve());
	
	return 0;
}
