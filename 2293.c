#include <stdio.h>

#define MAXN 110
#define MAXK 10010
int d[MAXK];	// d[i] = i원을 만드는 경우의 수
int a[MAXN];
int N, K;

void intput()
{
	scanf("%d %d\n", &N, &K);
	int i;
	for (i = 1; i <= N; i++) {
		scanf("%d\n", &a[i]);
	}
}

int solve()
{
	d[0] = 1;	// 0개로 0원을 만드는 것, 그자체로 1
	int i, j;
	for (i = 1; i <= N; i++) {
		for (j = 0; j <= K; j++) {
			if (j - a[i] >= 0) {
				d[j] += d[j - a[i]];	// a[i]를 넣는경우에, a[1]~a[i-1]원이 현재 만드려는 j원에서 a[i]를 뺀 값이 되어야 한다.
			}
		}
	}
	return d[K];
}

int main()
{
	freopen("input.txt", "r", stdin);
	intput();
	printf("%d\n", solve());
	return 0;
}
