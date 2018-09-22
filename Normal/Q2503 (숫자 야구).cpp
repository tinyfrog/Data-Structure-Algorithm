#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ar[101][3];

int main(void)
{
	int i, j, k, n, T, ans = 0;
	int c1, c2, c3;
	int t1, t2, t3;
	bool flag;
	scanf("%d", &T);

	for(i = 0; i < T; i++) scanf("%d %d %d", &ar[i][0], &ar[i][1], &ar[i][2]);
	
	for (i = 123; i <= 987; i++) {
		flag = true;
		c1 = i % 10, c2 = (i / 10) % 10, c3 = i / 100;
		if (c1 == 0 || c2 == 0 || c3 == 0) continue; // 1 ~ 9 숫자만 가능
		if (c1 == c2|| c2 == c3 || c1 == c3) continue; // 세 숫자가 달라야 함
		for (j = 0; j < T; j++) {
			n = 0;
			t1 = ar[j][0] % 10, t2 = (ar[j][0] / 10) % 10, t3 = ar[j][0] / 100;
			
			if (c1 == t1) ++n;
			if (c2 == t2) ++n;
			if (c3 == t3) ++n;
			if (n != ar[j][1]) { // strike 판별
				flag = false;
				break;
			}

			n = 0;
			if (c1 == t2 || c1 == t3) ++n;
			if (c2 == t1 || c2 == t3) ++n;
			if (c3 == t1 || c3 == t2) ++n;
			if (n != ar[j][2]) {
				flag = false;
				break;
			}
		}
		if (flag) ++ans;
	}
	printf("%d\n", ans);
	return 0;
}

// 문제 : https://www.acmicpc.net/problem/2503