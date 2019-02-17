#include <cstdio>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int n, m, v;
int arr[1001][1001] = { 0 };
bool check[1001] = { 0 };

void dfs(int x)
{
	printf("%d ", x);
	for(int i=1;i<=n;i++)
		if (arr[x][i] == 1 && check[i] == false)
		{
			check[i] = true;
			dfs(i);
		}
	return;
}

void bfs(int x)
{
	queue<int> q;
	q.push(x);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		printf("%d ", cur);
		for (int i = 1; i <= n; i++)
		{
			if (arr[cur][i] == 1 && check[i] == false)
			{
				check[i] = true;
				q.push(i);
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &v);
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	check[v] = true;
	dfs(v);
	printf("\n");
	memset(check, 0, sizeof(check));
	check[v] = true;
	bfs(v);
	return 0;
}