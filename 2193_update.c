#include <stdio.h>

typedef long long ll;
#define MAXN 100
ll d[MAXN]; // d[i] = 길이 i인 이친수의 개수
int N;

void intput()
{
	scanf("%d\n", &N);
}

ll solve()
{
	d[0] = 0;
	d[1] = 1; // 0으로 시작할 수 없다. 1로 시작하는 것만 셈.
	
	int i;
	for (i = 2; i <= N; i++) {
		d[i] = d[i - 1] + d[i - 2];
		// 끝이 0일때 앞에 0,1모두 올수 있으니, 바로앞의 경우의수가 된다.
		// 끝이 1일때 바로 앞의 수는 0,1을 모두 포함하고 있다, 1을 연속되면 안된다.
		// i - 2번째는 바로 앞의 수가 0일때, i - 2번째인 0,1을 모두 포함하는 수를 표현할 수 있다.
	}
	
	return d[N];
}

int main()
{
	intput();
	printf("%lld\n", solve());
	
	return 0;
}
