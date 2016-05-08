// 증가수열 d1
// 감소수열 d2, 2개를 구한다음에 d1[i] + d2[i] - 1중 최대값이 정답. -1인 이유는 d[i]가 a[i]를 포함하기 때문에 중복되는 a[i]를 빼기위함.
#include <stdio.h>

typedef long long ll;
#define MAXN 10010
ll d[MAXN]; // d[i] = a[1],a[2],...,a[i]인 수열 중 a[i]를 마지막으로 포함하는 증가수열의 최대길이
ll d2[MAXN]; // d2[i] = a2[1],a2[2],...,a2[i]인 수열 중 a[i]를 마지막으로 포함하는 증가수열의 최대길이
ll a[MAXN];
ll a2[MAXN];
int N;

void intput()
{
	scanf("%d\n", &N);
	int i;
	for (i = 1; i <= N; i++) {
		scanf(" %d", &a[i]);	// 가장 긴 증가수열을 찾는다.
		a2[N - i + 1] = a[i];	// 뒤집어서 가장 긴걸 찾을꺼니까.
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

void solve_maxlen(ll dp[MAXN], ll ap[MAXN])
{
	dp[0] = 0;	//길이0 = 0	
	dp[1] = 1;  //길이1 = 무조건 1개는 증가수열된다.

	int i, j;
	for (i = 2; i <= N; i++) {
		dp[i] = 0;
		for (j = 0; j < i; j++) {
			if (ap[j] < ap[i] && dp[i] < dp[j] + 1) {	// a[i]를 기준으로 a[0] ~ a[i - 1]중 a[1]보다 작아야하고, a[j]뒤에 a[i]를 더하는 것이 가장 긴가?
													    // 를 검사해서 길면 하나 더 증가(자신을 포함시킨다)
				dp[i] = dp[j] + 1;
			}
		}
	}
}

ll solve()
{
	solve_maxlen(d, a);
	solve_maxlen(d2, a2);

	ll maxlen = 0;
	int i;
	for (i = 0; i <= N; i++)
		maxlen = max2(d[i] + d2[N - i + 1] - 1, maxlen);  // d2를 거꾸로 찾았다면 d2[i]면 되지만, 
		                                                  // 난 뒤집어서 찾았으니까, 현재 d2결과도 뒤집힌 상태로,, N-i+1로 계산해야한다.

	return maxlen;
}

int main()
{
	freopen("input.txt", "r", stdin);
	intput();
	printf("%lld\n", solve());
	
	return 0;
}
