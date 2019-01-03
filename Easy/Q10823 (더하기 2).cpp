#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string t, tot;
	int i, len, tn = 0, sum = 0;

	while (getline(cin, t)) tot += t;

	len = tot.length();
	for (i = 0; i < len; i++) {
		if (tot[i] == ',') {
			sum += stoi(tot.substr(tn, i - tn + 1));
			tn = i + 1;
		}
	}

	sum += stoi(tot.substr(tn, len - tn));
	printf("%d\n", sum);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/10823
// 10823 더하기 2
// 문자열 처리