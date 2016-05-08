#include <stdio.h>

typedef long long ll;
#define MAXN 100010
ll d[MAXN]; // d[i] = 정수i를 제곱근의 합으로 표현할 수 있을때 필요한 최소 제곱근의 개수
			// d[i] = min(d[i - j^2] + 1) (1<=j^2<=i);
int N;

void intput()
{
	scanf("%d\n", &N);
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
	d[0] = 0;
	int i, j;
	for (i = 1; i <= N; i++) {
		d[i] = i;
		for (j = 1; j*j <= i; j++) {
			d[i] = min2(d[i], d[i - j*j] + 1);
		}
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
