// 일단 마지막 숫자를 기준으로 보면,
// <-길이i-->
// xxxxxxx 0
// xxxxxxx 1
// xxxxxxx 2
// ...
// xxxxxxx 8
// xxxxxxx 9
// 가 되겠구요,
// 
// 1은 바로 앞이 0 혹은 2만 될 수 있고,
// 2는 바로 앞이 1 혹은 3만 될 수 있고,
// ...
// 8은 바로 앞이 7 혹은 9만 될 수 있어서..
// 
// i가 8이라고 할때,
// 
// 8은 바로 앞이 7(D[i - 1][j - 1]) 혹은 9(D[i - 1][j + 1])만 될 수 있어서..
// 로 점화식을 쓸 수 있는 것 같습니다.

#include <stdio.h>

#define MODVAL  1000000000
#define MAXN 111
int D[MAXN][11];
int N;

void intput()
{
	scanf("%d\n", &N);
}

int max(int a, int b)
{
	return a > b ? a : b;
}

long long solve()
{
	int i, j;
	// N == 1 모두 계단수
	D[1][0] = 0;
	for (j = 1; j <= 9; j++)
		D[1][j] = 1;
	for (i = 2; i <= N; i++) {
		for (j = 0; j <= 9; j++) {
			D[i][j] = 0;
			if (j - 1 >= 0) D[i][j] += D[i - 1][j - 1];
			if (j + 1 <= 9) D[i][j] += D[i - 1][j + 1];
			D[i][j] %= MODVAL;
		}
	}

	long long ans = 0;
	for (j = 0; j <= 9; j++) {
		ans += D[N][j];	// 길이 N이고, 끝이 0~9로 끝나는 모든 계산수의 합
	}
	return ans % MODVAL;
}

int main()
{
	freopen("input.txt", "r", stdin);
	intput();
	printf("%lld\n", solve());
	
	return 0;
}
