#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int ar[10002];

int main(void)
{
	int i, wall, value, tmp;
	scanf("%d", &N);
	
	for (i = 1; i <= N; i++) scanf("%d", &ar[i]);

	wall = N, value = ar[N];
	for (i = N; i >= 2; i--) { // �������� ���ʺ��� �� ū ������ ã��
		if (ar[i - 1] < ar[i]) {
			wall = i - 1;
			value = ar[i - 1];
			break;
		}
	}

	if (wall == N) { // ������
		printf("-1\n");
		return 0;
	}

	for (i = N; i > wall; i--) { // ������ ������ ū���� ���� ���� ��谪�� �ٲ�
		if (value < ar[i]) {
			tmp = ar[wall];
			ar[wall] = ar[i];
			ar[i] = tmp;
			break;
		}
	}
	for (i = wall + 1; i <= N - 1; i++) { // ������ ������ ������������
		for (int j = i + 1; j <= N; j++) {
			if (ar[i] > ar[j]) {
				tmp = ar[i];
				ar[i] = ar[j];
				ar[j] = tmp;
			}
		}
	}

	for (int i = 1; i <= N; i++) printf("%d ", ar[i]);
	printf("\n");
	return 0;
}

// ��Ģ ã��