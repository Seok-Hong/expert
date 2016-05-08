// 경우의 수. x == y, 즉 숫자가 1개면 무조건 펠린드롬.
// 경우의 수. x + 1 == y, 즉 숫자가 2개일때, 두 숫자가 같으면 펠린드롬.
// 경우의 수. 그외에, a[x] == a[y]이고, d[x + 1][y - 1]이 펠린드롬이면, d[x][y]는 펠린드롬.
// 바깥쪽에서 안쪽으로 내려가면서 계산하기 때문에 재귀로 호출했으며,
// 질문을 계속할 수록 d가 정리되면서 복수문제를 풀지 않는다.

#include <stdio.h>

#define MAXN 2010
int d[MAXN][MAXN];	// d[i][j] = a[i]~a[j]가 펠린드롬이면 1, 아니면 0, 정의되지 않았으면 -1
int a[MAXN];
int N, M;

int solve(int x, int y)
{
	if (x == y)	return 1;		// d[i][i] = 1
	else if (x + 1 == y) {
		// 2개일때
		if (a[x] == a[y]) return 1;
		else return 0;
	}

	if (d[x][y] != -1) return d[x][y];
	if (a[x] != a[y]) return d[x][y] = 0;
	else return d[x][y] = solve(x + 1, y - 1);
}

int main()
{
	freopen("input.txt", "r", stdin);

	scanf("%d\n", &N);
	int i, j;
	for (i = 1; i <= N; i++) {
		scanf(" %d", &a[i]);
	}
	for (i = 0; i <= N; i++) {
		for (j = 0; j <= N; j++) {
			d[i][j] = -1;
		}
	}
	scanf("%d\n", &M);
	for (i = 0; i < M; i++) {
		int m1, m2;
		scanf("%d %d\n", &m1, &m2);
		printf("%d\n", solve(m1, m2));
	}
	
	return 0;
}
