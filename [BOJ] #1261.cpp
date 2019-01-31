#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
int n, m;
int arr[101][101];
int d[101][101];
int di[4] = { 0,0,1,-1 };
int dj[4] = { 1,-1,0,0 };
typedef struct node{
	pair<int, int> pos;
	int val;
};

bool operator < (node a, node b) {

	return a.val > b.val;
}

int main()
{
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%1d", &arr[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			d[i][j] = INT32_MAX;
	d[1][1] = 0;
	priority_queue<node> pq;
	pq.push({ make_pair(1,1), 0 });
	while (!pq.empty())
	{
		node cur = pq.top();
		pq.pop();
		for (int i = 0; i < 4; i++)
		{
			int ni = cur.pos.first + di[i];
			int nj = cur.pos.second + dj[i];
			if (ni >= 1 && ni <= n && nj >= 1 && nj <= m)
			{
				if (d[ni][nj] > cur.val + arr[ni][nj])
				{
					d[ni][nj] = arr[ni][nj] + cur.val;
					pq.push({ make_pair(ni,nj), d[ni][nj] });
				}
			}
		}
	}
	printf("%d", d[n][m]);
	return 0;
}