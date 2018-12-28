#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;
bool check[100];
char num[100];
int ans[52], len, lim;

bool go(int stat, int idx) {
	if (stat >= len) return true; // 종료
	
	int j = -1, k = num[stat] - '0';
	if (stat + 1 < len) j = num[stat + 1] - '0';

	if (!check[k]) { // 한자리수
		ans[idx] = k;
		check[k] = true;
		if(go(stat + 1, idx + 1)) return true;
		check[k] = false;
		ans[idx] = -1;
	} 

	if (j != -1 && 10 * k + j <= lim && !check[10 * k + j]) { // 두자리 수
		ans[idx] = 10 * k + j;
		check[10 * k + j] = true;
		if (go(stat + 2, idx + 1)) return true;
		check[10 * k + j] = false;
		ans[idx] = -1;
	}
	return false;
}

int main(void)
{
	int i;
	for (i = 0; i < 52; i++) ans[i] = -1;
	scanf("%s", &num);
	for (i = 0; num[i]; i++) len = i;
	len++;

	if (len < 10) lim = len;
	else lim = 9 + ((len - 9) / 2);

	go(0, 0);
	for (i = 0; ans[i] != -1; i++) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/10597
// 10597 순열장난
// 백트래킹