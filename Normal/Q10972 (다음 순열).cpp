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
	for (i = N; i >= 2; i--) { // 오른쪽이 왼쪽보다 더 큰 지점을 찾기
		if (ar[i - 1] < ar[i]) {
			wall = i - 1;
			value = ar[i - 1];
			break;
		}
	}

	if (wall == N) { // 마지막
		printf("-1\n");
		return 0;
	}

	for (i = N; i > wall; i--) { // 오른쪽 영역의 큰값을 왼쪽 영역 경계값과 바꿈
		if (value < ar[i]) {
			tmp = ar[wall];
			ar[wall] = ar[i];
			ar[i] = tmp;
			break;
		}
	}
	for (i = wall + 1; i <= N - 1; i++) { // 오른쪽 영역을 오름차순으로
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

// 규칙 찾기