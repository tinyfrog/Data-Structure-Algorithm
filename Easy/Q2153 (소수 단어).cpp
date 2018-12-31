#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

char word[21];

bool check(int a)
{
	if (a == 1) return true;
	if (!(a % 2)) return false;

	int i;
	for (i = 3; i * i <= a; i += 2) {
		if (!(a % i)) return false;
	}
	return true;
}

int main(void)
{
	int i, sum = 0;
	scanf("%s", word);

	for (i = 0; word[i]; i++) {
		if (word[i] <= 'z' && word[i] >= 'a') sum += word[i] - 'a' + 1;
		else if (word[i] <= 'Z' && word[i] >= 'A') sum += word[i] - 'A' + 27;
	}

	if (check(sum)) printf("It is a prime word.\n");
	else printf("It is not a prime word.\n");
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/2153
// 2153 소수 단어
// 수학