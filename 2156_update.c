#include <stdio.h>

typedef long long ll;
#define MAXN 10010
ll d[MAXN]; // d[i] = i번째 포도주를 마실때 최대 포도주양
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
	d[0] = 0;
	d[1] = a[1];
	d[2] = a[1] + a[2];
	int i;
	for (i = 3; i <= N; i++) {
		ll case1_dont_drink = d[i - 1];
		ll case2_drink_1time = d[i - 2] + a[i]; // 1번연속마시려면 바로전에는 안마셔야함.
		ll case3_drink_2time = d[i - 3] + a[i - 1] + a[i]; // 2번연속마시려면 i - 2에 안마시고, i - 1을 마시고, i도 마셔야함.
															// i - 2를 빼려면 i - 3에 i - 1와 i를 더한다.
		d[i] = max3(case1_dont_drink, case2_drink_1time, case3_drink_2time);
	}

	return d[N];
}

int main()
{
	freopen("input.txt", "r", stdin);
	intput();
	printf("%lld\n", solve());
	
	return 0;
}
