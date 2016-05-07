// https://www.acmicpc.net/problem/11052
// 붕어빵 i개를 팔면 Pi원을 얻을 수 있다. N개를 팔때 최대수익은 얼마인가?
// D[i] = 붕어빵 i개를 팔면 얻을 수 있는 최대수익
// D[0] = 0원
// D[1] = P1 + D[i - 1] // 1개를 팔면 P1을 얻고, i - 1개를 다시 구한다.
// D[2] = P2 + D[i - 2] // 2개를 팔면 P2를 얻고, i - 2개를 다시 구한다.
// D[3] = P3 + D[i - 3] // 3개를 팔면 P3을 얻고, i - 3개를 다시 구한다.
// D[i - 2] = P(i - 2) + D[i - i + 2] // i - 2개를 팔면 P(i - 2)을 얻고 2개를 다시 구한다.
// D[i - 1] = P(i - 1) + D[i - i + 1] // i - 1개를 팔면 P(i - 1)을 얻고 1개를 다시 구한다.
// D[i] = Pi + D[i - i] = Pi + D[0] // i개를 팔면 Pi를 얻고, 0개를 다시 구한다.
// D[i] = max(P[j] + D[i - j]) 단, 1<=i<=j 이다.


#include <stdio.h>

#define MAXN 1001
int D[MAXN];
int P[MAXN];
int N;

void intput()
{
	scanf("%d\n", &N);
	int i;
	for (i = 0; i <= N; i++) {
		D[i] = 0;
		scanf(" %d", &P[i + 1]);
	}
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int solve()
{
	int i, j;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= i; j++) {
			D[i] = max(P[j] + D[i - j], D[i]);
		}
	}
	return D[N];
}

int main()
{
	freopen("input.txt", "r", stdin);
	intput();
	printf("%d\n", solve());
	
	return 0;
}
