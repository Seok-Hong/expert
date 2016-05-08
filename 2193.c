// REMEMEBER ! can be longlong!!!
#include <stdio.h>

typedef long long ll;
#define MAXN 100
ll d[MAXN][2];
int N;

void intput()
{
	scanf("%d\n", &N);
}

ll solve()
{
	d[0][0] = 0;
	d[0][1] = 0;
	d[1][0] = 0; // 0으로 시작할 수 없다.
	d[1][1] = 1;

	int i;
	for (i = 2; i <= N; i++) {
		d[i][0] = d[i - 1][0] + d[i - 1][1];
		d[i][1] = d[i - 1][0]; // 1은 연속될 수 없다.
	}
	
	return d[N][0] + d[N][1];
}

int main()
{
	intput();
	printf("%lld\n", solve());
	
	return 0;
}
