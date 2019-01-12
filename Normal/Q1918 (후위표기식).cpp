#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

char set[101], st[101], ans[102];
int idx, idx2;

int priority(char c)
{
	switch (c)
	{
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	case '(':
	case ')':
		return 0;
	default:
		return -1;
	}
}

int main(void)
{
	int i;
	scanf("%s", set);
	for (i = 0; set[i]; i++) {
		int pri = priority(set[i]);
		char t = set[i];

		switch (t) {
		case '+':
		case '-':
		case '*':
		case '/':
			while (idx > 0 && priority(st[idx - 1]) >= pri) {
				ans[idx2++] = st[--idx];
			}
			st[idx++] = t;
			break;
		case '(':
			st[idx++] = t;
			break;
		case ')':
			while (idx > 0 && st[idx - 1] != '(') {
				ans[idx2++] = st[--idx];
			}
			st[--idx];
			break;
		default:
			ans[idx2++] = t;
		}
	}

	while (idx > 0) {
		ans[idx2++] = st[--idx];
	}
	
	printf("%s\n", ans);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/1918
// 1918 후위표기식
// 스택