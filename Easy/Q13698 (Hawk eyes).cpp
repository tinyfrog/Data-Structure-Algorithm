#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int i, t, a1, a2, ar[] = { 1, 2, 3, 4 };
	char st[201];
	scanf("%s", &st);

	for (i = 0; st[i]; i++) {
		switch (st[i])
		{
		case 'A':
			t = ar[0];
			ar[0] = ar[1];
			ar[1] = t;
			break;
		case 'B':
			t = ar[0];
			ar[0] = ar[2];
			ar[2] = t;
			break;
		case 'C':
			t = ar[0];
			ar[0] = ar[3];
			ar[3] = t;
			break;
		case 'D':
			t = ar[1];
			ar[1] = ar[2];
			ar[2] = t;
			break;
		case 'E':
			t = ar[1];
			ar[1] = ar[3];
			ar[3] = t;
			break;
		case 'F':
			t = ar[2];
			ar[2] = ar[3];
			ar[3] = t;
			break;
		}
	}

	for (i = 0; i < 4; i++) {
		if (ar[i] == 1) a1 = i+1;
		else if (ar[i] == 4) a2 = i + 1;
	}
	printf("%d\n%d\n", a1, a2);
}