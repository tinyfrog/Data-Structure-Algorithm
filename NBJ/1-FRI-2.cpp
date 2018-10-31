#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_NUM 1000001

char lst[MAX_NUM], rst[MAX_NUM]; // Ω∫≈√
char str[MAX_NUM], ans[MAX_NUM];
int idx1, idx2, len;

void initstack()
{
	int i;
	for (i = 0; i < len; i++) str[i] = 0;
	for (i = 0; i < idx1 + idx2; i++) ans[i] = 0;
	idx1 = 0, idx2 = 0, len = 0;
	return;
}

int main(void)
{
	int i, T;
	bool flag;
	scanf("%d", &T);
	while (T--)
	{
		initstack();
		scanf(" %s", str);

		flag = false;
		for (i = 0; str[i]; i++)
		{
			++len;
			switch (str[i])
			{
			case '<':
				if (idx1 == 0) continue;
				rst[idx2++] = lst[idx1 - 1];
				lst[--idx1] = 0; // pop
				break;
			case '>':
				if (idx2 == 0) continue;
				lst[idx1++] = rst[idx2 - 1];
				rst[--idx2] = 0; // pop
				break;
			case '-':
				if (idx1 == 0) continue;
				lst[--idx1] = 0;
				break;
			default:
				lst[idx1++] = str[i];
				break;
			}
		}
		int t2 = idx2;
		for (i = idx1 - 1; i >= 0; i--)
		{
			ans[i] = lst[i];
			lst[i] = 0;
		}
		for (i = idx1; i < idx1 + idx2; i++)
		{
			ans[i] = rst[--t2];
			rst[t2] = 0;
		}
		printf("%s\n", ans);
	}
	return 0;
}