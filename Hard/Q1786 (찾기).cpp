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
		while (j > 0 && T[i] != P[j]) j = fail[j - 1]; // 글자 불일치시 fail 함수 값을 따라감
													   // while 문인 이유는 실패함수 값이 길이 절반보다 클수 있기 때문 (ex)ababab 에서 fail(6) = 6)
		if (T[i] == P[j]) { // 현재 글자가 일치
			if (j == N - 1) { // P를 T[i:i+M-1]에서 찾음
				q[idx++] = i - N + 2; // 좌표 시작이 1인 문제
				j = fail[j]; // 찾지 못했을 때처럼 j를 실패함수로 이동
			}
			else j++;
		}
	}

	printf("%d\n", idx);
	for (i = 0; i < idx; i++) printf("%d ", q[i]);
	printf("\n");
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/1786
// 1786 찾기
// KMP 알고리즘