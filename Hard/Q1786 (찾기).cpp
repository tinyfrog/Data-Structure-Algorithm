#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

char T[1000001], P[1000001];
int idx, fail[1000001], q[1000001];

int main(void)
{
	gets(T);
	gets(P);

	int i, j, M = 0, N = 0;

	for (i = 0; T[i]; i++) M++;
	for (i = 0; P[i]; i++) N++;

	for (i = 1, j = 0; i < N; i++) {
		while (j > 0 && P[i] != P[j]) j = fail[j - 1];
		if (P[i] == P[j]) fail[i] = ++j;
	}

	for (i = 0, j = 0; i < M; i++) {
		while (j > 0 && T[i] != P[j]) j = fail[j - 1]; // ���� ����ġ�� fail �Լ� ���� ����
													   // while ���� ������ �����Լ� ���� ���� ���ݺ��� Ŭ�� �ֱ� ���� (ex)ababab ���� fail(6) = 6)
		if (T[i] == P[j]) { // ���� ���ڰ� ��ġ
			if (j == N - 1) { // P�� T[i:i+M-1]���� ã��
				q[idx++] = i - N + 2; // ��ǥ ������ 1�� ����
				j = fail[j]; // ã�� ������ ��ó�� j�� �����Լ��� �̵�
			}
			else j++;
		}
	}

	printf("%d\n", idx);
	for (i = 0; i < idx; i++) printf("%d ", q[i]);
	printf("\n");
	return 0;
}

// ��ó : https://www.acmicpc.net/problem/1786
// 1786 ã��
// KMP �˰���