#include <stdio.h>

typedef long long ll;
#define MAXN 40
ll d[MAXN]; // d[i] = 3xi 사각형을 1x2, 2x1로 채우는 경우의 수
			// d[i] = 3*d[i - 2] + 2*d[i - 4] + 2*d[i - 6] + ...
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
	d[0] = 1;
	int i, j;
	for (i = 1; i <= N; i++) {
		if (i % 2 != 0) {	// 홀수일때 채울 수 없음.
			d[i] = 0;
			continue;
		}

		d[i] = 3 * d[i - 2];
		for (j = i - 4; j >= 0; j -= 2) {
			d[i] += 2 * d[j];
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
