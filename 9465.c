#include <stdio.h>

typedef long long ll;
#define MAXN 100010
ll d[MAXN][3]; // d[i][j] = 2xi 스티커, i열에서 j번째 스티커를 땔때 얻을 수 있는 최대점수 (j=0,안뗌,1,위,2,아래)
ll a[MAXN][3];
int N;

void intput()
{
	scanf("%d\n", &N);
	int i, j;
	for (i = 1; i <= 2; i++) {
		for (j = 1; j <= N; j++) {
			scanf(" %d", &a[j][i]);
		}
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

	int i;
	for (i = 1; i <= N; i++) {
		d[i][0] = max3(d[i - 1][0], d[i - 1][1], d[i - 1][2]);	// 스티커를 안때는 것은 상관없으니 i - 1열의 최대값을 선택
		d[i][1] = max2(d[i - 1][0], d[i - 1][2]) + a[i][1];		// 윗쪽 스티커를 때려면 i - 1열에서 윗스티커를 때면 안된다. + 현재 i열 위스티커의 값 더함
		d[i][2] = max2(d[i - 1][0], d[i - 1][1]) + a[i][2];		// 아래쪽 스티커를 때려면 i - 1열에서 아래스티커를 대면 안된다. + 현재 i열 아래스티커의 값 더함
	}

	return max3(d[N][0], d[N][1], d[N][2]);	// N번째 열 역시, 안떼고, 위떼고, 아래떼고 중 가장 점수가 높은 것이 정답이다.
}

int main()
{
	freopen("input.txt", "r", stdin);

	int T;
	scanf("%d\n", &T);

	while (T--) {
		intput();
		printf("%lld\n", solve());
	}
	
	return 0;
}
