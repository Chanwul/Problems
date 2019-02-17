#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;
bool arr[101][101];
int m, n, k;
int di[4] = { 0,0,1,-1 };
int dj[4] = { 1,-1,0,0 };

typedef struct compare
{
	bool operator() (int a, int b)
	{
		return a > b;
	}
};

priority_queue<int, vector<int>, compare> pq;

void go(int i, int j)
{
	int res = 0;
	queue<pair<int, int>> q;
	arr[i][j] = true;
	q.push(make_pair(i, j));
	while (!q.empty())
	{
		res++;
		pair<int, int> cur = q.front();
		q.pop();
		for (int x = 0; x < 4; x++)
		{
			int ni = cur.first + di[x];
			int nj = cur.second + dj[x];
			if (ni >= 0 && ni < m && nj >= 0 && nj < n && arr[ni][nj] == false)
			{
				q.push(make_pair(ni, nj));
				arr[ni][nj] = true;
			}

		}
	}
	pq.push(res);
	return;
}

int main()
{
	scanf("%d %d %d", &m, &n, &k);
	for (int i = 0; i < k; i++)
	{
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		for(int x=m-b-1; x>=m-d;x--)
			for (int y = a; y <= c - 1; y++)
				arr[x][y] = true;
	}
	int answer = 0;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if (arr[i][j] == false)
			{
				go(i, j);
				answer++;
			}

	printf("%d\n", answer);
	while (!pq.empty())
	{
		printf("%d ", pq.top());
		pq.pop();
	}
	return 0;
}