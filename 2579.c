#include <stdio.h>

typedef long long ll;
#define MAXN 310
ll d[MAXN][3]; // d[i] = i번째 계단을 j번 연속으로 밟을 때의 최대점수
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
	d[0][0] = d[0][1] = d[0][2] = 0;
	d[1][0] = 0;
	d[1][1] = d[1][2] = a[1];

	int i;
	for (i = 2; i <= N; i++) {
		d[i][0] = 0;	// i번은 안밟을 수 없다.
		d[i][1] = max2(d[i - 2][1], d[i - 2][2]) + a[i];	// 1번 연속으로 밟으려면 i - 1을 밟으면 안되고, i - 2를 1연속,2연속 밟을때 큰 값이면 된다.
		d[i][2] = d[i - 1][1] + a[i]; // 2번 연속으로 밟으려면 i - 1을 꼭 밟아야 하는데, i - 1이 1연속일때만 가능하다.
	}

	return max2(d[N][1], d[N][2]); // 마지막은 꼭 밟아야한다.
}

int main()
{
	freopen("input.txt", "r", stdin);
	intput();
	printf("%lld\n", solve());
	
	return 0;
}
