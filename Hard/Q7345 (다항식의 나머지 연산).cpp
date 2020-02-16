#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 2020;
int f[N], g[N], h[N], p[N];
int cf, cg, ch, cp;

int main(void)
{
	int i, j, k, l, T;
	
	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		memset(p, 0, sizeof(p));
		scanf("%d", &cf);
		for (j = cf - 1; j >= 0; j--) scanf("%d", &f[j]);
		scanf("%d", &cg);
		for (j = cg - 1; j >= 0; j--) scanf("%d", &g[j]);
		scanf("%d", &ch);
		for (j = ch - 1; j >= 0; j--) scanf("%d", &h[j]);

		for (k = 0; k < cf; k++) {
			for (l = 0; l < cg; l++) {
				p[k + l] ^= f[k] & g[l]; // XOR operator (mod 2)
			}
		}

		cp = cf + cg; // coefficient of h(x)
		while (1)
		{
			while (!p[--cp]); // if 0 then skip
			if (cp + 1 < ch) break;
			for (k = ch - 1, l = cp; k >= 0; k--, l--) p[l] ^= h[k];
		}

		printf("%d", cp + 1);
		for (j = cp; j >= 0; j--) printf(" %d", p[j]);
		printf("\n");
	}
	return 0;
}

// Q7345 (다항식의 나머지 연산)
// 대전 2001 C번