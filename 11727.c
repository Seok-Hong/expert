//https://www.acmicpc.net/problem/11727
//D[i] = 2xi 사각형을 2x1, 1x2, 2x2 타일로 채우는 경우의 수

//2x3,
//2x4,
//2x5를 실제로 그려보면, 2x5에서 2x3이 2번 2x4가 1번 나옴을 알 수 있다.
//2x3이 2번인 이유는 1x2가 2개인경우, 2x2가 1개인경우로 2x5를 채우는 경우로 나뉘기 때문
#include <stdio.h>

#define MAXN 1001
int D[MAXN];
int N;

void intput()
{
	scanf("%d\n", &N);
	int i;
	for (i = 0; i <= N; i++) {
		D[i] = -1;
	}
}

int solve(int n)
{
	if (n == 0) return D[n] = 0;
	if (n == 1) return D[n] = 1;
	if (n == 2) return D[n] = 3;
	if (D[n] != -1)
		return D[n];
	return D[n] = ((solve(n - 1) + 2*solve(n - 2)) % 10007);
}

int main()
{
	freopen("input.txt", "r", stdin);
	intput();
	printf("%d\n", solve(N));
}
