#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int m, n, k;
int arr[50][50];
bool check[50][50];
int cnt = 0;
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,1,-1 };

void bfs(int i, int j)
{
	queue<pair<int, int>> q;

	q.push(make_pair(i, j));
	while (!q.empty())
	{
		pair<int, int>cur = q.front();
		q.pop();
		for (int a = 0; a < 4; a++)
		{
			int ni = cur.first + di[a];
			int nj = cur.second + dj[a];
			if (ni >= 0 && ni < n && nj >= 0 && nj < m && arr[ni][nj] == 1 && check[ni][nj] == false)
			{
				q.push(make_pair(ni, nj));
				check[ni][nj] = true;
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		::cnt = 0;
		memset(check, false, sizeof(check));
		memset(arr, 0, sizeof(arr));
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++)
		{
			int x, y;
			cin >> y >> x;
			arr[x][y] = 1;
		}
		for (int a = 0; a < n; a++)
		{
			for (int b = 0; b < m; b++)
			{
				if (arr[a][b] == 1 && check[a][b] == false)
				{
					check[a][b] = true;
					::cnt++;
					bfs(a, b);
				}
			}
		}

		cout << ::cnt << endl;
	}
	return 0;
}