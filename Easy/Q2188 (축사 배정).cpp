#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 201

int countA, countB;
int matchA[MAX];
int matchB[MAX];
int adj[MAX][MAX];
int visited[MAX];

bool dfs(int a)
{
	int b;

	if (visited[a]) return false;

	visited[a] = 1;

	for (b = 1; b <= countB; ++b)
	{
		if (adj[a][b] && (matchB[b] == -1 || dfs(matchB[b])))
		{
			matchA[a] = b;
			matchB[b] = a;
			return true;
		}
	}

	return false;
}

int bipartiteMatch(void)
{
	int i, start, size = 0;
	for (start = 1; start <= countA; ++start)
	{
		for (i = 1; i <= countA; i++) visited[i] = 0;
		if (dfs(start)) size++;
	}
	return size;
}

void initialize(void) 
{
	int i, j;
	for (i = 1; i <= countA; i++)
	{
		matchA[i] = -1;
		for (j = 1; j <= countB; j++) adj[i][j] = 0;
	}

	for (i = 1; i <= countB; i++) matchB[i] = -1;
}

int main(int argc, char* argv[]) 
{
	int i, j, num, barn;
	scanf("%d %d", &countA, &countB);

	initialize();

	for (i = 1; i <= countA; i++) 
	{
		scanf("%d", &num);
		for (j = 0; j < num; j++)
		{
			scanf("%d", &barn);
			adj[i][barn] = 1;
		}
	}
 	printf("%d\n", bipartiteMatch());
	
	return 0;
}