#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
char ar[8][7] = { "000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010" };
char word[61];
int check[8];
char ans[11], wrong;

int main(void)
{
	int i, j, k, num, t, idx = 0;
	wrong = 11;
	scanf("%d", &N);
	scanf("%s", &word);

	for (i = 0; word[i]; i += 6) {
		for (j = 0; j < 8; j++) {
			num = 0;
			for (k = 0; k < 6; k++) {
				if (word[i + k] != ar[j][k]) ++num;
			}
			check[j] = num;
			if (check[j] == 0) {
				ans[idx] = 'A' + j;
				break;
			}
		}
		if (ans[idx] != 0) {
			++idx;
			continue; // 글자 찾음
		}

		t = check[0];
		for (j = 1; j < 8; j++) { // 최소값 찾기
			if (check[j] < t) t = check[j];
		}

		num = 0;
		for (j = 0; j < 8; j++) {
			if (check[j] == t) {
				ans[idx] = 'A' + j;
				++num;
			}
		}
		if (num >= 2) { // 찾을수 없는 단어
			wrong = idx + 1;
			break;
		}
		++idx;
	}

	if (wrong != 11) printf("%d\n", wrong);
	else printf("%s\n", ans);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/2596
// 구현