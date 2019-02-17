#include<cstdio>
#include<queue>
#include<string.h>
using namespace std;
int n;
int arr[101][101];
int answer[101][101] = { 0 };

void bfs(int i)
{
	queue<int> q;
	q.push(i);
	bool check[101] = { false };
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int x = 1; x <= n; x++)
			if (check[x] == false && arr[cur][x] == 1)
			{
				q.push(x);
				check[x] = true;
				answer[i][x] = 1;
			}
	}
	return;
}

int main()
{
	memset(answer, 0, sizeof(answer));
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &arr[i][j]);
	for (int i = 1; i <= n; i++)
		bfs(i);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			printf("%d ", answer[i][j]);
		printf("\n");
	}
	return 0;
}