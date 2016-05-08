// 11053과 유사하다, 가장 긴 증가수열이라서 조건에 1을 더한값이 되었고,
// 이문제는 최대합이기때문에 a[i]를 넣었다.
#include <stdio.h>

typedef long long ll;
#define MAXN 10010
ll d[MAXN]; // d[i] = a[1],a[2],...,a[i]인 수열 중 a[i]를 마지막으로 포함하는 증가수열의 최대합
ll a[MAXN];
int N;

void intput()
{
	scanf("%d\n", &N);
	int i;
	for (i = 1; i <= N; i++) {
		scanf(" %d", &a[i]);
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
	d[0] = 0;	//길이0 = 0
	
	int i, j;
	d[1] = 0;
	d[1] = a[1]; //길이1 = 무조건 1개는 증가수열된다. a[1]이 가장 큰 합.

	for (i = 2; i <= N; i++) {
		d[i] = 0;
		for (j = 0; j < i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + a[i]) {	// a[i]를 기준으로 a[0] ~ a[i - 1]중 a[1]보다 작아야하고, a[j]뒤에 a[i]를 더하는 것이 가장 큰수인가?
													    // 를 검사해서 길면 하나 더 증가(자신을 포함시킨다)
				d[i] = d[j] + a[i];
			}
		}
	}

	ll maxlen = 0;
	for (i = 0; i <= N; i++) {
		maxlen = max2(d[i], maxlen);
	}

	return maxlen;
}

int main()
{
	freopen("input.txt", "r", stdin);
	intput();
	printf("%lld\n", solve());
	
	return 0;
}
