#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int map[21][21];
bool c1[21][21], c2[21][21], c3[21][21], c4[21][21]; // 坷弗率, 关, 快惑, 快窍
int ans, a1, a2;

bool check1(int x, int y, int num) // 坷弗率
{
	int t1, t2, n = 1;
	t1 = x, t2 = y;
	c1[x][y] = true;

	while (true)
	{
		t2 += 1;
		if (t2 >= 20 || map[t1][t2] != num) break;
		c1[t1][t2] = true;
		++n;
	}

	if (n == 5) {
		ans = num;
		a1 = x, a2 = y;
		return true;
	}
	else return false;
}

bool check2(int x, int y, int num) // 关
{
	int t1, t2, n = 1;
	t1 = x, t2 = y;
	c2[x][y] = true;

	while (true)
	{
		t1 += 1;
		if (t1 >= 20 || map[t1][t2] != num) break;
		c2[t1][t2] = true;
		++n;
	}

	if (n == 5) {
		ans = num;
		a1 = x, a2 = y;
		return true;
	}
	else return false;
}

bool check3(int x, int y, int num) // 快惑
{
	int t1, t2, n = 1;
	t1 = x, t2 = y;
	c3[x][y] = true;

	while (true)
	{
		t1 -= 1, t2 += 1;
		if (t1 <= 0 || t2 >= 20 || map[t1][t2] != num) break;
		c3[t1][t2] = true;
		++n;
	}

	if (n == 5) {
		ans = num;
		a1 = x, a2 = y;
		return true;
	}
	else return false;
}

bool check4(int x, int y, int num) // 快窍
{
	int t1, t2, n = 1;
	t1 = x, t2 = y;
	c4[x][y] = true;

	while (true)
	{
		t1 += 1, t2 += 1;
		if (t1 >= 20 || t2 >= 20 || map[t1][t2] != num) break;
		c4[t1][t2] = true;
		++n;
	}

	if (n == 5) {
		ans = num;
		a1 = x, a2 = y;
		return true;
	}
	else return false;
}

int main(void)
{
	int i, j;
	ans = 0;
	for (i = 1; i <= 19; i++) {
		for (j = 1; j <= 19; j++) scanf("%d", &map[i][j]);
	}

	for (j = 1; j <= 19; j++) {
		for (i = 1; i <= 19; i++) {
			if (map[i][j] != 0) {
				if (!c1[i][j]) check1(i, j, map[i][j]);
				if (ans != 0) break;
				if (!c2[i][j]) check2(i, j, map[i][j]);
				if (ans != 0) break;
				if (!c3[i][j]) check3(i, j, map[i][j]);
				if (ans != 0) break;
				if (!c4[i][j]) check4(i, j, map[i][j]);
			}
			if (ans != 0) break;
		}
		if (ans != 0) break;
	}

	printf("%d\n", ans);
	if (ans != 0) printf("%d %d\n", a1, a2);
	return 0;
}

// 免贸 : https://www.acmicpc.net/status?user_id=tinyfrog&problem_id=2615&from_mine=1
// 备泅