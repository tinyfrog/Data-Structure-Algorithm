#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int i, N, len, t;
	string s;

	cin >> N;
	cin.ignore(); // 숫자 -> 문자, 버퍼 비우기

	while (N--)
	{
		getline(cin, s);
		len = s.length();

		for (i = 0; i < len; i++) {
			if (s[i] == ' ') {
				t = i;
				break;
			}
		}
		printf("god");
		for (i = t + 1; i < len; i++) {
			if (s[i] == ' ') continue;
			else printf("%c", s[i]);
		}
		printf("\n");
	}

	return 0;
}